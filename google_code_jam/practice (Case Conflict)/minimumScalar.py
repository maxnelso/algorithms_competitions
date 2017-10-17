import os
import sys

"""
The basic code for reading a file, should return a string
"""
def parse_input(input_file):
    f = open(input_file, "r")
    test_cases = int(f.readline())
    finalString = ""
    for case in range(test_cases):
        numbers = int(f.readline())
        first = f.readline().split()
        second = f.readline().split()
        firstInts = []
        secondInts = []
        for i in range(len(first)):
            firstInts.append(int(first[i]))
            secondInts.append(int(second[i]))
        first = sorted(firstInts)
        second = sorted(secondInts)
        total = 0
        for i in range(len(firstInts)):
            total = total + first[i]*second[len(second)-i-1]
        finalString = finalString + "Case #" + str(case+1) + ": " + str(total) + "\n"
    f.close()
    return finalString


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
                   
