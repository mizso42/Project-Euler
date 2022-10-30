#include <iostream>

using namespace std;

int main()
{
    int f0=0, f1=1, fn=f0+f1, s=0, n;
    cin >> n;
    while (fn<=n)
    {
        if(fn%2==0)
            s+=fn;
        f0=f1;
        f1=fn;
        fn=f0+f1;
    }
    cout << s;
    return 0;
}
