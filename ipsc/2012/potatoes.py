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
        params = f.readline().split()
        rows = int(params[0])
        cols = int(params[1])
        capacity = int(params[2])
        field = []
        field_total = []
        for x in range(rows):
            row = []
            for y in range(cols):
                row.append(0)
            field.append(row)
            field_total.append(row)
        actions=[]
        round_num = 1
        while True:
            action = get_next(field,rows,cols)
            if action == ():
                break
            else:
                actions.append(action)
                take_action(field,rows,cols,action,capacity,field_total,round_num)
                round_num = round_num + 1

        final_string = final_string + get_string(field_total,rows,cols)           
        final_string = final_string + "\n"
        f.readline()
    return final_string
    f.close()

def get_string(field_total,rows,cols):
    final_string = ""
    for x in range(rows):
        for y in range(cols):
            if y != cols - 1:
                final_string = final_string + str(field_total[x][y]) + " "
            else:
                final_string = final_string + str(field_total[x][y])
        final_string = final_string + "\n"
    return final_string

def take_action(field,rows,cols,action,capacity,field_total,round_num):
    if action[0]=='r':
        x = int(action[1])
        for y in range(cols):
            if field[x][y] == 0 and capacity > 0:
                field[x][y] = 1
                field_total[x][y] = round_num
                capacity = capacity - 1

    if action[0]=='c':
        y = int(action[1])
        for x in range(rows):
            if field[x][y] == 0 and capacity > 0:
                field[x][y] = 1
                field_total[x][y] = round_num
                capacity = capacity - 1

def get_next(field,rows,cols):
    best_count = 0
    best_action = ()
    #try rows
    for x in range(rows):
        row_count = 0
        for y in range(cols):
            if field[x][y] == 0:
                row_count = row_count + 1
        if row_count > best_count:
            best_count = row_count
            best_action = ("r",x)
                
    #try cols
    for y in range(cols):
        col_count = 0
        for x in range(rows):
            if field[x][y] == 0:
                col_count = col_count + 1
        if col_count > best_count:
            best_count = col_count
            best_action = ("c",y)
    return best_action
            


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
                   
