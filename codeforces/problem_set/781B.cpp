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
#include <unordered_map>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

struct team {
  string name;
  string city;
  bool a_strat;

  team(string n, string c) {
    this->name = n;
    this->city = c;
    this->a_strat = true;
  }
};

string a_strat(team& t) {
  string s;
  s += t.name[0];
  s += t.name[1];
  s += t.name[2];
  return s;
}

string b_strat(team& t) {
  string s;
  s += t.name[0];
  s += t.name[1];
  s += t.city[0];
  return s;
}

int main () {
  int n;
  scanf("%d", &n);
  vector<team> teams;
  for (int i = 0; i < n; i++) {
    string s;
    string t;
    cin >> s >> t;
    team te(s, t);
    teams.push_back(te);
  }

  // a = a strats
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && a_strat(teams[i]) == a_strat(teams[j])) {
        teams[i].a_strat = false;
        teams[j].a_strat = false;
      }
    }
  }

  // a = b strats
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && teams[i].a_strat && !teams[j].a_strat && a_strat(teams[i]) == b_strat(teams[j])) {
        teams[i].a_strat = false;
        teams[j].a_strat = false;
      }
    }
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) {
          continue;
        }
        string x = teams[i].a_strat ? a_strat(teams[i]) : b_strat(teams[i]);
        string y = teams[j].a_strat ? a_strat(teams[j]) : b_strat(teams[j]);
        if (x == y) {
          printf("NO");
          return 0;
        }
      }
    }
  }
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    string x = teams[i].a_strat ? a_strat(teams[i]) : b_strat(teams[i]);
    printf("%s\n", x.c_str());
  }

}
