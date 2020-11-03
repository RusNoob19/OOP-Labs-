#include <iostream>
#include "Polynom.h"


using namespace std;

int main()
{
	//подключение русского языка
	setlocale(LC_ALL, "RU");

	cout << "Создание многочлена" << endl;
	int count = 1;

	//добавление многочлена
	Polynom ** Objects = new Polynom*[count];
	Objects[count] = nullptr;

	while (true)         
	{
			Polynom obj;
			//создание необходимых коэффициентов
			int number = count;
			int command;
			double* coefficients = nullptr;


			// Создать новый многочлен (конструктор по умолчанию)
			delete Objects[number];
			Objects[number] = new Polynom;	
			int degree = 0; // Задание степени многочлена
			cout << "Конструктор по умолчанию : 0*x^0" << endl;


			cout << "Заполненный многочленн n-й степени : ";
			degree = 5; // Задание новой степени многочлена
			delete[] coefficients;
			coefficients = new double[degree + 1]; //заполнение многочлена
			for (int i = 0; i < degree + 1; i++)
				coefficients[i] = i;
			delete Objects[number];
			Objects[number] = new Polynom(degree, coefficients);
			//Посмотреть многочлен
			cout << obj.to_string(degree, coefficients) << endl;
			

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
			int index = 2;
			cout << "Коэффициент по индексу " << index << " : ";
			cout << Objects[number]->getCoefficient(index) << endl;


			//изменение степени многочлена без сохранения коэффициентов
			cout << "Старая степень многочлена : " << degree << endl;
			//Посмотреть многочлен
			cout << obj.to_string(degree, coefficients) << endl;
			degree = 7;
			cout << "Новая степень многочлена, без коэффициентах в новых степенях" << degree << ":" << endl;
			Objects[number]->setDegree(degree);
			//Посмотреть многочлен
			cout << obj.to_string(degree, coefficients) << endl;


			//задание коэффициентов нового многочлена
			cout << "Новые коэффициенты многочлена: " << endl;
			delete[] coefficients;
			coefficients = new double[Objects[number]->getDegree()];
			for (int i = 0; i < Objects[number]->getDegree() + 1; i++)
			coefficients[i] = degree + i;
			Objects[number]->setCoefficients(coefficients);
			//Посмотреть многочлен
			cout << obj.to_string(degree, coefficients) << endl;


			index = 7;
			double pipidon = 2.3;
			cout << "Коэффициент по идексу " << index << ":" << endl;
			Objects[number]->setCoefficient(coefficients, pipidon, index);
			//Посмотреть многочлен
			cout << obj.to_string(degree, coefficients) << endl;


			//нахождение значения многочлена при заданном x
			double x;
			x = 1.4;
			cout << "Значение многочлена при х = " << x << " = " << Objects[number]->compute(x, coefficients, degree) << endl;
	

			//копирование многочлена
			int number2 = 2;
			Objects[number2] = new Polynom(*Objects[number]);
			cout << "Перекопирование многочлена " << endl;
			cout << "Многочлен 1 : ";
			//Посмотреть многочлен
			cout << obj.to_string(degree, coefficients) << endl;


			cout << "Многочлен 2 : ";
			//Посмотреть многочлен
			cout << obj.to_string(degree, coefficients) << endl;
		break;
	}
	system("pause");
	return 0;
}