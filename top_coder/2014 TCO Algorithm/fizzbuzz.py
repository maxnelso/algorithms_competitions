class FizzBuzzTurbo:
  def counts(self, A, B):
    fizzes = (B / 3) - (A / 3)
    if (A % 3 == 0):
      fizzes = fizzes + 1
    buzzes = (B / 5) - (A / 5)
    if (A % 5 == 0):
      buzzes = buzzes + 1
    fizzbuzzes = (B / 15) - (A / 15)
    if (A % 15 == 0):
      fizzbuzzes = fizzbuzzes + 1
    fizzes = fizzes - fizzbuzzes
    buzzes = buzzes - fizzbuzzes
    return (fizzes, buzzes, fizzbuzzes)


A = FizzBuzzTurbo()
print A.counts(0,10**18)
print A.counts(10**15,10**18)
