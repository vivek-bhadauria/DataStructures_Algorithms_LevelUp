#include "trie.h"

void applyQueries()
{
    Trie trie;
    cout<<"============ PREFIX TREE ============"<<endl;
    vector<string> words = {"apple", "ape", "mango", "news", "no", "man", "newcastle", "norway"};
    vector<string> queries = {"apple", "banana", "new", "mango"};

    for (auto word : words)
    {
        trie.insert(word);
    }

    cout << "Words in trie : ";
    for (auto word : trie.getAllWords())
    {
        cout << word << ", ";
    }
    cout << endl;

    cout << "Query Results: ";
    for (auto query : queries)
    {
        bool found = trie.search(query);
        string ans = found ? "YES" : "NO";
        cout << ans << " ";
    }
    cout << endl;

    string prefix;
    getline(cin, prefix);
    cout << "Words matching - " << prefix << " : ";
    for (auto word : trie.searchWords(prefix))
    {
        cout << word << ", ";
    }
    cout << endl;
}

void testSuffixTree(){

    SuffixTrie suffixTrie;
    cout<<"============ SUFFIX TREE ============"<<endl;
    suffixTrie.insertSuffixes("hello");
    bool found = suffixTrie.search("llo");
    string ans = found ? "YES" : "NO";
    cout<<"Found - llo ? "<<ans<<endl;
    cout<<"Words in suffix trie : ";
    suffixTrie.printSuffixes();
}

int main()
{
    applyQueries();
    testSuffixTree();
}