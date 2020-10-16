
//������� ������������� - ����� ��� ����, 
//����� ���� �� ������������ (�� ������� ��� ����)
#pragma once 

//����� ����������
class Polynom
{
	//����������� ������
	static int stati;

public:

	//����������� ������
	static void int_stati() { stati++; }

	//����������� �� ���������
	Polynom();

	//����������� � �����������
	Polynom(int degree, double* coefficients);

	//����������� �����������
	Polynom(const Polynom& polynom);

	//����������
	~Polynom();



	//������� - ����� ��� ��������� ����� ������

	//��������� ������� ����������
	int getDegree();

	//��������� ������������� ����������
	double* getCoefficients();

	//��������� ������������ ���������� ��� ������� index
	double getCoefficient(int index);



	//������� - ����� ��� ��������� ����� ������
	
	//��������� ������� ����������
	void setDegree(int degree);

	//��������� ���� ������������� ����������
	void setCoefficients(double* coefficients);

	//����� �� �������
	void show();

	//��������� �������� ����������
	double compute(double x);

private:

	//������������ ����������� �� ������� ������� � �������
	//�.�. ��� coefficients[0] ���������� ����������� ��� �^0

	//������� ����������
	int degree;

	//������������ ��� �������� ����������
	double* coefficients;

	char string[100];
};

