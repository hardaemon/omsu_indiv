#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>

const unsigned int MAX_X1 = 100;
const unsigned int MAX_X2 = 100;

int menu(int one) {
    system("cls");
    printf("< --------------------------- >\n");
    printf("| Что вы хотите сделать?      |\n");
    printf("< --------------------------- >\n");
    printf("| 1. Создать таблицу          |\n");
    printf("| 2. Показать таблицу         |\n");
    printf("| 3. Сохранить таблицу в файл |\n");
    printf("| 4. Выполнить задание №1     |\n");
    printf("| 5. Завершить программу      |\n");
    printf("< --------------------------- >\n\n");
    do {
        printf("Ответ: ");
        scanf("%d", &one);
    } while (one < 1 || one > 5);
    system("cls");
    return one;
}

void f(double **tabl, int& x1, int& x2, int& number) {
    int pop = 0;
    double per1, per2;
    do {
        for (int j = 0; j < x2; j++) {
            if ((j < x2 - 1) && (tabl[number - 1][j] > tabl[number - 1][j + 1])) {
                for (int i = 0; i < x1; i++) {
                    per1 = tabl[i][j];
                    per2 = tabl[i][j + 1];
                    tabl[i][j] = per2;
                    tabl[i][j + 1] = per1;
                }
                pop += 1;
            }
            else if (j == x2 - 1) pop += 1;
        }
    } while (pop < 100000);
    pop = 0;
}

