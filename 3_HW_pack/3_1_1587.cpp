#include <iostream>
using namespace std;

int main() {
    int N, a1, a2, a3, count = 0; cin >> N;

    if (N <= 1) { cin >> a1; cout << 0; return 0; } // Последовательность из 1 элемента - пилообразная (по условию).

    if (N == 2){ // Если последовательность состоит из двух элементов, мы проверяем только на их равенство.
        cin >> a1 >> a2;
        if (a1 == a2) { cout << 1; }
        else { cout << 0; }
        return 0; // 1 2 и 2 1 - пилообразные, 1 1 и 2 2 - нет
    }

    if (N > 2){ /* Тут происходит своего рода "рулеточная проверка":
        Т.к. нам надо проверять по 3 элемента, мы должны их фиксировать.
        Введённые значения мы смещаем, избавляясь от уже ненужных.
        Это позволяет не заполнять память лишними значениями. */

        cin >> a1 >> a2 >> a3; N -= 3; // Отнимаем 3, потому что задействовали сразу 3 элемента.

        if ((a1 >= a2 and a2 >= a3) or (a1 <= a2 and a2 <= a3)) { count++; a2 = a3; } // ниже коммент 1
        else { a1 = a2; a2 = a3; } // ниже коммент 2

        while (N > 0){
            cin >> a3;
            N -= 1;

            if ((a1 >= a2 and a2 >= a3) or (a1 <= a2 and a2 <= a3)) { count++; a2 = a3; }
            /* Если числа не соответствуют пилообразной последовательности,
            мы заменяем 2-й элемент на 3-й, тем самым вычеркивая его. */

            else { a1 = a2; a2 = a3; }
            /* "Рулеточное смещение"
            Если числа соответствуют пилообразной последовательности, мы смещаем 2 значения,
            а третье выводится с клавиатуры, как следующий элемент. */
        }
        cout << count << endl;
        return 0;
    }
}
