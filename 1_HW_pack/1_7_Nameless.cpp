#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int A, n; string s = "", sub = "", sym;
    cin >> A >> n;

    while (A>0) {
        s += to_string(A%2); // Перевод инта в строку
        A /= 2;
    }

    reverse(s.begin(), s.end()); // Переворот строки

    sub = s.substr(0, n); // Создание подстроки, которая смещается в конец

    s = s.substr(n, s.length()); // Создание подстроки, которая смещается в начало

    s.append(sub); // Добавление отделённой части в конец

    for (int i = 0; i < s.length(); i++){
        sym = s[i]; // Значение бита, на которое необходимо умножить степень двойки
        A += pow(2,(s.length() - 1 - i)) * atoi(sym.c_str()); // Формирование десятичного числа по правилам
    }
    cout << A << endl;
}
