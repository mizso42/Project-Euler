#include <iostream>

using namespace std;

int main()
{
    int d;
    cin >> d;
    int n=1, t, k;
    do
    {
        t=n*(n+1)/2;
        k=0;
        for(int i=1;i<=t;i++)
            if(t%i==0)
            {
                k++;
            }
        n++;
    } while (k<d);
    cout << t << endl;
    return 0;
}
