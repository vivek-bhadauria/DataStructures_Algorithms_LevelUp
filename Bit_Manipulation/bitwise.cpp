#include <iostream>
#include <string>
using namespace std;

bool isOdd(int n)
{
    return n & 1;
}

int getIthBit(int n, int i)
{
    return (n >> i) & 1;
}

void setIthBit(int &n, int i)
{
    n = n | (1 << i);
}

void clearIthBit(int &n, int i)
{
    n = n & ~(1 << i);
}

void updateIthBit(int &n, int i, int bit)
{
    clearIthBit(n, i);
    if (bit)
    {
        setIthBit(n, i);
    }
}

void clearIBits(int &n, int i)
{
    n = n & (~0 << i);
}

void replaceBits(int &n, int i, int j, int bits)
{
    int mask1 = ~0 << (j + 1);
    int mask2 = ~(~0 << i);
    n = n & (mask1 | mask2) | (bits << i);
}

int twoRaisedToPower(int n)
{
    return 1 << n;
}

int countBits(int n)
{
    int c = 0;
    while (n != 0)
    {
        c += n & 1;
        n = n >> 1;
    }
    return c;
}

int fastCountBits(int n)
{
    int c = 0;
    while (n != 0)
    {
        c++;
        n = n & (n - 1);
    }
    return c;
}

int fastPower(int n, int m)
{

    if (m == 0)
    {
        return 1;
    }
    int x = fastPower(n, m >> 1);
    int r = x * x;
    if (m & 1)
    {
        return n * r;
    }
    return r;
}

int fastPowerIterative(int n, int m)
{
    int p = n;
    int k = m;
    if (k == 0)
    {
        return 1;
    }
    if (k == 1)
    {
        return n;
    }
    while (k != 1)
    {
        p *= p;
        k = k >> 1;
    }
    return m & 1 ? n * p : p;
}

int decimalToBinary(int n)
{

    int p = 1;
    int r = 0;
    while (n != 0)
    {
        r += (n % 2) * p;
        n /= 2;
        p *= 10;
    }
    return r;
}

int binaryToDecimal(int n)
{
    int r = 0;
    int p = 1;
    while (n != 0)
    {
        r += n % (10) * p;
        n /= 10;
        p *= 2;
    }
    return r;
}

int convertBetweenDecimalBinary(int n, int from, int to)
{
    int p = 1;
    int r = 0;
    while (n != 0)
    {
        r += (n % to) * p;
        n /= to;
        p *= from;
    }
    return r;
}

bool isTwoPower(int n)
{
    return n & (n - 1) ? false : true;
}

int main()
{

    int n = 24; // 11000
    string evenOdd = isOdd(n) ? "Odd" : "Even";
    cout << n << " is " << evenOdd << endl;
    int i;
    cin >> i;
    cout << i << "th bit in " << n << " : " << getIthBit(n, i) << endl;
    setIthBit(n, i);
    cout << i << "th bit set and n --> " << n << endl;
    clearIthBit(n, i);
    cout << i << "th bit cleared and n --> " << n << endl;
    updateIthBit(n, i, 0);
    cout << i << "th bit updated to 0 and n --> " << n << endl;
    updateIthBit(n, i, 1);
    cout << i << "th bit updated to 1 and n --> " << n << endl;
    n = 31;
    clearIBits(n, i);
    cout << i << " bits cleared and n --> " << n << endl;
    int n1 = 97;
    replaceBits(n1, 1, 3, 5);
    cout << "replace 1 to 3 bits with 5 and n1 --> " << n1 << endl;
    n1 = 97; // 1100001
    replaceBits(n1, 2, 4, 5);
    cout << "replace 2 to 4 bits with 5 n1 --> " << n1 << endl;
    cout << "Two to the power 7 : " << twoRaisedToPower(7) << endl;
    int n2;
    cin >> n2;
    cout << n2 << " bits count : " << countBits(n2) << endl;
    cout << n2 << " fast bits count : " << fastCountBits(n2) << endl;
    cout << "3^9 with fast power : " << fastPower(3, 9) << endl;
    cout << "3^8 with fast power : " << fastPower(3, 8) << endl;
    cout << "3^9 with fast power iterative : " << fastPowerIterative(3, 9) << endl;
    cout << "3^8 with fast power iterative : " << fastPowerIterative(3, 8) << endl;
    cout << n2 << " --> " << decimalToBinary(n2) << " --> " << binaryToDecimal(decimalToBinary(n2)) << endl;
    cout << "with common conversion code : " << n2 << " --> " << convertBetweenDecimalBinary(n2, 10, 2) << " --> " << convertBetweenDecimalBinary(convertBetweenDecimalBinary(n2, 10, 2), 2, 10) << endl;
    string twoPower = isTwoPower(n2) ? "YES" : "NO";
    cout << n2 << " is power of 2 ? " << twoPower << endl;
}