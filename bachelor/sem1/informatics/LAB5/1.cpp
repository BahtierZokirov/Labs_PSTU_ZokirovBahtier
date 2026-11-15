#include <iostream>
#include <iomanip>
#include <clocale>

using namespace std;

const int N = 100; 

double sr_stolb(int a[][N], int n, int k) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i][k];
    }
    return sum / n;
}

int kol_bolshe(int a[][N], int n, int k, double sr) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][k] > sr) {
            count++;
        }
    }
    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int a[N][N];
    int n, m; 

    cout << "Введите количество строк и столбцов (от 2 до 100): ";
    cin >> n >> m;

    if (n < 2 || n > N || m < 2 || m > N) {
        cout << "Ошибка: некорректные размеры матрицы!" << endl;
        return 1;
    }

    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cout << "\nИсходная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }

    double sr = sr_stolb(a, n, 0);
    cout << fixed << setprecision(2);
    cout << "\nСреднее арифметическое 1-го столбца: " << sr << endl;

    for (int j = 1; j < m; j++) {
        int k = kol_bolshe(a, n, j, sr);
        cout << "Столбец " << j + 1 << ": " << k
            << " эл. больше " << sr << endl;

        sr = sr_stolb(a, n, j);
    }

    return 0;
}
