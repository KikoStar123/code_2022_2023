/*
 * @Author: KIKOSTAR 842544563@outlook.com
 * @Date: 2023-03-28 21:57:04
 * @LastEditors: KIKOSTAR 842544563@outlook.com
 * @LastEditTime: 2023-03-28 21:57:13
 * @FilePath: \CODE\C++(3)\Graham.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

// 计算两点之间距离的平方
int dist2(Point &a, Point &b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

// 计算叉积
int cross(Point &a, Point &b, Point &c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// 比较两点之间的极角
bool cmp(Point &a, Point &b)
{
    int c = cross(p0, a, b);
    if (c == 0)
    {
        return dist2(p0, a) < dist2(p0, b);
    }
    return c > 0;
}

// 寻找最下方的点
int findBottomMostPoint(vector<Point> &points)
{
    int idx = 0;
    for (int i = 1; i < points.size(); i++)
    {
        if (points[i].y < points[idx].y)
        {
            idx = i;
        }
    }
    return idx;
}

// Graham扫描法实现
vector<Point> grahamScan(vector<Point> &points)
{
    int n = points.size();
    if (n < 3)
    {
        return points;
    }

    // 找到最下方的点
    int idx = findBottomMostPoint(points);
    swap(points[0], points[idx]);
    p0 = points[0];

    // 将其他点按照极角排序
    sort(points.begin() + 1, points.end(), cmp);

    // 构建凸包
    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    for (int i = 2; i < n; i++)
    {
        while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0)
        {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    return hull;
}

int main()
{
    vector<Point> points = {{0, 0}, {0, 1}, {1, 1}, {1, 0}, {0.5, 0.5}};
    vector<Point> hull = grahamScan(points);

    // 输出凸包上的所有点
    for (Point &p : hull)
    {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }
    return 0;
}