int main()
{
    /*
    Программа для переставления столбца таблицы так, чтобы в заданной строке сначала стояли отрицательные, потом нули, потом положительные числа.
    Входные данные:
    1) Переменная для завершения работы программы                               //(rabota)
    2) Переменная для выбора команды из меню и для выбора ввода чисел в таблицу //(one)
    3) Функция - меню                                                           //(menu(one))
    4) Значение количества строк таблицы                                        //(x1)
    5) Значение количесва столбцов таблицы                                      //(x2)
    6) Переменная для ручного ввода чисел в таблицу                             //(znach)
    7) Заполненный числами массив                                               //(tabl[MAX_X1][MAX_X2])
    8) Значение строки, которую нужно обработать                                //(number)
    9) Переменные для переставления столбцов                                    //(per1, per2, pop)
    10) Переменная для проверки заполнения таблицы                              //(flag)
    11) Функция - подпрограмма                                                  //(f(tabl,x1,x2,number))
    Выходные данные:
    1) Обработанная таблица                                                     //(tabl[MAX_X1][MAX_X2])
    Функция возвращает 0 при завершении программы.
    */
    setlocale(LC_ALL, "Russian");
    double **tabl = new double* [MAX_X1];
    for (int i = 0; i < MAX_X1; i++) tabl[i] = new double[MAX_X2];
    int x1, x2, one, number;
    double znach;
    bool rabota = true, flag = false;
    do {
        one = menu(0);
        if (one == 1) {
            printf("< ------------------------------------------ >\n");
            printf("| Введите размеры таблицы (2 целых значения) |\n");
            printf("< ------------------------------------------ >\n\n");
            printf("Ответ: ");
            scanf("%d%d", &x1, &x2);
            system("cls");
            printf("< ------------------------------------------------------------------------ >\n");
            printf("|                          Как заполнить таблицу?                          |\n");
            printf("< ------------------------------------------------------------------------ >\n");
            printf("| 1. Ввод значений | 2. Произвольные значения | 3. Взять значения из файла |\n");
            printf("< ------------------------------------------------------------------------ >\n\n");
            do {
                printf("Ответ: ");
                scanf("%d", &one);
            } while (one < 1 || one > 3);
            system("cls");
            if (one == 1) {
                printf("< ---------------- >\n");
                printf("| Введите значения |\n");
                printf("< ---------------- >\n\n");
                printf("Ответ: ");
                for (int i = 0; i < x1; i++) {
                    for (int j = 0; j < x2; j++) {
                        scanf("%lf", &znach);
                        tabl[i][j] = znach;
                    }
                }
                system("cls");
                printf("< ----------------- >\n");
                printf("| Таблица заполнена |\n");
                printf("< ----------------- >\n\n");
                flag = true;
                system("pause");
            }
            else if (one == 2) {
                srand(time(0));
                for (int i = 0; i < x1; i++) {
                    for (int j = 0; j < x2; j++) {
                        tabl[i][j] = (rand() % 100 - 50) * 0.1;
                    }
                }
                system("cls");
                printf("< --------------------------------------- >\n");
                printf("| Таблица заполнена рандомными значениями |\n");
                printf("< --------------------------------------- >\n\n");
                flag = true;
                system("pause");
            }
            else if (one == 3)
            {
                printf("< ---------------------------------------- >\n");
                printf("| Введите название файла (или путь к нему) |\n");
                printf("< ---------------------------------------- >\n\n");
                char namef[1000];
                scanf("%s", namef);
                FILE* file = fopen(namef, "r");
                if (file == NULL)
                {
                    system("cls");
                    printf("< --------------------- >\n");
                    printf("| Ошибка открытия файла |\n");
                    printf("< --------------------- >\n\n");
                    system("pause");
                }
                else
                {
                    for (int i = 0; i < x1; i++) {
                        for (int j = 0; j < x2; j++) {
                            fscanf(file, "%lf", &tabl[i][j]);
                        }
                    }
                    system("cls");
                    printf("< ------------------------- >\n");
                    printf("| Таблица успешно извлечена |\n");
                    printf("< ------------------------- >\n\n");
                    fclose(file);
                    flag = true;
                    system("pause");
                }
            }
        }
        else if (one == 2) {
            if (flag == false) {
                printf("< -------------- >\n");
                printf("| Таблица пустая |\n");
                printf("< -------------- >\n\n");
                system("pause");
            }
            else {
                for (int i = 0; i < x1; i++) {
                    for (int j = 0; j < x2; j++) {
                        if (tabl[i][j] < 0) printf(" %.1lf", tabl[i][j]);
                        else printf("  %.1lf", tabl[i][j]);
                    }
                    printf("\n\n");
                }
                printf("\n");
                system("pause");
            }
        }
        else if (one == 3) {
            if (flag == false) {
                printf("< -------------- >\n");
                printf("| Таблица пустая |\n");
                printf("< -------------- >\n\n");
                system("pause");
            }
            else {
                printf("< ---------------------------------------- >\n");
                printf("| Введите название файла (или путь к нему) |\n");
                printf("< ---------------------------------------- >\n\n");
                char nameff[1000];
                scanf("%s", nameff);
                FILE* files = fopen(nameff, "w");
                if (files == NULL)
                {
                    system("cls");
                    printf("< --------------------- >\n");
                    printf("| Ошибка открытия файла |\n");
                    printf("< --------------------- >\n\n");
                    system("pause");
                }
                else
                {
                    for (int i = 0; i < x1; i++) {
                        for (int j = 0; j < x2; j++) {
                            fprintf(files, "%.1lf ", tabl[i][j]);
                        }
                        fprintf(files, "\n");
                    }
                    system("cls");
                    printf("< ------------------------------- >\n");
                    printf("| Таблица успешно записана в файл |\n");
                    printf("< ------------------------------- >\n\n");
                    fclose(files);
                    system("pause");
                }
            }
        }
        else if (one == 4) {
            if (flag == false) {
                printf("< -------------- >\n");
                printf("| Таблица пустая |\n");
                printf("< -------------- >\n\n");
                system("pause");
            }
            else {
                printf("< -------------------- >\n");
                printf("| Введите номер строки |\n");
                printf("< -------------------- >\n\n");
                do {
                    printf("Ответ: ");
                    scanf("%d", &number);
                } while (number < 1 || number > x1);
                f(tabl, x1, x2, number);
                system("cls");
                printf("< ----------------- >\n");
                printf("| Задание выполнено |\n");
                printf("< ----------------- >\n\n");
                system("pause");
            }
        }
        else if (one == 5) {
            printf("< ----------------------- >\n");
            printf("| Завершение программы... |\n");
            printf("< ----------------------- >\n\n");
            for (int i = 0; i < MAX_X1; i++)
            {
                delete[] tabl[i];
            }
            delete[] tabl;
            return 0;
        }
    } while (rabota = true);
}