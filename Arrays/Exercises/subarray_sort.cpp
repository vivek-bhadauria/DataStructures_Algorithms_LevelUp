#include <iostream>
#include <vector>
using namespace std;

/*
Time Complexity - O(N)
Space Complexity - O(1)
*/
vector<int> subArraySort(vector<int> a)
{

    vector<int> ans;
    int n = a.size();
    int lt = 0;
    int rt = a.size() - 1;
    int s = INT_MAX;
    int l = INT_MIN;
    if (n == 2)
    {
        if (a[0] < a[1])
        {
            ans.push_back(lt);
            ans.push_back(rt);
        }
        else
        {
            ans.push_back(0);
            ans.push_back(1);
        }
        return ans;
    }

    for (int i = 0; i < n; i++)
    {
        if (i < n - 1 and a[i] > a[i + 1])
        {
            l = max(l, a[i]);
        }
        else if (i > 0 and a[i] < a[i - 1])
        {
            s = min(s, a[i]);
        }
    }

    if (s == INT_MAX)
    {
        ans.push_back(lt);
        ans.push_back(rt);
        return ans;
    }

    for (int i = 0; i < n; i++)
    {
        int j = n - 1 - i;
        if (i < n - 1 and a[i] < s and s < a[i + 1])
        {
            lt = i + 1;
        }
        if (j > 0 and a[j - 1] < l and l < a[j])
        {
            rt = j - 1;
        }
    }

    ans.push_back(lt);
    ans.push_back(rt);
    return ans;
}

int main()
{

    vector<int> v = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};

    vector<int> r = subArraySort(v);

    for (auto x : r)
    {
        cout << x << ", ";
    }
    cout << endl;
}