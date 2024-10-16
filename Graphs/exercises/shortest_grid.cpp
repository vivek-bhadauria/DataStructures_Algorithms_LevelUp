#include <iostream>
#include <vector>
#include <set>
using namespace std;

int minCostWithDijkstraAlgo(vector<vector<int>> grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
    set<vector<int>> s; /* each vector means - {distance, i, j} */

    dist[0][0] = grid[0][0];
    s.insert({dist[0][0], 0, 0});

    while (!s.empty())
    {
        auto curr = s.begin();
        vector<int> v = *curr;
        int currDist = v[0];
        int currRow = v[1];
        int currCol = v[2];
        s.erase(curr);

        vector<vector<int>> directions = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

        for (auto d : directions)
        {
            int nxt_i = currRow + d[0];
            int nxt_j = currCol + d[1];
            if (nxt_i >= 0 and nxt_i < rows and nxt_j >= 0 and nxt_j < cols)
            {
                int newDist = currDist + grid[nxt_i][nxt_j];
                if (newDist < dist[nxt_i][nxt_j])
                {
                    /* update or insert entry into set for new Distance */
                    auto found = s.find({dist[nxt_i][nxt_j], nxt_i, nxt_j});
                    if (found != s.end())
                    {
                        s.erase(found);
                    }
                    dist[nxt_i][nxt_j] = newDist;
                    s.insert({dist[nxt_i][nxt_j], nxt_i, nxt_j});
                }
            }
        }
    }

    return dist[rows - 1][cols - 1];
}

int minCost(vector<vector<int>> &grid, vector<vector<int>> &directions, vector<vector<bool>> &visited, int i, int j)
{
    int rows = grid.size();
    int cols = grid[0].size();
    if (i == rows - 1 and j == cols - 1)
    {
        return grid[i][j];
    }
    visited[i][j] = true;
    int cost = INT_MAX;
    for (auto d : directions)
    {
        int nxt_i = i + d[0];
        int nxt_j = j + d[1];
        if (nxt_i >= 0 and nxt_i < rows and nxt_j >= 0 and nxt_j < cols and !visited[nxt_i][nxt_j])
        {
            int currCost = minCost(grid, directions, visited, nxt_i, nxt_j);
            if (currCost != INT_MAX)
            {
                cost = min(cost, currCost);
            }
        }
    }
    visited[i][j] = false;

    return cost == INT_MAX ? INT_MAX : grid[i][j] + cost;
}

int shortest_path(vector<vector<int>> grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> directions = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int res = minCost(grid, directions, visited, 0, 0);
    return res;
}

int main()
{
    vector<vector<int>> grid = {{31, 100, 65, 12, 18},
                                {10, 13, 47, 157, 6},
                                {100, 113, 174, 11, 33},
                                {88, 124, 41, 20, 140},
                                {99, 32, 111, 41, 20}};

    int res = minCostWithDijkstraAlgo(grid);
    cout << "Result : " << res << endl;
    int res2 = shortest_path(grid);
    cout << "Result2 : " << res2 << endl;
}