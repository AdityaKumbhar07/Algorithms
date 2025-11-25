#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int cross(Point A, Point B, Point P) {
    return (B.x - A.x)*(P.y- A.y)-(B.y- A.y)*(P.x - A.x);
}

void Quickhull(vector<Point>& pts, Point A, Point B, vector<Point> &hull) {
    int ind = -1, mdis = 0;

    for (int i = 0; i < pts.size();i++) {
        int side = cross(A,B,pts[i]);
        int dis = abs(cross(A,B,pts[i]));

        if (side > 0 && dis > mdis) {
            mdis = dis;
            ind = i;
        }
    }

    if (ind == -1) {
        hull.push_back(B);
        return;
    }

    Quickhull(pts, A, pts[ind], hull);
    Quickhull(pts, pts[ind], B, hull);
}

int main() {


    vector<Point> pts = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
            {0, 0}, {1, 2}, {3, 1}, {3, 3}
    };

    int mn = 0, mx = 0;

    for (int i = 0; i < pts.size();i++) {
        if (pts[i].x < pts[mn].x) mn = i;
        if (pts[i].x > pts[mx].x) mx = i;
    }

    vector<Point> hull;

    Quickhull(pts,pts[mn],pts[mx],hull);
    Quickhull(pts,pts[mx],pts[mn],hull);

    for (auto p : hull) {
        cout<<"("<<p.x<<","<<p.y<<") ";
    }
    return 0;

}