#include <iostream>
#include <clocale>
#include <string>

using namespace std;

struct Advertising
{
	int n;
	double pr;
	double s;
};
int main()
{
	setlocale(LC_ALL, "Russian");

	Advertising dohod;
	cout << "Введите кол-во объявлений: ";cin >> dohod.n;
	cout << "\nВведите процент посетителей нажавших на объявление: "; cin >> dohod.pr;
	cout << "\nВведите средний заработок за каждое нажатие: "; cin >> dohod.s;
	double DOHOD;
	DOHOD = dohod.n * dohod.pr / 100 * dohod.s;
	cout << "\nДоход от показа рекламы\t" << DOHOD <<"$";

}

