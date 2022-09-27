#include <iostream>
using namespace std;

int main() {
    int bday, bmonth, day, month, year, count = 0;
    int jahre_tage[13] = {0, 31, 28, 31, 30, 31,
                          30, 31, 31, 30, 31, 30, 31};

    cin >> bday >> bmonth;
    cin >> day >> month >> year;

    if (year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)){ // Проверка года на "високосность"
        jahre_tage[2] = 29;
    }

    if (((bmonth == month) and (bday >= day)) or (bday == 29 and jahre_tage[2] == 29)) { // Нормализация счётчика дней
        count = bday - day;                                                              // внутри одного месяца
        cout << count << endl; return 0;
    }

    if ((day < bday) and (month < bmonth)) { // Стандартное сложение дней от даты до даты (если др после текущ. днём)
        jahre_tage[month] -= day; jahre_tage[bmonth] = bday;
        for (int i = month; i <= bmonth; i++) {
            count += jahre_tage[i];
        }
        cout << count << endl; return 0;
    }

    else{ // Сложение дней при переходе на следующий год (если др перед текущ. днём)
        for (int i = month; i <= 12; i++) { // Первый кусок
            jahre_tage[month] -= day;
            count += jahre_tage[i];
        }

        if ((year + 1) % 400 == 0 or ((year + 1) % 4 == 0 and (year + 1) % 100 != 0)){ // Проверка следующего года
            jahre_tage[2] += 1;                                                        // на "високосность"
        }

        for (int i = 1; i <= bmonth; i++) { // Соответственно второй кусок
            jahre_tage[bmonth] = bday;
            count += jahre_tage[i];
        }
        cout << count << endl; return 0;
    }
}
