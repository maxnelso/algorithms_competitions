from fractions import gcd

def f(x):
  #return (x**2)*(x-1)*(x-2)
  #return (x**2)*(x-2)*(x-3)**4

  return (x-0)**3 * \
        (x-1)**1 * \
        (x-2)**4 * \
        (x-3)**1 * \
        (x-4)**5 * \
        (x-5)**9 * \
        (x-6)**2 * \
        (x-7)**6 * \
        (x-8)**5 * \
        (x-9)**3 * \
        (x-10)**5

out = []
for i in range(20):
  print f(i)
  if f(i) > 0:
    out.append(f(i))

gcd = reduce(lambda x,y: gcd(x, y), out)
print gcd % 1000000007
