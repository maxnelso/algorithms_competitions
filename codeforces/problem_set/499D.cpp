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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

float dp[5010][5010]; // time x starting_index
bool seen[5010][5010];

float solve(int t, int index, vector<pair<float, int>> songs, float p, int game_time) {
  printf("Looking at %d %d, with prob %f\n", t, index, p);
  if (seen[t][index]) {
    return dp[t][index];
  }
  if (index == songs.size() || t >= game_time) {
    seen[t][index] = true;
    dp[t][index] = p * index;
    printf("Outting: %f\n", p * index);
    return p * index;
  }
  pair<float, int> song = songs[index];
  float out = 0;
  for (int i = 0; i < song.second - 1; i++) {
    float tmp = p;
    tmp = tmp * (pow(1 - song.first, i)); // bads
    out += solve(t + i + 1, index + 1, songs, p * tmp * song.first, game_time);
  }
  out += solve(t + song.second, index + 1, songs, p * pow(1 - song.first, song.second - 1), game_time);
  printf("Finished\n");
  dp[t][index] = out;
  seen[t][index] = true;
  return out;
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, T;
  scanf("%d %d", &n, &T);
  vector<pair<float, int>> songs;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d %d\n", a, b);
    songs.push_back(make_pair(a / 100.f, b));
  }
  memset(seen, 0, sizeof(seen));
  float out = solve(0, 0, songs, 1.0f, T);
  printf("%f", out);
}
