#include <iostream>
#include <new>
#include <exception>

using namespace std;

long long lastPrime (long long &n, long long d);

int main()
{
    long long n;
    cin >> n; //Legyen nagyobb, mint 1!
    long long p=lastPrime(n,2);
    cout << p << endl;
    return 0;
}

long long lastPrime (long long &n, long long d)
{
    long long i=d;
    while (n%i!=0)//Megkeressük az első prímosztót
        i++;
    while (n%i==0)//Lecsupaszítjuk ettől az osztótól
        n/=i;
    if (n>1)
        return lastPrime(n,i+1);//Keresünk más prímtényezőt
    else
        return i;
}
