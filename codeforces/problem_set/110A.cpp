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
  long long int n;
  cin >> n;
  stringstream ss;
  ss << n;
  string s = ss.str();
  if ((count(s.begin(), s.end(), '4') + count(s.begin(), s.end(), '7') == 4) ||
     (count(s.begin(), s.end(), '4') + count(s.begin(), s.end(), '7') == 7)) {
    printf("YES");
  } else {
    printf("NO");
  }
  fflush(stdout);
}
