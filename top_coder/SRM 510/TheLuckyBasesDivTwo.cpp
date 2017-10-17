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

class TheLuckyBasesDivTwo {
  public: long long find(long long n);
};

bool is_lucky(int base, long long n) {
  int digs = 0;
  while (n != 0) {
    int exp = 0;
    while ((int) round(pow(base, exp)) < n) {
      exp++;
    }
    exp--;
    long long d = (long long) round(pow(base, exp));
    if (n / d != 7 && n / d != 4) {
      return false;
    }
    n = n % d;
    digs++;
    if (n == 0 && exp != 0) {
      return false;
    }
  }
  return digs >= 3;
}

int count3(long long n) {
  int count = 0;
  for (int i = 2; i < (int) sqrt(n) + 1; ++i) {
    printf("%d\n", i);
    if (is_lucky(i, n)) {
      count++;
    }
  }
  return count;
}

int count2(long long n) {
  int count = 0;
  printf("Starting\n");
  for (int a = 4; a <= 7; a += 3) {
    for (int b = 4; b <= 7; b += 3) {
      long ax = n - b;
      if (ax % a == 0) {
        long x = ax / a;
        if (x > a && x > b) {
          count++;
        }
      }
    }
  }
  printf("Returning\n");
  return count;
}

long long TheLuckyBasesDivTwo::find(long long n) {
  int count = 0;
  if (n == 4 || n == 7) {
    return -1;
  }
  printf("hello!\n");
  count += count2(n);
  count += count3(n);
  return count;
}

// CUT begin
ifstream data("TheLuckyBasesDivTwo.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(long long n, long long __expected) {
    time_t startClock = clock();
    TheLuckyBasesDivTwo *instance = new TheLuckyBasesDivTwo();
    long long __result = instance->find(n);
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
        long long n;
        from_stream(n);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1408814880;
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
        cout << "TheLuckyBasesDivTwo (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
