#include "../trie.h"

int countOf(Node *root, string str, int s, int e)
{
    Node *curr = root;
    if (s > e)
    {
        return 0;
    }
    for (int j = s; j <= e; j++)
    {
        char ch = str[j];
        if (curr->m.count(ch) == 0)
        {
            return -1;
        }
        curr = curr->m[ch];
        if (curr != NULL and curr->end)
        {
            int c1 = countOf(root, str, j + 1, e);
            if (c1 != -1)
            {
                return 1 + c1;
            }
        }
    }
    return -1;
}

vector<string> googlyStrings(vector<string> input)
{
    Trie trie;
    vector<string> res;

    for (auto str : input)
    {
        trie.insert(str);
    }

    for (auto str : input)
    {
        int k = 2;
        int n = str.length();
        int c = countOf(trie.root, str, 0, n - 1);
        if (c >= k)
        {
            res.push_back(str);
        }
    }

    return res;
}

int main()
{

    vector<string> v = {"goo", "gle", "google", "le", "googly", "ly", "g", "googoole"};
    vector<string> res = googlyStrings(v);
    cout << "Result : ";
    for (auto str : res)
    {
        cout << str << ", ";
    }
}