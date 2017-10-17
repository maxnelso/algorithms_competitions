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

class ${ClassName} {
  public: ${Method.ReturnType} ${Method.Name}(${Method.Params});
};

${Method.ReturnType} ${ClassName}::${Method.Name}(${Method.Params}) {
  return ${Method.ReturnType;zeroval};
}

${CutBegin}
${<TestCode}
${CutEnd}
