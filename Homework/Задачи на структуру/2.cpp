#include <iostream>
#include <clocale>
#include <string>

struct worker
{
	string fio;
	int days;
	double oplata;
	double prem;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	worker n;
	cout << "ФИО: ";
	getline(cin, n.fio);
	cout << "\nОтработанные дни: "; cin >> n.days;
	cout << "\nОплата за день: "; cin >> n.oplata;
	cout << "\nПремия: "; cin >> n.prem;
	int zar;
	zar = n.days * n.oplata + n.prem;
	cout << "Заработная плата " << zar << " руб";
}
