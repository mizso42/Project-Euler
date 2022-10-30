#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    bool szorzat=false;
    for(a=9;a>0;a--)
    {
        for(b=9;b>=0;b--)
        {
            for(c=9;c>=0;c--)
            {
                int n=100001*a+10010*b+1100*c;
                for(int i=100;i<1000;i++)
                {
                    if((n%i==0)&&((n/i)<1000))
                    {
                        szorzat=true;
                        cout << n << '=' << i << '*' << n/i << endl;
                    }
                    if(szorzat)
                        break;
                }
                if(szorzat)
                    break;
            }
                if(szorzat)
                    break;
        }
                if(szorzat)
                    break;
    }
    return 0;
}
