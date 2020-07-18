// Reference: https://www.tutorialspoint.com/Graham-Scan-Algorithm
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <utility>
using namespace std;

struct point {
	int x, y;
};
point p0;

int direction(point a, point b, point c) {
	int val = (b.y - a.y)*(c.x - b.x) - (b.x - a.x)*(c.y - b.y);
	return val == 0 ? 0 : (val < 0 ? 2 : 1); // 0: colinear, 1: clockwise, 2: anti-clockwise
}

double squared_dist(point p1, point p2) {
	return (pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

bool comparator(point p1, point p2) {
	int dir = direction(p0, p1, p2);
	if (dir == 0)
		return squared_dist(p0, p2) < squared_dist(p0, p1);
	return dir != 2;
}

point second_top(stack<point> &stack) {
	point top = stack.top(); stack.pop();
	point second = stack.top();
	stack.push(top);
	return second;
}

void graham_scan(vector<point> &points, int n) {
	int min_y = points[0].y;
	int min = 0;

	for (int i = 1; i < n; i++) {
		int y = points[i].y;

		// find bottom most or left most point
		if (y < min_y || y == min_y && points[i].x < points[min].x) {
			min_y = points[i].y;
			min = i;
		}
	}

	swap(points[0], points[min]);
	p0 = points[0];
	sort(points.begin(), points.end(), comparator);
	p0 = points[0];

	stack<point> stack;
	stack.push(points[0]);
	stack.push(points[1]);

	for (int i = 2; i < n; i++) {
		while (stack.size() > 1 && direction(second_top(stack), stack.top(), points[i]) != 1)
			stack.pop();
		stack.push(points[i]);
	}

	cout << stack.size() << endl;
	while (!stack.empty()) {
		point vertex = stack.top();
		cout << vertex.x << " " << vertex.y << endl;
		stack.pop();
	}
}

int main() {
	int n, x, y;
	cin >> n;
	while (n != 0) {

		/* 
			unordered_set cannot hash object by default, unless you write your own hash or include some libraries
			I'm lazy to look it up, so just gonna write like this then
			you may wanna do something like set<point>
		*/
		unordered_map<int, unordered_set<int>> um;
		vector<point> points;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			if (um.find(x) == um.end())
				um[x] = unordered_set<int>{ y };
			else
				um[x].insert(y);
		}

		for (pair<int, unordered_set<int>> p : um)
		{
			for (int y : p.second)
				points.push_back(point{ p.first, y });
		}

		if (points.size() > 2)
			graham_scan(points, points.size());
		else {
			cout << points.size() << endl;
			for (point p : points)
				cout << p.x << " " << p.y << endl;
		}

		cin >> n;
	}
	
	return 0;
}