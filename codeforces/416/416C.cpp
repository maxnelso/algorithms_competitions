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
#define print_vector(a) for (int i = 0; i < a.size(); i++) { if (i == a.size() - 1) {cout << a[i];} else { cout << a[i] << " ";}}
using namespace std;

struct compare {
  bool operator()(pair< pair<int,int>, int> a, pair< pair<int, int>, int> b) {
    return a.first.first > b.first.first;
  }
};

int main () {
  int n;
  scanf("%d", &n);
  vector<pair <pair<int, int>, int > > requests;
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    pair<int, int> p = make_pair(b, a);
    pair<pair<int, int>, int> p_real = make_pair(p, i+1);
    requests.push_back(p_real);
  }
  sort(requests.begin(), requests.end(), compare());
  int k;
  scanf("%d", &k);
  vector<pair<int, int> > tables;
  for (int i = 0; i < k; ++i) {
    int a;
    scanf("%d", &a);
    tables.push_back(make_pair(a, i+1));
  }
  sort(tables.begin(), tables.end());
  vector<bool> seen(k);
  fill(seen.begin(), seen.end(), false);
  int total = 0;
  int money = 0;
  vector<pair <int, int> > result;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      if (!seen[j] && tables[j].first >= requests[i].first.second) {
        seen[j] = true;
        money += requests[i].first.first;
        total++;
        result.push_back(make_pair(requests[i].second, tables[j].second));
        break;
      }
    }
  }
  printf("%d %d\n", total, money);
  for (int i = 0; i < result.size(); ++i) {
    if (i != result.size() - 1) {
      printf("%d %d\n", result[i].first, result[i].second);
    } else {
      printf("%d %d", result[i].first, result[i].second);
    }
  }
  fflush(stdout);
}
