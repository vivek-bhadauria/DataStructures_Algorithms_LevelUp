#include "../trie.h"

string getBinaryConversion(int num)
{
    string bnary;
    int i = 30;
    while (i >= 0)
    {
        char curBit;
        int bit = (num >> i) & 1;
        if (bit)
        {
            curBit = '1';
        }
        else
        {
            curBit = '0';
        }
        bnary.push_back(curBit);
        i--;
    }
    return bnary;
}

int maxXor(vector<int> v)
{

    Trie trie;

    /* Step 1: Insert binary representation of each in trie - O(n * k), k being 32 bits in integer */
    for (auto num : v)
    {
        string bnary = getBinaryConversion(num); /* O(k)*/
        trie.insert(bnary);
    }

    /* Step 2: Calculation of max xor - O(k)*/
    int mxXor = 0;
    Node *first = trie.root;
    Node *second = trie.root;

    while (!first->end)
    {
        mxXor = mxXor << 1;
        if (first->m.count('1') != 0 and second->m.count('0') != 0)
        {
            mxXor = mxXor | 1;
            first = first->m['1'];
            second = second->m['0'];
        }
        else if (first->m.count('0') != 0 and second->m.count('1') != 0)
        {
            mxXor = mxXor | 1;
            first = first->m['0'];
            second = second->m['1'];
        }
        else if (first->m.count('1') != 0)
        {
            first = first->m['1'];
            second = second->m['1'];
        }
        else
        {
            first = first->m['0'];
            second = second->m['0'];
        }
    }

    return mxXor;
}

int main()
{

    vector<int> v = {3, 10, 5, 8, 2, 25};
    int res = maxXor(v);
    cout << "Result = " << res;
}