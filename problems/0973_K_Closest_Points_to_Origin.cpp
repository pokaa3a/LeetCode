#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
/*
struct comp {
	bool operator() (const vector<int>& a, const vector<int>& b) {
		return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]); 
	}
};
class Solution {
public:
	vector<vector<int> > kClosest(vector<vector<int> > &points, int k) {
		priority_queue<vector<int>, vector<vector<int> >, comp> q;

		for (int i = 0; i < points.size(); ++i) {
			q.push(points[i]);
			if (q.size() > k) {
				q.pop();
			}
		}

		vector<vector<int> > ans;
		while (!q.empty()) {
			ans.push_back(q.top());
			q.pop();
		}
		return ans;
	}
};
*/
class Solution {
public:
	vector<vector<int> > kClosest(vector<vector<int> > &points, int K) {
		int ref = points[0][0] * points[0][0] + points[0][1] * points[0][1];

		vector<vector<int>> left, mid, right;
		for (auto p : points)
		{
			int dist = p[0] * p[0] + p[1] * p[1];

			if (dist < ref) left.push_back(p);
			else if (dist == ref) mid.push_back(p);
			else right.push_back(p);
		}

		if (K <= left.size())
		{
			left = kClosest(left, K);
		}
		else if (K <= left.size() + mid.size())
		{
			left.insert(left.end(), mid.begin(), mid.begin() + (K - left.size())); 
		}
		else
		{
			vector<vector<int>> remain = kClosest(right, K - left.size() - mid.size());
			left.insert(left.end(), mid.begin(), mid.end());
			left.insert(left.end(), remain.begin(), remain.end());
		}
		return left;
	}
};

int main() {
	int p1[] = {3, 3};
	int p2[] = {5, -1};
	int p3[] = {-2, 4};
	vector<vector<int> > points;
	points.push_back(vector<int>(p1, p1 + 2));
	points.push_back(vector<int>(p2, p2 + 2));
	points.push_back(vector<int>(p3, p3 + 2));
	int k = 1;
	Solution sol;
	vector<vector<int> > closest_points = sol.kClosest(points, k);
	for (int i = 0; i < closest_points.size(); ++i) {
		cout << "(" << closest_points[i][0] << ", " << closest_points[i][1] << ")" << endl;
	}
}