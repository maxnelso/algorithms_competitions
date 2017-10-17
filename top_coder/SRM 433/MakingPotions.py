import itertools
import collections
import math

class MakingPotions:

  memo = {}

  def getCheapest(self, marketGoods, costs, recipes, potionType, seen):
    if potionType in self.memo:
      return self.memo[potionType]
    cost = -1
    if potionType in marketGoods:
      cost = costs[marketGoods.index(potionType)]

    print 'Looking at ', potionType
    for recipe in recipes:
      result, ins = recipe.split('=')
      if result != potionType:
        continue
      ingredients = ins.split('+')
      total_cost = 0
      for ingredient in ingredients:
        amount, name = int(ingredient[0]), ingredient[1:]
        if name in seen: # Cycle
          total_cost = -1
          break
        seen_copy = seen.copy()
        seen_copy.add(name)
        potion_cost = self.getCheapest(marketGoods, costs, recipes, name, seen_copy)
        print 'For', potionType, 'checking out', name, 'cost being', potion_cost
        if potion_cost == -1:
          total_cost = -1
          break
        total_cost += amount * potion_cost
        print 'ok', potionType, total_cost
      if total_cost != -1 and total_cost < cost or cost == -1:
        cost = total_cost

    if cost > 1000000000:
      cost = 1000000001
    self.memo[potionType] = cost
    print 'Cost of ', potionType, 'is ', cost
    return cost


  def getCost(self, marketGoods, cost, recipes):
    self.memo = {}
    cost = self.getCheapest(marketGoods, cost, recipes, 'LOVE', set())
    print self.memo
    return cost

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    #( [ ("LOVE","WATER","HONEY",), (100,1,30,), ("LOVE=5WATER+3HONEY",) ], 95 ),
    #( [ ("WATER","HONEY","HOP",), (2,6,9,), ("LOVE=2WATER+4HONEY+2BEER","BEER=1HOP+3WATER+1HOP",) ], 76 ),
    #( [ ("ORANGEJUICE","APPLEJUICE",), (6,4,), ("JUICEMIX=1ORANGEJUICE+1APPLEJUICE",) ], -1 ),
    #( [ ("WATER","HONEY","HOP",), (1,22,17,), ("LOVE=7WATER+3HONEY","LOVE=2HONEY+2HOP",) ], 73 ),
    #( [ ("OIL","WATER",), (60,70,), ("FIRSTPOTION=1OIL+1SECONDPOTION","SECONDPOTION=4WATER+1FIRSTPOTION","LOVE=1FIRSTPOTION+1SECONDPOTION",) ], -1 ),
    #( [ ("HONEYBIT",), (100,), ("LOVE=6HONEYMEGABYTE","HONEYMEGABYTE=2HONEYFIFTYTWELVEKBYTES","HONEYFIFTYTWELVEKBYTES=8HONEYSIXTYFOURKBYTES","HONEYSIXTYFOURKBYTES=8HONEYEIGHTKBYTES","HONEYEIGHTKBYTES=8HONEYKBYTE","HONEYKBYTE=2EIGHTBYEIGHTWORDS","EIGHTBYEIGHTWORDS=8EIGHTWORDS","EIGHTWORDS=8HONEYWORD","HONEYWORD=8HONEYBYTE","HONEYBYTE=8HONEYBIT",) ], 1000000001 ),
    ( [ ("SE", "VB", "GZ", "VZ", "JI", "EJ", "OI", "VK"), (45, 25, 10, 51, 19, 74, 82, 68,), ("VK=4EN+6GZ+8IG", "EN=3VZ", "IG=8VZ+2GZ", "JZ=7IG+9SE+2VZ+4EN+1EJ", "VZ=8VB", "VK=1GZ+6SE+5VK+7JZ+8EJ", "SE=4JI+6VB+9VB+4HB+8EN", "EN=3HB+8VB+3EJ+1GZ+8VB", "IG=1IG+2EN+7JI+1GZ+5EJ", "VB=6HB+9VK+2VB+1HB+9VK", "VB=2JZ+4OI+3GZ+4HB+8JI", "GZ=8OI+5VZ+5HB+2VZ+9EJ", "GZ=1EJ+1JI+2HB+4JZ+9JZ", "GZ=5JI+1VZ", "EN=7OI+5VZ+6HB+6GZ+6JI", "GZ=9GZ+5EJ+2HB+6HB+2JI", "GZ=7JI+7HB+7HB+9JZ+4JZ", "IG=1EJ+3SE+4VB+4HB+3EN", "LOVE=2EN+2JZ+3GZ", "IG=4VB+8SE+4GZ+4JI+4GZ", "VB=1VK+2VK+3JI+6JZ+7OI", "VK=3HB+8JZ+2EJ+3SE+7GZ", "SE=8OI+5SE+2HB+8JI+3EN", "JZ=6EN+7EJ+1IG+9EJ+4VZ", "IG=2EJ+4VB+6VB", "VK=1VZ+7SE+6VZ+5JI+3JZ", "VZ=5HB+1EJ") ], 5744),
    #( [ ("WATER",), (1,), ("LOVE=1LOVE",) ], -1 ),
    #( [ ("MILK","WATER","HOP",), (6,1,14,), ("NECTAR=4HOP+2MILK","LOVE=5MILK+3BEER","LOVE=2WATER+1LOVE","LOVE=2MIX+1NECTAR","MIX=1MILK+1WATER+1HOP","BEER=5WATER+2HOP","LOVE=1NECTAR+3WATER+3HOP","NECTAR=3BEER+1MILK+2MILK",) ], 110 ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        MakingPotions, 'getCost', TEST_CASES, isTestDisabled, 
        1476398824, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
