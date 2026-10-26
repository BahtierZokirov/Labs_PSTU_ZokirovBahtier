#include <iostream>
#include <cmath>    // Библиотека для функции pow()
#include <clocale>  // Библиотека для поддержки русского языка
#include <iomanip>  // Библиотека для манипулятора setprecision
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    float a = 100.0f;
    float b = 0.001f;

    float f1 = pow(a - b, 4);                     // (a - b)^4
    float f2 = pow(a, 4);                         // a^4
    float f3 = 4.0f * pow(a, 3) * b;              // 4 * a^3 * b
    float f4 = 6.0f * pow(a, 2) * pow(b, 2);      // 6 * a^2 * b^2
    float f5 = 4.0f * a * pow(b, 3);              // 4 * a * b^3
    float f6 = pow(b, 4);                         // b^4

    float chis = f1 - f2 + f3;
    float znam = f4 - f5 + f6;
    float res_f = chis / znam;

    
    double a_d = 100.0;
    double b_d = 0.001;

    double d1 = pow(a_d - b_d, 4);                     // (a - b)^4
    double d2 = pow(a_d, 4);                           // a^4
    double d3 = 4.0 * pow(a_d, 3) * b_d;               // 4 * a^3 * b
    double d4 = 6.0 * pow(a_d, 2) * pow(b_d, 2);       // 6 * a^2 * b^2
    double d5 = 4.0 * a_d * pow(b_d, 3);               // 4 * a * b^3
    double d6 = pow(b_d, 4);                           // b^4

    double numerator_d = d1 - d2 + d3;
    double denominator_d = d4 - d5 + d6;
    double res_d = numerator_d / denominator_d;

    
    
    cout << "Результат для float:  "   << setprecision(12) << res_f << endl;
    cout << "Результат для double: " << setprecision(12) << res_d << endl << endl;
    return 0;
}
