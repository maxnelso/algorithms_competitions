#include <vector>
#include <list>
#include <fstream>
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
#include <tuple>
#include <cstring>
#include <ctime>
#include <iterator>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

class CheapestRoute {
  public: vector<int> routePrice(vector<int> cellPrice, vector<int> enterCell, vector<int> exitCell, int teleportPrice);
};

vector<int> CheapestRoute::routePrice(vector<int> cellPrice, vector<int> enterCell, vector<int> exitCell, int teleportPrice) {
  map<int, vector<int>> teleports;
  for (int i = 0; i < enterCell.size(); ++i) {
    if (teleports.find(enterCell[i]) != teleports.end()) {
      if (cellPrice[exitCell[i]] != -1) {
        teleports[enterCell[i]].push_back(exitCell[i]);
      }
    } else {
      if (cellPrice[exitCell[i]] != -1) {
        teleports[enterCell[i]] = {exitCell[i]};
      }
    }
  }
  int n = cellPrice.size();
  pair<int, int> distances[120][120];
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      distances[i][j] = make_pair(1000000000, 1000000000);
    }
  }
  pair<int, int> start = make_pair(0, 0);
  distances[0][0] = start;
  queue<pair<int, int>> q;
  q.push(start);
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    printf("Looking at ");

    int old_cost = distances[p.first][p.second].first;
    int old_d = distances[p.first][p.second].second;

    // left
    if (p.first - 1 >= 0 && cellPrice[p.first - 1] != -1) {
      int new_cost = old_cost + cellPrice[p.first - 1];
      if (distances[p.first - 1][p.second].first > new_cost) {
        distances[p.first - 1][p.second] = make_pair(new_cost, old_d + 1);
        q.push(make_pair(p.first - 1, p.second));
      }
    }
    // right
    if (p.first + 1 < n && cellPrice[p.first + 1] != -1) {
      int new_cost = old_cost + cellPrice[p.first + 1];
      printf("new cost: %d\n", new_cost);
      printf("old cost: %d\n", distances[p.first + 1][p.second]);
      if (distances[p.first + 1][p.second].first > new_cost) {
        distances[p.first + 1][p.second] = make_pair(new_cost, old_d + 1);
        q.push(make_pair(p.first + 1, p.second));
      }
    }
    // teleports
    if (teleports.find(p.first) != teleports.end()) {
      for (int i = 0; i < teleports[p.first].size(); ++i) {
        int new_cost = old_cost + teleportPrice + p.second;
        if (distances[teleports[p.first][i]][p.second + 1].first > new_cost) {
          distances[teleports[p.first][i]][p.second + 1] = make_pair(new_cost, old_d + 1);
          q.push(make_pair(teleports[p.first][i], p.second + 1));
        }
      }
    }
  }
  pair<int, int> best = {1000000000, 1000000000};
  for (int i = 0; i <= n; ++i) {
    if (distances[n-1][i] < best) {
      best = distances[n-1][i];
    }
  }
  if (best.first == 1000000000) {
    return vector<int>();
  }
  vector<int> out;
  out.push_back(best.first);
  out.push_back(best.second);
  return out;
}

// CUT begin
ifstream data("CheapestRoute.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(vector<int> cellPrice, vector<int> enterCell, vector<int> exitCell, int teleportPrice, vector<int> __expected) {
    time_t startClock = clock();
    CheapestRoute *instance = new CheapestRoute();
    vector<int> __result = instance->routePrice(cellPrice, enterCell, exitCell, teleportPrice);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<int> cellPrice;
        from_stream(cellPrice);
        vector<int> enterCell;
        from_stream(enterCell);
        vector<int> exitCell;
        from_stream(exitCell);
        int teleportPrice;
        from_stream(teleportPrice);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(cellPrice, enterCell, exitCell, teleportPrice, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1409589357;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "CheapestRoute (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
