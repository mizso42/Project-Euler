#include <iostream>
#include <vector>

using namespace std;

const int GIVEN_LIMIT = 28123;
vector<int> abundants;

int divisorSum(int);
bool isAbundantSum(int);

int main()
{
    for (int n = 12; n <= GIVEN_LIMIT - 12; n++)
    {
        if (n < divisorSum(n))
            abundants.push_back(n);
    }

    int sum = 0;
    for (int i = 1; i <= GIVEN_LIMIT; i++)
    {
        if(!isAbundantSum(i))
        {
            sum += i;
        }
    }

    cout << endl << endl << sum;

    return 0;
}

int divisorSum(int n)
{
    int sum = 0;

    for (int i = 1; i <= n/2; i++)
        if (!(n % i))
            sum += i;

    return sum;
}

bool isAbundantSum(int n)
{
    for (int i = 0; abundants[i] * 2 <= n; i++)
    {
        for (unsigned j = i; abundants[j] < n; j++)
        {
            if (abundants[i] + abundants[j] == n)
                return true;
        }
    }

    return false;
}
