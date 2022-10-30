#include <iostream>
#include <string>

using namespace std;

int lb(int);

int main()
{
    int n;
    cin >> n;
    int pn=16*n/(10*lb(n));//durva becslés pi(n)-re
    int p[pn];
    p[0]=2;
    p[1]=3;
    for(int k=2;k<=pn;k++)//k az ismert prímek darabszáma
    {
        int v=p[k-1];//v a következő lehetséges prím
        do
        {
            v+=v%6==1?4:2;//A 3-nál nagyobb prímek +/-1 maradékot adnak 6-tal osztva, elég csak ezeket ellenőrizni (ezért kellett a 2-t és a 3-at előre beírni)
            int i=0;
            while (v%p[i]!=0)
            {
                if(++i==k)//az összes eddigi prím oszthatóságát leellenőriztük
                {
                    p[i]=v;//új prímet találtunk
                    cout << i << ' ' << p[i] << endl;
                }
            }
        } while(v!=p[k]);//minimális rá az esély, hogy az ellenőrizendő szám épp egyenlő lenne a még meg nem talált prím helyén lévő adatszeméttel
    }
    unsigned long long sum=0;
    for(int i=0; p[i]<=n;i++)
        sum+=p[i];
    cout << sum << endl;//*/
    return 0;
}

int lb(int n)
{
    int k=0;
    do
    {
        n/=2;
        k++;
    } while(n);
    return k;
}
