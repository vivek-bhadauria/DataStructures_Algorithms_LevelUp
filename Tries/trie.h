#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Node
{
public:
    char data;
    bool end;
    unordered_map<char, Node *> m;

    Node(char ch)
    {
        data = ch;
        end = false;
    }
};

class Trie
{
    void prepareWords(Node *root, vector<string> &words, string curr)
    {
        if (root->end)
        {
            words.push_back(curr);
        }
        for (auto p : root->m)
        {
            char ch = p.first;
            Node *next = p.second;
            prepareWords(next, words, curr + ch);
        }
    }

public:
    Node *root;

    Trie()
    {
        root = new Node('\0');
    }

    void insert(string str)
    {
        Node *curr = root;
        int i = 0;
        int n = str.length();
        while (i < n)
        {
            char ch = str[i];
            if (curr->m.find(str[i]) == curr->m.end())
            {
                curr->m[ch] = new Node(ch);
            }
            curr = curr->m[ch];
            i++;
        }
        curr->end = true;
    }

    vector<string> getAllWords()
    {
        vector<string> words;
        for (auto p : root->m)
        {
            string currStr;
            char ch = p.first;
            Node *curr = p.second;
            currStr.push_back(ch);
            prepareWords(curr, words, currStr);
        }
        return words;
    }

    vector<string> searchWords(string prefix)
    {
        Node *curr = root;
        int i = 0;
        vector<string> words;
        while (curr != NULL and prefix[i] != '\0')
        {
            char ch = prefix[i];
            curr = curr->m[ch];
            i++;
        }
        if (curr == NULL)
        {
            return words;
        }
        prepareWords(curr, words, prefix);
        return words;
    }

    bool search(string str)
    {
        Node *curr = root;
        int i = 0;
        while (curr != NULL and str[i] != '\0')
        {
            char ch = str[i];
            curr = curr->m[ch];
            i++;
        }
        return curr != NULL and curr->end;
    }
};


class SuffixTrie{
    Trie trie;
    public:
        void insertSuffixes(string word){
            int n= word.length();
            for(int i=0; i<n; i++){
                trie.insert(word.substr(i, n - i));
            }
        }

        void printSuffixes(){
            vector<string> suffixes = trie.getAllWords();
            for(auto str : suffixes){
                cout<<str<<", ";
            }
            cout<<endl;
        }

        bool search(string suffix){
            return trie.search(suffix);
        }
};