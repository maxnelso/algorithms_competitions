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
  char c[1024];
  scanf("%s", c);
  string a(c);
  char d[1024];
  scanf("%s", d);
  string b(d);
  map<char, int> acount;
  map<char, int> bcount;
  for (int i = 0; i < a.size(); i++) {
    if (acount.find(a[i]) == acount.end()) {
      acount[a[i]] = 1;
    } else {
      acount[a[i]]++;
    }
  }
  for (int i = 0; i < b.size(); i++) {
    if (bcount.find(b[i]) == bcount.end()) {
      bcount[b[i]] = 1;
    } else {
      bcount[b[i]]++;
    }
  }
  int result = 0;
  for (map<char, int>::iterator iter = bcount.begin(); iter != bcount.end(); iter++) {
    if (acount.find(iter->first) == acount.end()) {
      printf("-1");
      return 0;
    } else {
      result += min(iter->second, acount[iter->first]);
    }
  }
  printf("%d", result);
  fflush(stdout);
}
