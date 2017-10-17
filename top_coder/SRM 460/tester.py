# vexorian's Generic Tester example! version 0.7
#  - Ansi color codes to make output easy to read.
#  - run_tests needs a lot of arguments... 
# (c) 2013 Victor Hugo Soliz Kuncar, ZLIB/LibPNG license 

import sys
import time
import traceback
import os

FULL_REPORT    = 0;
COMPACT_REPORT = 1;
ONLY_REPORT    = 2;

# Name the color codes:
COLOR_RESET  = "\033[0m";    

BRIGHT_GREEN   = "\033[1;32m";
BRIGHT_RED     = "\033[1;31m";
NORMAL_CROSSED = "\033[0;9;37m";
RED_BACKGROUND = "\033[1;41m";
NORMAL_FAINT   = "\033[0;2m";
BRIGHT_CYAN    = "\033[1;36m";

# Configuration:
BAR_LENGTH = 73; #length of the bar === that separates test cases
BAR_COLOR  = NORMAL_FAINT;  #The bar ====
TEST_COLOR = BRIGHT_CYAN; #Color for the word "Test"

GRADE_COLOR = [
    RED_BACKGROUND, # bad (overall), 
    BRIGHT_RED,   # bad (case),
    COLOR_RESET,  # neutral
    BRIGHT_GREEN  # good
]

RESULT_COLOR = {
    '+' : BRIGHT_GREEN,
    'X' : BRIGHT_RED,
    'T' : BRIGHT_RED,
    'E' : RED_BACKGROUND,
    '?' : COLOR_RESET,
    'd' : NORMAL_CROSSED,
}

def disableColors():
    COLOR_RESET  = ''        
    BRIGHT_GREEN   = ''
    BRIGHT_RED     = ''
    NORMAL_CROSSED = ''
    RED_BACKGROUND = ''
    NORMAL_FAINT   = ''
    BRIGHT_CYAN    = ''
    global GRADE_COLOR
    GRADE_COLOR = [''] * len(GRADE_COLOR)
    copy = [x for x in RESULT_COLOR]
    for x in copy :
        RESULT_COLOR[x] = ''

def colorCode(q):
    return GRADE_COLOR[q+2] + "%s" + COLOR_RESET  

def colorTestResult(r):
    return '%s%s%s' % (RESULT_COLOR[r], r, COLOR_RESET)

def prettyStr(x):
    sel = {
        str  : lambda: '"%s"' % x,
        tuple: lambda: '(%s)' % (','.join( (prettyStr(y) for y in x) ) ),
        list : lambda: '[%s]' % (','.join( (prettyStr(y) for y in x) ) ),
    }
    return sel.get(type(x), lambda:str(x) )()

def prettyCase(i, n):
    return ( "%%%dd" % max(len(str(n-1)), 1) ) % i

def tc_equal(expected, received):
    try:
        _t = type(expected)
        received = _t(received)
        if _t == list or _t == tuple:
            if len(expected) != len(received): return False
            return all(tc_equal(e, r) for (e, r) in zip(expected, received))
        elif _t == float:
            eps = 1e-9
            if abs(expected - received) < eps: return True
            if abs(received) > abs(expected) * (1.0 - eps) and abs(received) < abs(expected) * (1.0 + eps): return True
        else:
            return expected == received
    except:
        return False

