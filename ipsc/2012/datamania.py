import os
import sys
from operator import itemgetter, attrgetter
"""
The basic code for reading a file, should return a string
"""
def parse_input(input_file):
    f = open(input_file, "r")
    test_cases = int(f.readline())
    
    members_list = open('d-members.txt','r').readlines()
    members=[]
    for line in members_list:
        members.append(line.rstrip('\n').split())

    problems_list = open('d-problems.txt','r').readlines()
    problems=[]
    for line in problems_list:
        problems.append(line.rstrip('\n').split())

    teams_list = open('d-teams.txt','r').readlines()
    teams=[]
    for line in teams_list:
        teams.append(line.rstrip('\n').split())
        
    submissions_list = open('d-submissions.txt','r').readlines()
    submissions=[]
    for line in submissions_list:
        submissions.append(line.rstrip('\n').split())
#        submissions.append(line.rstrip('\n').replace('-',' ').split())

    messages_list = open('d-messages.txt','r').readlines()
    messages=[]
    for line in messages_list:
        messages.append(line.rstrip('\n').split())
    practice(members,problems,teams,submissions,messages)
    f.close()


def getElement(d_list,index,element,return_element):
    print element
    for e in d_list:
        if str(e[index]) == str(element):
            return e[return_element]

def practice(members,problems,teams,submissions,messages):
    sorted(submissions, key=itemgetter(0))
    years = []
    string = ""
    for submission in submissions:
        print submission
        if submission[0][0:4] not in years and getElement(teams,0,submission[2],1
            print submission[2]
            string = string + str(submission[0][0:4]) + str(getElement(teams,0,submission[2],1)
            years.append(submission[0][0:4])
    print string

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
                   
