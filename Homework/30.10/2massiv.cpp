#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a[5] = { 5,6,7,8,8 }, n = 5;
	bool f = false;
	int i = 0;
	while ( (i < (n - 1)) && f == false)
	{
		if (a[i] >= a[i + 1]) f = true;
		i++;
	}
	if (f == true) cout << "Не упорядочен";
	else cout << "Упорядочен";
	return 0;
}
