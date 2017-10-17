import itertools
import math

class Ropestring:

  def makerope(self, s):
    even_ropes = []
    odd_ropes = []
    current_rope = 0
    for c in s:
      if c == "-":
        current_rope += 1
      else:
        if current_rope > 0:
          if current_rope % 2 == 0:
            even_ropes.append(current_rope)
          else:
            odd_ropes.append(current_rope)
        current_rope = 0
    if current_rope > 0:
      if current_rope % 2 == 0:
        even_ropes.append(current_rope)
      else:
        odd_ropes.append(current_rope)
    even_ropes.sort(reverse = True)
    odd_ropes.sort(reverse = True)
    out = ""
    for rope in even_ropes:
      out += "-" * rope
      out += "."
    for rope in odd_ropes:
      out += "-" * rope
      out += "."
    if len(out) > len(s):
      return out[:len(out) - 1]
    else:
      return out + ("." * (len(s) - len(out)))
    return ""

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "..-..-" ], "-.-..." ),
    ( [ "-.-" ], "-.-" ),
    ( [ "--..-.---..--" ], "--.--.---.-.." ),
    ( [ "--..-.---..--..-----.--." ], "--.--.--.-----.---.-...." ),
    ( [ "..." ], "..." ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        Ropestring, 'makerope', TEST_CASES, isTestDisabled, 
        1471930165, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
