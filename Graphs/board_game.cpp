#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "../Tries/trie.h"
using namespace std;

bool isPossible(vector<vector<char>> board, vector<vector<bool>> &visited, Node *root, int i, int j)
{
    int rows = board.size();
    int cols = board[0].size();

    if (i < 0 or i >= rows)
    {
        return false;
    }
    if (j < 0 or j > cols)
    {
        return false;
    }
    if (visited[i][j])
    {
        return false;
    }
    char ch = board[i][j];
    if (root == NULL or root->m.count(ch) == 0)
    {
        return false;
    }
    return true;
}

void solve(vector<vector<char>> board, vector<string> words, vector<vector<bool>> &visited, vector<vector<int>> &directions, unordered_set<string> &res, string out, Node *root, int i, int j)
{
    if (root == NULL or visited[i][j])
    {
        return;
    }
    if (root->end)
    {
        res.insert(out);
    }
    visited[i][j] = true;
    for (auto d : directions)
    {
        int nxt_i = i + d[0];
        int nxt_j = j + d[1];
        if (isPossible(board, visited, root, nxt_i, nxt_j))
        {
            char nxt_ch = board[nxt_i][nxt_j];
            solve(board, words, visited, directions, res, out + nxt_ch, root->m[nxt_ch], nxt_i, nxt_j);
        }
    }
    visited[i][j] = false;
}

unordered_set<string> solveBoard(vector<vector<char>> board, vector<string> words)
{
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    unordered_set<string> res;
    Trie trie;
    vector<vector<int>> directions = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

    for (auto word : words)
    {
        trie.insert(word);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            char ch = board[i][j];
            string s = "";
            if (trie.root->m.count(ch) != 0)
            {
                solve(board, words, visited, directions, res, s + ch, trie.root->m[ch], i, j);
            }
        }
    }
    return res;
}

int main()
{
    vector<string> words = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "SENS", "TUNES", "CAT"};
    vector<vector<char>> board = {{'S', 'E', 'R', 'T'},
                                  {'U', 'N', 'K', 'S'},
                                  {'T', 'C', 'A', 'T'}};
    unordered_set<string> res = solveBoard(board, words);
    cout << "Result : ";
    for (auto word : res)
    {
        cout << word << ", ";
    }
}