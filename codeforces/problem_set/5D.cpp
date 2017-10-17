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
#include <unordered_map>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

float a, v, l, d, w;
double const EPS = 1E-8;

float dist(float speed, float time) {
  return speed * time + (a * time * time) / 2;
}

float travelTime(float d, float s) {
  float tAll = (sqrt(2 * a * d + (s * s)) - s) / a;
  float tMax = (v - s) / a;
  if (tMax + EPS > tAll) {
    return tAll;
  }
  return tMax + (d - dist(s, tMax)) / v;
}

int main () {
  scanf("%f %f", &a, &v);
  scanf("%f %f %f", &l, &d, &w);
  if (v <= w) {
    printf("%f", travelTime(l, 0));
    return 0;
  }
  float timeToW = w / a;
  float distanceToGetToWSpeed = dist(0, timeToW);
  if (distanceToGetToWSpeed >= d) {
    printf("%f", travelTime(l, 0));
    return 0;
  }
  printf("%f", timeToW + 2 * travelTime(.5 * (d - distanceToGetToWSpeed), w) + travelTime(l - d, w));

}
