import sys
import re
import os
from bs4 import BeautifulSoup
import requests
from subprocess import Popen, PIPE, STDOUT


if __name__ == "__main__":
  name = os.path.splitext(sys.argv[1])[0]
  r = re.compile("([0-9]+)([a-zA-Z]+)")
  m = r.match(name)
  number = m.group(1)
  problem = m.group(2)
  current_problem = open("tests/current_problem.txt", "r+")
  cached = False
  line = current_problem.readline().rstrip()
  if line == number + problem:
    print "Cached problem tests"
    cached = True
  if not cached:
    current_problem.seek(0)
    current_problem.write(number + problem)
    current_problem.truncate()
    url = "http://codeforces.com/contest/{0}/problem/{1}".format(number, problem)
    print "Sending request"
    request = requests.get(url)
    data = request.text
    soup = BeautifulSoup(data, "html.parser")
    count = 0
    print "Parsing"
    for i in soup.find_all("div", class_ = "input"):
      s = str(i.pre).replace('<br/>','\n').replace('<pre>','').replace('</pre>', '')
      f = open("tests/test_{0}.in".format(count), "w")
      if (s[-1] == '\n'):
        f.write(s[:-1])
      else:
        f.write(s)
      f.close()
      count += 1
    current_problem.write("\n{0}".format(count))
    count = 0
    for i in soup.find_all("div", class_ = "output"):
      s = str(i.pre).replace('<br/>','\n').replace('<pre>','').replace('</pre>', '')
      f = open("tests/test_{0}.out".format(count), "w")
      if (s[-1] == '\n'):
        f.write(s[:-1])
      else:
        f.write(s)
      f.close()
      count += 1
  current_problem.seek(0)
  current_problem.readline()
  num_tests = int(current_problem.readline())
  for i in range(num_tests):
    if sys.argv[1].endswith(".cpp"):
      command = ["./a.out"]
    else:
      command = ["python", "{0}/problem_set/{1}".format(os.path.dirname(os.path.realpath(__file__)), sys.argv[1])]
    print "Test {0}".format(i)
    inp = open("tests/test_{0}.in".format(i), "r")
    p = Popen(command, stdout=PIPE, stdin=inp, stderr=STDOUT)
    result = p.communicate()[0]
    out = open("tests/test_{0}.out".format(i), "r")
    expected = "".join(out.readlines())
    if result.rstrip() != expected.rstrip():
      print '\033[1;31mFAILED\033[0m:\nExpected value was:\n{0}\nOutputted:\n{1}\n'.format(expected, result.rstrip())
    else:
      print '\033[1;32mPASSED\033[0m'
    inp.close()
    out.close()
