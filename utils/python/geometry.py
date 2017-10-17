import math

class Coordinate:

  def __init__(self, x, y):
    self.x = x
    self.y = y

  def __repr__(self):
    return "({0}, {1})".format(self.x, self.y)

  def __eq__(self, other):
    return self.x == other.x and self.y == other.y

class Polygon:

  def __init__(self, vertices):
    self.vertices = vertices # Tuple of Coordinate objects

  def point_in_polygon(self, point, count_border):
    """
    Takes in a Coordinate and returns True if this point is within this
    polygon, False otherwise. The count_border flag indicates whether we count the
    point inside the polygon if it is on the border.
    Taken from
    http://stackoverflow.com/questions/217578/point-in-polygon-aka-hit-test
    """
    if count_border:
      edges = self.get_edges()
      for e in edges:
        if point_on_line_segment(e[0], e[1], point):
          return True
    j = len(self.vertices) - 1
    c = False
    for i in range(len(self.vertices)):
      if ( ((self.vertices[i].y > point.y) != (self.vertices[j].y > point.y)) \
          and (point.x < (self.vertices[j].x - self.vertices[i].x) * \
          (point.y - self.vertices[i].y) / (self.vertices[j].y - \
          self.vertices[i].y) + self.vertices[i].x) ):
        c = not c
      j = i

    return c

  def get_area(self):
    def get_area_helper(points):
      """
      Returns the area of the polygon.
      Taken from
      http://stackoverflow.com/questions/9447227/area-of-a-polygon-recursively-using-python
      """
      def area_of_triangle(points):
        (x1, y1) = int(points[0].x), int(points[0].y)
        (x2, y2) = int(points[1].x), int(points[1].y)
        (x3, y3) = int(points[2].x), int(points[2].y)
        return abs(x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1) / 2

      def lop_triangle(points):
        triangle = [points[0], points[-1], points[-2]]
        polygon = points[:-1]
        return triangle, polygon

      if len(points) == 3:
        return area_of_triangle(points)
      else:
        triangle, polygon = lop_triangle(points)
        return area_of_triangle(triangle) + get_area_helper(polygon)

    return get_area_helper(self.vertices)

  def get_edges(self):
    """
    Returns a list of tuples of the form (a, b), where a and b are coordinates
    on the polygon.
    """
    mesh = []
    for i in range(len(self.vertices)):
      for j in range(i + 1, len(self.vertices)):
        mesh.append((self.vertices[i], self.vertices[j]))
    edges = []
    for e1 in mesh:
      good = True
      for e2 in mesh:
        intersection = line_intersection(e1[0], e1[1], e2[0], e2[1])
        if e1 != e2 and intersection and intersection not in self.vertices:
          good = False
      if good:
        edges.append(e1)
    return edges

class Circle:

    def __init__(self, x, y, radius):
      self.x = x
      self.y = y
      self.radius = radius

    def point_in_circle(self, point):
      dist = math.sqrt((self.x - point.x) ** 2 + (self.y - point.y) ** 2)
      return dist <= self.radius

def point_on_line_segment(a, b, c):
  """
  a and b are Coordinates defining the line segment, c is the point to be
  tested, returns True if c is on the line segment.
  Taken from
  http://stackoverflow.com/questions/328107/how-can-you-determine-a-point-is-between-two-other-points-on-a-line-segment
  """
  epsilon = .0000001
  cross_product = (c.y - a.y) * (b.x - a.x) - (c.x - a.x) * (b.y - a.y)
  if abs(cross_product) > epsilon:
    return False   # (or != 0 if using integers)

  dot_product = (c.x - a.x) * (b.x - a.x) + (c.y - a.y)*(b.y - a.y)
  if dot_product < 0:
    return False

  squared_length_ba = (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y)
  if dot_product > squared_length_ba:
    return False

  return True

def line_intersection(a, b, c, d):
  """
  Returns true if the line segment ab intersects the line segment cd.
  """
  xdiff = Coordinate(a.x - b.x, c.x - d.x)
  ydiff = Coordinate(a.y - b.y, c.y - d.y)

  def det(a, b):
    return a.x * b.y - a.y * b.x

  div = det(xdiff, ydiff)
  if div == 0:
    return False

  d = Coordinate(det(a,b), det(c,d))
  x = det(d, xdiff) / div
  y = det(d, ydiff) / div
  return Coordinate(x, y)


a = Coordinate(1, 74)
b = Coordinate(126,74)
c = Coordinate(35, 31.835)
d = Coordinate(35, -100031.835)
print line_intersection(a, b, c, d)
