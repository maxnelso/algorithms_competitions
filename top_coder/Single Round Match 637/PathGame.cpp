#include <bitset>
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

class PathGame {
  public: string judge(vector<string> board);
};

string PathGame::judge(vector<string> board) {
  return "";
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {"#..","..."} }, {"Snuke"} },
    { { {"#","."} }, {"Sothe"} },
    { { {".....","..#.."} }, {"Sothe"} },
    { { {".#...","....."} }, {"Snuke"} },
    { { {".....#..#........##.......","..........#..........#...."} }, {"Snuke"} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "tester.cpp"
    struct input {
        vector<string> p0;

        string run(PathGame* x) {
            return x->judge(p0);
        }
        void print() { Tester::printArgs(p0); }
    };
    
    int main() {
        return Tester::runTests<PathGame>(
            getTestCases<input, Tester::output<string>>(), disabledTest, 
            500, 1414077962, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
