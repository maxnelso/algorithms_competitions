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
        params = f.readline().split()
        P = int(params[0])
        K = int(params[1])
        L = int(params[2])
        frequencies = [int(x) for x in f.readline().split()]
        frequencies.sort(reverse = True)
        presses = 1
        total_presses = 0
        while len(frequencies) > 0:
            total_presses = total_presses + presses * sum(frequencies[:min(K, len(frequencies))])
            frequencies = frequencies[min(K, len(frequencies)):]
            presses = presses + 1
        final_string = final_string + "Case #{0}: {1}\n".format(i+1,total_presses)

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
