#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int n, m;
    fstream file ("adat.txt");
    file >> n >> m;
    int tomb [n][m];
    string sor;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            getline(file, sor, ' ');
            stringstream(sor) >> tomb[i][j];
        }
    }
    file.close();
    int mx=0, p;
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<m-3;j++)
        {
            p=1;
            for(int k=0; k<4;k++)
            {
                p*=tomb[i][j+k];
            }
            if(mx<p)
                mx=p;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<m-3;j++)
        {
            p=1;
            for(int k=0; k<4;k++)
            {
                p*=tomb[j+k][i];
            }
            if(mx<p)
                mx=p;
        }
    }
    for(int i=0; i<n-3; i++)
    {
        for(int j=0;j<m-3;j++)
        {
            p=1;
            for(int k=0; k<4;k++)
            {
                p*=tomb[i+k][j+k];
            }
            if(mx<p)
                mx=p;
        }
    }
    for(int i=3; i<n; i++)
    {
        for(int j=0;j<m-3;j++)
        {
            p=1;
            for(int k=0; k<4;k++)
            {
                p*=tomb[i-k][j+k];
            }
            if(mx<p)
                mx=p;
        }
    }
    cout << mx << endl;
    return 0;
}
