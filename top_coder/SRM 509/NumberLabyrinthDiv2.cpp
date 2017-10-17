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

class NumberLabyrinthDiv2 {
  public: int getMinimumNumberOfMoves(vector<string> board, int r1, int c1, int r2, int c2, int K);
};

const int INF = 1000000000;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};
int NumberLabyrinthDiv2::getMinimumNumberOfMoves(vector<string> board, int r1, int c1, int r2, int c2, int K) {
  int R = board.size();
  int C = board[0].size();
  int distance[50][50][51];
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      for (int k = 0; k <= K; ++k) {
        distance[i][j][k] = INF;
      }
    }
  }
  distance[r1][c1][K] = 0;

  queue<int> q;
  q.push(r1);
  q.push(c1);
  q.push(K);

  while (!q.empty()) {
    int r = q.front(); q.pop();
    int c = q.front(); q.pop();
    int k = q.front(); q.pop();

    if (r == r2 && c2 == c) {
      return distance[r][c][k];
    }

    for (int d = 1; d <= 9; ++d) {
      for (int t = 0; t < 4; ++t) {
        bool can_change = ((board[r][c] == '.') && (k > 0));

        if (can_change || board[r][c] - '0' == d) {
          int nr = r + dx[t] * d;
          int nc = c + dy[t] * d;
          int nk = k;
          if (can_change) {
            nk--;
          }
          if (nr >= 0 && nr < R && nc >= 0 && nc < C && distance[nr][nc][nk] > distance[r][c][k] + 1) {
            distance[nr][nc][nk] = distance[r][c][k] + 1;
            q.push(nr);
            q.push(nc);
            q.push(nk);
          }
        }
      }
    }
  }
  return -1;
}

// CUT begin
ifstream data("NumberLabyrinthDiv2.sample");

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

bool do_test(vector<string> board, int r1, int c1, int r2, int c2, int K, int __expected) {
    time_t startClock = clock();
    NumberLabyrinthDiv2 *instance = new NumberLabyrinthDiv2();
    int __result = instance->getMinimumNumberOfMoves(board, r1, c1, r2, c2, K);
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
        vector<string> board;
        from_stream(board);
        int r1;
        from_stream(r1);
        int c1;
        from_stream(c1);
        int r2;
        from_stream(r2);
        int c2;
        from_stream(c2);
        int K;
        from_stream(K);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(board, r1, c1, r2, c2, K, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1408810239;
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
        cout << "NumberLabyrinthDiv2 (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
