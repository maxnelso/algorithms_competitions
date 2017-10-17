import math

def winner(yang_hp, yang_atk, yang_def, m_hp, m_atk, m_def):
  yangs_damage = max(yang_atk - m_def, 0)
  monster_damage = max(m_atk - yang_def, 0)
  if yangs_damage == 0 or monster_damage == 0:
    if yangs_damage > 0 and monster_damage == 0:
      return True
    return False
  yangs_rounds_to_live = math.ceil(yang_hp / float(monster_damage))
  m_rounds_to_live = math.ceil(m_hp / float(yangs_damage))
  return yangs_rounds_to_live > m_rounds_to_live

yang_hp, yang_atk, yang_def = map(int, raw_input().split())
m_hp, m_atk, m_def = map(int, raw_input().split())
h, a, d = map(int, raw_input().split())
best_cost = 1000000000
for i in xrange(101):
  for j in xrange(101):
    for k in xrange(101):
      cost = i*h + j*a + k*d
      if winner(yang_hp + i, yang_atk + j, yang_def + k, m_hp, m_atk, m_def) and cost < best_cost:
        best_cost = cost
print best_cost

