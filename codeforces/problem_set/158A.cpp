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
#define print_vector(a) cout << "{"; for (int i = 0; i < a.size(); i++) { if (i == a.size() - 1) {cout << a[i];} else { cout << a[i] << ",";}} cout << "}\n";
using namespace std;

int main () {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> scores;
  for (int i = 0; i < n; i++) {
    int score;
    scanf("%d", &score);
    scores.push_back(score);
  }
  sort(scores.begin(), scores.end());
  int count = 0;
  for (int i = 0; i < scores.size(); i++) {
    if (scores[i] >= scores[n-k] && scores[i] > 0) {
      count++;
    }
  }
  printf("%d", count);
  fflush(stdout);
}