import os
import sys

"""
The basic code for reading a file, should return a string
"""
def parse_input(input_file):
    f = open(input_file, "r")
    test_cases = int(f.readline())
    
    counts = []
    for i in range(test_cases):
        count = 0
        engines = []
        num_engines = int(f.readline())
        for j in range(num_engines):
            engines.append(f.readline())
        current_index = 0
        num_queries = int(f.readline())
        queries = []
        for j in range(num_queries):
            queries.append(f.readline())
        while current_index < num_queries:
            best_engine = 0
            for engine in engines:
                engine_goodness = 0
                temp_index = current_index
                while queries[temp_index] != engine:
                    engine_goodness = engine_goodness + 1
                    temp_index = temp_index + 1
                    if temp_index > len(queries) - 1:
                        break
                if engine_goodness > best_engine:
                    best_engine = engine_goodness
            current_index = current_index + best_engine
            if current_index >= num_queries:
                break
            else:
                count = count + 1
        counts.append(count)
    f.close()
    output = "" 
    for i in range(len(counts)):
        output = output + ("Case #{0}: {1}\n".format(i+1,counts[i]))
    print output
    return output

"""
Writes a string to the file of the form X-Y-output.txt,
where X is the name of this script and Y is the name of the
test case
"""
def write_output(answer_string):
    script_name = os.path.splitext(sys.argv[0])[0] + "-"
    f = open("Outputs/"+ script_name +"output.txt","w")
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
                   
