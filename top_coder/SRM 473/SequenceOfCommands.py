import itertools
import math

class SequenceOfCommands:

  def dir_to_diff(self, dir):
    if dir == "N":
      return (0, 1)
    elif dir == "E":
      return (1, 0)
    elif dir == "S":
      return (0, -1)
    else:
      return (-1, 0)

  def next_dir(self, current, command):
    if current == "N":
      return "E" if command == "R" else "W"
    elif current == "E":
      return "S" if command == "R" else "N"
    elif current == "S":
      return "W" if command == "R" else "E"
    elif current == "W":
      return "N" if command == "R" else "S"

  def whatHappens(self, commands):
    start = (0, 0, "N")
    diff = 0
    seen_step = False
    seen = {}
    for i in range(100):
      if start in seen:
        return "bounded"
      seen[start] = True
      for l in commands:
        for c in l:
          if c == "S":
            start = (start[0] + self.dir_to_diff(start[2])[0], start[1] + self.dir_to_diff(start[2])[1], start[2])
          else:
            start = (start[0], start[1], self.next_dir(start[2], c))
    return "unbounded"


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ("L",) ], "bounded" ),
    ( [ ("SRSL",) ], "unbounded" ),
    ( [ ("SRSRSRSR") ], "bounded" ),
    ( [ ("SSSS","R",) ], "bounded" ),
    ( [ ("SRSL","LLSSSSSSL","SSSSSS","L",) ], "unbounded" ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        SequenceOfCommands, 'whatHappens', TEST_CASES, isTestDisabled, 
        1475373488, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
