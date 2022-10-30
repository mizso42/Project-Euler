#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void bubbleSort(vector<string>&);
int summation(vector<string>&);
int strValue(const string&);

int main()
{
    ifstream rawInput("p022_names.txt");
    vector<string> refinedInput;

    if(rawInput.is_open())
    {
        string line;
        while(getline(rawInput, line, ','))
        {
            string name = "";
            for(unsigned i = 1; i < line.length() - 1; i++)
            {
                name += line[i];
            }
            refinedInput.push_back(name);
        }
        rawInput.close();
    }

    bubbleSort(refinedInput);

    int sum = summation(refinedInput);

    cout << sum;

    return 0;
}

void bubbleSort(vector<string> &alphabetical)
{
    int maxIndex = alphabetical.size() - 1;
    string str;
    while (maxIndex > 0)
    {
        for (int i = 0; i < maxIndex; i++)
        {
            if (alphabetical[i] > alphabetical[i+1])
            {
                str = alphabetical[i];
                alphabetical[i] = alphabetical[i+1];
                alphabetical[i+1] = str;
            }
        }
        maxIndex--;
    }
}

int summation(vector<string> &strList)
{
    int sum = 0;

    for (unsigned i = 0; i < strList.size(); i++)
    {
        sum += ((i + 1) * strValue(strList[i]));
        if (sum < 0)
            cout << "ERROR!";
    }

    return sum;
}

int strValue(const string &str)
{
    int sum = 0;

    for (unsigned i = 0; i < str.length(); i++)
    {
        sum += (str[i] - 64);
    }

    return sum;
}
