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
  vector<int> homes;
  vector<int> aways;
  for (int i = 0; i < n; ++i) {
    int home, away;
    scanf("%d %d", &home, &away);
    homes.push_back(home);
    aways.push_back(away);
  }
  int result = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        if (aways[i] == homes[j]) {
          result++;
        }
      }
    }
  }
  printf("%d", result);
  fflush(stdout);
}
