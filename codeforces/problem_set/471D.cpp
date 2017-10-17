#include <bitset>
#include <vector>
#include <list>
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

using namespace std;

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif


template <typename T> vector<T> readVector(int n) { vector<T> res(n); for (int i = 0 ; i < n ; i++) cin >> res[i]; return res; }

// z-function implementation taken from e-maxx.ru
vector<int> zFunction(vector<int> &s) {
    int n = (int) s.size();
        cout << "S: " << endl;
        for (int i = 0; i < s.size(); ++i)
    {
    	cout << " " << s[i];	
    }
    cout << endl;
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
    	    for (int j = 0; j < z.size(); ++j)
    {
    	cout << " " << z[j];	
    }
        cout << endl;

        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}

int findNumberOfOccurences(vector<int> &v, vector<int> &pattern) {
    if (pattern.size() == 0) return v.size() + 1;

    vector<int> str = pattern;
    str.insert(str.end(), v.begin(), v.end());
    cout << endl;
        for (int i = 0; i < str.size(); ++i)
    {
    	cout << " " << str[i];	
    }
    cout << endl;
    vector<int> z = zFunction(str);

    for (int i = 0; i < z.size(); ++i)
    {
    	cout << " " << z[i];	
    }
    int result = 0;
    for (int i = pattern.size() ; i < z.size() ; i++) {
        if (z[i] >= pattern.size()) result++;
    }
        
    return result;
}

vector<int> toDiffArray(vector<int> &v) {
    vector<int> result;
    for (int i = 1 ; i < v.size() ; i++)
        result.push_back(v[i] - v[i - 1]);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    int m; cin >> m;
	
    vector<int> a = readVector<int>(n);
    vector<int> b = readVector<int>(m);

    vector<int> aDiff = toDiffArray(a);
    vector<int> bDiff = toDiffArray(b);

    int result = findNumberOfOccurences(aDiff, bDiff);

    cout << result;
}
