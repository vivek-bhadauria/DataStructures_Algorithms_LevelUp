#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isValid(vector<vector<int>> &grid, const int &nxt_i, const int &nxt_j, const int &rows, const int &cols)
{
    return nxt_i >= 0 and nxt_i < rows and nxt_j >= 0 and nxt_j < cols and grid[nxt_i][nxt_j] == 1;
}

int bfs(vector<vector<int>> &directions, vector<vector<int>> &grid, int i, int j, const int &rows, const int &cols)
{
    queue<pair<int, int>> q;

    q.push({i, j});
    grid[i][j] = 0; /* mark as visited */
    int area = 1;

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        int currRow = curr.first;
        int currCol = curr.second;
        q.pop();

        for (auto d : directions)
        {
            int nxtRow = currRow + d[0];
            int nxtCol = currCol + d[1];

            if (isValid(grid, nxtRow, nxtCol, rows, cols))
            {
                q.push({nxtRow, nxtCol});
                grid[nxtRow][nxtCol] = 0;
                area++;
            }
        }
    }
    return area;
}

int dfs(vector<vector<int>> &directions, vector<vector<int>> &grid, int i, int j, const int &rows, const int &cols)
{
    grid[i][j] = 0; /* mark as visited */
    int sumArea = 1;

    for (auto d : directions)
    {
        int nxt_i = i + d[0];
        int nxt_j = j + d[1];
        if (isValid(grid, nxt_i, nxt_j, rows, cols))
        {
            int area = dfs(directions, grid, nxt_i, nxt_j, rows, cols);
            sumArea += area;
        }
    }
    return sumArea;
}

int largest_island(vector<vector<int>> grid)
{
    vector<vector<int>> directions = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    int rows = grid.size();
    int cols = grid[0].size();
    int maxArea = INT_MIN;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 1)
            {
                // int area = bfs(directions, grid, i, j, rows, cols);
                int area = dfs(directions, grid, i, j, rows, cols);
                maxArea = max(maxArea, area);
            }
        }
    }
    return maxArea == INT_MIN ? 0 : maxArea;
}

int main()
{
    vector<vector<int>> grid = {{1, 0, 0, 1, 0},
                                {1, 0, 1, 0, 0},
                                {0, 0, 1, 0, 1},
                                {1, 0, 1, 1, 1},
                                {1, 0, 1, 1, 0}};

    int res = largest_island(grid);
    cout << "Result : " << res;
}