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


//������� - ������, ����������� ��� ��������� ����� ������

//�������� ������� ����������
void Polynom::setDegree(int degree, double* coefficients)
{
	this->degree = degree;

	delete[] coefficients;
	coefficients = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		coefficients[i] = 0;
}

//�������� ������������ ����������
void Polynom::setCoefficients(double* coefficients, int degree)
{
	for (int i = 0; i < degree + 1; i++)
		this->coefficients[i] = coefficients[i];
}

//�������� ����������� �� �������
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

//����� ����������� ���������� �� �����
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


// ����� // ����� // ����� // ����� // ����� // ����� // ����� // ����� // ����� // ����� // ����� // ����� // �����

// ������� ����� ��������� (����������� �� ���������)
void Polynom::setCreateCtandart(int degree, Polynom** Objects, int number)
{
	cout << "�������� ����������: ";
	delete Objects[number];
	Objects[number] = new Polynom;
	degree = 0; // ������� ������� ����������
	cout << "����������� �� ��������� : 0*x^0" << endl;
}

// ������� ����� ���������
Polynom * Polynom::setCreateObject(Polynom first, int degree, double* coefficients, int number, Polynom** Objects, Polynom obj)
{
		cout << "����������� ���������� n-� ������� : ";
		delete[] coefficients;
		coefficients = new double[degree + 1]; //���������� ����������
		for (int i = 0; i < degree + 1; i++)
			coefficients[i] = i;
		delete Objects[number];
		Objects[number] = new Polynom(degree,  coefficients);
		//���������� ���������
		cout << obj.to_string(degree, coefficients) << endl;
		return Objects[number];
}

// ��������� ������� ����������
void Polynom::setStep(Polynom** Objects, int number)
{
	cout << "n-� ������� ���������� = " << Objects[number]->getDegree() << endl;
}

// ��������� �������������
double* Polynom::setKoef(Polynom** Objects, int number, double* coefficients)
{
	delete[] coefficients;
	coefficients = Objects[number]->getCoefficients();
	cout << "������������ = ";
	for (int i = 0; i < Objects[number]->getDegree() + 1; i++)
		cout << coefficients[i] << " ";
	cout << endl;
	return coefficients;
}

// ����������� ������������ �� �������
void Polynom::setIndex(int index, Polynom** Objects, int number, int degree)
{
	cout << "����������� �� ������� " << index << " : ";
	int f = Objects[number]->getCoefficient(index, degree);
	if (f == 0 && index > degree)
	{
		cout << "� ������ ���������� ��� ������ ������������" << endl;
	}
	else
	{
		cout << f << endl;
	}
}

// ��������� ������� ���������� ��� ���������� �������������
int Polynom::setStepen(int degree, Polynom obj, double* coefficients, Polynom second, Polynom first, int number, Polynom** Objects)
{
	cout << "������ ������� ���������� : " << degree << endl;
	// ���������� ���������
	cout << obj.to_string(degree, coefficients) << endl;
	degree = second.int_stati();
	cout << "����� ������� ����������, ��� ���������� ������������� = " << degree << ":" << endl;
	Objects[number]->setDegree(degree, coefficients);
	// ���������� ���������
	cout << obj.to_string(degree, coefficients) << endl;
	return degree;
}

// ������� ������������� ������ ����������
double* Polynom::setNewKaefCreate(double* coefficients, Polynom** Objects, int number, int degree, Polynom obj)
{
	cout << "����� ������������ ����������: " << endl;
	delete[] coefficients;
	coefficients = new double[Objects[number]->getDegree()];
	for (int i = 0; i < Objects[number]->getDegree() + 1; i++)
		coefficients[i] = degree + i;
	Objects[number]->setCoefficients(coefficients, degree);
	//���������� ���������
	cout << obj.to_string(degree, coefficients) << endl;
	return coefficients;
}

// ����������� �� �������
void Polynom::setKoefIndex(int index, double x, Polynom** Objects, int degree, double* coefficients, int number, Polynom obj)
{
	cout << "����������� �� ������ " << index << ": " << endl;
	coefficients[index] = Objects[number]->setCoefficient(x, index, degree);
	if (coefficients[index] == 0 && index > degree)
	{
		cout << "� ������ ���������� ��� ������� ������������" << endl;
	}
	//���������� ���������
	cout << obj.to_string(degree, coefficients) << endl;
}

// ���������� �������� ���������� ��� �������� x
void Polynom::setPoiskX(double x, double* coefficients, int degree, Polynom** Objects, int number)
{
	x = 1.4;
	cout << "�������� ���������� ��� � = " << x << " = " << Objects[number]->compute(x, coefficients, degree) << endl;
}

// ����������� ����������
void Polynom::setCop(Polynom** Objects, int number, Polynom obj, int degree, double* coefficients, int number2)
{
	Objects[number2] = new Polynom(*Objects[number]);
	cout << "��������������� ���������� " << endl;
	cout << "��������� 1 : ";
	//���������� ���������
	cout << obj.to_string(degree, coefficients) << endl;
	cout << "��������� 2 : ";
	//���������� ���������
	cout << obj.to_string(degree, coefficients) << endl;
}