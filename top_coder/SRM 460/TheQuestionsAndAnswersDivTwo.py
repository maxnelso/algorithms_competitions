import itertools
import math

class TheQuestionsAndAnswersDivTwo:

  def find(self, questions):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ("How_are_you_doing?","How_do_you_like_our_country?","How_are_you_doing?",) ], 4 ),
    ( [ ("Whazzup?",) ], 2 ),
    ( [ ("Are_you_ready?","Are_you_ready?","Are_you_ready?","Are_you_ready?",) ], 2 ),
    ( [ ("Do_you_like_my_story?","Do_you_like_my_story","DO_YOU_LIKE_MY_STORY?","Do__you__like__my__story?",) ], 16 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        TheQuestionsAndAnswersDivTwo, 'find', TEST_CASES, isTestDisabled, 
        1477365005, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
