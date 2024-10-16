#include "trie.h"

void findWordInSubStr(Trie &trie, int i, string doc, unordered_map<string, int> &foundWords)
{
    Node *curr = trie.root;
    int n = doc.length();
    int j = i;
    string str = "";
    while (j < n and curr != NULL)
    {
        char ch = doc[j];
        if (curr->m.count(ch) == 0)
        {
            return;
        }
        str.push_back(ch);
        curr = curr->m[ch];
        if (curr->end)
        {
            foundWords[str]++;
        }
        j++;
    }
}

vector<pair<string, string>> containsWords(string doc, vector<string> words)
{
    unordered_map<string, int> foundWords;
    Trie trie;
    vector<pair<string, string>> res;

    for (auto word : words)
    {
        trie.insert(word);
    }

    int n = doc.length();
    for (int i = 0; i < n; i++)
    {
        findWordInSubStr(trie, i, doc, foundWords);
    }

    for (auto word : words)
    {
        string ans = foundWords.count(word) != 0 ? "FOUND" : "NOT FOUND";
        res.push_back({word, ans});
    }

    return res;
}

int main()
{
    string doc = "little cute cat loves to code in c++,java & python";
    vector<string> words = {"cute cat", "ttle", "cat", "quick", "big", "little cute cat", "& python", "loves", "cute cat loves to code"};

    vector<pair<string, string>> res = containsWords(doc, words);
    cout << "================== Result ==================" << endl;
    for (auto p : res)
    {
        string word = p.first;
        string isFound = p.second;
        cout << word << " --> " << isFound << endl;
    }
    cout << endl;
}