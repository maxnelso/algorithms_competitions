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

using namespace std;

string FILENAME = "test";

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  freopen((FILENAME + ".in").c_str(), "r", stdin);
  freopen((FILENAME + ".out").c_str(), "w", stdout);
  int testcases;
  scanf("%d", &testcases);
  for (int case_id = 1; case_id <= testcases; case_id++) {
    printf("Case #%d: ", case_id);
    int n, k;
    scanf("%d %d", &n, &k);
    float U;
    scanf("%f", &U);
    vector<float> ps;
    for (int i = 0; i < n; i++) {
      float p;
      scanf("%f", &p);
      ps.push_back(p);
    }
    sort(ps.rbegin(), ps.rend());
    ps.resize(k);
    float sum = 0;
    sort(ps.begin(), ps.end());
    for (int i = 0; i < k; i++) {
      sum += ps[i];
    }
    printf("sum %f\n", sum);
    sum += U;
    printf("sum %f\n", sum);
    sum /= k;
    printf("sum %f\n", sum);
    if (sum >= 1) {
      printf("1.000000\n");
    } else {
      double p = 1;
      printf("sum %f\n", sum);
      if (sum >= ps[k - 1]) { // can all go together!
        printf("sum %f\n", sum);
        for (int i = 0; i < k; i++) {
          p *= (1 - (sum));
        }
      } else { // gotta do the best we can
        for (int i = 0; i < k; i++) {
          if (U > 0) {
            float next_biggest = ps[i + 1];
            float diff = next_biggest - ps[i];
            float total_needed = diff * (i + 1);
            if (U > total_needed) {
              U -= total_needed;
              for (int j = 0; j <= i; j++) {
                ps[i] = next_biggest;
              }
            } else {
              float what_we_got = U / (i + 1);
              for (int j = 0; j <= i; j++) {
                ps[i] += what_we_got;
              }
              break;
            }
          } else {
            break;
          }
        }
        for (int i = 0; i < k; i++) {
          printf("After %f\n", ps[i]);
          p *= (1 - ps[i]);
        }
      }
      cout << setprecision(15) << p << endl;
    }
  }
  fflush(stdout);
}
