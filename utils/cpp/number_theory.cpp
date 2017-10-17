#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "prettyprint.hpp"

using namespace std;

long long gcd(long long a, long long b) {
  if (a == b) {
    return a;
  }
  if (a < b) {
    swap(a, b);
  }
  while (b > 0) {
    long long tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}

long long lcm(long long a, long long b) {
  return a * b / gcd(a, b);
}

vector<long long> primes_below(long long n) {
  vector<bool> sieve(n + 1);
  fill(sieve.begin(), sieve.end(), true);
  vector<long long> primes;
  for (long long p = 2; p <= n; ++p) {
    if (sieve[p]) {
      primes.push_back(p);
      for (long long i = p*p; i <= n; i += p) {
        sieve[i] = false;
      }
    }
  }
  return primes;
}

vector<long long> small_primes = primes_below(100000);
set<long long> small_primes_set(small_primes.begin(), small_primes.end());
long long _smallprimeset = 100000;

bool is_prime(long long n, long long precision = 7) {
  if (n == 1 || n % 2 == 0) {
    return false;
  } else if (n < 1) {
    return false;
  } else if (n < _smallprimeset) {
    return small_primes_set.find(n) != small_primes_set.end();
  }

  long long d = n - 1;
  long long s = 0;
  while (d % 2 == 0) {
    d /= 2;
    s++;
  }
  for (long long repeat = 0; repeat < precision; ++repeat) {
    long long a = (rand() % (n - 2 - 2)) + 2;
    long long x = (long long) pow(a, d) % n;

    if (x == 1 || x == n - 1) {
      continue;
    }

    for (long long r = 0; r < s - 1; ++r) {
      x = (long long) pow(x, 2) % n;
      if (x == 1) {
        return false;
      }
      if (x == n - 1) {
        break;
      }
    }
  }
  return true;
}

long long pollard_brent(long long n) {
  if (n % 2 == 0) {
    return 2;
  }
  if (n % 3 == 0) {
    return 3;
  }
  long long y = (rand() % (n - 1 -1)) + 1;
  long long c = (rand() % (n - 1 -1)) + 1;
  long long m = (rand() % (n - 1 -1)) + 1;
  long long g = 1;
  long long r = 1;
  long long q = 1;
  long long ys, x;
  while (g == 1) {
    x = y;
    for (int i = 0; i < r; ++i) {
      y = (((long long) pow(y, 2) % n) + c) % n;
    }
    long long k = 0;
    while (k < r && g == 1) {
      ys = y;
      for (int i = 0; i < min(m, r - k); ++i) {
        y = (((long long) pow(y, 2) % n) + c) % n;
        q = q * abs(x - y) % n;
      }
      g = gcd(q, n);
      k += m;
    }
    r *= 2;
  }
  if (g == n) {
    while (true) {
      ys = (((long long) pow(ys, 2) % n) + c) % n;
      g = gcd(abs(x - ys), n);
      if (g > 1) {
        break;
      }
    }
  }

  return g;
}

vector<long long> prime_factors(long long n) {
  vector<long long> factors;

  long long limit = (long long) sqrt(n) + 1;
  for (long long checker : small_primes) {
    if (checker > limit) {
      break;
    }
    while (n % checker == 0) {
      factors.push_back(checker);
      n /= checker;
      limit = (long long) sqrt(n) + 1;
      if (checker > limit) {
        break;
      }
    }
  }

  if (n < 2) {
    return factors;
  }

  while (n > 1) {
    if (is_prime(n)) {
      factors.push_back(n);
      break;
    }
    long long factor = pollard_brent(n);
    for (long long a : prime_factors(factor)) {
      factors.push_back(a);
    }
    n /= factor;
  }
  return factors;
}

map<long long, int> factorization(long long n) {
  map<long long, int> factors;
  for (long long p : prime_factors(n)) {
    if (factors.find(p) == factors.end()) {
      factors[p] = 1;
    } else {
      factors[p]++;
    }
  }
  return factors;
}

vector<long long> get_divisors_helper(vector<long long> prime_list) {
  set<long long> elts_tmp(prime_list.begin(), prime_list.end());
  vector<long long> elts(elts_tmp.begin(), elts_tmp.end());
  long long num_elts = elts.size();
  vector<long long> divisors;
  function<vector<long long> (long long)> gen_inner = [&] (long long i) {
    vector<long long> temp_divisors;
    if (i >= num_elts) {
      temp_divisors.push_back(1);
      return temp_divisors;
    }
    long long this_elt = elts[i];
    long long this_max = count(prime_list.begin(), prime_list.end(), this_elt);
    vector<long long> powers;
    powers.push_back(1);
    for (long long i = 0; i < this_max; ++i) {
      powers.push_back(powers.back() * this_elt);
    }
    for (long long d : gen_inner(i+1)) {
      for (long long prime_power : powers) {
        temp_divisors.push_back(prime_power * d);
      }
    }
    return temp_divisors;
  };
  return divisors;
}

vector<long long> get_divisors(long long n) {
  return get_divisors_helper(prime_factors(n));
}

int main () {
  printf("GCD of 3 and 5: %d\n", gcd(3, 5));
  printf("GCD of 5 and 10: %d\n", gcd(5, 10));
  printf("GCD of 10 and 5: %d\n", gcd(10, 5));
  printf("\n");
  printf("LCM of 3 and 5: %d\n", lcm(3, 5));
  printf("LCM of 5 and 10: %d\n", lcm(5, 10));
  printf("LCM of 10 and 5: %d\n", lcm(10, 5));
  printf("\n");
  printf("7 is prime: %d\n", is_prime(7));
  printf("15 is prime: %d\n", is_prime(15));
  printf("29 is prime: %d\n", is_prime(29));
  printf("104729 is prime: %d\n", is_prime(104729));
  printf("Factorization for 27 ");
  cout << factorization(27) << endl;
  printf("Factorization for 55 ");
  cout << factorization(55) << endl;
}
