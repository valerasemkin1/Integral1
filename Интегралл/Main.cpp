#include<iostream>
#include <math.h> 
#include<Windows.h>
using namespace std;

enum Menu1
{
	Pryamougolnik = 1,
	Trapeciya = 2,
	Simpson = 3,
	Exit = 0

};

enum Menu2
{
	func1 = 1,
	func2 = 2,
	func3 = 3,
	func4 = 4,
	func5 = 5,
	func6 = 6,
	func7 = 7,
	func8 = 8
	
};

double set_S(double s)
{
    cout << "Введите переменную s:" << endl;
	cin >> s;
	return s;
}

double f1(double x, double s)
{
	return sin(x);
}
double f2(double x, double s)
{
	return cos(x);
}
double f3(double x, double s)
{
	return tan(x);
}
double f4(double x, double s)
{
	
	x = x + s;
	return x ;
}
double f5(double x, double s)
{
	return cos(x) * sin(x);
}
double f6(double x, double s)
{
	return pow(2, x);
}
double f7(double x, double s)
{
	return x * s;
}
double f8(double x, double s)
{
	return sqrt(x);
}


typedef double (*pointFunc)(double,double);

int main()
{


	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choise1;
	int choise2;

	int i;
	double Integral;
	double a, b;
	double h;
	pointFunc f = nullptr;
	double n;
	cout << "Задайте отрезок интегрирования [a,b]: " << endl;
	cin >> a >> b;
	cout << "Задайте шаг интегрирования h: " << endl;
	cin >> h;
	n = (b - a) / h;
	
		cout << "Виды функций: " << endl;
		cout << func1 << " - функция вида sin(x);\n"
			<< func2 << " - функция вида cos(x);\n"
			<< func3 << " - функция вида tan(x);\n"
			<< func4 << " - функция вида x+s;\n"
			<< func5 << " - функция вида cos(x) * sin(x);\n"
			<< func6 << " - функция вида x в квадрате;\n"
			<< func7 << " - функция вида x * s;\n"
			<< func8 << " - функция вида квадратный корень из х;\n"
			<< endl;
		cout << "Выберите вид функции: ";
		cin >> choise1;
		system("cls");
		switch (choise1)
		{
		case 1:
		{
			f = f1;
			cout << "Подыинтегральная функция f(x)=sinx\n";
			break;
		}
		case 2:
		{
			f = f2;
			cout << "Подыинтегральная функция f(x)=cosx\n";
			break;

		}
		case 3:
		{
			f = f3;
			cout << "Подыинтегральная функция f(x)=tanx\n";
			break;

		}
		case 4:
		{

			f = f4;
			cout << "Подыинтегральная функция f(x)=x+s\n";
			break;

		}
		case 5:
		{
			f = f5;
			cout << "Подыинтегральная функция f(x)=cos(x) * sin(x)\n";
			break;

		}
		case 6:
		{
			f = f6;
			cout << "Подыинтегральная функция f(x)=x в квадрате\n";
			break;

		}
		case 7:
		{
			f = f7;
			cout << "Подыинтегральная функция f(x)=x * s\n";
			break;

		}
		case 8:
		{
			f = f8;
			cout << "Подыинтегральная функция f(x)=корень из х\n";
			break;

		}

		}
	


	do
	{
		cout << Pryamougolnik << " - Рассчёт интеграла по формуле центральных прямоугольников \n"
			<< Trapeciya << " - Рассчёт интеграла по формуле трапеций \n"
			<< Simpson << " - Рассчёт интеграла по формуле Симпсона\n"
			<< Exit << " - Выход из программы\n";
		cout << "Выберите способ вычисления: ";
		cin >> choise2;

		double s = 0;
		if (choise2!=0)
		s = set_S(s);

		switch (choise2)
		{
		case Pryamougolnik:
		{
			//формулa центральных прямугольников
			Integral = 0.0;
			for (i = 1; i <= n; i++)
				Integral = Integral + h * f(a + h * (i - 0.5),s);
			cout << "Интеграл по формуле центральных прямоугольников: I = " << Integral << endl << endl;
			break;
		}
		case Trapeciya:
		{
			// формулa трапеций
			Integral = h * (f(a,s) + f(b,s)) / 2.0;
			for (i = 1; i <= n - 1; i++)
				Integral = Integral + h * f(a + h * i,s);
			cout << "Интеграл по формуле трапеций: I = " << Integral << endl << endl;
			break;
		}
		case Simpson:
		{
			// формулa Симпсона
			Integral = h * (f(a,s) + f(b,s)) / 6.0;
			for (i = 1; i <= n; i++)
				Integral = Integral + 4.0 / 6.0 * h * f(a + h * (i - 0.5),s);
			for (i = 1; i <= n - 1; i++)
				Integral = Integral + 2.0 / 6.0 * h * f(a + h * i,s);
			cout << "Интеграл по формуле Симпсона: I = " << Integral << endl << endl;
			break;
		}
		}
	
	} while (choise2 != Exit);



	return 0;

}