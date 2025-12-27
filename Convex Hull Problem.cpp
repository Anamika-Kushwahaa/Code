//CONVEX HULL PROBLEM

#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

// Cross product of OA and OB vectors
long long cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y - O.y)
         - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convexHull(vector<Point> &pts) {
    int n = pts.size();
    if (n <= 1) return pts;

    // Sort points by x, then y
    sort(pts.begin(), pts.end(), [](Point a, Point b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    vector<Point> hull;

    // Lower hull
    for (auto &p : pts) {
        while (hull.size() >= 2 &&
               cross(hull[hull.size()-2], hull.back(), p) <= 0)
            hull.pop_back();
        hull.push_back(p);
    }

    // Upper hull
    int lowerSize = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        while ((int)hull.size() > lowerSize &&
               cross(hull[hull.size()-2], hull.back(), pts[i]) <= 0)
            hull.pop_back();
        hull.push_back(pts[i]);
    }

    hull.pop_back(); // last point is same as first
    return hull;
}

int main() {
    vector<Point> points = {
        {0, 3}, {2, 2}, {1, 1}, {2, 1},
        {3, 0}, {0, 0}, {3, 3}
    };

    vector<Point> hull = convexHull(points);

    cout << "Convex Hull Points:\n";
    for (auto &p : hull)
        cout << "(" << p.x << ", " << p.y << ")\n";

    return 0;
}


//OUTPUT
// Convex Hull Points:
// (0, 0)
// (3, 0)
// (3, 3)
// (0, 3)
