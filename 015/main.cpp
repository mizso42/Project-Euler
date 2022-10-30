#include <iostream>

using namespace std;

long long nCr(int n, int k);

int main()
{
    int n, m;
    cin >> n >> m;
    cout << nCr(n+m, n<m?n:m) << endl;
    return 0;
}

long long nCr(int n, int k)
{
    long long r=1;
    for(int i=0; i<k; i++)
    {
        r*=n-i;
        r/=i+1;
    }
    return r;
}
