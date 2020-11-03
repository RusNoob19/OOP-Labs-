#include "Polynom.h"
#include <iostream>
#include <stdio.h>
using namespace std;

//���������� �� ���������
Polynom::Polynom()
{
	//�������������� ��������� ������� ��������
	degree = 0;
	
	//� �������� � ���� ������ ���� ������� - ����� ������ � ������ ����
	coefficients = new double[degree + 1];
	coefficients[0] = 0;
}

//����������� � �����������
Polynom::Polynom(int degree, double* coefficients)
{

	//��������� ������� �� ���������
	this->degree = degree;

	//�������� ��� ������������ �� �������� ������� � ��� ������
	this->coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		this->coefficients[i] = coefficients[i];
}

//����������� �����������
Polynom::Polynom(const Polynom& polynom)
{

	//�������� ������� ��������
	this->degree = polynom.degree;

	//�������� ��� ������������ �� �������� ������� � ��� ������
	this->coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		this->coefficients[i] = polynom.coefficients[i];
	
}

//����������
Polynom::~Polynom()
{
	delete[] coefficients;
}



//������� - ����� ��� ��������� ����� ������

//��������� ������� ����������
int Polynom::getDegree()
{
	return degree;
}

//��������� ������� �������������
double* Polynom::getCoefficients()
{
	//�������� ���������� ������� ������������� 
	double* coefficientsCopy = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficientsCopy[i] = coefficients[i];

	//���������� �����
	return coefficientsCopy;
}

//��������� ������������ ��� ������� index
double Polynom::getCoefficient(int index)
{
	return coefficients[index];
}



//������� - ������, ����������� ��� ��������� ����� ������

//�������� ������� ����������
void Polynom::setDegree(int degree)
{
	this->degree = degree;

	delete[] coefficients;
	coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = 0;
}

//�������� ������������ ����������
void Polynom::setCoefficients(double* coefficients)
{
	for (int i = 0; i < degree + 1; i++)
		this->coefficients[i] = coefficients[i];
}

//�������� ����������� �� �������
void Polynom::setCoefficient(double* coefficients, double coefficient, int index)
{
	coefficients[index] = coefficient;
}

//����� ����������� ���������� �� �����
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

//��������� �������� ����������
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
