#include <iostream>
#include <windows.h>

using namespace std;

bool XOR(bool a, bool b)
{
    return (a||b)&&!(a&&b);
}

const int BIN_SIZE = 1024;

struct bin
{
    bool bits[BIN_SIZE];
//public:
    bin()
    {
        for(int i = 0; i < BIN_SIZE; i++)
            bits[i] = false;
    }

    int usefulDigits()
    {
        int i = BIN_SIZE - 1;
        while (!bits[i] && i > 0)
        {
            i--;
        }
        return ++i;
    }

    void operator<< (int shifter)
    {
        for (int i = usefulDigits() + shifter - 1; i > shifter - 1; i--)
            bits[i] = bits[i - shifter];
        for (int i = 0; i < shifter; i++)
            bits[i] = false;
    }

    void operator= (bin value)
    {
        for (int i = 0; i < BIN_SIZE; i++)
        {
            this->bits[i] = value.bits[i];
        }
    }

    bool operator< (bin relative)
    {
        if (usefulDigits() != relative.usefulDigits())
            return usefulDigits() < relative.usefulDigits();
        else
        {
            int i = usefulDigits();
            while (i > 0 && bits[i-1] == relative.bits[i-1])
                i--;
            return (i-- == 0 ? false : relative.bits[i]);
        }
    }

    bool operator> (bin relative)
    {
        return relative < *this;
    }

    bool operator== (bin relative)
    {
        return !(*this < relative || relative < *this);
    }

    bool operator>= (bin relative)
    {
        return !(*this < relative);
    }

    bool operator<= (bin relative)
    {
        return !(relative < *this);
    }

    bin operator+ (bin addend)
    {
        if (usefulDigits() < addend.usefulDigits())
            return addend + *this;
        bin sum;
        bool residue = false;
        for (int i = 0; i <= usefulDigits(); i++)
        {
            sum.bits[i] = XOR(XOR(bits[i], addend.bits[i]), residue);
            residue = (bits[i] && addend.bits[i]) || (residue && XOR(bits[i], addend.bits[i]));
        }
        return sum;
    }

    bin operator- (bin subtrahend)
    {
        bin difference;
        bool residue = false;
        for (int i = 0; i < usefulDigits(); i++)
        {
            difference.bits[i] = XOR(XOR(bits[i], subtrahend.bits[i]), residue);
            residue = (!bits[i] && subtrahend.bits[i]) || (residue && !XOR(bits[i], subtrahend.bits[i]));
        }
        return difference;
    }

    bin operator* (bin multiplier)
    {
        bin product;
        if (product == multiplier)
            return product;
        else
            product = multiplier;
        for (int i = usefulDigits() - 2; i >= 0; i--)
        {
            product << 1;
            if (bits[i])
                product = product + multiplier;
        }
        return product;
    }

    bin operator% (bin divisor)
    {
        if (*this < divisor)
            return *this;

        int divisorLength = divisor.usefulDigits();
        int dividendLength = usefulDigits();

        bin remainder;
        for (int i = 0; i < divisorLength - 1; i++)
        {
            remainder.bits[i] = bits[dividendLength - divisorLength + 1 + i];
        }

        for (int i = dividendLength - divisorLength; i >= 0; i--)
        {
            for (int j = divisorLength; j > 0; j--)
                remainder.bits[j] = remainder.bits[j-1];
            remainder.bits[0] = bits[i];
            if (!(remainder < divisor))
                remainder = remainder - divisor;
        }
        return remainder;
    }

    bin operator/ (bin divisor)
    {
        int divisorLength = divisor.usefulDigits();
        int dividendLength = usefulDigits();

        bin quotient;

        bin remainder;
        for (int i = 0; i < divisorLength - 1; i++)
        {
            remainder.bits[i] = bits[dividendLength - divisorLength + 1 + i];
        }

        for (int i = dividendLength - divisorLength; i >= 0; i--)
        {
            for (int j = divisorLength; j > 0; j--)
                remainder.bits[j] = remainder.bits[j-1];
            remainder.bits[0] = bits[i];
            quotient.bits[i] = !(remainder < divisor);
            if (quotient.bits[i])
                remainder = remainder - divisor;
        }
        return quotient;
    }
};

bin int2bin(int n)
{
    bin r;
    int i=0;
    while(n>0)
    {
        r.bits[i++]=n%2;
        n/=2;
    }
    return r;
}
int bin2int(bin n)
{
    if (n.usefulDigits()>30)
        throw n.usefulDigits();
    int r=0;
    for(int i=n.usefulDigits();i>0;i--)
    {
        r*=2;
        if(n.bits[i-1])
            r++;
    }
    return r;
}

int digitSum(bin bigNumber)
{
    int sum = 0;
    bin base;
    base = int2bin(10);
    while (int2bin(0) < bigNumber)
    {
        sum += bin2int(bigNumber % base);
        bigNumber = bigNumber / base;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    bin factorial;
    factorial.bits[0] = true;
    for (int i = n; i > 1; i--)
    {
        factorial = factorial * int2bin(i);
    }
    cout << digitSum(factorial);
    return 0;
}
