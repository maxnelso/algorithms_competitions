import os
import sys
import copy

"""
The basic code for reading a file, should return a string
"""
def parse_input(input_file):
    f = open(input_file, "r")
    test_cases = int(f.readline())
    final_string = ""
    for case in range(test_cases):
        print case
        s = f.readline().strip("\n")
        count = ugly_helper(s, 0, (len(s) - 1) * [""])
        final_string = final_string + "Case #{0}: {1}\n".format(case + 1, count)
    return final_string
    f.close()



def ugly_helper(s, index, operators):
    if index == len(s) - 1:
        eval_string = ""
        start_of_number = True
        for i in range(0,len(s)-1):
            eval_string = eval_string + s[i] + operators[i]
            if operators[i] == "+" or operators[i] == "-":
                eval_string = eval_string + " "
        eval_string = eval_string + s[len(s)-1]
        my_split = eval_string.split()
        eval_string = ""
        for sep in my_split:
            sep = list(sep)
            if len(sep) > 2 and sep[0] == "0":
                index = 0
                while (sep[index] == "0"):
                    sep[index] = ""
            eval_string = eval_string + "".join(sep)
        output = eval(eval_string)
        if output % 2 == 0 or output % 3 == 0 or output % 5 == 0 or output % 7 == 0:
            return 1
        else:
            return 0
    else:
        count = 0
        with_string = copy.copy(operators)
        with_string[index] = ""
        count = count + ugly_helper(s, index + 1, with_string)
        with_plus = copy.copy(operators)
        with_plus[index] = "+"
        count = count + ugly_helper(s, index + 1, with_plus)
        with_minus = copy.copy(operators)
        with_minus[index] = "-"
        count = count + ugly_helper(s, index + 1, with_minus)
        return count


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
