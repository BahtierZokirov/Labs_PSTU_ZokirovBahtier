#include <iostream>
#include <clocale>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int max, min, maxi = 0,mini = 0, n = 7,maxS = 1, minS = 1;
	int a[7] = { 2, 5, 5, 3, 2, 9, 9};
	max = a[0];
	min = a[0];
	for (int i = 1; i <= (n - 1); i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			maxi = i;
			maxS = 1;
		}
		else
			if (a[i] == max)
			{
				maxS += 1;
			}
		if (a[i] < min)
		{
			min = a[i];
			mini = i;
			minS = 1;
		}
		else
			if (a[i] == min) minS += 1;
	}
	cout << "Значение максимального элемента:\t" << max << "\n"<< "Индекс максимального элемента:\t\t" << maxi << "\n"
		<< "Номер максимального элемента:\t\t" << maxi + 1 << "\n"<< "Количество максимальных элементов:\t" << maxS << "\n\n\n";
	cout << "Значение минимального элемента:\t\t" << min << "\n"<< "Индекс минимального элемента:\t\t" << mini << "\n"
		<< "Номер минимального элемента:\t\t" << mini + 1 << "\n"<< "Количество минимальных элементов:\t" << minS << "\n";

	return 0;
}
