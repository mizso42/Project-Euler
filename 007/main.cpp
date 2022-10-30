#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int p[n];//prímlista
    p[0]=2;
    p[1]=3;
    for(int k=2;k<n;k++)//k az ismert prímek darabszáma
    {
        int v=p[k-1];//v a következő lehetséges prím
        do
        {
            v+=v%6==1?4:2;//A 3-nál nagyobb prímek +/-1 maradékot adnak 6-tal osztva, elég csak ezeket ellenőrizni (ezért kellett a 2-t és a 3-at előre beírni)
            int i=0;
            while (v%p[i]!=0)
            {
                if(++i==k)//az összes eddigi prím oszthatóságát leellenőriztük
                    p[i]=v;//új prímet találtunk
            }
        } while(v!=p[k]);//minimális rá az esély, hogy az ellenőrizendő szám épp egyenlő lenne a még meg nem talált prím helyén lévő adatszeméttel
    }
    cout << p[n-1] << endl;
    return 0;
}
