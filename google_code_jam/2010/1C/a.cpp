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

string FILENAME = "A-large-practice";

int main () {
  freopen((FILENAME + ".in").c_str(), "r", stdin);
  freopen((FILENAME + ".out").c_str(), "w", stdout);
  int testcases;
  scanf("%d",&testcases);
  for (int case_id = 1; case_id <= testcases; case_id++) {
    bool A[10000];
    memset(A, false, sizeof(A));
    bool B[10000];
    memset(B, false, sizeof(B));
    vector<pair<int,int>> pairs;
    int a, b, n;
    printf("Case #%d: ", case_id);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &a, &b);
      pair<int, int> new_pair(a,b);
      pairs.push_back(new_pair);
      A[a] = true;
      B[b] = true;
    }
    int count = 0;
    for (int i = 0; i < pairs.size(); i++) {
      for (int j = 0; j < pairs.size(); j++) {
        if (i != j) {
          if ((pairs[i].first < pairs[j].first && pairs[i].second > pairs[j].second) ||
              (pairs[i].first > pairs[j].first && pairs[i].second < pairs[j].second)) {
            count++;
          }
        }
      }
    }
    printf("%d\n", count/2);
  }
  fflush(stdout);
}
