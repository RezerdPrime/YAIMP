// https://fincalculator.ru/kalkulyator-dnej - Калькулятор дней
// https://web2.0calc.com/ - Просто научный калькулятор

#include <iostream>
using namespace std;

int main() {
    int bday, bmonth, day, month, year, count = 0;
    int jahre_tage[13] = {0, 31, 28, 31, 30, 31,
                          30, 31, 31, 30, 31, 30, 31};

    cin >> bday >> bmonth;
    cin >> day >> month >> year;

    if (year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)){ // Проверка года на "високосность"
        jahre_tage[2] = 29; // Условие, показывающее, что год високосный
    }


    if (bday == 29 and bmonth == 2 and (jahre_tage[2] = 29)){ // Добавление дней в случае, если год невисокосный,
        for (int i = year; i < 3000; i++){                    // а др 29 февраля
            if (i % 400 == 0 or (i % 4 == 0 and i % 100 != 0)){
                count += 365 * (i - year - 1);
                break;
            }
        }
    }


    if ((bmonth == month and bday >= day and jahre_tage[2] != 29 and bday != 29)
        or ((year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)) and bday == 29)) { // Нормализация счётчика дней
        count = bday - day;                                                             // внутри одного месяца
        cout << count << endl; return 0;//1
    }


    if (((day < bday) or (month < bmonth)) and (not(bday == 29 and bmonth == 2))) { // Стандартное сложение дней от даты до даты (если др после текущ. дня)
        jahre_tage[month] -= day; jahre_tage[bmonth] = bday;
        for (int i = month; i <= bmonth; i++) {
            count += jahre_tage[i];
        }
        cout << count << endl; return 0;//2
    }

    else { // Сложение дней при переходе на следующий год (если др перед текущ. днём)
        jahre_tage[month] -= day;
        for (int i = month; i <= 12; i++) { // Первый кусок
            //cout << count << " " << jahre_tage[i] << endl;///
            count += jahre_tage[i];
        }
        jahre_tage[month] += (day - 1);

        if ((year + 1) % 400 == 0 or ((year + 1) % 4 == 0 and (year + 1) % 100 != 0)) { // Проверка следующего года
            jahre_tage[2] += 1;                                                        // на "високосность"
        }
        //cout << "<>" << endl;///
        jahre_tage[bmonth] = bday;
        for (int i = 1; i <= bmonth; i++) { // Соответственно второй кусок
            //cout << count << " " << jahre_tage[i] << endl;///
            count += jahre_tage[i];
        }
        count = (bday == 29 and day == 28 and month == 2 and bmonth == 2) ? count-1 : count;
        cout << count << endl; return 0;//3
    }
}
