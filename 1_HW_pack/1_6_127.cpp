#include <iostream>
#include <string> //Для введения строки
#include <cmath> //Для степени двойки
using namespace std;

int main()
{
    int A, n; string s = "", s2;
    cin >> A >> n;

    while (A>0) {
        s += to_string(A%2); //Перевод инта в строку
        A /= 2;
    }

    if (n > s.length()) { //Защита от выхода за диапазон
        n = s.length();
    }

    s = s.substr(0, n);
    A = 0;

    for (int i = s.length()-1; i > -1; i--) {
        s2 = s[i];
        A += pow(2,i) * atoi(s2.c_str());
    }
    cout << A;
}
