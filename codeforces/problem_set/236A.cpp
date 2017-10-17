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

int main () {
  char c[256];
  scanf("%s", c);
  string s(c);
  map<char, bool> m;
  for (char i : s) {
    if (m.find(i) == m.end()) {
      m[i] = true;
    }
  }
  if (m.size() % 2 == 0) {
    printf("CHAT WITH HER!");
  } else {
    printf("IGNORE HIM!");
  }
  fflush(stdout);
}
