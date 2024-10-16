#include "../trie.h"
#include <unordered_set>

void findMatches(Node *root, string phn, int s, int e, unordered_map<char, string> keymap, unordered_set<string> &res, string out)
{

    if (s > e or root == NULL)
    {
        return;
    }
    char num = phn[s];
    for (char ch : keymap[num])
    {
        if (root->m.count(ch) != 0)
        {
            Node *curr = root->m[ch];
            if (curr->end)
            {
                res.insert(out + ch);
            }
            findMatches(root->m[ch], phn, s + 1, e, keymap, res, out + ch);
        }
    }
    return;
}

vector<string> filterNames(string phoneNumber, vector<string> words)
{

    Trie trie;
    unordered_set<string> res;
    vector<string> ans;
    unordered_map<char, string> keymap = {{'0', ""},
                                          {'1', ""},
                                          {'2', "abc"},
                                          {'3', "def"},
                                          {'4', "ghi"},
                                          {'5', "jkl"},
                                          {'6', "mno"},
                                          {'7', "pqrs"},
                                          {'8', "tuv"},
                                          {'9', "wxyz"}};

    for (auto str : words)
    {
        trie.insert(str);
    }

    int n = phoneNumber.length();
    for (int i = 0; i < n; i++)
    {
        findMatches(trie.root, phoneNumber, i, n - 1, keymap, res, "");
    }

    for (auto str : res)
    {
        ans.push_back(str);
    }

    return ans;
}

int main()
{
    string phoneNumber = "7728335";
    vector<string> words = {"prat", "prateek", "codingminutes", "code", "prat335", "teek"};
    vector<string> res = filterNames(phoneNumber, words);
    cout << "Result : ";
    for (auto str : res)
    {
        cout << str << ", ";
    }
}