import os
import sys

"""
The basic code for reading a file, should return a string
"""
def parse_input(input_file):
    f = open(input_file, "r")
    test_cases = int(f.readline())
    f.readline()
    final_string = ""
    for i in range(test_cases):
        count = 0
        dimensions = f.readline().split()
        r = int(dimensions[0])
        c = int(dimensions[1])
        matrix = []
        for x in range(r):
            row = list(f.readline().rstrip('\n').rstrip(' '))
            matrix.append(row)
        for x in range(r):
            for y in range(c):
                if matrix[x][y] == 'o':
                    if check(matrix,x,y):
                        count = count+1
        if i!= test_cases-1:
            final_string = final_string + str(count) + "\n"
        else:
            final_string = final_string + str(count)
        f.readline()
    f.close()
    return final_string


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


def check(matrix,x,y):
    horiz = checkHoriz(matrix,x,y)
    vert = checkVert(matrix,x,y)
    return horiz or vert


def checkHoriz(matrix,x,y):
    if y-1<0 or y+1>len(matrix[0])-1:
        return False
    if matrix[x][y-1]!=">" or matrix[x][y+1]!="<":
        return False
    return True
    


def checkVert(matrix,x,y):
    if x-1<0 or x+1>len(matrix)-1:
        return False
    if matrix[x-1][y]!="v" or matrix[x+1][y]!="^":
        return False
    return True
    
if __name__ == "__main__":
    if len(sys.argv) > 1:
        answer_string = parse_input(sys.argv[1])
        if answer_string == None:
            print "No answer given"
        else:
            write_output(answer_string)
    else:
        print "Pass in the input file"
                   
