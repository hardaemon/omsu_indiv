#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>

const double p1 = -2, p2 = 2, x1 = -2.4, x2 = 2.4, h = 0.03;
const int str = 15, col = 4, xv = 8, xp = 2, yv = 8, yp = 2;
const double pi = 3.14159; //число пи
const int len_arg = 8; //длина строки arg
const int len_fun = 7;
const int len_naz1 = 24;

int main()
{
    setlocale(LC_ALL, "Russian"); //добавляем поддержку киллирицы

    double p, x, y;
    int i, j, page = 1;
    int ost_arg = xv + 2 - len_arg; //сколько не хватает символов для ровной таблицы (+2 т.к. есть еще 2 пробела)
    int ost_fun = yv + 2 - len_fun;
    int ost_naz1 = (xv + yv + 6) * col + 1 - len_naz1;
    x = x1;

    if (len_arg > xv + 2) //если "Аргумент" не помещается в таблицу
    {
        printf("Произошла ошибка!\nНазвание столбца не помещается в таблицу.\nУвеличьте значение xv.");
        return 0;
    }

    if (len_fun > yv + 2) //если "Функция" не помещается в таблицу
    {
        printf("Произошла ошибка!\nНазвание столбца не помещается в таблицу.\nУвеличьте значение yv.");
        return 0;
    }

    printf("Введите число p [%.1lf;%.1lf]: ", p1, p2);
    scanf("%lf", &p);

    while (p < p1 || p > p2) //проверка на соблюдения условия
    {
        printf("Число p должно быть числом и находиться в промежутке [%.1lf;%.1lf].\n", p1, p2);
        printf("Повторный ввод числа p: ");
        scanf("%lf", &p);
    }

    while (x <= x2 + 0.5 * h)
    {
        system("cls"); //очистка экрана

        printf("Страница %d.\n", page);


        if (xv + yv < 18 && col == 1) //если таблица меньше текста в print
        {
            printf("Таблица значений функции\n");
            printf("При параметре   %lf", p);
        }
        else
        {
            if (ost_naz1 % 2 == 1) //если не хватает нечетное кол-во
            {
                int ost_naz_1 = (ost_naz1 + 1) / 2; //берем половину в начало (+1, т.к. нечетное)
                for (i = 1; i <= ost_naz_1; i++)
                {
                    printf(" ");
                }
            }
            else //если не хватает четное кол-во
            {
                int ost_naz_1 = ost_naz1 / 2;
                for (i = 1; i <= ost_naz_1; i++)
                {
                    printf(" ");
                }
            }

            printf("Таблица значений функции");

            if (ost_naz1 % 2 == 1)
            {
                int ost_naz_1 = (ost_naz1 - 1) / 2; //берем половину в конец (-1, т.к. нечетное и один символ лишний)
                for (i = 1; i <= ost_naz_1; i++)
                {
                    printf(" ");
                }
            }
            else
            {
                int ost_naz_1 = ost_naz1 / 2;
                for (i = 1; i <= ost_naz_1; i++)
                {
                    printf(" ");
                }
            }
            printf("\n");

            if (ost_naz1 % 2 == 1) //если не хватает нечетное кол-во
            {
                int ost_naz_1 = (ost_naz1 + 1) / 2; //берем половину в начало (+1, т.к. нечетное)
                for (i = 1; i <= ost_naz_1; i++)
                {
                    printf(" ");
                }
            }
            else //если не хватает четное кол-во
            {
                int ost_naz_1 = ost_naz1 / 2;
                for (i = 1; i <= ost_naz_1; i++)
                {
                    printf(" ");
                }
            }

            printf("При параметре   %lf", p);

            if (ost_naz1 % 2 == 1)
            {
                int ost_naz_1 = (ost_naz1 - 1) / 2; //берем половину в конец (-1, т.к. нечетное и один символ лишний)
                for (i = 1; i <= ost_naz_1; i++)
                {
                    printf(" ");
                }
            }
            else
            {
                int ost_naz_1 = ost_naz1 / 2;
                for (i = 1; i <= ost_naz_1; i++)
                {
                    printf(" ");
                }
            }
            printf("\n\n");
        }

        for (int z = 0; z < col; z++) //сделать col раз
        {
            printf("!");
            for (i = 0; i < xv + 2; i++)
            {
                printf("-");
            }
            printf("!");

            for (i = 0; i < yv + 2; i++)
            {
                printf("-");
            }
        }
        printf("!\n");

        for (int z = 0; z < col; z++) //сделать col раз
        {
            printf("!");
            if (len_arg < xv + 2) //если символов не хватает (для "Аргумент")
            {
                if (ost_arg % 2 == 1) //если не хватает нечетное кол-во
                {
                    int ost_arg_1 = (ost_arg + 1) / 2; //берем половину в начало (+1, т.к. нечетное)
                    for (i = 1; i <= ost_arg_1; i++)
                    {
                        printf(" ");
                    }
                }
                else //если не хватает четное кол-во
                {
                    int ost_arg_1 = ost_arg / 2;
                    for (i = 1; i <= ost_arg_1; i++)
                    {
                        printf(" ");
                    }
                }
            }

            printf("Аргумент");

            if (len_arg < xv + 2) //если не хватало больше одного символа
            {
                if (ost_arg % 2 == 1)
                {
                    int ost_arg_1 = (ost_arg - 1) / 2; //берем половину в конец (-1, т.к. нечетное и один символ лишний)
                    for (i = 1; i <= ost_arg_1; i++)
                    {
                        printf(" ");
                    }
                }
                else
                {
                    int ost_arg_1 = ost_arg / 2;
                    for (i = 1; i <= ost_arg_1; i++)
                    {
                        printf(" ");
                    }
                }
            }
            printf("!");

            if (len_fun < yv + 2) //если символов не хватает (для "Функция")
            {
                if (ost_fun % 2 == 1) //если не хватает нечетное кол-во
                {
                    int ost_fun_1 = (ost_fun + 1) / 2; //берем половину в начало (+1, т.к. нечетное)
                    for (i = 1; i <= ost_fun_1; i++)
                    {
                        printf(" ");
                    }
                }
                else //если не хватает четное кол-во
                {
                    int ost_fun_1 = ost_fun / 2;
                    for (i = 1; i <= ost_fun_1; i++)
                    {
                        printf(" ");
                    }
                }
            }

            printf("Функция");

            if (len_fun < yv + 2) //если не хватало больше одного символа
            {
                if (ost_fun % 2 == 1)
                {
                    int ost_fun_1 = (ost_fun - 1) / 2; //берем половину в конец (-1, т.к. нечетное и один символ лишний)
                    for (i = 1; i <= ost_fun_1; i++)
                    {
                        printf(" ");
                    }
                }
                else
                {
                    int ost_fun_1 = ost_fun / 2;
                    for (i = 1; i <= ost_fun_1; i++)
                    {
                        printf(" ");
                    }
                }
            }
        }
        printf("!\n");

        for (int z = 0; z < col; z++) //сделать col раз
        {
            printf("!");
            for (i = 0; i < xv + 2; i++)
            {
                printf("-");
            }
            printf("!");

            for (i = 0; i < yv + 2; i++)
            {
                printf("-");
            }
        }
        printf("!\n");

        for (i = 1; (i <= str) && (x <= x2 + 0.5 * h); i++)
        {
            for (j = 1; (j <= col) && (x <= x2 + 0.5 * h); j++)
            {
                if (pow(x, 9) <= exp(p))
                {
                    y = log(1 + abs(p * x));
                }
                else
                {
                    y = (pi - (atan(p * x)) * 2) / (sqrt(x));
                }

                printf("! %*.*lf ! %*.*lf ", xv, xp, x, yv, yp, y);

                x = x + h;
            }
            printf("!\n");

            for (int z = 0; z < col; z++) //сделать col раз
            {
                printf("!");
                for (int w = 0; w < xv + 2; w++)
                {
                    printf("-");
                }
                printf("!");

                for (int w = 0; w < yv + 2; w++)
                {
                    printf("-");
                }
            }
            printf("!\n");

        }

        system("pause"); //пауза (для продолжения...)
        page++;
    }
    return 0;
}
