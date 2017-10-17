import java.util.*;

/**
 * Basic graph implementation.
 *
 * @author Max Nelson
 *
 */
class Node {

  public int value;
  public int index;
  public int lowlink;

  public Node() {
    this.index = -1;
    this.lowlink = -1;
  }

  public Node(int value) {
    this.value = value;
    this.index = -1;
    this.lowlink = -1;
  }

}

class Edge {

  public Node src;
  public Node dest;
  public double weight;

  public Edge(Node src, Node dest) {
    this.src = src;
    this.dest = dest;
    this.weight = 1.0;
  }

  public Edge(Node src, Node dest, double weight) {
    this.src = src;
    this.dest = dest;
    this.weight = weight;
  }

  public int compareTo(Edge e) {
     return (int) (this.weight - e.weight);
  }

}

class DirectedGraph {

  public HashMap<Node, ArrayList<Edge>> edges;
  private Stack<Node> nodeStack;
  private int index;
  public ArrayList<ArrayList<Node>> stronglyConnectedComponents;
  public boolean hasCycle;
  public ArrayList<Edge> minimumSpanningTree;
  public HashMap<Node, HashMap<Node, Double>> shortestPathsLengths;
  public HashMap<Node, HashMap<Node, ArrayList<Node>>> shortestPaths;
  private HashMap<Node, HashMap<Node, Node>> next;

  public DirectedGraph() {
    this.edges = new HashMap<Node, ArrayList<Edge>>();
  }

  public ArrayList<Edge> getEdges() {
    ArrayList<Edge> allEdges = new ArrayList<Edge>();
    for (Node node : this.edges.keySet()) {
      allEdges.addAll(this.edges.get(node));
    }
    return allEdges;
  }

  public void addNode(Node node) {
    if (!this.edges.containsKey(node)) {
      this.edges.put(node, new ArrayList<Edge>());
    }
  }

  public void addEdge(Edge edge) {
    this.edges.get(edge.src).add(edge);
  }

  /*
   * @returns A path of Node objects from start to dest.
   */
  public ArrayList<Node> breadthFirstSearch(Node start, Node dest) {
    Queue<ArrayList<Node>> queue = new LinkedList<ArrayList<Node>>();
    ArrayList<Node> firstPath = new ArrayList<Node>();
    firstPath.add(start);
    queue.add(firstPath);
    HashMap<Node, Boolean> visited = new HashMap<Node, Boolean>();
    while (queue.size() != 0) {
      ArrayList<Node> path = queue.remove();
      Node node = path.get(path.size() - 1);
      for (Edge edge : this.edges.get(node)) {
        Node nextNode = edge.dest;
        if (visited.containsKey(nextNode)) {
          continue;
        }
        visited.put(nextNode, true);
        ArrayList<Node> newPath = new ArrayList<Node>(path);
        newPath.add(nextNode);
        if (nextNode.equals(dest)) {
          return newPath;
        }
        queue.add(newPath);
      }
    }
    return null;
  }

  /*
   * Finds the strongly connected components of the graph. Taken from
   * http://en.wikipedia.org/wiki/Tarjan%E2%80%99s_strongly_connected_components_algorithm
   *
   * Sets this.stronglyConnectedCompoents to be the strong connected components
   * of the graph.
   *
   */
  public void findAndSetStronglyConnectedComponents() {
    this.stronglyConnectedComponents = new ArrayList<ArrayList<Node>>();
    this.nodeStack = new Stack<Node>();
    for (Node node: this.edges.keySet()) {
      if (node.index == -1) {
        stronglyConnectedComponentsHelper(node);
      }
    }
  }

  private void stronglyConnectedComponentsHelper(Node node) {
    node.index = index;
    node.lowlink = index;
    this.index++;
    this.nodeStack.push(node);

    for (Edge edge : this.edges.get(node)) {
      Node dest = edge.dest;
      if (dest.index == -1) {
        stronglyConnectedComponentsHelper(dest);
        node.lowlink = Math.min(node.lowlink, dest.lowlink);
      } else if (this.nodeStack.search(dest) != -1) {
        node.lowlink = Math.min(node.lowlink, dest.index);
      }
    }
    if (node.lowlink == node.index) {
      ArrayList<Node> connected = new ArrayList<Node>();
      Node w;
      do {
        w = this.nodeStack.pop();
        connected.add(w);
      } while (!w.equals(node));
      this.stronglyConnectedComponents.add(connected);
    }
  }

  /*
   * Sets this.hasCycle to be true if the graph has a cycle.
   */
  public void findAndSetHasCycle() {
    this.findAndSetStronglyConnectedComponents();
    ArrayList<ArrayList<Node>> stronglyConnectedComponentsList = this.stronglyConnectedComponents;
    for (ArrayList<Node> component : stronglyConnectedComponentsList) {
      if (component.size() != 1) {
        this.hasCycle = true;
      }
    }
    this.hasCycle = false;
  }

