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

using namespace std;

int main () {
  int n;
  scanf("%d", &n);
  map<string, int> scores;
  map<pair<string, int>, int> whens;

  for (int i = 0; i < n; i++) {
    char c[33];
    int score;
    scanf("%s %d", c, &score);
    string name(c);
    scores[name] += score;
    pair<string, int> p = make_pair(name, scores[name]);
    if (whens.find(p) == whens.end()) {
      whens[p] = i;
    }
  }

  //print_container(scores);
  //print_container(whens);
  pair<string, int> best;
  for (auto &p : scores) {
    string s = p.first;
    if (scores[s] > best.second) {
      best.first = s;
      best.second = scores[s];
    }
  }
  int min_time = INT_MAX;
  for (auto &p : scores) {
    string s = p.first;
    int score = p.second;
    if (score != best.second) {
      continue;
    }
    for (auto &q : whens) {
      const pair<string, int> a = q.first;
      if (a.first != s) {
        continue;
      }
      if (a.second >= score && q.second <= min_time) {
        best.first = a.first;
        min_time = q.second;
      }
    }
  }
  printf("%s", best.first.c_str());
}
