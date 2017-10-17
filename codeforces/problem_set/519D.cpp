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

vector<long long> sums;
map<pair<char, long long>, long long> m;

int main () {
  map<char, vector<int>> alphabet_indexes;
  map<char, long long> scores;
  for (int i = 0; i < 26; i++) {
    long long a;
    cin >> a;
    scores['a' + i] = a;
  }

  string s;
  cin >> s;
  long long out = 0;
  long long sum = 0;
  for (int i = 0; i < s.size(); i++) {
    out += m[make_pair(s[i], sum)];
    sum += scores[s[i]];
    m[make_pair(s[i], sum)]++;
  }

  cout << out;

}
