class Whatever:
  def __init__(self):
    self.exact_count_cache = {}
    self.exact_count_cache[0] = 0
    self.exact_count_cache[1] = 1
  
  def count(self, n):
    ans = 0
    ans += self.exact_count(n)
    return ans
    
  def exact_count(self, n):
    # You have to use all the letters.
    if n in self.exact_count_cache:
      return self.exact_count_cache[n]
    ans = self.factorial(n - 1) * self.combination(n, 2) * n
    ans %= 1000000007
    self.exact_count_cache[n] = ans
    return ans
    
  def factorial(self, k):
    product = 1
    for i in range(k):
        product = product * (i + 1)
    return product
    
  def combination(self, n, r):
    return self.factorial(n) / (self.factorial(r) * self.factorial(n - r))

A = Whatever()
print A.count(1)
print A.count(2)
print A.count(5)