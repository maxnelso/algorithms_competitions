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
#include <regex>
#define print_vector(a) for (int i = 0; i < a.size(); i++) { if (i == a.size() - 1) {cout << a[i];} else { cout << a[i] << " ";}}
using namespace std;

int main () {
  char c[256];
  scanf("%s", c);
  string s(c);
  while (s.find("WUB") == 0) {
    s = s.substr(3);
  }
  while (s.rfind("WUB") == s.size() - 1) {
    s = s.substr(0, s.size() - 3);
  }
  while (s.find("WUB") != string::npos) {
    int start = s.find("WUB");
    int index = start;
    for (int i = start+3; i < s.size(); i = i + 3) {
      if (s.substr(i, 3) == "WUB") {
        index = i;
      } else {
        break;
      }
    }
    s = s.replace(start, index -start + 3, " ");
  }
  printf("%s", s.c_str());
  fflush(stdout);
}
