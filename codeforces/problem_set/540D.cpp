#include <bitset>
#include <vector>
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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

const int MAX = 105;

map<tuple<int, int, int>, tuple<double, double, double>> dp;

tuple<double, double, double> solve(int r, int s, int p) {
  if (dp.find(make_tuple(r, s, p)) != dp.end()) {
    return dp[make_tuple(r, s, p)];
  }
  double r_wins = 0;
  double s_wins = 0;
  double p_wins = 0;
  double total = r + s + p;
  double other_probs = 0;
  if (r >= 2) {
    other_probs += (r / total) * ((r - 1) / (total - 1));
  }
  if (s >= 2) {
    other_probs += (s / total) * ((s - 1) / (total - 1));
  }
  if (p >= 2) {
    other_probs += (p / total) * ((p - 1) / (total - 1));
  }
  other_probs = 1- other_probs;
  if (r > 0 && s > 0) {
    double prob = (r / total) * (s / (total - 1)) +
                 (s / total) * (r / (total - 1));
    prob /= other_probs;
    tuple<double, double, double> sim = solve(r, s - 1, p);
    r_wins += prob * get<0>(sim);
    s_wins += prob * get<1>(sim);
    p_wins += prob * get<2>(sim);
  }
  if (r > 0 && p > 0) {
    double prob = (r / total) * (p / (total - 1)) +
                 (p / total) * (r / (total - 1));
    prob /= other_probs;
    tuple<double, double, double> sim = solve(r - 1, s, p);
    r_wins += prob * get<0>(sim);
    s_wins += prob * get<1>(sim);
    p_wins += prob * get<2>(sim);
  }
  if (s > 0 && p > 0) {
    double prob = (s / total) * (p / (total - 1)) +
                 (p / total) * (s / (total - 1));
    prob /= other_probs;
    tuple<double, double, double> sim = solve(r, s, p - 1);
    r_wins += prob * get<0>(sim);
    s_wins += prob * get<1>(sim);
    p_wins += prob * get<2>(sim);
  }
  tuple<double, double, double> out = make_tuple(r_wins, s_wins, p_wins);
  dp[make_tuple(r, s, p)] = out;
  return out;

}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int r, s, p;
  scanf("%d %d %d", &r, &s, &p);

  for (int i = 0; i < MAX; i++) {
    tuple<double, double, double> r = make_tuple(1, 0, 0);
    dp[make_tuple(i, 0, 0)] = r;
    tuple<double, double, double> s = make_tuple(0, 1, 0);
    dp[make_tuple(0, i, 0)] = s;
    tuple<double, double, double> p = make_tuple(0, 0, 1);
    dp[make_tuple(0, 0, i)] = p;
  }

  tuple<double, double, double> out = solve(r, s, p);
  printf("%.12f %.12f %.12f", get<0>(out), get<1>(out), get<2>(out));
}
