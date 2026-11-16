#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const int N = 100;

int count_el(int a[], int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            k++;
        }
    }
    return k;
}

int count_el(string s) {
    int k = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
            k++;
        }
    }
    return k;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a[N];
    int n;

    cout << "Введите размер массива (от 1 до 100): ";
    cin >> n;

    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int nechet = count_el(a, n);
    cout << "Количество нечётных элементов в массиве: " << nechet << endl << endl;

    cin.ignore();

    string s;
    cout << "Введите строку текста: ";
    getline(cin, s);

    int slova = count_el(s);
    cout << "Количество слов в строке: " << slova << endl;

    return 0;
}
 
