#include <iostream>
#include <cmath>    // Библиотека для функции pow()
#include <clocale>  // Библиотека для поддержки русского языка
#include <iomanip>  // Библиотека для манипулятора setprecision

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n, m;
    cout << "=== ЗАДАНИЕ 2 ===" << endl;

    n = 5; m = 5;
    int res1 = ++n * ++m;
    cout << "1) Выражение ++n * ++m = " << res1 << " (при n=" << n << ", m=" << m << ")" << endl;

    n = 5; m = 5;
    bool res2 = m++ < n;
    cout << "2) Выражение m++ < n   = " << res2 << " (при n=" << n << ", m=" << m << ")" << endl;
   
    return 0;
}
