#include <iostream>
#include <fstream>
using namespace std;

short qwerty(ifstream&, double&);
int main()
{
	setlocale(LC_ALL, "rus");
	ifstream file;
	double otv;
	short rez = qwerty(file, otv);
	if (rez == 0)
	{
		cout << "Ответ: " << otv << endl;
		return 0;
	}
	else return -1;
}
/*Программа для решения задачи: Дана последовательность вещественных
чисел, заданная в файле. Методом индуктивной функции вычислить
среднюю длину связных строго возрастающих подпоследовательностей.
Одиночное число не считаем возрастающей.

Входные данные:
ifstream &file - класс для чтения файла, переданного по ссылке

Выходные данные:
double &otv - средняя длина св. стр. возр. подпослед.

Функция возвращает 0 при успешном завершении, -1 при ошибке*/

short qwerty(ifstream &file, double &otv)
{
	double a, a2;
	unsigned short lenall = 1, len = 0, count = 0;
	string name;
	cout << "Введите путь или название файла с расширением: ";
	cin >> name;
	cout << endl;
	file.open(name);
	if (!file)
	{
		cout << "ERROR: Не удалось открыть файл" << endl;
		file.close();
		return -1;
	}
	if (file.eof())
	{
		cout << "ERROR: Файл пустой" << endl;
		file.close();
		return -1;
	}
	file >> a;
	for (file >> a2; !file.eof(); file >> a2)
	{
		if (file.fail() && !file.eof())
		{
			cout << "ERROR: Ошибка при чтении файла" << endl;
			file.close();
			return -1;
		}
		if (a2 > a) lenall++;
		else if (lenall > 1)
		{
			len += lenall;
			lenall = 1;
			count++;
		}
		a = a2;
	}
	file >> a2;
	if (a2 > a)
	{
		lenall++;
		len += lenall;
		count++;
	}
	else if (lenall > 1)
	{
		len += lenall;
		count++;
	}
	if (count == 0)
	{
		cout << "ERROR: Нет связных строго возрастающих подпоследовательностей" << endl;
		file.close();
		return -1;
	}
	otv = len / double(count);
	file.close();
	return 0;
}