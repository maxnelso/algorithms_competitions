import os
import sys

"""
The basic code for reading a file, should return a string
"""
def parse_input(input_file):
    f = open(input_file, "r")
    test_cases = int(f.readline())
    final_result = ""
    for i in range(test_cases):
        test = int(f.readline())
        result = next_number(test)
        final_result = final_result + "Case {0}: {1}\n".format(i+1, result)
    f.close()
    return final_result

def next_number(number):
    decreasing_sequence = True
    index_of_out_of_place = -1
    for i in range(1,len(str(number))):
        if int(str(number)[i]) > int(str(number)[i-1]):
            decreasing_sequence = False
            index_of_out_of_place = i
    if decreasing_sequence:
        sorted_sequence = sorted(str(number))
        first_nonzero_index = -1
        for i in range(len(sorted_sequence)):
            if sorted_sequence[i] != '0':
                first_nonzero_index = i
                break
        sorted_sequence[0], sorted_sequence[first_nonzero_index] = sorted_sequence[first_nonzero_index], sorted_sequence[0]
        sorted_sequence.insert(1,"0")
        result = "".join(sorted_sequence)
    else:
        number_list = list(str(number))
        number_list[index_of_out_of_place], number_list[index_of_out_of_place - 1] = number_list[index_of_out_of_place -1], number_list[index_of_out_of_place]
        result = "".join(number_list)
    return result


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
