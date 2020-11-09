#include "Polynom.h"
#include <iostream>
#include <stdio.h>
using namespace std;

//конструкто по умолчанию
Polynom::Polynom()
{
	//инициализируем многочлен нулевой степенью
	degree = 0;
	
	//и помещаем в него только один элемент - самый первый и равный нулю
	coefficients = new double[degree + 1];
	coefficients[0] = 0;
}

//конструктор с параметрами
Polynom::Polynom(int degree, double* coefficients)
{

	//сохраняем степень из аргумента
	this->degree = degree;

	//копируем все коэффициенты из входного массива в наш объект
	this->coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		this->coefficients[i] = coefficients[i];
}

//конструктор копирования
Polynom::Polynom(const Polynom& polynom)
{

	//копируем степень полинома
	this->degree = polynom.degree;

	//копируем все коэффициенты из входного объекта в наш объект
	this->coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		this->coefficients[i] = polynom.coefficients[i];
	
}

//деструктор
Polynom::~Polynom() 
{
	delete[] coefficients;
}


//геттеры - нужны для получения полей класса

//получение степени многочлена
int Polynom::getDegree()
{
	return degree;
}

//получение массива коэффициентов
double* Polynom::getCoefficients()
{
	//копируем содержимое массива коэффициентов 
	double* coefficientsCopy = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficientsCopy[i] = coefficients[i];

	//возвращаем копию
	return coefficientsCopy;
}

//получение коэффициента под номером index
double Polynom::getCoefficient(int index, int degree)
{
	if (degree >= index && index >= 0)
	{
		return coefficients[index];
	}
	else
	{
		return 0;
	}
}


//сеттеры - методы, необходимые для установки полей класса

//изменить степень многочлена
void Polynom::setDegree(int degree, double* coefficients)
{
	this->degree = degree;

	delete[] coefficients;
	coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = 0;
}

//изменить коэффициенты многочлена
void Polynom::setCoefficients(double* coefficients, int degree)
{
	for (int i = 0; i < degree + 1; i++)
		this->coefficients[i] = coefficients[i];
}

//изменить коэффециент по индексу
double Polynom::setCoefficient(double coefficient, int index, int degree)
{
	if (index <= degree && index >= 0)
	{
	return coefficients[index] = coefficient;
	}
	else
	{
		return 0;
	}
}

//вывод содержимого многочлена на экран
char* Polynom::to_string(int degree, double* coefficients)
{
	char str[1000] = " ";
	int j = 0;
	for (int i = degree; i > 0; i-- )
	{
		j += sprintf_s(str + j, 1000 - j, "%.01f*x^%d+", coefficients[i], i);
	}
	sprintf_s(str + j, 1000 - j, "%.01f*x^0", coefficients[0]);
	return str;
}

//вычислить значение многочлена
double Polynom::compute(double x, double* coefficients, int degree)
{
	double polynomValue = 0, singleTermValue = 1;
	for (int i = 0; i < degree + 1; i++)
	{
		polynomValue += singleTermValue * coefficients[i];

		singleTermValue *= x;
	}

	return polynomValue;
}


// Тесты // Тесты // Тесты // Тесты // Тесты // Тесты // Тесты // Тесты // Тесты // Тесты // Тесты // Тесты // Тесты

// Создать новый многочлен (конструктор по умолчанию)
void Polynom::setCreateCtandart(int degree, Polynom** Objects, int number)
{
	cout << "Создание многочлена: ";
	delete Objects[number];
	Objects[number] = new Polynom;
	degree = 0; // Задание степени многочлена
	cout << "Конструктор по умолчанию : 0*x^0" << endl;
}

// Создать новый многочлен
Polynom * Polynom::setCreateObject(Polynom first, int degree, double* coefficients, int number, Polynom** Objects, Polynom obj)
{
		cout << "Заполненный многочленн n-й степени : ";
		delete[] coefficients;
		coefficients = new double[degree + 1]; //заполнение многочлена
		for (int i = 0; i < degree + 1; i++)
			coefficients[i] = i;
		delete Objects[number];
		Objects[number] = new Polynom(degree,  coefficients);
		//Посмотреть многочлен
		cout << obj.to_string(degree, coefficients) << endl;
		return Objects[number];
}

