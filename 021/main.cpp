#include <iostream>

using namespace std;

int sigma(int n);
int amicableSum(int array[], int length);

int main()
{
    int n;
    cin >> n;
    //cout << sigma(n);/*
    int nums[n];
    for (int i = 0; i < n; i++)
        nums[i] = sigma(i);
    cout << amicableSum(nums, n); //*/
    return 0;
}

int sigma(int n)
{
    if (n == 0 || n == 1)
        return 0;
    int sum = 1;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            sum += i;
    }
    return sum;
}

int amicableSum(int array[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        if (i < array[i] && array[i] < length)
            if (i == array[array[i]])
                sum += i + array[i];
    }
    return sum;
}
