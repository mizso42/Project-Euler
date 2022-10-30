#include <iostream>

using namespace std;

int main()
{
    int n, mh=0, mv=0;
    unsigned long long k;
    cin >> n;
    for(int i=1; i<n; i++)
    {
        k=i;
        int j;
        for(j=1; k>1; j++)
        {
            if(k%2)
                k=3*k+1;
            else
                k/=2;
        }
        if(j>mv)
        {
            mh=i;
            mv=j;
        }
    }
    cout << mh << ' ' << mv << endl;
    return 0;
}
