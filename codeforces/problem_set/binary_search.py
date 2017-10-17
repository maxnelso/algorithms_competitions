
def binary_search(A, x):
  low = 0
  high = len(A) - 1
  while low <= high:
    mid = low + (high - low) / 2
    print low, mid, high
    if A[mid] == x:
      return True
    elif A[mid] < x:
      low = mid + 1
    else:
      high = mid - 1
  return False


print binary_search([1,2,3,4], 3)
print binary_search([1,2,3,4], 2)
print binary_search([1,2,3,4], 1)
print binary_search([1,2,3,4], 4)
print binary_search([1,2,3,4], 0)
print binary_search([1,2,3,4], 5)
