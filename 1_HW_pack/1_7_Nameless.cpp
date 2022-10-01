#include <iostream>
using namespace std;

int main() {
    int A, n, first_part, second_part, result;
    cin >> A >> n;

    first_part = (A << n);

    second_part = ((A & ~((A >> n) << n)) >> (8 - n));

    result = (first_part | second_part);

    result &= ~((result >> 8) << 8);

    cout << result << endl;
}
/*
 *   (A & ~((A >> B) << B)) - "срез" числовой записи для переноса вперёд (допустим B = 2, A = 0001 1011, тогда результат: 0000 0011)
 */
