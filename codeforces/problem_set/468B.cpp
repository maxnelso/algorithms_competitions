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

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n;
  long long a, b;
  cin >> n >> a >> b;
  set<long long> nums;
  vector<long long> ordering;
  for (int i = 0; i < n; i++) {
    long long num;
    cin >> num;
    nums.insert(num);
    ordering.push_back(num);
  }
  string out = "";
  for (int i = 0; i < ordering.size(); i++) {
    if (nums.find(a - ordering[i]) != nums.end()) {
      out += "0 ";
    } else if (nums.find(b - ordering[i]) != nums.end()) {
      out += "1 ";
    } else {
      printf("NO");
      return 0;
    }
  }
  printf("YES\n");
  printf("%s", out.c_str());
}
