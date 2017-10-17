def main():
  edges = [{} for i in range(60)]
  construct_andy_edges(edges)
  #construct_edges(edges)

  write_file('tmp.in', 60, edges)

def construct_edges(edges):
  #############################
  ##   DO YOUR MAGIC HERE!   ##
  #############################

  edges[0][1] = 2
  edges[1][2] = 2
  edges[2][3] = 2
  edges[3][4] = 2

  edges[0][5] = 13
  edges[5][1] = -12
  edges[1][6] = 10
  edges[2][7] = 6
  edges[7][3] = -5
  edges[3][8] = 3
  edges[8][4] = -2

  edges[0][9] = 14
  edges[9][2] = -13
  edges[2][10] = 7
  edges[10][4] = -6

  edges[0][11] = 15
  edges[11][4] = -14

def construct_andy_edges(edges):
  for i in range(29):
    b = 3 * (30 - i)
    edges[2 * i][2 * i + 1] = 0
    edges[2 * i][2 * i + 2] = 0
    edges[2 * i + 1][2 * i + 2] = -1

def write_file(filename, num_vertices, edges):
  f = open(filename, 'w')
  f.write('%d\n' % num_vertices)

  edge_list = []
  for a in range(len(edges)):
    for b in edges[a]:
      s = '%d %d %d\n' % (a, b, edges[a][b])
      edge_list.append(s)

  f.write('%d\n' % len(edge_list))
  for e in edge_list:
    f.write(e)
  f.close()

if __name__ == '__main__':
  ###########################################################
  ##   run: python dijkstra_sol.py ; python d.py < tmp.in  ##
  ###########################################################
  main()
