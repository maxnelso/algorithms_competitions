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
        f.readline()
        text_length = int(f.readline())
        temp = f.readline().split()
        text = []
        for e in temp:
            text.append(int(e))
        first_length = int(f.readline())
        temp = f.readline().split()
        first_pattern = []
        for e in temp:
            first_pattern.append(int(e))
        second_length = int(f.readline())
        temp = f.readline().split()
        second_pattern = []
        for e in temp:
            second_pattern.append(int(e))
        max_val = max(text)
        first_comp = find_compatibility(text,first_pattern)
        second_comp = find_compatibility(text,second_pattern)
        max_comp = 0
        best_val = 0

        for j in range(max_val+2):
            new_pattern = first_pattern + [j] + second_pattern
            comp = find_compatibility(text,new_pattern)
            if comp > max_comp:
                max_comp = comp
                best_val = j
        final_string = final_string + str(first_comp) + " " + str(second_comp) + " " + str(best_val) + " " + str(max_comp)
        
    f.close()
    return final_string


def find_compatibility(text,pattern):
    compatibility = 0
    for k in range(len(text)):
        print k
        low_index = k
        alist=[]
        pattern_index = 0
        new_sum = text[k]
        for a in range(len(text[low_index+1:])):
            if a:
                if new_sum == pattern[pattern_index]:
                    pattern_index = pattern_index + 1
                    new_sum = text[a]
                    if pattern_index > len(pattern) - 1:
                        print k
                        compatibility = compatibility + 1
                        break
                    low_index = low_index + a
                else:
                    new_sum = new_sum + text[a]
    return compatibility

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
    

if __name__ == "__main__":
    if len(sys.argv) > 1:
        answer_string = parse_input(sys.argv[1])
        if answer_string == None:
            print "No answer given"
        else:
            write_output(answer_string)
    else:
        print "Pass in the input file"
                   
