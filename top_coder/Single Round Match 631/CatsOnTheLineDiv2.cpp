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

class CatsOnTheLineDiv2 {
  public: string getAnswer(vector<int> position, vector<int> count, int time);
};

int to_positive(int i) {
  if (i < 0) {
    return i + 2000;
  }
  return i;
}

string CatsOnTheLineDiv2::getAnswer(vector<int> position, vector<int> count, int time) {
  vector<pair<int, int>> *pairs;
  for (int i = 0; i < position.size(); ++i) {
    pairs.push_back(make_pair(position[i], count[i]));
  }
  sort(pairs.begin(), pairs.end());
  vector<int> line;
  int index = 0;
  for (int i = 0; i < 5000; ++i) {
    if (to_positive(pairs[index].first) == i) {
      line.push_back(pairs[index].second);
    } else {
      line.push_back(0)
    }
  }
  for (int i = 0; i < pairs.size(); ++i) {
    if (pairs[i].second <= time) {
      for (int j = pairs[i].first - time; j < time; ++j) {
        if (line[j] == 0) {
          line[j] == 1;
        }
      }
    }
  }
}

// CUT begin
ifstream data("CatsOnTheLineDiv2.sample");

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

bool do_test(vector<int> position, vector<int> count, int time, string __expected) {
    time_t startClock = clock();
    CatsOnTheLineDiv2 *instance = new CatsOnTheLineDiv2();
    string __result = instance->getAnswer(position, count, time);
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
        vector<int> position;
        from_stream(position);
        vector<int> count;
        from_stream(count);
        int time;
        from_stream(time);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(position, count, time, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1409414652;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "CatsOnTheLineDiv2 (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
