#include <iostream>
#include "Polynom.h"


using namespace std;

int main()
{
	//����������� �������� �����
	setlocale(LC_ALL, "RU");

	cout << "�������� ����������" << endl;
	int count = 1;

	//���������� ����������
	Polynom ** Objects = new Polynom*[count];
	Objects[count] = nullptr;

	while (true)         
	{
			Polynom obj;
			//�������� ����������� �������������
			int number = count;
			int command;
			double* coefficients = nullptr;


			// ������� ����� ��������� (����������� �� ���������)
			delete Objects[number];
			Objects[number] = new Polynom;	
			int degree = 0; // ������� ������� ����������
			cout << "����������� �� ��������� : 0*x^0" << endl;


			cout << "����������� ���������� n-� ������� : ";
			degree = 5; // ������� ����� ������� ����������
			delete[] coefficients;
			coefficients = new double[degree + 1]; //���������� ����������
			for (int i = 0; i < degree + 1; i++)
				coefficients[i] = i;
			delete Objects[number];
			Objects[number] = new Polynom(degree, coefficients);
			//���������� ���������
			cout << obj.to_string(degree, coefficients) << endl;
			

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
			int index = 2;
			cout << "����������� �� ������� " << index << " : ";
			cout << Objects[number]->getCoefficient(index) << endl;


			//��������� ������� ���������� ��� ���������� �������������
			cout << "������ ������� ���������� : " << degree << endl;
			//���������� ���������
			cout << obj.to_string(degree, coefficients) << endl;
			degree = 7;
			cout << "����� ������� ����������, ��� ������������� � ����� ��������" << degree << ":" << endl;
			Objects[number]->setDegree(degree);
			//���������� ���������
			cout << obj.to_string(degree, coefficients) << endl;


			//������� ������������� ������ ����������
			cout << "����� ������������ ����������: " << endl;
			delete[] coefficients;
			coefficients = new double[Objects[number]->getDegree()];
			for (int i = 0; i < Objects[number]->getDegree() + 1; i++)
			coefficients[i] = degree + i;
			Objects[number]->setCoefficients(coefficients);
			//���������� ���������
			cout << obj.to_string(degree, coefficients) << endl;


			index = 7;
			double pipidon = 2.3;
			cout << "����������� �� ������ " << index << ":" << endl;
			Objects[number]->setCoefficient(coefficients, pipidon, index);
			//���������� ���������
			cout << obj.to_string(degree, coefficients) << endl;


			//���������� �������� ���������� ��� �������� x
			double x;
			x = 1.4;
			cout << "�������� ���������� ��� � = " << x << " = " << Objects[number]->compute(x, coefficients, degree) << endl;
	

			//����������� ����������
			int number2 = 2;
			Objects[number2] = new Polynom(*Objects[number]);
			cout << "��������������� ���������� " << endl;
			cout << "��������� 1 : ";
			//���������� ���������
			cout << obj.to_string(degree, coefficients) << endl;


			cout << "��������� 2 : ";
			//���������� ���������
			cout << obj.to_string(degree, coefficients) << endl;
		break;
	}
	system("pause");
	return 0;
}