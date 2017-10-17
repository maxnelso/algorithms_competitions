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

static int dp[100000];
static int previous[100000];

struct Envelope {
  int w;
  int h;
  int i;

  Envelope(int w, int h, int i) {
    this->w = w;
    this->h = h;
    this->i = i;
  }


  bool operator<(Envelope e) const {
    return w < e.w;
  }


  bool operator>(Envelope e) const {
    return w > e.w && h > e.h;
  }
};

int main () {
  int n, w, h;
  scanf("%d %d %d", &n, &w, &h);
  vector<Envelope> envelopes;
  //envelopes.push_back({w, h, 0});
  envelopes.push_back(Envelope(w, h, 0));
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a <= w || b <= h) {
      continue;
    }
    //envelopes.push_back({a, b, i + 1});
    envelopes.push_back(Envelope(a, b, i + 1));
  }
  if (envelopes.size() == 1) {
    printf("0");
    return 0;
  }
  sort(envelopes.begin(), envelopes.end());
  dp[0] = 0;
  previous[0] = 0;
  for (int i = 1; i < envelopes.size(); i++) {
    int max_count = 0;
    for (int j = 0; j < i; j++) {
      if (envelopes[i] > envelopes[j]) {
        if (dp[j] + 1 > max_count) {
          max_count = dp[j] + 1;
          previous[i] = j;
        }
      }
    }
    dp[i] = max_count;
  }

  int max_count = 0;
  int starting_index = 0;
  //printf("envelopes size %d\n", envelopes.size());
  for (int i = 0; i < envelopes.size(); i++) {
    //printf("prev %d %d %d %d\n", i, envelopes[i].i, dp[i], previous[i]);
    if (dp[i] > max_count) {
      starting_index = i;
      max_count = dp[i];
    }
  }

  vector<int> path;
  printf("%d\n", max_count);
  while (starting_index != 0) {
    if (starting_index < 0 || starting_index >= envelopes.size()) {
      printf("OH NO %d\n", starting_index);
    }
    path.push_back(envelopes[starting_index].i);
    starting_index = previous[starting_index];
  }

  reverse(path.begin(), path.end());
  for (int i = 0; i < path.size(); i++) {
    printf("%d ", path[i]);
  }
  return 0;
}
