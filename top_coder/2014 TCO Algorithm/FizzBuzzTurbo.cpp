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

class FizzBuzzTurbo {
  public: vector<long long> counts(long long A, long long B);
};

vector<long long> FizzBuzzTurbo::counts(long long A, long long B) {
  return vector<long long>();
}

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 1, 4 }, { {1LL,0LL,0LL} } },
    { { 2, 6 }, { {2LL,1LL,0LL} } },
    { { 150, 165 }, { {4LL,2LL,2LL} } },
    { { 474747, 747474 }, { {72728LL,36363LL,18182LL} } },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        long long p0;long long p1;

        vector<long long> run(FizzBuzzTurbo* x) {
            return x->counts(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<FizzBuzzTurbo>(
            getTestCases<input, Tester::output<vector<long long>>>(), disabledTest, 
            450, 1398528255, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
