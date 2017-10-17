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
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class DivideAndShift {
public:
    int getLeast(int N, int M) {
        //initialize memo
        for(long i = 0; i <= N; ++i) {
            vector<long> row;
            for(long j = 0; j <= N; ++j) {
                row.push_back(0);
            }
            memo.push_back(row);
        }
        return recurse(N, M);
    }
    long recurse(long N, long M) {
        if(memo.size() < N+1 || memo[0].size() < N+1)
            return -1;
        if(memo[N][M] > 0)
            return memo[N][M];
        if(M == 1)
            return 0;
            
        long min_dist = M;
        for(long i = 2; i <= N; ++i) {
            if(isPrime(i) && N % i == 0) {
                long new_N = N / i;
                long new_M = M % new_N;
                if(new_M == 0)
                    new_M = new_N;
                    
                long dist = 1 + recurse(new_N, new_M);
                if(dist < min_dist)
                    min_dist = dist;
            }
        }

        long new_M = M + 1;
        if(new_M > N)
            new_M = 1;
        long dist = 1 + recurse(N, new_M);
        if(dist < min_dist)
            min_dist = dist;
        
        new_M = M - 1;
        if(new_M < 1)
            new_M = N;
        dist = 1 + recurse(N, new_M);
        if(dist < min_dist)
            min_dist = dist;
        memo[N][M] = min_dist;
        return min_dist;
    }
    
    bool isPrime(long N) {
        if(N == 1)
            return false;
        if(N == 2)
            return true;
        
        for(long i = 2; i <= sqrt(N); ++i) {
            if(N % i == 0)
                return false;
        }
        return true;
    }
private:
    vector<vector<long> > memo;
};

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 56, 14 }, {3} },
    { { 49, 5 }, {2} },
    { { 256, 7 }, {6} },
    { { 6, 1 }, {0} },
    { { 77777, 11111 }, {2} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "../tester.cpp"
    struct input {
        int p0;int p1;

        int run(DivideAndShift* x) {
            return x->getLeast(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };
    
    int main() {
        return Tester::runTests<DivideAndShift>(
            getTestCases<input, Tester::output<int>>(), disabledTest, 
            500, 1406398784, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
