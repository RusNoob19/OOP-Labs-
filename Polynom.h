
//команда препроцессора - нужна для того, 
//чтобы файл не зацикливался (не включал сам себя)
#pragma once 

//класс многочлена
class Polynom
{
	//статические методы
	static int stati;

public:

	//статические методы
	static void int_stati() { stati++; }

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
	double getCoefficient(int index);



	//сеттеры - нужны для установки полей класса
	
	//изменение степени многочлена
	void setDegree(int degree);

	//изменение всех коэффициентов многочлена
	void setCoefficients(double* coefficients);

	//вывод на консоль
	void show();

	//вычислить значение многочлена
	double compute(double x);

private:

	//коэффициенты расположены от меньшей степени к большей
	//т.е. под coefficients[0] расположен коэффициент при х^0

	//степень многочлена
	int degree;

	//коэффициенты при степенях многочлена
	double* coefficients;

	char string[100];
};

