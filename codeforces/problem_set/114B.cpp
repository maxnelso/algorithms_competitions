#include <bitset>
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

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, m;
  scanf("%d %d", &n, &m);
  vector<string> volunteers;
  map<string, vector<string>> dislike;
  for (int i = 0; i < n; i++) {
    char c[256];
    scanf("%s", c);
    string s(c);
    volunteers.push_back(s);
    vector<string> new_dislike;
    dislike[s] = new_dislike;
  }
  for (int i = 0; i < m; i++) {
    char c[256];
    char d[256];
    scanf("%s %s", c, d);
    string s(c);
    string t(d);
    dislike[s].push_back(t);
    dislike[t].push_back(s);
  }
  for (int num_people = n; num_people >= 1; num_people--) {
    vector<bool> v(n);
    fill(v.begin() + num_people, v.end(), true);
    do {
      vector<string> team;
      for (int i = 0; i < n; i++) {
        if (!v[i]) {
          team.push_back(volunteers[i]);
        }
      }
      bool good = true;
      for (int i = 0; i < team.size(); i++) {
        vector<string> baddies = dislike[team[i]];
        for (int j = 0; j < baddies.size(); j++) {
          if (find(team.begin(), team.end(), baddies[j]) != team.end()) {
            good = false;
            break;
          }
        }
      }
      if (good) {
        printf("%d\n", team.size());
        sort(team.begin(), team.end());
        for (int i = 0; i < team.size(); i++) {
          printf("%s\n", team[i].c_str());
        }
        return 0;
      }
    } while (next_permutation(v.begin(), v.end()));
  }
}
