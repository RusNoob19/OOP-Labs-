
//команда препроцессора - нужна для того, 
//чтобы файл не зацикливался (не включал сам себя)
#pragma once 

//класс многочлена
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


	//статические методы

	int int_stati() const { return stati++; }

	//конструктор по умолчанию
	Polynom();

	//конструктор с параметрами
	Polynom(int degree, double* coefficients);

	//конструктор копирования
	Polynom(const Polynom& polynom);

	//деструктор
	~Polynom();


	//геттеры - нужны для получения полей класса

	//получение степени многочлена
	int getDegree();

	//получение коэффициентов многочлена
	double* getCoefficients();

	//получение коэффициента многочлена под номером index
	double getCoefficient(int index, int degree);


	//сеттеры - нужны для установки полей класса

	//вывод на консоль
	char* to_string(int degree, double* coefficients);

	//изменение степени многочлена
	void setDegree(int degree, double* coefficients);

	//изменение всех коэффициентов многочлена
	void setCoefficients(double* coefficients, int degree);
	
	//вычислить значение многочлена
	double compute(double x, double* coefficients, int degree);

	//изменение коэффициента по индексу
	double setCoefficient (double coefficient, int index, int degree);

private:
	//коэффициенты расположены от меньшей степени к большей
	//т.е. под coefficients[0] расположен коэффициент при х^0

	//статические методы
	static int stati;

	//степень многочлена
	int degree;

	//"выходная строка"
	char str[100];

	//коэффициенты при степенях многочлена
	double* coefficients;
};

