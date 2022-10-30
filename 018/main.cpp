#include <iostream>
#include <fstream>

using namespace std;

int maximum (int a, int b);

int main()
{
    int nums[15][15];

    ifstream file;
    file.open("input.txt");

    for (int i = 0; i < 15; i++)
        for (int j = 0; j <= i; j++)
            file >> nums[i][j];

    for (int i = 13; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
            nums[i][j] += maximum(nums[i+1][j], nums[i+1][j+1]);
    }
    cout << nums[0][0];
    return 0;
}

int maximum(int a, int b)
{
    return (a > b ? a : b);
}
