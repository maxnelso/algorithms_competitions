#include <fstream>
#include <iostream>
#include <string>
#include <iterator> 
#include <vector>   
#include <sstream>
#include <algorithm>
#include <boost/lexical_cast.hpp>
using namespace std;

string run(vector<string> tokens) {
    //TODO
    return "Return the output value here\n";
}

int main(int argc, char* argv[]) { 
    if (argc < 2) {
        cout << "Don't forget to pass in the input file\n";
        exit(0);
    }
    string program_name = string(argv[0]);
    //input file name
    ifstream inputfile(argv[1]);
    ofstream outputfile;
    string line;
    getline(inputfile,line);
    int testcases = atoi(line.c_str());
    string output = "";
    for (int i = 0; i < testcases; i++) {
        while(getline(inputfile, line)) {
            //split line up into tokens
            vector<string> tokens;
            istringstream iss(line);
            copy(istream_iterator<string>(iss),
                istream_iterator<string>(),
                back_inserter<vector<string> >(tokens));
            string output_string = run(tokens);
            output.append(output_string);
        }
    }
    string unique = "";
    string new_file = "";
    int count = 0;
    while (1) {
        new_file = program_name + unique + ".txt";
        ifstream test(new_file.c_str());
        if (test) {
            count++;
            unique = boost::lexical_cast<string>(count);
        }
        else {
            break;
        }
    }
    outputfile.open(("Outputs/" + new_file).c_str());
    outputfile << output;
    outputfile.close();
    inputfile.close();
    return 0;
}