def run_testcase( problemClass, methodName, testInExpected, caseNo, totalCase, testTimeOut, finalLines, compactMode ):
    (testIn, expected) = testInExpected # so that it compiles in python3
    if compactMode != ONLY_REPORT: 
        sys.stdout.write(TEST_COLOR + "Test " + str(caseNo) + COLOR_RESET + ": " + prettyStr(testIn)+"\n")
    startTime = time.time()
    instance = problemClass()
    exception = None
    try:
        result = getattr(instance, methodName)(*testIn);
    except Exception as e:
        ln = None
        for x in traceback.extract_tb(sys.exc_traceback):
            if x[0] == problemClass.__name__+'.py':
                ln = x[1] 
        if ln is None:
            exceptionShort = '%s, (unknown line)'%( type(e).__name__ )
        else:
            exceptionShort = '%s, line: %d'%( type(e).__name__, ln )
        exception = traceback.format_exc()
        
    elapsed = time.time() - startTime   # in sec
    if compactMode != ONLY_REPORT:
        sys.stdout.write("Time: %.02f seconds.\n" % elapsed)

    if exception is not None:
        if compactMode != ONLY_REPORT:
            sys.stdout.write("RUNTIME ERROR: \n")
            sys.stdout.write(exception)
        correct = False
    else:
        correct = expected is None or tc_equal(expected, result)
        if compactMode != ONLY_REPORT:
            if not correct:
                sys.stdout.write("Desired answer:\n")
                sys.stdout.write("\t%s\n" % prettyStr(expected) )
            sys.stdout.write("Your answer:\n")
            sys.stdout.write("\t%s\n" % prettyStr(result) )
    
    res = '?'
    if exception is not None:
        res = 'E'
    elif not correct:
        res = 'X'
    elif elapsed > testTimeOut:
        res = 'T'
    elif expected is not None:
        res = '+'
    
    # final lines:
    s = ( TEST_COLOR + "t" + prettyCase(caseNo, totalCase) + COLOR_RESET + ": " + colorTestResult(res) )
    s += (" (%.2fs)" % elapsed)
    if res in ('?', 'X'):
        s += (" (" + prettyStr( result)+ ")" )
    elif res == 'E':
        s += (" " + exceptionShort)
    finalLines.append(s)

    if compactMode != ONLY_REPORT:
        sys.stdout.write(" %s\n" % colorTestResult(res) )
        sys.stdout.write( BAR_COLOR + ('='*BAR_LENGTH) + COLOR_RESET + "\n")
    return res

#-------------------------------------------------------------------------------------------------------
# run_tests() starts the tester.
#
# problemClass: The class of the solution to the problem
# methodName  : String equal to the name of the method that needs to be called.
# testCases   : A list of tuples. Each tuple is a test case. ( input, output)
#               input is a tuple of arguments. output is the return value or None 
# isTestDisabled: A function, returns True if the test case id is disabled.
# problemScore  : The score of the problem.
# testTimeOut   : The time required for each test case. 
# compactMode   : True if you want the final report to be a single line.  
# 
def run_tests( problemClass, methodName, testCases, isTestDisabled, createTime, problemScore, testTimeOut, compactMode):
    result = ''
    finalLines = []
    header = "%s:\n\n" % problemClass.__name__
    if compactMode == ONLY_REPORT:
        sys.stdout.write( header )
    for i in xrange(0, len(testCases)):
        ch = 'd'
        if isTestDisabled(i):
            finalLines.append( '%st%s%s: %s' %( TEST_COLOR, prettyCase(i,len(testCases)) , COLOR_RESET, colorTestResult('d') ) )
        else:
            ch = run_testcase( problemClass, methodName, testCases[i] , i, len(testCases), testTimeOut, finalLines, compactMode)
        finalLines[-1] = ' ' + finalLines[-1]    
        if compactMode == ONLY_REPORT:
            sys.stdout.write( '%s\n' % finalLines[-1] )
        result += ch
        
    if compactMode == FULL_REPORT:
        sys.stdout.write( header )
        for ln in finalLines:
            sys.stdout.write('%s\n' % str(ln)  )

    line = "%s: %s" % ( problemClass.__name__, ' '.join( (colorTestResult(ch) for ch in result) ) )
    T = time.time() - createTime
    PT, TT = (T / 60.0, 75.0)
    points = problemScore * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
    points = "%.2f" % points
    q = 1
    if any( ch not in ('+','?') for ch in result ):
        q = -2
    points = colorCode(q) %  points
    if compactMode != COMPACT_REPORT:
        sys.stdout.write("\n%s\n" % points)
    else:
        line = "%s (%s)" % (line, points)
        sys.stdout.write("%s\n" % line)

if __name__ == '__main__':
    sys.stdout.write("Not supposed to run this")
