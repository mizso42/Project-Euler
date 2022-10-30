#include <iostream>
#include <vector>

using namespace std;

const int PERMUTATION_LENGTH = 10;

int factorial(int);

int main()
{
    vector<int> nums;
    for (int i = 0; i < PERMUTATION_LENGTH; i++)
        nums.push_back(i);
    int permutation[PERMUTATION_LENGTH];

    int n, k = 0;
    cin >> n;
    n--;

    for (int i = PERMUTATION_LENGTH; i > 0; i--)
    {
        n -= k * factorial(i);
        k = n / factorial(i - 1);
        permutation[PERMUTATION_LENGTH - i] = nums[k];
        nums.erase(nums.begin() + k);
    }

    for (int i = 0; i < PERMUTATION_LENGTH; i++)
        cout << permutation[i];

    return 0;
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
