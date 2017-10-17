from collections import defaultdict
from competitions.utils.python.union_find import UnionFind
import heapq

class Node(object):

  def __init__(self, name = ""):
    self.name = name

  def __repr__(self):
    return self.name

class Edge(object):

  def __init__(self, src, dest, weight = 1.0):
    self.src = src
    self.dest = dest
    self.weight = weight

  def __repr__(self):
    return "{0} -> {1} ({2})".format(self.src, self.dest, self.weight)

class Digraph(object):

  def __init__(self):
    self.nodes = []
    self.edges = {}

  def add_node(self, node):
    """
    Adds a node to the graph.
    """
    if node in self.nodes:
      raise ValueError('Duplicate node')
    self.nodes.append(node)
    self.edges[node] = []

  def add_edge(self, edge):
    """
    Adds an edge to the graph
    """
    self.edges[edge.src].append(edge)


class UndirectedGraph(Digraph):

  def add_edge(self, edge):
    """
    Override
    """
    super(UndirectedGraph, self).add_edge(edge)
    reverse = Edge(edge.dest, edge.src, edge.weight)
    super(UndirectedGraph, self).add_edge(reverse)

  def prims_algorithm(self):
    """
    Returns a set of edges that form the minimum spanning tree of the graph.
    Note that this graph must be connected. Taken from
    http://programmingpraxis.com/2010/04/09/minimum-spanning-tree-prims-algorithm/
    """
    connections = defaultdict(list)
    for node in self.edges:
      for e in self.edges[node]:
        connections[e.src].append((e.weight, e.src, e.dest, e))
        connections[e.dest].append((e.weight, e.dest, e.src, e))
    mst = set()
    used = set()
    used.add(node) # Last element of iterating, hacky
    usable_edges = connections[node][:]
    heapq.heapify(usable_edges)
    while len(usable_edges) > 0:
      weight, n1, n2, e = heapq.heappop(usable_edges)
      if n2 not in used:
        used.add(n2)
        mst.add(e)
        for edge in connections[n2]:
          if edge[2] not in used:
            heapq.heappush(usable_edges, (edge[0],
                                          edge[1],
                                          edge[2],
                                          edge[3]))
    return mst
