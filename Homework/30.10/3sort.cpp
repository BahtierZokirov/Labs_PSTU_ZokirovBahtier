#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a[7] = { -4, 5, 2, 9, 6, -3, -2 };
	int t;
	cout << "Исходный массив\t\t";

	for (int i = 0;i <= 6; i++)
	{
		cout << a[i] << ' ';
	}
	
	for(int i = 0;i<=5;i++)
		for (int j = 0; j <= 5; j++)
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
	cout << "\n\nОтсортированный массив\t";
	for (int i = 0;i <= 6; i++)
		cout << a[i] << ' ';
	return 0;
}
