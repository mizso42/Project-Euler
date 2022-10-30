#include <iostream>
#include <string>

using namespace std;

string ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
"fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int numberOfLetters(int n);

int main()
{
    int sumOfLetters = 0;
    for (int i = 1; i <= 1000; i++)
    {
        sumOfLetters += numberOfLetters(i);
    }
    cout << sumOfLetters;
    return 0;
}


int numberOfLetters(int n) // up to 1000
{
    int letters;
    if (n == 1000)
        return 11;
    if (n < 100)
    {
        if (n < 20)
        {
            letters = ones[n].length();
        }
        else
        {
            letters = tens[n / 10].length() + numberOfLetters(n % 10);
        }
    }
    else
    {
        letters = numberOfLetters(n / 100) + 7;
        if (n % 100)
            letters += (3 + numberOfLetters(n % 100));
    }
    return letters;
}
