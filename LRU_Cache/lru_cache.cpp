#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Node
{
public:
    string key;
    int value;

    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class LRUCache
{
    void addNewNodeToQueueEndAndMap(string key, int value)
    {
        Node node(key, value);
        q.push_back(node);
        auto endItr = q.end();
        m[key] = --endItr;
    }

public:
    int maxSize;
    unordered_map<string, list<Node>::iterator> m;
    list<Node> q;

    LRUCache(int maxSize)
    {
        this->maxSize = max(maxSize, 2);
    }

    void insert(string key, int value)
    {

        if (m.count(key) == 0)
        {
            /* case for insert */
            if (q.size() < maxSize)
            {
                addNewNodeToQueueEndAndMap(key, value);
            }
            else
            {
                /* remove least recent pair from list and map */
                auto startItr = q.begin();
                string leastRecentKey = startItr->key;
                q.pop_front();
                m.erase(leastRecentKey);
                addNewNodeToQueueEndAndMap(key, value);
            }
        }
        else
        {
            /* case for update : remove node from its current position and create and add new node to end of queue */
            auto nodeItr = m[key];
            q.erase(nodeItr);
            addNewNodeToQueueEndAndMap(key, value);
        }
    }

    int get(string key)
    {
        if (m.count(key) == 0)
        {
            return -1;
        }
        /*  remove node from its current position and create and add new node to end of queue */
        auto nodeItr = m[key];
        int value = nodeItr->value;
        q.erase(nodeItr);
        addNewNodeToQueueEndAndMap(key, value);
        return value;
    }

    int remove(string key)
    {
        if (m.count(key) == 0)
        {
            return -1;
        }
        /* remove pair from list and map */
        auto nodeItr = m[key];
        int value = nodeItr->value;
        q.erase(nodeItr);
        m.erase(key);
        return value;
    }

    pair<string, int> getMostRecent()
    {
        if (q.empty())
        {
            return {"", -1};
        }
        auto endItr = q.end();
        endItr--;
        return {endItr->key, endItr->value};
    }

    pair<string, int> getLeastRecent()
    {
        if (q.empty())
        {
            return {"", -1};
        }
        auto startItr = q.begin();
        return {startItr->key, startItr->value};
    }

    void print()
    {
        for (auto itr = q.begin(); itr != q.end(); itr++)
        {
            cout << "{" << itr->key << ", " << itr->value << "} ";
        }
        cout << endl;
    }
};

int main()
{
    LRUCache cache(5);

    cache.insert("Mango", 10);
    cache.insert("Apple", 20);
    cache.insert("Pear", 30);
    cache.insert("Guava", 40);
    cache.insert("Papaya", 50);
    cache.insert("Berry", 60);

    cache.print();

    auto recent = cache.getMostRecent();
    cout << "Most recent : {" << recent.first << ", " << recent.second << "}" << endl;

    auto oldest = cache.getLeastRecent();
    cout << "Least recent : {" << oldest.first << ", " << oldest.second << "}" << endl;

    int val = cache.get("Mango");
    if (val == -1)
    {
        cout << "Mango does not exist" << endl;
    }
    else
    {
        cout << "Mango value : " << val << endl;
    }

    cache.print();

    val = cache.get("Guava");
    if (val == -1)
    {
        cout << "Guava does not exist" << endl;
    }
    else
    {
        cout << "Guava value : " << val << endl;
    }

    cache.print();

    cout << "Updating Papaya" << endl;
    cache.insert("Papaya", 100);

    cache.print();

    cout << "Inserting Orange" << endl;
    cache.insert("Orange", 90);

    cache.print();
}