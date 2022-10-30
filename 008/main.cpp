#include <iostream>
#include <string>

using namespace std;

int char2int (char);

int main()
{
    string s;
    cin >> s;//még az unsigned long long is túl kicsi tárolni egyben azn értékét
    int n[int (s.length())];
    for (unsigned i=0;i<s.length();i++)//string konvertálása int-tömbbé
    {
        n[i]=char2int(s[i]);
    }
    int d;
    long long p, m=0;//számjegyek, szorzat, maximum
    cin >> d;
    for (unsigned i=0; i<=s.length()-d;i++)//maximum keresése
    {
        if(i*n[i-1])//menet közben a már létező szorzatból a továbbléptetésnél csak a legrégebbi tagot kell szanálni és a legújabbat hozzávenni
        {
            p/=n[i-1];
            p*=n[i+d-1];
        }
        else//ha még nincs szorzatunk, vagy épp egy 0 tényezőt hagynánk el, újra kell építeni a szorzatot
        {
            p=1;
            for(int j=0; j<d; j++)
            {
                p*=n[i+j];
            }
        }
        if(p>m)//maximum értéket keresünk, nem helyet
            m=p;
    }
    cout << m << endl;
    return 0;
}

int char2int (char c)
{
    int n;
    n = int (c)-48;
    return n;
}
