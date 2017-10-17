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

class ChildStuntedness2 {
  public: vector<string> predict(vector<string> training, vector<string> testing);
};

vector<string> &split(const string &s, char delim, vector<string> &elems) {
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}
vector<string> split(const string &s, char delim) {
  vector<string> elems;
  split(s, delim, elems);
  return elems;
}

vector<string> ChildStuntedness2::predict(vector<string> training, vector<string> testing) {
  double weight_average = 0;
  double recumbent_average = 0;
  double head_average = 0;
  for (int i = 0; i < training.size(); ++i) {
    vector<string> sp = split(training[i], ',');
    weight_average += stod(sp[13]);
    recumbent_average += stod(sp[14]);
    head_average += stod(sp[15]);
  }
  weight_average = weight_average / (double) training.size();
  recumbent_average = recumbent_average / (double) training.size();
  head_average = head_average / (double) training.size();
  vector<string> out;
  for (int i = 0; i < testing.size(); ++i) {
    vector<string> sp = split(testing[i], ',');
    sp[13] = weight_average;
    sp[14] = recumbent_average;
    sp[15] = head_average;
    string delimiter = ",";
    stringstream s;
    copy(sp.begin(), sp.end(), ostream_iterator<string>(s, delimiter.c_str()));
    string fixed = s.str();
    fixed.pop_back();
    printf("Pushing %s\n", fixed.c_str());
    out.push_back(fixed);
  }
  return out;
}


int main () {
  ChildStuntedness2 dummy;
  print_container(dummy.predict({}, { "a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a",
                                      "a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a"}));





}
