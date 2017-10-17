import os
import sys
import random
import string

"""
The basic code for reading a test case
"""
def parse_input(input_file):
    f = open(input_file, "r")
    test_cases = int(f.readline())
    f.readline()
    answer_string = str(test_cases)+"\n\n"
    for i in range(test_cases):
        
        length = int(f.readline())
        array = f.readline().split()
        unsorted_array = get_unsorted(array,length)
        answer_string = answer_string + str(length) + "\n"
        answer_string = answer_string + string.join(unsorted_array, " ")
        answer_string = answer_string + "\n\n"
        f.readline()

    
    f.close()
    return answer_string


"""
Writes a string to the file of the form X-Y-output.txt,
where X is the name of this script and Y is the name of the
test case
"""
def write_output(answer_string):
    script_name = os.path.splitext(sys.argv[0])[0] + "-"
    test_name = os.path.splitext(sys.argv[1])[0] + "-"
    f = open(script_name + test_name +"output.txt","w")
    f.write(answer_string)
    f.close()
    



def get_unsorted(array,length):
    increasing = False
    #check to see if array is an increasing array
    if array[1] > array[0]:
        increasing = True
    while True:
        first = random.randint(0,length-1)
        second = random.randint(0,length-1)
        while second == first:
            second = random.randint(0,length-1)
        first_element = array[first]
        second_element = array[second]
        if increasing:
            if first > second:
                if second_element < first_element:
                    array[first] = second_element
                    array[second] = first_element
                    break
            else:
                if first_element < second_element:
                    array[first] = second_element
                    array[second] = first_element
                    break
        else:
            if first > second:
                if second_element > first_element:
                    array[first] = second_element
                    array[second] = first_element
                    break
            else:
                if first_element > second_element:
                    array[first] = second_element
                    array[second] = first_element
                    break
    return array
        

if __name__ == "__main__":
    if len(sys.argv) > 1:
        answer_string = parse_input(sys.argv[1])
        write_output(answer_string)
    else:
        print "Pass in the input file"
                   
