import itertools
import random


k = 3
for yvonne in itertools.product('rb', repeat=k):
  best_zara_percent = 0
  best_zara_sequence = 0
  yvonne = ''.join(yvonne)
  for zara in itertools.product('rb', repeat=k):
    zara = ''.join(zara)
    if yvonne == zara:
      continue
    yvonne_wins = 0;
    no_one_wins = 0;
    zara_wins = 0;
    trials = 10000
    for i in range(trials):
      red = 26
      black = 26
      for c in yvonne:
        if c == 'r':
          red -= 1
        if c == 'b':
          black -= 1
      for c in zara:
        if c == 'r':
          red -= 1
        if c == 'b':
          black -= 1

      last_k = []
      total_left = red + black
      winner = False
      while red + black != 0:
        red_fraction = float(red) / (red + black)
        if random.random() < red_fraction:
          red -= 1
          if len(last_k) < k:
            last_k.append('r')
          else:
            last_k.pop(0)
            last_k.append('r')
        else:
          black -= 1
          if len(last_k) < k:
            last_k.append('b')
          else:
            last_k.pop(0)
            last_k.append('b')
        if ''.join(last_k) == zara:
          zara_wins += 1
          winner = True
          break
        if ''.join(last_k) == yvonne:
          yvonne_wins += 1
          winner = True
          break
      if not winner:
        zara_wins += .5
        yvonne_wins += .5
    zara_fraction = zara_wins / float(trials)
    print 'trying ' + zara + ' with fraction ' + str(zara_fraction)
    if zara_fraction > best_zara_percent:
      best_zara_sequence = zara
      best_zara_percent = zara_fraction
  print 'For yvonne ' + yvonne + ' best zara is ' + best_zara_sequence + ' with percent ' + str(best_zara_percent)
