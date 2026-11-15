#include <iostream>
#include <clocale>

using namespace std;

int step_num = 0; 

void han(int n, int from, int to, int temp) {
    if (n == 1) {
        step_num++;
        cout << "Ход " << step_num << ": переложить кольцо 1 со стержня "
            << from << " на стержень " << to << endl;
        return;
    }

    han(n - 1, from, temp, to);

    step_num++;
    cout << "Ход " << step_num << ": переложить кольцо " << n
        << " со стержня " << from << " на стержень " << to << endl;

    han(n - 1, temp, to, from);
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n = 5; 
    cout << "Решение задачи Ханойской башни для " << n << " колец (3 стержня):\n" << endl;

    han(n, 1, 3, 2);

    cout << "\nВсего выполнено ходов: " << step_num << endl;
    return 0;
}
