#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string eng = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string rus = "эбсдэфг ижклмнопкрстуввкйз";

    string s, result = "";
    cout << "Введите предложение: ";
    getline(cin, s);

    int i = 0;
    while (i < s.length()) {
        while (i < s.length() && s[i] == '_') {
            i++;
        }

        string word = "";
        string auto_pr = "";

        while (i < s.length() && s[i] != '_') {
            word += s[i];
            char zvuk = s[i];
            for (int j = 0; j < eng.length(); j++) {
                if (s[i] == eng[j]) {
                    zvuk = rus[j];
                }
            }
            auto_pr += zvuk;
            i++;
        }

        if (word != "") {
            string user_pr;
            cout << word << " - \"" << auto_pr << "\" -> ";
            getline(cin, user_pr);

            if (result != "") {
                result += " ";
            }
            if (user_pr == "") {
                result += auto_pr;
            }
            else {
                result += user_pr;
            }
        }
    }

    cout << "\n" << s << " -> " << result << endl;
    return 0;
}
