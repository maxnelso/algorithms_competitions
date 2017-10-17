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
#include <cstring>
#include <ctime>
#include <iterator>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

class SpiralWalking {
  public: int totalPoints(vector<string> levelMap);
};

bool in_bounds(vector<string> levelMap, int x, int y) {
  return x >= 0 && x < levelMap.size() &&
         y >= 0 && y < levelMap[0].size();
}

pair<int, int> get_new_dir(pair<int, int> p) {
  if (p.first == 0 && p.second == 1) {
    return make_pair(1, 0);
  }
  if (p.first == 1 && p.second == 0) {
    return make_pair(0, -1);
  }
  if (p.first == 0 && p.second == -1) {
    return make_pair(-1, 0);
  }
  if (p.first == -1 && p.second == 0) {
    return make_pair(0, 1);
  }
}

int SpiralWalking::totalPoints(vector<string> levelMap) {
  map<pair<int, int>, bool> seen;
  pair<int, int> start = make_pair(0, 0);
  pair<int, int> dir = make_pair(0, 1);
  int out = 0;
  while (seen.size() != levelMap[0].size() * levelMap.size()) {
    if (in_bounds(levelMap, start.first + dir.first, start.second + dir.second) && seen.find(make_pair(start.first + dir.first, start.second + dir.second)) == seen.end()) {
      out += levelMap[start.first][start.second] - '0';
    } else {
      dir = get_new_dir(dir);
    }
    seen[start] = true;
    if (seen.size() == levelMap[0].size() * levelMap.size()) {
      out += levelMap[start.first][start.second] - '0';
    }
    start.first += dir.first;
    start.second += dir.second;
  }
  return out;
}

// CUT begin
ifstream data("SpiralWalking.sample");

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

bool do_test(vector<string> levelMap, int __expected) {
    time_t startClock = clock();
    SpiralWalking *instance = new SpiralWalking();
    int __result = instance->totalPoints(levelMap);
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
        vector<string> levelMap;
        from_stream(levelMap);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(levelMap, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1409586112;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "SpiralWalking (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
