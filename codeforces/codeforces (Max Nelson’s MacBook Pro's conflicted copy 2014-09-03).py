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
  url = "http://codeforces.com/problemset/problem/{0}/{1}".format(number, problem)
  print "Sending request"
  request = requests.get(url)
  data = request.text
  soup = BeautifulSoup(data)
  if len(soup.find_all("div", class_ = "input")) == 0: # a contest
    url = "http://codeforces.com/contest/{0}/problem/{1}".format(number, problem)
    request = requests.get(url)
    data = request.text
  print "Received data"
  soup = BeautifulSoup(data)
  inputs = []
  outputs = []
  print "Parsing"
  for i in soup.find_all("div", class_ = "input"):
    s = str(i.pre).replace('<br/>','\n').replace('<pre>','').replace('</pre>', '')
    if (s[-1] == '\n'):
      inputs.append(s[:-1])
    else:
      inputs.append(s)
  for i in soup.find_all("div", class_ = "output"):
    s = str(i.pre).replace('<br/>','\n').replace('<pre>','').replace('</pre>', '')
    if (s[-1] == '\n'):
      outputs.append(s[:-1])
    else:
      outputs.append(s)
  for i in range(len(inputs)):
    command = "./a.out"
    print "Test {0}".format(i)
    p = Popen([command], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
    result = p.communicate(inputs[i])[0]
    if result.rstrip() != outputs[i].rstrip():
      print '\033[1;31mFAILED\033[0m: Expected value was {0}, outputted {1}'.format(outputs[i], result.rstrip())
    else:
      print '\033[1;32mPASSED\033[0m'
