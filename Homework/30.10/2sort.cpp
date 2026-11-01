#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a[7] = { -4, 5, 2, 9, 6, -3, -2 };
	int min = a[0];
	int mini,t,i;
	cout << "Исходный массив\t\t";

	for (int i = 0;i <= 6; i++)
	{
		cout << a[i] << ' ';
	}
	
	for (int i = 0; i <= 5;i++)
	{
		mini = i;
		for (int j = i + 1;j <= 6;j++)
			if (a[j] < a[mini])
			{
				mini = j;
			}
		t = a[i];
		a[i] = a[mini];
		a[mini] = t;

	}
	cout << "\n\nОтсортированный массив\t";
	for (int i = 0;i <= 6; i++)
		{
		cout << a[i] << ' ';
		}
	return 0;
}
