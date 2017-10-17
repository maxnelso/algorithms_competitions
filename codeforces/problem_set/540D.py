import math
import sys

MAX = 105

def main():
  r, s, p = map(int, raw_input().split())

  dp = {}
  for i in range(1, MAX):
    dp[(i, 0, 0)] = (1, 0, 0);
    dp[(0, i, 0)] = (0, 1, 0);
    dp[(0, 0, i)] = (0, 0, 1);

  def solve(r, s, p):
    if (r, s, p) in dp:
      return dp[r, s, p]
    r_wins = 0
    s_wins = 0
    p_wins = 0
    total = float(r + s + p)
    other_probs = 0
    if r >= 2:
      other_probs += (r / total) * ((r - 1) / (total - 1))
    if s >= 2:
      other_probs += (s / total) * ((s - 1) / (total - 1))
    if p >= 2:
      other_probs += (p / total) * ((p - 1) / (total - 1))
    other_probs = 1- other_probs
    # Rock meets scissors
    if r > 0 and s > 0:
      prob = (r / total) * (s / (total - 1)) + \
             (s / total) * (r / (total - 1))
      prob /= other_probs
      sim = solve(r, s - 1, p)
      r_wins += prob * sim[0]
      s_wins += prob * sim[1]
      p_wins += prob * sim[2]
    # Rock meets paper
    if r > 0 and p > 0:
      prob = (r / total) * (p / (total - 1)) + \
             (p / total) * (r / (total - 1))
      prob /= other_probs
      sim = solve(r - 1, s, p)
      r_wins += prob * sim[0]
      s_wins += prob * sim[1]
      p_wins += prob * sim[2]
    # Paper meets scissors
    if p > 0 and s > 0:
      prob = (s / total) * (p / (total - 1)) + \
             (p / total) * (s / (total - 1))
      prob /= other_probs
      sim = solve(r, s, p - 1)
      r_wins += prob * sim[0]
      s_wins += prob * sim[1]
      p_wins += prob * sim[2]
    out = (r_wins, s_wins, p_wins)
    dp[(r, s, p)] = out
    return out

  solve(r, s, p)
  out = dp[(r,s,p)]
  print out[0], out[1], out[2]


if __name__ == '__main__':
  main()
