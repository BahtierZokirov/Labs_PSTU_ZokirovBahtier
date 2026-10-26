#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double sum, s;
	int n = 2;

	s = pow(n, log(n)) / pow(log(n), n);
	sum = s;

	for (n = 2; n <= 15; n++)
	{
		s = s * (pow((n + 1), log(n + 1)) * pow(log(n), n)) 
			/ (pow(log(n + 1), (n + 1)) * pow(n, log(n)));
		sum += s;
	}
	cout << "Лабараторная работа №2\nВариант 22\nСумма равна " << sum;
	return 0;
}
