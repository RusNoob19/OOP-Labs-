
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

	//����� �� �������
	char* to_string(int degree, double* coefficients);

	//��������� ������� ����������
	void setDegree(int degree);

	//��������� ���� ������������� ����������
	void setCoefficients(double* coefficients);

	//��������� �������� ����������
	double compute(double x, double* coefficients, int degree);

	//��������� ������������ �� �������
	void setCoefficient(double* coefficients, double coefficient, int index);

private:

	//������������ ����������� �� ������� ������� � �������
	//�.�. ��� coefficients[0] ���������� ����������� ��� �^0

	//������� ����������
	int degree;

	//������������ ��� �������� ����������
	double* coefficients;

	//������ ������
	char str[100];
};

