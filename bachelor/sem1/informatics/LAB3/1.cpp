#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int k = 10, N_max = 35;
	double a = 0.1, b = 1.0, eps = 0.0001;
	double step = (b - a) / k;
	double y, sn, se, an;

	for (double x = a; x <= b; x += step)
	{
		y = (1.0 - (x * x) / 2.0) * cos(x) - (x / 2.0) * sin(x);
		sn = 1.0; 
		an = 1.0;
		for (int n = 0; n < N_max; n++)
		{
			an = an * (-x * x / ((2.0 * n + 1.0) * (2.0 * n + 2.0))) * ((2.0 * n * n + 4.0 * n + 3.0) / (2.0 * n * n + 1.0));
			sn += an;

		}
		se = 1.0;
		an = 1.0;
		int n = 0;

		while (abs(an) >= eps)
		{
			an = an * (-x * x / ((2.0 * n + 1.0) * (2.0 * n + 2.0))) * ((2.0 * n * n + 4.0 * n + 3.0) / (2.0 * n * n + 1.0));
			se += an;
			n++;
		}
		cout << "При X = " << x << " получено: SN = " << sn << ", SE = " << se << ", точное Y = " << y << endl;
	}
	return 0;
}
