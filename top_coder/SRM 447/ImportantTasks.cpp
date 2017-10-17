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
#define print_vector(a) cout << "{"; for (int i = 0; i < a.size(); i++) { if (i == a.size() - 1) {cout << a[i];} else { cout << a[i] << ",";}} cout << "}n";
using namespace std;

class ImportantTasks {
  public: int maximalCost(vector<int> complexity, vector<int> computers);
};

int ImportantTasks::maximalCost(vector<int> complexity, vector<int> computers) {
  return 0;
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { {1,2,3}, {2,2,2} }, {2} },
    { { {1,2,3}, {3} }, {1} },
    { { {3,5,1,7}, {9,4,1,1,1} }, {3} },
    { { {5,2,7,8,6,4,2,10,2,3}, {4,1,3,6,2,10,11,1,1,3,4,2} }, {8} },
    { { {100}, {100,100} }, {1} },
    // Your custom test goes here:
    //{ { {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        vector<int> p0;vector<int> p1;

        int run(ImportantTasks* x) {
            return x->maximalCost(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<ImportantTasks>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            250, 1397947745, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
