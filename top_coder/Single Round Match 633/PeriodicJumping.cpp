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

class PeriodicJumping {
  public: int minimalTime(int x, vector<int> jumpLengths);
};

int PeriodicJumping::minimalTime(int x, vector<int> jumpLengths) {
  long long total = 0;
  for (int i = 0; i < jumpLengths.size(); ++i) {
    total += (long long) jumpLengths[i];
  }
  if (x == total) {
    return 1;
  }
  vector<int> concat;
  for (int i = 0; i < jumpLengths.size(); ++i) {
    concat.push_back(jumpLengths[i]);
  }
  for (int i = 0; i < jumpLengths.size(); ++i) {
    concat.push_back(jumpLengths[i]);
  }
  int offset = 0;
  if (abs(x) % total == 0) {
    return abs(x) / total;
  }
  if (abs(x) > total) {
    offset = (abs(x) / total) * jumpLengths.size();
    if (x < 0) {
      x += abs(x) / total * total;
    } else {
      x -= abs(x) / total * total;
    }
  }
  if (x > 0) {
    long long tmp = 0;
    for (int i = 0; i < jumpLengths.size(); ++i) {
      tmp += jumpLengths[i];
      if (tmp == x) {
        return i + 1 + offset;
      }
      if (tmp > x) {
        int index = find(concat.begin() + i + 1, concat.end(), jumpLengths[i]) - concat.begin() - i;
        return i + index + 1 + offset;
      }
    }
  } else {
    long long tmp = 0;
    for (int i = 0; i < jumpLengths.size(); ++i) {
      tmp -= jumpLengths[i];
      if (tmp == x) {
        return i + 1 + offset;
      }
      if (tmp < x) {
        int index = find(concat.begin() + i + 1, concat.end(), jumpLengths[i]) -  concat.begin() - i;
        return i + index + 1 + offset;
      }
    }
  }
  return -1;
}

// CUT begin
ifstream data("PeriodicJumping.sample");

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

bool do_test(int x, vector<int> jumpLengths, int __expected) {
    time_t startClock = clock();
    PeriodicJumping *instance = new PeriodicJumping();
    int __result = instance->minimalTime(x, jumpLengths);
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
        int x;
        from_stream(x);
        vector<int> jumpLengths;
        from_stream(jumpLengths);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(x, jumpLengths, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1410966904;
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
        cout << "PeriodicJumping (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
