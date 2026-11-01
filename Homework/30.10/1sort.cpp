#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int y,j;
	int a[7] = { -4, 5, 2, 9, 6, -3, -2 };
	cout << "Исходный массив\t";

	for (int i = 0;i <= 6; i++)
	{
		cout << a[i] << ' ';
	}
	
	for (int i = 1;i <= 6;i++)
	{
		y = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > y)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = y;
	}
	cout << "\n\nОтсортированный массив\t";
	for (int i = 0; i <= 6; i++)
		cout << a[i] << ' ';
	return 0;
}
