#include <bits/stdc++.h>
using namespace std;

/* ----------------------- Closest Pair of Points O(nlog^2n) ----------------------- */

struct Point{
  double x, y;
};

double dist(const Point& a, const Point& b){
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx*dx + dy*dy);
}

double brute_force(vector<Point>& points, int low, int high){
  double best = DBL_MAX;
  for(int i = low; i<=high; i++){
    for(int j = i+1; j<=high; j++){
      best = min(best, dist(points[i], points[j]));
    }
  }
  return best;
}

double closest_pair_util(vector<Point>& points, int low, int high){
  if(high - low < 3){
    return brute_force(points, low, high);
  }

  int mid = low + (high - low) / 2;
  double left_best = closest_pair_util(points, low, mid);
  double right_best = closest_pair_util(points, mid+1, high);

  double best = min(left_best, right_best);

  vector<Point> strip;
  for(int i = low; i<=high; i++){
    if(abs(points[i].x - points[mid].x) < best) strip.push_back(points[i]);
  }
  sort(strip.begin(), strip.end(), [](const Point& a, const Point& b){
    return a.y < b.y;
  });
  for(int i = 0; i<strip.size(); i++){
    for(int j = i+1; j<strip.size() && abs(strip[j].y - strip[i].y) < best; j++){
      best = min(best, dist(strip[i], strip[j]));
    }
  }
  return best;
}

double closest_pair(vector<Point> points){
  int n = points.size();
  sort(points.begin(), points.end(), [](const Point& a, const Point& b){
    return a.x < b.x;
  });
  return closest_pair_util(points, 0, n-1);
}

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<Point> points(n);
  for(int i = 0; i<n; i++){
    cin >> points[i].x >> points[i].y;
  }
  cout << closest_pair(points);
  return 0;
}