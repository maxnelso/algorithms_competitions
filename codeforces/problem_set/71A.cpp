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
  for (int i = 0; i < n; ++i) {
    char word[256];
    scanf("%s", word);
    string s(word);
    if (s.length() <= 10) {
      printf("%s\n", s.c_str());
    } else {
      printf("%c%d%c\n", s[0], s.length() - 2, s[s.length()-1]);
    }
  }
  fflush(stdout);
}
