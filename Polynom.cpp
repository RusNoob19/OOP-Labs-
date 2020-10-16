#include "Polynom.h"
#include <iostream>


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

//����� ����������� ���������� �� �����
void Polynom::show()
{
	for (int i = degree; i > 0; i--)
	{
		//printf("%.1f*x^%d+", coefficients[i], i);
		//printf("%d", coefficients[0]);
	}
}

//��������� �������� ����������
double Polynom::compute(double x)
{
	double polynomValue = 0, singleTermValue = 1;
	for (int i = 0; i < degree + 1; i++)
	{
		polynomValue += singleTermValue * coefficients[i];

		singleTermValue *= x;
	}

	return polynomValue;
}
