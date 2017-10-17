import os
import sys

"""
The basic code for reading a file, should return a string
"""
def parse_input(input_file):
    f = open(input_file, "r")
    final_string = ""
    test_cases = int(f.readline())
    for i in range(test_cases):
      parameters = f.readline().split()
      L = int(parameters[0])
      t = int(parameters[1])
      N = int(parameters[2])
      C = int(parameters[3])
      a_s = [int(x) for x in parameters[4:]]
      current_star = 0
      current_distance = 0
      travel_distance = a_s[0]
      print travel_distance
      time = 0
      while current_star != N:
        print "time ,", time
        print "current_distance ,", current_distance
        if time >= t:
          print "in speed boost time"
          time = time + 1
          if current_star >= N - L:
            current_distance = current_distance + 1
            if (current_distance >= travel_distance):
              current_star = current_star + 1
              current_distance = 0
              travel_distance = a_s[current_star % C]
              print travel_distance
          else:
            current_distance = current_distance + .5
            if (current_distance >= travel_distance):
              current_star = current_star + 1
              current_distance = 0
              travel_distance = a_s[current_star % C]
              print travel_distance
        else:
          time = time + 1
          current_distance = current_distance + .5
          if (current_distance >= travel_distance):
            current_star = current_star + 1
            current_distance = 0
            travel_distance = a_s[current_star % C]
            print travel_distance

      final_string = final_string + "Case #{0}: {1}\n".format(i+1, time)



    return final_string
    f.close()


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
                   
