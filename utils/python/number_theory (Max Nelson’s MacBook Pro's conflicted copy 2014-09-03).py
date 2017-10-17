import math
import random


def gcd(a, b):
  """
  Returns the greatest common divisor of two numbers
  """
  if a == b: return a
  while b > 0: a, b = b, a % b
  return a

def lcm(a, b):
  """
  Returns the least common multiple between two numbers.
  """
  return a * b // gcd(a, b)

def lcmm(args):
  """
  Return lcm of a list of integers.
  """
  return reduce(lcm, args)

def get_divisors_helper(prime_list):
  elts = sorted(set(prime_list))
  numelts = len(elts)
  divisors = []
  # Split on the number of copies of elts[i].
  def gen_inner(i):
    temp_divisors = []
    if i >= numelts:
      temp_divisors.append(1)
      return temp_divisors
    thiselt = elts[i]
    thismax = prime_list.count(thiselt)

    # powers <- [thiselt**i for i in range(thismax+1)],
    # but using only thismax multiplications.
    powers = [1]
    for j in xrange(thismax):
      powers.append(powers[-1] * thiselt)

    for d in gen_inner(i+1):
      for prime_power in powers:
        temp_divisors.append(prime_power * d)
    return temp_divisors
  result = gen_inner(0)
  for d in result:
    divisors.append(d)
  return divisors

def get_divisors(n):
  """
  Returns a list of divisors the number n.
  """
  return get_divisors_helper(prime_factors(n))

def primes_below(n):
  """
  From http://stackoverflow.com/questions/2068372/fastest-way-to-list-all-primes-below-n-in-python/3035188#3035188
  Input n >= 6, returns a list of primes, 2 <= p < n.
  """
  correction = n % 6 > 1
  n = {0:n, 1:n-1, 2:n+4, 3:n+3, 4:n+2, 5:n+1}[n%6]
  sieve = [True] * (n // 3)
  sieve[0] = False
  for i in range(int(n ** .5) // 3 + 1):
    if sieve[i]:
      k = (3 * i + 1) | 1
      sieve[k*k // 3::2*k] = [False] * ((n//6 - (k*k)//6 - 1)//k + 1)
      sieve[(k*k + 4*k - 2*k*(i%2)) // 3::2*k] = [False] * ((n // 6 - (k*k + 4*k - 2*k*(i%2))//6 - 1) // k + 1)
  return [2, 3] + [(3 * i + 1) | 1 for i in range(1, n//3 - correction) if sieve[i]]

smallprimeset = set(primes_below(100000)) 
_smallprimeset = 100000
def is_prime(n, precision=7):
  """
  From http://en.wikipedia.org/wiki/Miller-Rabin_primality_test#Algorithm_and_running_time
  Returns True if n is prime, False otherwise.
  """
  if n == 1 or n % 2 == 0:
    return False
  elif n < 1:
    return False
  elif n < _smallprimeset:
    return n in smallprimeset


  d = n - 1
  s = 0
  while d % 2 == 0:
    d //= 2
    s += 1

  for repeat in range(precision):
    a = random.randrange(2, n - 2)
    x = pow(a, d, n)

    if x == 1 or x == n - 1: continue

    for r in range(s - 1):
      x = pow(x, 2, n)
      if x == 1: return False
      if x == n - 1: break
    else: return False

  return True

def pollard_brent(n):
  """
  From https://comeoncodeon.wordpress.com/2010/09/18/pollard-rho-brent-integer-factorization/
  """
  if n % 2 == 0: return 2
  if n % 3 == 0: return 3

  y, c, m = random.randint(1, n-1), random.randint(1, n-1), random.randint(1, n-1)
  g, r, q = 1, 1, 1
  while g == 1:
    x = y
    for i in range(r):
      y = (pow(y, 2, n) + c) % n

    k = 0
    while k < r and g==1:
      ys = y
      for i in range(min(m, r-k)):
        y = (pow(y, 2, n) + c) % n
        q = q * abs(x-y) % n
      g = gcd(q, n)
      k += m
    r *= 2
  if g == n:
    while True:
      ys = (pow(ys, 2, n) + c) % n
      g = gcd(abs(x - ys), n)
      if g > 1:
        break

  return g

smallprimes = primes_below(1000)
def prime_factors(n, sort=False):
  """
  Returns a list of prime factors of n.
  """
  factors = []

  limit = int(n ** .5) + 1
  for checker in smallprimes:
    if checker > limit: break
    while n % checker == 0:
      factors.append(checker)
      n //= checker
      limit = int(n ** .5) + 1
      if checker > limit: break

  if n < 2: return factors

  while n > 1:
    if is_prime(n):
      factors.append(n)
      break
    factor = pollard_brent(n) # trial division did not fully factor, switch to pollard-brent
    factors.extend(prime_factors(factor)) # recurse to factor the not necessarily prime factor returned by pollard-brent
    n //= factor

  if sort: factors.sort()

  return factors

def factorization(n):
  """
  Returns a dictionary of prime factor -> count for the prime factorization of
  n.
  """
  factors = {}
  for p1 in prime_factors(n):
    try:
      factors[p1] += 1
    except KeyError:
      factors[p1] = 1
  return factors

totients = {}
def totient(n):
  """
  Returns the number of positive integers less than or equal to n that are
  relatively prime to n.
  """
  if n == 0: return 1

  try: return totients[n]
  except KeyError: pass

  tot = 1
  for p, exp in factorization(n).items():
    tot *= (p - 1)  *  p ** (exp - 1)

  totients[n] = tot
  return tot

f = factorization(1000000000)
print f
