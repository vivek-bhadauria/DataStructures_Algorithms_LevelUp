#include <iostream>
#include <vector>
using namespace std;

int findLongestPath(vector<vector<int>> &matrix, vector<vector<int>> directions, vector<vector<bool>> &visited, vector<vector<int>> &dp, int i, int j, const int &rows, const int &cols)
{
    visited[i][j] = true;
    int maxLength = INT_MIN;

    for (auto d : directions)
    {
        int nxt_i = i + d[0];
        int nxt_j = j + d[1];
        if (nxt_i >= 0 and nxt_i < rows and nxt_j >= 0 and nxt_j < cols and matrix[nxt_i][nxt_j] > matrix[i][j])
        {
            if (!visited[nxt_i][nxt_j])
            {
                int currLength = findLongestPath(matrix, directions, visited, dp, nxt_i, nxt_j, rows, cols);
                maxLength = max(maxLength, currLength);
            }
            else
            {
                maxLength = max(maxLength, dp[nxt_i][nxt_j]);
            }
        }
    }
    dp[i][j] = maxLength == INT_MIN ? 1 : 1 + maxLength;
    return dp[i][j];
}

int longestPathSequence(vector<vector<int>> matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<int>> dp(rows, vector<int>(cols, INT_MIN));
    vector<vector<int>> directions = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    int maxLength = INT_MIN;
    cout << "Cache : " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int currLength = dp[i][j];
            if (!visited[i][j])
            {
                currLength = findLongestPath(matrix, directions, visited, dp, i, j, rows, cols);
            }
            cout << dp[i][j] << " ";
            maxLength = max(maxLength, currLength);
        }
        cout << endl;
    }
    return maxLength;
}

int main()
{

    vector<vector<int>> matrix = {{0, 2, 4, 3, 2},
                                  {7, 6, 5, 5, 1},
                                  {8, 9, 7, 18, 14},
                                  {5, 10, 11, 12, 13}};
    int res = longestPathSequence(matrix);
    cout << "Result : " << res;
}