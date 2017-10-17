import itertools
import math

class CondorcetVoting:

  def winner(self, votes):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ("acbd","bacd","bdca",) ], 0 ),
    ( [ ("abc","bca","cab",) ], -1 ),
    ( [ ("cezdqcw",) ], -1 ),
    ( [ ("abcd","abcd","abcd","abcd","abcd","abcd","cbad","cbad","cbad","cbad","cbad","dbca","cbda","cbda",) ], 1 ),
    ( [ ("abbcbbbaaccaaccbbacbbbaacbccbccacaaacaacaaacbccaac","accbabcaacacbcccbbccbbcaccccccbbcbbcbaccbcbcacbcbc","acacaaabccaaaccabbaaaacabaaabacacbaacbcccbccbcbacb","acbcbabaabbcaababaacbabcacbaccabbaaacccbcabbbcacba","cbbbacbbacccbbabbbcbaabaaaacaacbcbccbaaccbcaaccbcb","cbacbbcbbcbcaaabccabcabbcbacaaabccabbcbacbbacbbaca","cacaabccbbbaaacccacbbcacababbcaaabccbbacbbbccacbaa","bccbbabaaaababcbabbbbcbcacbcbcbacccacacacacacacaab","bccabcaabcabbccaaccbcabaaabbbcaabaaabbbbabbbaabaac","accccbabaaaabcbacabbcbbacaacaaaacccbbbcacaccccaaac","cccbcaababbaacaaabbbaabbccccacaacbacaacbbbaacccbbb","bccccaccbcbbaaaaaaaaccbababcabaaccacbbabbbcabbaaca","cbacacaabbccacaabbbbbbccabcbbaccacbcacacacbccbcbcc","baabcabccaaaaccbaacaaccacccbcbbaaacacaccbcaacbbbba","bccaaaabcbbcbbbbbcaabaacccbccbbcbabacaaccbccaababb","cacbbbbcabbcbaabbccbaccbaacbbcbbbbcabababccabbbcab","bccbcacbccaacacccccaacabacbacbbbcaabacacccbbbccaac","aaaccbbbacacbaaaacacaabbaacccbcccbcabbccbcacabbacb","bcabcbbacbacacbbaaccabcabcbbaabacacccbbbcabbbcaacb","bacbbbbaccbaabbbbbcaccbbcbcabbbccbcacccbabbbcaaacc","bababcacbacacacccccbbcacccbbcbccaccaacbbcacabcabba","aaabaccbbcacaacbabccccabbbcbcccccccbaacbccbaacbbbc","abacbaaaaaccacbbbaccbbbabaacbcbccacccabaaaacbaabbb","cbbcacbaccabbbcaacbcbabbcabcbaccabcbbbcabcbcbaacca","babbacaaacbbcbbbabbaabcbabcbbaacaacbbbaaaabbcabcca","cbabaacabcccaabbbacccaccbacabbaacaaabcbcccbcbcccaa","aabbbcbacabbcabcbcccbccaccbcacbaacabbbccaabaabcbba","caccabcccabbaacbabbaaaccccccccaaccbcaccacaabacccba","bbbcabcababaabacaccacabcbccacccbbbbcbbbaccabcabaab","bbbcaababbbbababababcbbbbaaabbacaabcacbbccbcaaaaaa","bcbacccaaaabbcbcabbbcababbcacaabbbbcbbacbaabcbaccb","bbcaccaaccacbbaaccaaaabccbbacbcbacaacbacbccaaccbba","abaaacbccbbabbcaccbaccccbaaacaccccababcbccccbabcca","acccaccababababacbbaccbcabcaccbabaabacbaacaaacabca","aaabababccabccbcbabcabcacbbcacbcbbbabcabacbcaacacb","ccacbaabbcbaccaccbbabbabbabaacccabcaaccacacccbbcab","bbaabcbabbbaacacabaabcbaaabacbccccaccaaaacbacabbbc","abaaaccaacbbcacacbcbccbaaacbbcbacabbbccabbbccaaaac","bbacbabbcacbbacccaccbcbcabbcbaacabbbbabbaaabaacacb","cacbacbccbcbabacccacabcacacabbcabbccaacacbaaacaacb","bacbbacbccccabcbabcbbcbacacaaabcbaccccaabaabbacbcb","abcaaccccabccaaaaccbabccacbcaaaacaccaccccccaaaabaa","bacabcbccbacccbaaaabcbbaabbabaabcabacccbcabacccbcc","babaccbbcbcbacccabccbcccbaaaaacccabcbccbbbbcbabcbc","cccbbaccbabbbbcbcbcbaaacbbcacbcaacacacccbcabccbcaa","caacbcacbccaaaaacaaababbcccacbabaaabcaacaaababacba","cccccaccabcaacababbacbcbabbcaacbacbabbbccbabcbabbb","ccbcababcabcbcccaccccacabcbaaacaabccbbaabaccbaccab","abbbcacaccabcbccbacabbbccaccaaaacccabbcbacbbccabcb","bacabccabcbbcaacbcacabcbccacbcccbcbcaaaabbaabccabb",) ], 12 ),
    ( [ ("h","e","l","l","o",) ], 0 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        CondorcetVoting, 'winner', TEST_CASES, isTestDisabled, 
        1412292480, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
