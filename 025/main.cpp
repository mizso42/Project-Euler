#include <iostream>

using namespace std;

double sqrt(int);
double sqrt(double);

double PHI = (1 + sqrt(5)) / 2;

int main()
{
    int n = 0;
    double fn = 1 / sqrt(5);

    int limit;
    cin >> limit;

    while (fn + 0.5 < limit)
    {
        fn *= PHI;
        n++;
    }

    cout << n;

    return 0;
}

double sqrt(int n)
{
    return sqrt((double) n);
}

double sqrt(double x)
{
    double a = 1.0;
    bool stop = false;

    while (!stop)
    {
        double b = a;
        a = (a + x / a) / 2;
        stop = a == b;
    }

    return a;
}
