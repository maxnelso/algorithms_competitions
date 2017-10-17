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
        test = f.readline().split()
        n = int(test[0])
        s = int(test[1])
        p = int(test[2])
        totals = test[3:]
        for_sures = []
        for j in range(len(totals)):
            if int(totals[j]) >= 3*p - 2:
                for_sures.append(j)
        good_surprises = []
        for j in range(len(totals)):
            if s == 0:
                break
            if j not in for_sures:
                if p == 1:
                    if int(totals[j]) > 0:
                        good_surprises.append(j)
                elif int(totals[j]) >= 3*p - 4:
                    good_surprises.append(j)
                    s = s - 1
        final_string = final_string + "Case #{0}: {1}\n".format(i+1,len(for_sures)+len(good_surprises))


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
                   
