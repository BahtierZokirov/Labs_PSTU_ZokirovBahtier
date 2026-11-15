#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

double geron(int a, int b, int c) {
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double square(int k, ...) {
    int* p = &k; 
    double s = 0;

    if (k == 3) {
        int a = *(++p);
        int b = *(++p);
        int c = *(++p);
        s = geron(a, b, c);
    }
    else if (k == 5) {
        int a = *(++p);
        int b = *(++p);
        int d1 = *(++p);
        int c = *(++p);
        int d = *(++p);
        s = geron(a, b, d1) + geron(d1, c, d);
    }
    else if (k == 8) {
        int a = *(++p);
        int b = *(++p);
        int d1 = *(++p);
        int c = *(++p);
        int d2 = *(++p);
        int d = *(++p);
        int e = *(++p);
        s = geron(a, b, d1) + geron(d1, c, d2) + geron(d2, d, e);
    }

    return s;
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "1) Площадь треугольника (3 параметра)     = "
        << square(3, 3, 4, 5) << endl;

    cout << "2) Площадь четырехугольника (5 параметров) = "
        << square(5, 3, 4, 5, 3, 4) << endl;

    cout << "3) Площадь пятиугольника (8 параметров)    = "
        << square(8, 3, 4, 5, 5, 6, 5, 5) << endl;

    return 0;
}
