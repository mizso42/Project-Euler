#include <iostream>

using namespace std;

int main()
{
    int n, a=0, b=0;
    cin >> n;
    for(int i=1;i<=n;i++)
        a+=i*i;
    for(int i=1;i<=n;i++)
        b+=i;
    b*=b;
    cout << b-a << endl;
    return 0;
}
