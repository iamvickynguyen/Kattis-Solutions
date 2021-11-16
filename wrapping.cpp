#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef priority_queue<int, vector<int>, greater<int>> minpq;
typedef unordered_set<int> usi;
typedef unordered_map<int, vi> ivi;
typedef unordered_map<int, int> ii;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define PI 3.14159265359

double EPS = 0.000000000001;

struct point {
    double x, y;
};

point p0;
vector<point> points;

int cmp(double n) {
	if (n < -EPS) return -1;
	if (n > EPS) return 1;
	return 0;
}

int direction(point a, point b, point c) {
    int val = cmp((b.y - a.y)*(c.x - b.x) - (b.x - a.x)*(c.y - b.y));
    return val == 0 ? 0 : (val < 0 ? 2 : 1); // 0: colinear, 1: clockwise, 2: anti-clockwise
}

double squared_dist(point p1, point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool comparator(point p1, point p2) {
    int dir = direction(p0, p1, p2);
    if (dir == 0)
        return squared_dist(p0, p2) < squared_dist(p0, p1);
    return dir != 2;
}

point second_top(vector<point> &stack) {
    return stack[stack.size() - 2];
}

vector<point> graham_scan(int n) {
    double min_y = points[0].y;
    double min = 0.0;

    for (int i = 1; i < n; i++) {
        double y = points[i].y;

        // find bottom most or left most point
        if (y < min_y || cmp(y - min_y) == 0 && points[i].x < points[min].x) {
            min_y = points[i].y;
            min = i;
        }
    }

    swap(points[0], points[min]);
    p0 = points[0];
    sort(points.begin(), points.end(), comparator);
    p0 = points[0];

    vector<point> stack;
    stack.pb(points[0]);
    stack.pb(points[1]);

    for (int i = 2; i < n; i++) {
        while (stack.size() > 1 && direction(second_top(stack), stack.back(), points[i]) != 1)
            stack.pop_back();
        stack.pb(points[i]);
    }

    return stack;
}

double cosine(double t){
	return cos (t * PI / 180.0);
}

double sine(double t) {
	return sin (t * PI/180.0);
}

point rotate(double x, double y, double v) {
	double mycos = cosine(-v);
	double mysin = sine(-v);
	return point{mycos*x - mysin*y, mysin*x + mycos*y};
}

vector<point> to_points(double x, double y, double w, double h, double v) {
    point p1 = rotate(-w/2, h/2, v),
        p2 = rotate(w/2, h/2, v),
        p3 = rotate(-w/2, -h/2, v),
        p4 = rotate(w/2, -h/2, v);

    return {point{p2.x + x, p2.y + y}, point{p1.x + x, p1.y + y}, point{p4.x + x, p4.y + y}, point{p3.x + x, p3.y + y}};
}

double convex_hull_area(vector<point> &hull) {
    int n = hull.size();
	double area = 0.0;
	for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (hull[i].x * hull[j].y - hull[j].x * hull[i].y);
    }
	return abs(area)/2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
	double x, y, w, h, v;
	cin >> t;
	while (t--) {
		cin >> n;
		points.clear();
		double board_area = 0.0;
		for (int i = 0 ; i < n; i++) {
			cin >> x >> y >> w >> h >> v;
			board_area += w * h;
			vector<point> ps = to_points(x, y, w, h, v);
			for (auto &p : ps) points.pb(p);
		}

        vector<point> hull = graham_scan(points.size());
        double area = convex_hull_area(hull);

        cout << fixed;
        cout << setprecision(1);
        cout << board_area/area * 100 << " %" << '\n';
    }

    return 0;
}