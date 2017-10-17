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
  if (n >= 0) {
    printf("%d", n);
  } else {
    stringstream ss;
    ss << n;
    string s = ss.str();
    char last = s[s.size() - 1];
    char second_to_last = s[s.size() - 2];
    string a = s.substr(0, s.size() - 2) + last;
    string b = s.substr(0, s.size() - 2) + second_to_last;
    printf("%d", max(atoi(a.c_str()), atoi(b.c_str())));
  }
  fflush(stdout);
}
