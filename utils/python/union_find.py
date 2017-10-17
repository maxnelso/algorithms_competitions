class UnionFind:
  def __init__(self):

    self.num_weights = {}
    self.parent_pointers = {}
    self.num_to_objects = {}
    self.objects_to_num = {}

  def insert_objects(self, objects):
    for object in objects:
      self.find(object);

  def find(self, object):
    if not object in self.objects_to_num:
      obj_num = len(self.objects_to_num)
      self.num_weights[obj_num] = 1
      self.objects_to_num[object] = obj_num
      self.num_to_objects[obj_num] = object
      self.parent_pointers[obj_num] = obj_num
      return object
    stack = [self.objects_to_num[object]]
    parent = self.parent_pointers[stack[-1]]
    while parent != stack[-1]:
      stack.append(parent)
      parent = self.parent_pointers[parent]
    for i in stack:
      self.parent_pointers[i] = parent
      return self.num_to_objects[parent]

  def union(self, object1, object2):
    o1p = self.find(object1)
    o2p = self.find(object2)
    if o1p != o2p:
      on1 = self.objects_to_num[o1p]
      on2 = self.objects_to_num[o2p]
      w1 = self.num_weights[on1]
      w2 = self.num_weights[on2]
      if w1 < w2:
        o1p, o2p, on1, on2, w1, w2 = o2p, o1p, on2, on1, w2, w1
      self.num_weights[on1] = w1+w2
      del self.num_weights[on2]
      self.parent_pointers[on2] = on1

  def get_sets(self):
    sets = [[]]*len(self.objects_to_num)
    for i in xrange(len(self.objects_to_num)):
      sets[i] = []
    for i in self.objects_to_num:
      sets[self.objects_to_num[self.find(i)]].append(i)
    return filter(lambda a: a != [], sets)
