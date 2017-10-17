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
#include <climits>
#include <iterator>
#include <unordered_map>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

unordered_map<pair<int, int>> memo;
vector<int> people;
vector<int> keys;
const int MAXN = 2000 + 10;
bool used[MAXN];

int solv

int main () {
  int n, k, p;
  scanf("%d %d %d", &n, &k, &p);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    people.push_back(a);
  }
  for (int i = 0; i < k; i++) {
    int a;
    scanf("%d", &a);
    keys.push_back(a);
  }
  sort(people.begin(), people.end());
  sort(keys.begin(), keys.end());
  solve(

}
