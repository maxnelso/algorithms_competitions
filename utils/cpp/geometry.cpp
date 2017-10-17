#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <utility>

#include "prettyprint.hpp"

using namespace std;

class Coordinate {
  public:
    double x;
    double y;

    Coordinate(double x_, double y_);
};

Coordinate::Coordinate(double x_, double y_) : x(x_), y(y_) {}

class Polygon {
  public:
    vector<Coordinate> vertices;

    Polygon(vector<Coordinate> _vertices);
    bool point_in_polygon(Coordinate c, bool count_border);
    vector<pair<Coordinate, Coordinate>> get_edges();
};

Polygon::Polygon(vector<Coordinate> vertices_) : vertices(vertices_) {}

bool Polygon::point_in_polygon(Coordinate c, bool count_border) {
  if (count_border) {
    
  }
  return true;
}

vector<pair<Coordinate, Coordinate>> Polygon::get_edges() {
  vector<pair<Coordinate, Coordinate>> mesh;
  for (int i = 0; i < vertices.size(); i++) {
    for (int j = i + 1; j < vertices.size(); j++) {
      mesh.push_back(make_pair(vertices[i], vertices[j]));
    }
  }
  vector<pair<Coordinate, Coordinate>> edges;
  for (pair<Coordinate, Coordinate> e1 : mesh) {
    bool good = true;
    for (pair<Coordinate, Coordinate> e2 : mesh) {
      Coordinate* intersection = line_intersection(e1.first, e1.second, e2.first, e2.second);
      //if (!(e1.x == e2.x && e1.y == e2.y) && intersection != nullptr && 
    }
  }
  return edges;

}

double det(Coordinate a, Coordinate b) {
  return a.x * b.y - a.y * b.x;
}

Coordinate* line_intersection(Coordinate a, Coordinate b, Coordinate c, Coordinate d) {
  Coordinate xdiff = Coordinate(a.x - b.x, c.x - d.x);
  Coordinate ydiff = Coordinate(a.y - b.y, c.y - d.y);

  double div = det(xdiff, ydiff);
  if (div == 0) {
    return nullptr;
  }

  Coordinate e = Coordinate(det(a, b), det(c, d));
  double x = det(e, xdiff) / div;
  double y = det(e, ydiff) / div;
  return new Coordinate(x, y);
}


int main() {
  Coordinate a = Coordinate(0, 0);
  Coordinate b = Coordinate(1, 1);
  Coordinate c = Coordinate(1, 0);
  Coordinate d = Coordinate(0, 1);
  Coordinate* e = line_intersection(a, b, c, d);
  printf("(%f %f)\n", e->x, e->y);
}
