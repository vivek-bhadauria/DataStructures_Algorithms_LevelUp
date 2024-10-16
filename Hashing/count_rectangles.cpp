#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Point
{
public:
    int x;
    int y;

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

class PointCompare
{
public:
    bool operator()(Point p1, Point p2) const
    {
        return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
    }
};

void printRect(vector<vector<int>> curr_rect)
{
    for (auto pt : curr_rect)
    {
        cout << "(" << pt[0] << ", " << pt[1] << "), ";
    }
    cout << endl;
}

/*
Rectangle will have 4 points as follows
  p1(x,y)
  p2(x,y) = >p1.x, =p1.y
  p3(x,y) = =p1.x, >p1.y
  p4(x,y) = =p2.x, =p3.y
*/
int countRectanglesBruteForce(vector<vector<int>> v)
{
    int n = v.size();
    int ctr = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> p1 = v[i];
        for (int j = 0; j < n; j++)
        {
            if (v[j][1] == p1[1] and v[j][0] > p1[0])
            {
                vector<int> p2 = v[j];
                for (int k = 0; k < n; k++)
                {
                    if (v[k][0] == p1[0] and v[k][1] > p1[1])
                    {
                        vector<int> p3 = v[k];
                        for (int l = 0; l < n; l++)
                        {
                            if (v[l][0] == p2[0] and v[l][1] == p3[1])
                            {
                                vector<int> p4 = v[l];
                                vector<vector<int>> curr_rect;
                                curr_rect.push_back(p1);
                                curr_rect.push_back(p2);
                                curr_rect.push_back(p3);
                                curr_rect.push_back(p4);
                                printRect(curr_rect);
                                ctr++;
                            }
                        }
                    }
                }
            }
        }
    }
    return ctr;
}

vector<Point> getPoints(vector<vector<int>> v)
{
    vector<Point> pv;

    for (auto pt : v)
    {
        Point p(pt[0], pt[1]);
        pv.push_back(p);
    }
    return pv;
}

/*
Intuition:
Suppose we choose two points P1(x1,y1) and P3(x2,y2) along diagonals
then other two points will be P2(x2,y1) and P4(x1,y2) which if present in set then we found a rectangle
*/
int countRectanglesOptimized(vector<Point> v)
{

    set<Point, PointCompare> s;
    int n = v.size();
    int ctr = 0;

    for (auto p : v)
    {
        s.insert(p);
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            Point p1 = v[i];
            Point p3 = v[j];
            if (p1.x != p3.x and p1.y != p3.y)
            {
                Point p2(p3.x, p1.y);
                Point p4(p1.x, p3.y);

                if (s.find(p2) != s.end() and s.find(p4) != s.end())
                {
                    ctr++;
                }
            }
        }
    }
    return ctr / 2; /* as each rectangle is counted twice */
}

int main()
{

    vector<vector<int>> v = {{0, 0}, {0, 1}, {1, 1}, {1, 0}, {2, 1}, {2, 0}, {3, 1}, {3, 0}};
    int res = countRectanglesBruteForce(v);
    cout << "Count of Rectangles Brute Force : " << res << endl;
    int res2 = countRectanglesOptimized(getPoints(v));
    cout << "Count of Rectangles Optimized : " << res2 << endl;
}