// Узнавание степени многочлена
void Polynom::setStep(Polynom** Objects, int number)
{
	cout << "n-я степень многочлена = " << Objects[number]->getDegree() << endl;
}

// Задавание коэффициентов
double* Polynom::setKoef(Polynom** Objects, int number, double* coefficients)
{
	delete[] coefficients;
	coefficients = Objects[number]->getCoefficients();
	cout << "Коэффициенты = ";
	for (int i = 0; i < Objects[number]->getDegree() + 1; i++)
		cout << coefficients[i] << " ";
	cout << endl;
	return coefficients;
}

// Определение коэффициента по индексу
void Polynom::setIndex(int index, Polynom** Objects, int number, int degree)
{
	cout << "Коэффициент по индексу " << index << " : ";
	int f = Objects[number]->getCoefficient(index, degree);
	if (f == 0 && index > degree)
	{
		cout << "В данном многочлене нет такого коэффициента" << endl;
	}
	else
	{
		cout << f << endl;
	}
}

// Изменение степени многочлена без сохранения коэффициентов
int Polynom::setStepen(int degree, Polynom obj, double* coefficients, Polynom second, Polynom first, int number, Polynom** Objects)
{
	cout << "Старая степень многочлена : " << degree << endl;
	// Посмотреть многочлен
	cout << obj.to_string(degree, coefficients) << endl;
	degree = second.int_stati();
	cout << "Новая степень многочлена, без сохранения коэффициентов = " << degree << ":" << endl;
	Objects[number]->setDegree(degree, coefficients);
	// Посмотреть многочлен
	cout << obj.to_string(degree, coefficients) << endl;
	return degree;
}

// Задание коэффициентов нового многочлена
double* Polynom::setNewKaefCreate(double* coefficients, Polynom** Objects, int number, int degree, Polynom obj)
{
	cout << "Новые коэффициенты многочлена: " << endl;
	delete[] coefficients;
	coefficients = new double[Objects[number]->getDegree()];
	for (int i = 0; i < Objects[number]->getDegree() + 1; i++)
		coefficients[i] = degree + i;
	Objects[number]->setCoefficients(coefficients, degree);
	//Посмотреть многочлен
	cout << obj.to_string(degree, coefficients) << endl;
	return coefficients;
}

// Коэффициент по индексу
void Polynom::setKoefIndex(int index, double x, Polynom** Objects, int degree, double* coefficients, int number, Polynom obj)
{
	cout << "Коэффициент по идексу " << index << ": " << endl;
	coefficients[index] = Objects[number]->setCoefficient(x, index, degree);
	if (coefficients[index] == 0 && index > degree)
	{
		cout << "В данном многочлене нет данного коэффициента" << endl;
	}
	//Посмотреть многочлен
	cout << obj.to_string(degree, coefficients) << endl;
}

// Нахождение значения многочлена при заданном x
void Polynom::setPoiskX(double x, double* coefficients, int degree, Polynom** Objects, int number)
{
	x = 1.4;
	cout << "Значение многочлена при х = " << x << " = " << Objects[number]->compute(x, coefficients, degree) << endl;
}

// Копирование многочлена
void Polynom::setCop(Polynom** Objects, int number, Polynom obj, int degree, double* coefficients, int number2)
{
	Objects[number2] = new Polynom(*Objects[number]);
	cout << "Перекопирование многочлена " << endl;
	cout << "Многочлен 1 : ";
	//Посмотреть многочлен
	cout << obj.to_string(degree, coefficients) << endl;
	cout << "Многочлен 2 : ";
	//Посмотреть многочлен
	cout << obj.to_string(degree, coefficients) << endl;
}