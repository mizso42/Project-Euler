#include <iostream>

using namespace std;

int hatvany(int n, int k);

int main()
{
    int n;
    cin >> n;
    int p[n+1];
    p[0]=p[1]=0;//eratosztenészi szita
    for(int i=2;i<=n;i++)
        p[i]=1;
    for(int i=0;i*i<=n;i++)
    {
        if(p[i])
        {
            for(int j=i;j*i<=n;j++)
            {
                p[i*j]=0;
            }
        }
    }//szita vége
    for(int i=0;i<=n;i++)//legnagyobb megengedett prím-hatványkitevő keresése
    {
        if(p[i])
        {
            while(hatvany(i,p[i])<=n)
            {
                p[i]++;
            }
            p[i]--;//eggyel túlfut a while-ciklus
        }
    }
    int sz=1;//szorzat
    for(int i=1;i<=n;i++)
    {
        sz*=hatvany(i,p[i]);
    }
    cout << sz << endl;
    return 0;
}

int hatvany(int n, int k)
{
    int r=1;
    while (k>0)
    {
        r*=n;
        k--;
    }
    return r;
}
