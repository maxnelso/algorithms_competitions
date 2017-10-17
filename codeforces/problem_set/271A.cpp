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
  int n;
  scanf("%d", &n);
  while (true) {
    n++;
    stringstream ss;
    ss << n;
    string s = ss.str();
    set<int> a;
    for (int i =0; i< s.size();i++) {
      a.insert(s[i]);
    }
    if (a.size() == 4) {
      printf("%d", n);
      break;
    }
  }
  fflush(stdout);
}
