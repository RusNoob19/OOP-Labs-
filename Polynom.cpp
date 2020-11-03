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
double Polynom::getCoefficient(int index)
{
	return coefficients[index];
}



//сеттеры - методы, необходимые для установки полей класса

//изменить степень многочлена
void Polynom::setDegree(int degree)
{
	this->degree = degree;

	delete[] coefficients;
	coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = 0;
}

//изменить коэффициенты многочлена
void Polynom::setCoefficients(double* coefficients)
{
	for (int i = 0; i < degree + 1; i++)
		this->coefficients[i] = coefficients[i];
}

//изменить коэффециент по индексу
void Polynom::setCoefficient(double* coefficients, double coefficient, int index)
{
	coefficients[index] = coefficient;
}

//вывод содержимого многочлена на экран
char* Polynom::to_string(int degree, double* coefficients)
{
	char str[10000] = "";
	int j = 0;
	for (int i = degree; i > 0; i--)
	{
		j += sprintf_s(str + j, 10000 - j, "%.01f*x^%d+", coefficients[i],i);
	}
	sprintf_s(str + j, 10000 - j, "%.01f*x^0", coefficients[0]);
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
