#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

void add(int a[], int b[], int d);

int main()
{
    int n, l, k=0, n2;
    string s;
    ifstream adat;
    adat.open("adat.txt");
    getline(adat, s, '\n');
    stringstream(s) >> n;
    getline(adat, s, '\n');
    stringstream(s) >> l;
    n2=n;
    do
    {
        n2/=10;
        k++;
    } while(n2>0);
    int m=l+k-1;
    int szamok[n][m];
    for (int i=0; i<n; i++)
    {
        getline(adat, s, '\n');
        for(int j=0; j<l; j++)
        {
            szamok[i][j]=s[l-1-j]-48;
        }
        for(int j=l; j<m; j++)
        {
            szamok[i][j]=0;
        }
    }
    adat.close();
    int szum[m];
    for(int i=0;i<m;i++)
        szum[i]=0;
    for(int i=0;i<n;i++)
    {
        add(szum,szamok[i],m);
    }
    for(int i=0;i<m;i++)
    {
        cout << szum[m-i-1];
    }
    cout << endl;
    return 0;
}

void add(int a[], int b[], int d)
{
    int m=0;
    for(int i=0; i<d; i++)
    {
        int k=(a[i]+b[i]+m)/10;
        a[i]=(a[i]+b[i]+m)%10;
        m=k;
    }
}
