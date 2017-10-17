#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <iterator>
#define print_vector(a) for (int i = 0; i < a.size(); i++) { if (i == a.size() - 1) {cout << a[i];} else { cout << a[i] << " ";}}
#define print_vector_2d(a) for (int i = 0; i < a.size(); i++) {for (int j = 0; j < a[i].size(); j++) { if (j == a[0].size() - 1) {cout << a[i][j];} else { cout << a[i][j] << " ";}} cout << endl; }
using namespace std;


int helper(vector<int> balls) {
  int current_color = balls[0];
  int count = 0;
  vector<int> new_vec;
  if (balls.size() < 3) {
    return balls.size();
  }
  for (int i = 0; i < balls.size(); i++) {
    if (balls[i] == current_color) {
      count++;
    } else {
      if (count < 3) {
        for (int j = i - count; j < i; j++) {
          new_vec.push_back(balls[j]);
        }
      }
      current_color = balls[i];
      count = 1;
    }
  }
  if ( count < 3) {
    for (int j = balls.size() - count; j < balls.size(); j++) {
      new_vec.push_back(balls[j]);
    }
  }
  if (new_vec.size() == balls.size()) {
    return new_vec.size();
  }
  if (new_vec.size() == 0) {
    return 0;
  }
  return helper(new_vec);
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, k, x;
  scanf("%d %d %d", &n, &k, &x);
  vector<int> balls;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    balls.push_back(a);
  }
  int best = 0;
  helper(balls);
  for (int i = 0; i < n; i++) {
    vector<int> z = balls;
    vector<int>::iterator it = z.begin() + i;
    z.insert(it, x);
    best = max(best, n - helper(z));
  }
  balls.push_back(x);
  best = max(best, n - helper(balls));
  printf("%d", best);
}
