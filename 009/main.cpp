#include <iostream>

using namespace std;

int main()
{
    bool db=false;
    int m=0, n;
    do
    {
        m++;
        n=0;
        do
        {
            n++;
            if(2*m*(m+n)==1000)
                db=true;
        }while(!db&&n<m);
    }while (!db);
    cout << m*m-n*n << ' ' << 2*m*n << ' ' << m*m+n*n << endl << 2*m*m*m*m*m*n-2*m*n*n*n*n*n << endl;
    return 0;
}
