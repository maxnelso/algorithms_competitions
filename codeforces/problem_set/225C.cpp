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
#include <climits>
#include <iterator>
#include <unordered_map>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

const int MAXN = 1005;
const int INF = (-1u)/2;
int sum_black[MAXN];
int sum_white[MAXN];
int dp[MAXN][2];

int get_sum(const vector<int>& sums, int l, int r) {
  if (l == 0) {
    return sums[r];
  }
  return sums[r] - sums[l - 1];
}

int main () {
  int n, m, x, y;
  scanf("%d %d %d %d", &n, &m, &x, &y);
  vector<string> grid;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    grid.push_back(s);
  }

  vector<int> col_counts;
  for (int i = 0; i < m; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      sum += grid[j][i] == '#';
    }
    col_counts.push_back(sum);
  }

  for (int i = 1; i <= m; i++) {
    sum_black[i] = sum_black[i - 1] + col_counts[i - 1];
    sum_white[i] = sum_white[i - 1] + n - col_counts[i - 1];
  }

  for (int i = 0; i <= m; i++) {
    dp[i][1] = INF;
    dp[i][0] = INF;
  }

  dp[0][0]=dp[0][1]=0;
  for(int i=1;i<=m;++i)
    {
      for(int j=x;j<=y and j<=i;++j)
	{
	  //black
	  if(dp[i-j][0]!=INF)
	    dp[i][1]=min(dp[i][1],sum_black[i]-sum_black[i-j]+dp[i-j][0]);
	  //white
	  if(dp[i-j][1]!=INF)
	    dp[i][0]=min(dp[i][0],sum_white[i]-sum_white[i-j]+dp[i-j][1]);
	}
      //      cerr<<"i:"<<i<<" cst:"<<dp[i][0]<<","<<dp[i][1]<<endl;
    }
  printf("%d", min(dp[m][0], dp[m][1]));
}
