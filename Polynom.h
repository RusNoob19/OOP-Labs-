
//������� ������������� - ����� ��� ����, 
//����� ���� �� ������������ (�� ������� ��� ����)
#pragma once 

//����� ����������
class Polynom
{
public:

	void setCreateCtandart(int degree, Polynom** Objects, int number);
	Polynom * setCreateObject(Polynom first, int degree, double* coefficients, int number, Polynom** Objects, Polynom obj);
	void setStep(Polynom** Objects, int number);
	double* setKoef(Polynom** Objects, int number, double* coefficients);
	void setIndex(int index, Polynom** Objects, int number, int degree);
	int setStepen(int degree, Polynom obj, double* coefficients, Polynom second, Polynom first, int number, Polynom** Objects);
	double* setNewKaefCreate(double* coefficients, Polynom** Objects, int number, int degree, Polynom obj);
	void setKoefIndex(int index, double x, Polynom** Objects, int degree, double* coefficients, int number, Polynom obj);
	void setPoiskX(double x, double* coefficients, int degree, Polynom** Objects, int number);
	void setCop(Polynom** Objects, int number, Polynom obj, int degree, double* coefficients, int number2);


	//����������� ������

	int int_stati() const { return stati++; }

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
	double getCoefficient(int index, int degree);


	//������� - ����� ��� ��������� ����� ������

	//����� �� �������
	char* to_string(int degree, double* coefficients);

	//��������� ������� ����������
	void setDegree(int degree, double* coefficients);

	//��������� ���� ������������� ����������
	void setCoefficients(double* coefficients, int degree);
	
	//��������� �������� ����������
	double compute(double x, double* coefficients, int degree);

	//��������� ������������ �� �������
	double setCoefficient (double coefficient, int index, int degree);

private:
	//������������ ����������� �� ������� ������� � �������
	//�.�. ��� coefficients[0] ���������� ����������� ��� �^0

	//����������� ������
	static int stati;

	//������� ����������
	int degree;

	//"�������� ������"
	char str[100];

	//������������ ��� �������� ����������
	double* coefficients;
};

