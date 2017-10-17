import os
import sys

"""
The basic code for reading a file, should return a string
"""
def parse_input(input_file):
    f = open(input_file, "r")
    test_cases = int(f.readline())
    final_string = ""
    for i in range(test_cases):
      parameters = f.readline().split()
      grid = []
      for j in range(int(parameters[0])):
        grid.append(list(f.readline().strip("\n")))
      result = get_changed_grid(grid)
      final_string = final_string + "Case #{0}:\n{1}\n".format(i+1,result)
    f.close()
    return final_string


def get_changed_grid(grid):
  return_string = ""
  change_ds = ((0,0,"/"), (0,1,"\\"), (1,0,"\\"), (1,1,"/"))
  for i in range(len(grid)):
    for j in range(len(grid[0])):
      if grid[i][j] == "#":
        for d in change_ds:
          if i+d[0] >= len(grid) or j+d[1] >= len(grid[0]) or grid[i+d[0]][j+d[1]] != "#":
            return "Impossible"
          grid[i+d[0]][j+d[1]] = d[2]
  for i in range(len(grid)):
    for j in range(len(grid[0])):
      return_string = return_string + str(grid[i][j])
    if i!= len(grid) - 1:
      return_string = return_string + "\n"
  return return_string


"""
Writes a string to the file of the form X-Y-output.txt,
where X is the name of this script and Y is the name of the
test case
"""
def write_output(answer_string):
    script_name = os.path.splitext(sys.argv[0])[0] + "-"
    f = open("Outputs/" + script_name +"output.txt","w")
    f.write(answer_string)
    f.close()
    

if __name__ == "__main__":
    if len(sys.argv) > 1:
        answer_string = parse_input(sys.argv[1])
        if answer_string == None:
            print "No answer given"
        else:
            write_output(answer_string)
    else:
        print "Pass in the input file"
                   
