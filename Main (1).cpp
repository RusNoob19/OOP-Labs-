#include <iostream>
#include "Polynom.h"
#include <string>
using namespace std;

//вывод полинома
string func(double coefficients[10], int degree, string str)
{
	while (true)
	{
		for (int i = degree; i > 0; i--)
		{
			double x_double = coefficients[i];
			string str1 = std::to_string(x_double);
			string str2 = "*x^";
			string str3 = std::to_string(i);
			string str4 = "+";
			str = str + str1 + str2 + str3 + str4;
		}
		double x_double = coefficients[0];
		string str5 = std::to_string(x_double);
		str = str + str5;
		break;
	}
	return str;
}

int main()
{
	string str;
	//подключение русского языка
	setlocale(LC_ALL, "RU");

	cout << "Создание многочлена" << endl;
	int count = 1;

	//добавление многочлена
	Polynom ** Objects = new Polynom*[count];
	for (int i = 1; i <= count; i++)
		Objects[i] = nullptr;

	while (true)         
	{
		//создание необходимых коэффициентов
		int number = count;
		int command;
		double* coefficients = nullptr;

			// Создать новый многочлен (конструктор по умолчанию)
			delete Objects[number];
			Objects[number] = new Polynom;
			cout << "Конструктор по умолчанию = ";
			string funk_naz = "0*x^0";
			cout << funk_naz << endl;

			cout << "Заполненный многочленн n-й степени : ";
			int degree = 5; // Задание степени многочлена
			delete[] coefficients;
			coefficients = new double[degree + 1]; //заполнение многочлена
			for (int i = 0; i < degree + 1; i++)
			coefficients[i] = i;
			delete Objects[number];
			Objects[number] = new Polynom(degree, coefficients);
			//Посмотреть многочлен
			cout << func(coefficients, degree, str) << endl;

			//Узнавание степени многочлена
			cout << "n-я степень многочлена = " << Objects[number]->getDegree() << endl;

			//задание коэффициентов
			delete[] coefficients;
			coefficients = Objects[number]->getCoefficients();
			cout << "Коэффициенты = ";
			for (int i = 0; i < Objects[number]->getDegree() + 1; i++)
				cout << coefficients[i] << " ";
			cout << endl;
		

			//определение коэффициента по индексу
			int index = 1;
			cout << "Коэффициент по индексу " << index << " : ";
			cout << Objects[number]->getCoefficient(index) << endl;


			//изменение степени многочлена без сохранения коэффициентов
			cout << "Старая степень многочлена : " << degree << endl;
			//Посмотреть многочлен
			cout << func(coefficients, degree, str) << endl;


			degree = 7;
			cout << "Новая степень многочлена, без сохранения коэффициента = " << degree << endl;
			Objects[number]->setDegree(degree);
			//Посмотреть многочлен
			cout << func(coefficients, degree, str) << endl;


			//задание коэффициентов нового многочлена
			cout << "Новые коэффициенты многочлена = " << endl;
			delete[] coefficients;
			coefficients = new double[Objects[number]->getDegree()];
			for (int i = 0; i < Objects[number]->getDegree() + 1; i++)
				coefficients[i] = i + 1;
			Objects[number]->setCoefficients(coefficients);
			//Посмотреть многочлен
			cout << func(coefficients, degree, str) << endl;


			//нахождение значения многочлена при заданном x
			double x;
			x = 1.7;
			cout << "Значение многочлена при х = " << x << " = " << Objects[number]->compute(x) << endl;
	

			//копирование многочлена
			int number2 = 2;
			Objects[number2] = new Polynom(*Objects[number]);
			cout << "Перекопирование многочлена " << endl;
			cout << "Многочлен 1 : ";
			//Посмотреть многочлен
			cout << func(coefficients, degree, str) << endl;;

			cout << "Многочлен 2 : ";
			//Посмотреть многочлен
			cout << func(coefficients, degree, str) << endl;;

		break;
	}
	system("pause");
	return 0;
}