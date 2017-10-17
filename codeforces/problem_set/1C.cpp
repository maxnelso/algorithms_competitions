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

struct Point {
  float x;
  float y;
};

struct Line {
  float m;
  float b;
};

float dist(float x0, float y0, float x1, float y1) {
  return sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2));
}

Line create_line(float x0, float y0, float x1, float y1) {
  float m = (x1 - x0) / (y1 - y0);
  printf("sup sup %f %f\n", y1, y0);
  float b = (x1 * x1 - x0 * x0 + y1 * y1 - y0 * y0) / (2 * (y1 - y0));
  return {m, b};
}

Point intersection(Line a, Line b) {
  float x = (b.b - a.b) / (a.m - b.m);
  float y = b.m * x + b.b;
  return {x, y};
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  float x0, y0, x1, y1, x2, y2;
  scanf("%f %f", &x0, &y0);
  scanf("%f %f", &x1, &y1);
  scanf("%f %f", &x2, &y2);
  printf("%f %f %f %f %f %f\n", x0, y0, x1, y1, x2, y2);

  float epsilon = 10e-5;

  Point center;
  if (fabs(y1 - y0) <= epsilon) {
    center.x = (x0 + x1) / 2;
  } else if (fabs(y2 - y1) <= epsilon) {
    center.x = (x2 + x1) / 2;
    center.y = (y2 + y1) / 2;
  } else if (fabs(y2 - y0) <= epsilon) {
    center.x = (x2 + x0) / 2;
    center.y = (y2 + y0) / 2;
  } else {
    Line a = create_line(x0, y0, x1, y1);
    Line b = create_line(x1, y1, x2, y2);
    center = intersection(a, b);
    printf("%f %f\n", a.m, a.b);
    printf("%f %f\n", b.m, b.b);
  }
  printf("%f %f %f %f %f %f\n", x0, y0, x1, y1, x2, y2);
  printf("%f %f\n", center.x, center.y);

  //float a = dist(x0, y0, x1, y1);
  //float b = dist(x0, y0, x2, y2);
  //float c = dist(x1, y1, x2, y2);
}
