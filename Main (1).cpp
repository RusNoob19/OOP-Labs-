#include <iostream>
#include "Polynom.h"
#include <stdio.h>

using namespace std;

int Polynom::stati = 4;//���������� ����������� ���������� �����
 
int main()
{
	//����������� �������� �����
	setlocale(LC_ALL, "RU");

	Polynom first;
	Polynom second;
	Polynom obj;

	int count = 1;
	//���������� ����������
	Polynom ** Objects = new Polynom*[count];
	Objects[count] = nullptr;

	int command, index = 6, degree = 0, number = count;
	double x = 2.5;
	double* coefficients = nullptr;
	int number2 = 2;

	Polynom primer1;
	primer1.setCreateCtandart(0, Objects, 1);                                         // ������� ����� ��������� (����������� �� ���������) 
	primer1.setCreateObject(first, first.int_stati(), coefficients, 1, Objects, obj); // ������� ����� ���������
	primer1.setStep(Objects, 1);                                                 // ��������� ������� ����������
	coefficients = primer1.setKoef(Objects, 1, coefficients);                         // ��������� �������������
	primer1.setIndex(1, Objects, 1, degree);                                          // ����������� ������������ �� �������
	degree = primer1.setStepen(4, obj, coefficients, second,first, 1, Objects);       // ��������� ������� ���������� ��� ���������� �������������
	coefficients = primer1.setNewKaefCreate(coefficients, Objects, 1, degree, obj);   // ������� ������������� ������ ����������
	primer1.setKoefIndex(5, 2.5, Objects, degree, coefficients, 1, obj);              // ����������� �� �������
	primer1.setPoiskX(2.3, coefficients, degree, Objects, 1);                         // ���������� �������� ���������� ��� �������� x
	primer1.setCop(Objects, 1, obj, degree, coefficients, 2);                         // ����������� ����������

	system("pause");
	return 0;
}