  /*
   *
   * Sets this.minimumSpanningTree to be the ArrayList of Edges that is the MST
   * of the graph.
   */
  public void findAndSetMinimumSpanningTree() {
    HashMap<Node, ArrayList<Node>> forests = new HashMap<Node, ArrayList<Node>>();
    ArrayList<Edge> minimumSpanningTree = new ArrayList<Edge>();
    for (Node node : this.edges.keySet()) {
      ArrayList<Node> forest = new ArrayList<Node>();
      forest.add(node);
      forests.put(node, forest);
    }
    ArrayList<Edge> allEdges = getEdges();
    Collections.sort(allEdges, new Comparator<Edge>() {
      public int compare(Edge e1, Edge e2) {
        if (e1.weight == e2.weight) {
          return 0;
        }
        return e1.weight < e2.weight ? -1 : 1;
      }
    });
    for (int i = 0; i < allEdges.size(); i++) {
      Edge edge = allEdges.get(i);
      if (!forests.get(edge.src).equals(forests.get(edge.dest))) {
        if (!minimumSpanningTree.contains(edge)) {
          minimumSpanningTree.add(edge);
        }
        Set<Node> set = new HashSet<Node>();
        set.addAll(forests.get(edge.src));
        set.addAll(forests.get(edge.dest));
        ArrayList<Node> newForest = new ArrayList<Node>(set);
        forests.put(edge.src, newForest);
        forests.put(edge.dest, newForest);
      }
    }
    this.minimumSpanningTree = minimumSpanningTree;
  }

  /*
   * Floyd-Warshall while simultaneously keeping the this.next data structure
   * to reconstruct the shortest paths later. Sets this.shortestPathsLengths
   *
   * http://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
   *
   */
  public void findAndSetAllPairsShortestPathLengths() {
    this.shortestPathsLengths = new HashMap<Node, HashMap<Node, Double>>();
    this.next = new HashMap<Node, HashMap<Node, Node>>();
    for (Node a : this.edges.keySet()) {
      HashMap<Node, Double> distMap = new HashMap<Node, Double>();
      HashMap<Node, Node> nextMap = new HashMap<Node, Node>();
      for (Node b : this.edges.keySet()) {
        distMap.put(b, Double.POSITIVE_INFINITY);
        nextMap.put(b, null);
      }
      this.shortestPathsLengths.put(a, distMap);
      this.next.put(a, nextMap);
    }
    for (Node node : this.edges.keySet()) {
      this.shortestPathsLengths.get(node).put(node,  new Double(0));
    }
    for (Edge edge : this.getEdges()) {
      this.shortestPathsLengths.get(edge.src).put(edge.dest, edge.weight);
    }
    for (Node k : this.edges.keySet()) {
      for (Node i : this.edges.keySet()) {
        for (Node j : this.edges.keySet()) {
          Double distance = this.shortestPathsLengths.get(i).get(k) + this.shortestPathsLengths.get(k).get(j);
          if (distance < this.shortestPathsLengths.get(i).get(j)) {
            this.shortestPathsLengths.get(i).put(j, distance);
            this.next.get(i).put(j, k);
          }
        }
      }
    }
  }

  public void findAndSetAllPairsShortestPaths() {
    this.findAndSetAllPairsShortestPathLengths();
    this.shortestPaths = new HashMap<Node, HashMap<Node, ArrayList<Node>>>();
    for (Node a : this.edges.keySet()) {
      HashMap<Node, ArrayList<Node>> shortestPathMap = new HashMap<Node, ArrayList<Node>>();
      for (Node b : this.edges.keySet()) {
        ArrayList<Node> shortestPath = shortestPath(a,b);
        shortestPath.add(0, a);
        shortestPathMap.put(b, shortestPath);
      }
      this.shortestPaths.put(a, shortestPathMap);
    }
  }

  private ArrayList<Node> shortestPath(Node i, Node j) {
    ArrayList<Node> shortestPath = new ArrayList<Node>();
    if (this.shortestPathsLengths.get(i).get(j) == Double.POSITIVE_INFINITY) {
      return shortestPath;
    }
    Node intermediate = this.next.get(i).get(j);
    if (intermediate == null) {
      shortestPath.add(j);
      return shortestPath;
    }
    shortestPath.addAll(shortestPath(i, intermediate));
    shortestPath.addAll(shortestPath(intermediate, j));
    return shortestPath;
  }


}

class UndirectedGraph extends DirectedGraph {

  @Override
  public void addEdge(Edge edge) {
    this.edges.get(edge.src).add(edge);
    this.edges.get(edge.dest).add(edge);
  }

  public static void main(String[] args) {
    UndirectedGraph graph = new UndirectedGraph();
    Node node1 = new Node(1);
    Node node2 = new Node(2);
    Node node3 = new Node(3);
    graph.addNode(node1);
    graph.addNode(node2);
    graph.addNode(node3);
    Edge edge1 = new Edge(node1, node2, 3);
    Edge edge2 = new Edge(node2, node1, 4);
    Edge edge3 = new Edge(node2, node3, 5);
    Edge edge4 = new Edge(node3, node2, 6);
    Edge edge5 = new Edge(node3, node2, 7);
    graph.addEdge(edge1);
    graph.addEdge(edge2);
    graph.addEdge(edge3);
    graph.addEdge(edge4);
    graph.addEdge(edge5);
    graph.findAndSetAllPairsShortestPathLengths();
    graph.findAndSetAllPairsShortestPaths();
  }
}
