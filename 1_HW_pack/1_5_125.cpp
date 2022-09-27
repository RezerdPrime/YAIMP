#include <iostream>
#include <string> //Для введения строки
#include <cmath> //Для степени (перевода в 10сс)
using namespace std;

int main()
{
    int A, i, A2; string s = "", sym;
    cin >> A >> i;

    while (A>0) {
        s += to_string(A%2); //Перевод инта в строку
        A /= 2;
    }

    if (i >= s.length()) {
        string str("0", i - s.length() + 1); s.append(str);
    }
    sym = s[i];
    A2 = atoi(sym.c_str()); //Перевод символа в инт
    s = s.replace(i, 1, to_string((A2 + 1) % 2)); //Инвертация бита

    A = 0;

    for (int j = s.length()-1; j > -1; j--) {
        sym = s[j];
        A += pow(2,j) * atoi(sym.c_str());
    }
    cout << A;
}
