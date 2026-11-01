#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a[][3] = { { 0, 24, 12 },{ 23, 6, 8 } };
	int maxi = 0, maxj = 0, max = a[0][0];
	for (int i = 0; i <= 1; i++)
		for (int j = 0; j <= 2; j++)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
				maxi = i;
				maxj = j;
			}
		}
	cout << "Максимальный элемент\t" << max << "\nЕго индексы\t\t" << maxi << ' ' << maxj;
	return 0;

}
