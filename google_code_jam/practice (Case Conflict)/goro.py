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
        num_numbers = int(f.readline())
        my_list = f.readline().split()
        sorted_list = sorted(my_list)
        out_of_order = 0
        for j in range(len(my_list)):
            if my_list[j] != sorted_list[j]:
                out_of_order = out_of_order + 1
        final_string = final_string + "Case #" + str(i+1) + ": " + str(out_of_order) + ".000000\n"
    f.close()
    return final_string


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
                   
