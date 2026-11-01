#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	const int N = 100;
	int a[N];
	int n;
	cout << "Введите размер массива ";
	cin >> n;
	cout << "Заполните стек числами\n";
	for (int i = 0;i <= n - 1;i++)
		cin >> a[i];
	while (true)
	{
		cout << "\n\nВыберите операцию:\n1-Добавить\n2-Удалить\n3-Выйти\n";
		int op;
		cin >> op;
		if (op == 1)
		{
			if (n >= N) cout << "Ошибка, стек забит";
			else
			{
				int x;
				cout << "Введите число для добавления ";
				cin >> x;

				a[n] = x;
				n++;
				cout << "Элемент успешно добавлен ";
			}
		}
		else if (op == 2)
			if (n > 0) n--;
			else cout << "Ошибка, стек пуст";
		else if (op == 3)
		{
			cout << "Выход из программы\n";
			break;
		}
		else
		{
			cout << "Неверный номер. Попробуйте еще раз\n";
			continue;
		}
		cout << "\n";
		for (int i = 0; i <= n - 1;i++)
			cout << a[i] << ' ';
		
	}
	return 0;
}
