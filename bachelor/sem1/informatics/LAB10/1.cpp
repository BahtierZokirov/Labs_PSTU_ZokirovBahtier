#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int maxDL = 256;

	int rows, i = 0;
	cout << "Введите количество строк: ";
	cin >> rows;
	cin.ignore();

	char** lines = new char* [rows];
	for (int i = 0;i < rows;i++)
	{
		lines[i] = new char[maxDL];
		cout << "Строка " << i + 1 << ": ";
		cin.getline(lines[i], maxDL);
	}
	cout << '\n' << "Вы ввели:\n";
	for (int i = 0;i < rows;i++)
		cout << lines[i] << '\n';

	int k, n;
	cout << "Количество строк которые нужно удалить: ";
	cin >> k;
	cout << "\nС какой строки начать удаление: ";
	cin >> n;
	n--;
	

	if (n >= 0 && n < rows && k > 0 && n + k <= rows)
	{
		for (int i = n;i < n + k;i++)
		{
			delete[] lines[i];
		}
		int rowsNew = rows - n;
		char** linesNew = new char* [rowsNew];

		int j = 0;
		for (int i = 0;i < rows; i++)
		{
			if (i < n || i >= n + k)
			{
				linesNew[j] = lines[i];
				j++;
			}
		}
		delete[] lines;
		lines = linesNew;
		rows = rowsNew;
	}
	else cout << "Некорректный диапазон для удаления!\n ";

	cout << "Оставшиеся строки: " << endl;
	for (int i = 0;i < rows;i++)
		cout << lines[i] << '\n';
	
	for (int i = 0;i < rows;i++)
		delete[] lines[i];
	delete[] lines;

	return 0;
}
