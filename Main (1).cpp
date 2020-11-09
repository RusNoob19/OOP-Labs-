#include <iostream>
#include "Polynom.h"
#include <stdio.h>

using namespace std;

int Polynom::stati = 4;//определяем статическую переменную члена
 
int main()
{
	//подключение русского языка
	setlocale(LC_ALL, "RU");

	Polynom first;
	Polynom second;
	Polynom obj;

	int count = 1;
	//добавление многочлена
	Polynom ** Objects = new Polynom*[count];
	Objects[count] = nullptr;

	int command, index = 6, degree = 0, number = count;
	double x = 2.5;
	double* coefficients = nullptr;
	int number2 = 2;

	Polynom primer1;
	primer1.setCreateCtandart(0, Objects, 1);                                         // Создать новый многочлен (конструктор по умолчанию) 
	primer1.setCreateObject(first, first.int_stati(), coefficients, 1, Objects, obj); // Создать новый многочлен
	primer1.setStep(Objects, 1);                                                 // Узнавание степени многочлена
	coefficients = primer1.setKoef(Objects, 1, coefficients);                         // Задавание коэффициентов
	primer1.setIndex(1, Objects, 1, degree);                                          // Определение коэффициента по индексу
	degree = primer1.setStepen(4, obj, coefficients, second,first, 1, Objects);       // Изменение степени многочлена без сохранения коэффициентов
	coefficients = primer1.setNewKaefCreate(coefficients, Objects, 1, degree, obj);   // Задание коэффициентов нового многочлена
	primer1.setKoefIndex(5, 2.5, Objects, degree, coefficients, 1, obj);              // Коэффициент по индексу
	primer1.setPoiskX(2.3, coefficients, degree, Objects, 1);                         // Нахождение значения многочлена при заданном x
	primer1.setCop(Objects, 1, obj, degree, coefficients, 2);                         // Копирование многочлена

	system("pause");
	return 0;
}