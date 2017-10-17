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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

string FILENAME = "h1";

vector<int> read(string s){
  vector<int> ret;
  int n;
  istringstream sin(s);
  while(sin>>n)
    ret.push_back(n);
  return ret;
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  freopen((FILENAME + ".in").c_str(), "r", stdin);
  freopen((FILENAME + ".out").c_str(), "w", stdout);
  int testcases;
  scanf("%d", &testcases);
  for (int case_id = 1; case_id <= testcases; case_id++) {
    scanf("\n");
    int n, m;
    scanf("%d %d", &n, &m);
    map<int, set<int>> friends;
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      friends[a - 1].insert(b - 1);
      friends[b - 1].insert(a - 1);
    }
    std::vector<bool> v(n);
    int max_sum = -100000;
    int min_sum = 100000000;
    for (int first_team_size = 1; first_team_size < n; first_team_size++) {
        std::fill(v.begin() + n - first_team_size, v.end(), true);
        do {
          if ((v[0] == 0 && v[1] == 1) /*|| (v[1] == 1 && v[1] == 0)*/) { // Make sure those guys are on different teams
            int first_team_score = 0;
            int second_team_score = 0;
            for (int j = 0; j < n; j++) {
              if (v[j]) { // First team
                for (int k = j + 1; k < n; k++) {
                  if (v[k]) {
                    if (friends.find(j) != friends.end() && friends[j].find(k) != friends[j].end()) {
                      first_team_score++;
                    }
                  }
                }
              } else { // Second team
                for (int k = j + 1; k < n; k++) {
                  if (!v[k]) {
                    if (friends.find(j) != friends.end() && friends[j].find(k) != friends[j].end()) {
                      second_team_score++;
                    }
                  }
                }
              }
            }
            int total = first_team_score + second_team_score;
            max_sum = max(max_sum, total);
            min_sum = min(min_sum, abs(first_team_score - second_team_score));
          }
        } while (std::next_permutation(v.begin(), v.end()));
    }
    printf("%d %d\n", max_sum, min_sum);
    fflush(stdout);
  }
}
