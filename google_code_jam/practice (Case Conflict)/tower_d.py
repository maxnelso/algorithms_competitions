import os
import sys
import heapq

"""
The basic code for reading a file, should return a string
"""
def parse_input(input_file):
    f = open(input_file, "r")
    test_cases = int(f.readline())
    final_result = ""
    for i in range(test_cases):
        num_levels = int(f.readline())
        one_stars = []
        two_stars = []
        two_to_one_mapping = {}
        for j in range(num_levels):
            line = f.readline().split()
            one_stars.append(int(line[0]))
            two_stars.append(int(line[1]))
            if (int(line[1])) in two_to_one_mapping:
                two_to_one_mapping[int(line[1])].append(int(line[0]))
            else:
                two_to_one_mapping[int(line[1])] = [int(line[0])]
        result = tower_d_helper(one_stars, two_stars, two_to_one_mapping)
        final_result = final_result + "Case #{0}: {1}\n".format(i+1, result)
    f.close()
    return final_result


def tower_d_helper(one_stars, two_stars, two_to_one_mapping):
    heapq.heapify(one_stars)
    heapq.heapify(two_stars)
    count = 0
    current_stars = 0
    while len(two_stars) > 0:
        min_two_star = two_stars[0]
        if current_stars >= min_two_star:
            heapq.heappop(two_stars)
            mapped_one_star = two_to_one_mapping[min_two_star].pop(0)
            try:
                one_stars.remove(mapped_one_star)
                current_stars = current_stars + 2
            except: #Already gone I suppose
                current_stars = current_stars + 1
        else:
            if len(one_stars) == 0:
                return "Too Bad"
            min_one_star = heapq.heappop(one_stars)
            if current_stars < min_one_star:
                return "Too Bad"
            current_stars = current_stars + 1
        count = count + 1
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
