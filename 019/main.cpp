#include <iostream>

using namespace std;

int main()
{
    int days = 366;
    int counter = days % 7 == 0;
    for (int i = 0; i < 1200; i++)
    {
        int year = i / 12 + 1901;
        int month = i % 12 + 1;
        bool leap = (year % 100 ? (year % 4 ? false : true) : (year % 400 ? false : true));
        if (month == 2)
            days += leap ? 29 : 28;
        else if (month == 4 || month == 6 || month == 9 || month == 11)
            days += 30;
        else
            days += 31;

        if (days % 7 == 0)
            counter++;
    }
    cout << counter;
    return 0;
}
