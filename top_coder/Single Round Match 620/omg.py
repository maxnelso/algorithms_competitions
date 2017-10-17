class CandidatesSelectionEasy:
  def sort(self, score, x):
    out = [0] * len(score)
    pairs = []
    for i in range(len(score)):
      pairs.append([score[i][x], i])
    pairs.sort()
    print pairs
    for i in range(len(score)):
      out[i] = pairs[i][1]
    return out

A = CandidatesSelectionEasy()
print A.sort(("A", "C", "B", "C", "A"), 0)
