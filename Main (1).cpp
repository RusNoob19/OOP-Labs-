#include <iostream>
#include "Polynom.h"
#include <string>
using namespace std;

//����� ��������
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
	//����������� �������� �����
	setlocale(LC_ALL, "RU");

	cout << "�������� ����������" << endl;
	int count = 1;

	//���������� ����������
	Polynom ** Objects = new Polynom*[count];
	for (int i = 1; i <= count; i++)
		Objects[i] = nullptr;

	while (true)         
	{
		//�������� ����������� �������������
		int number = count;
		int command;
		double* coefficients = nullptr;

			// ������� ����� ��������� (����������� �� ���������)
			delete Objects[number];
			Objects[number] = new Polynom;
			cout << "����������� �� ��������� = ";
			string funk_naz = "0*x^0";
			cout << funk_naz << endl;

			cout << "����������� ���������� n-� ������� : ";
			int degree = 5; // ������� ������� ����������
			delete[] coefficients;
			coefficients = new double[degree + 1]; //���������� ����������
			for (int i = 0; i < degree + 1; i++)
			coefficients[i] = i;
			delete Objects[number];
			Objects[number] = new Polynom(degree, coefficients);
			//���������� ���������
			cout << func(coefficients, degree, str) << endl;

			//��������� ������� ����������
			cout << "n-� ������� ���������� = " << Objects[number]->getDegree() << endl;

			//������� �������������
			delete[] coefficients;
			coefficients = Objects[number]->getCoefficients();
			cout << "������������ = ";
			for (int i = 0; i < Objects[number]->getDegree() + 1; i++)
				cout << coefficients[i] << " ";
			cout << endl;
		

			//����������� ������������ �� �������
			int index = 1;
			cout << "����������� �� ������� " << index << " : ";
			cout << Objects[number]->getCoefficient(index) << endl;


			//��������� ������� ���������� ��� ���������� �������������
			cout << "������ ������� ���������� : " << degree << endl;
			//���������� ���������
			cout << func(coefficients, degree, str) << endl;


			degree = 7;
			cout << "����� ������� ����������, ��� ���������� ������������ = " << degree << endl;
			Objects[number]->setDegree(degree);
			//���������� ���������
			cout << func(coefficients, degree, str) << endl;


			//������� ������������� ������ ����������
			cout << "����� ������������ ���������� = " << endl;
			delete[] coefficients;
			coefficients = new double[Objects[number]->getDegree()];
			for (int i = 0; i < Objects[number]->getDegree() + 1; i++)
				coefficients[i] = i + 1;
			Objects[number]->setCoefficients(coefficients);
			//���������� ���������
			cout << func(coefficients, degree, str) << endl;


			//���������� �������� ���������� ��� �������� x
			double x;
			x = 1.7;
			cout << "�������� ���������� ��� � = " << x << " = " << Objects[number]->compute(x) << endl;
	

			//����������� ����������
			int number2 = 2;
			Objects[number2] = new Polynom(*Objects[number]);
			cout << "��������������� ���������� " << endl;
			cout << "��������� 1 : ";
			//���������� ���������
			cout << func(coefficients, degree, str) << endl;;

			cout << "��������� 2 : ";
			//���������� ���������
			cout << func(coefficients, degree, str) << endl;;

		break;
	}
	system("pause");
	return 0;
}