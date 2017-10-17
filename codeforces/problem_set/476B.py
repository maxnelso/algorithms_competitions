import math

def pascal(n):
  line = [1]
  for k in range(n):
    line.append(line[k] * (n - k) / (k + 1))
  return line

good = raw_input()
good_pos = 0
for i in good:
  if i == '+':
    good_pos += 1
  else:
    good_pos -= 1

bad = raw_input()
bad_pos = 0
question_marks = 0
for i in bad:
  if i == '+':
    bad_pos += 1
  elif i == '-':
    bad_pos -= 1
  else:
    question_marks += 1

diff = bad_pos - good_pos
probs = pascal(question_marks)
s = sum(probs)
start = -question_marks
for i in range(len(probs)):
  if start == diff:
    print float(probs[i]) / s
    exit()
  start += 2

print 0.0
