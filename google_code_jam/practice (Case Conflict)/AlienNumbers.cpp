#include <fstream>
#include <iostream>
#include <string>
#include <iterator> 
#include <vector>   
#include <sstream>
#include <algorithm>
#include <boost/lexical_cast.hpp>
#include <math.h>
#include <map>
using namespace std;
int COUNT = 1;
int get_decimal(map<char,int> source_language, string alien_number) {
    int decimal = 0;
    for (int i = 0; i < alien_number.length(); i++) {
        decimal = decimal + pow((double) source_language.size(),
                                 (int) (alien_number.length()-i-1)) *
                            source_language[alien_number[i]];
    }
    return decimal;
}

string run(vector<string> tokens) {
    map<char,int> source_language;
    map<char,int> target_language;
    string alien_number = tokens[0];
    for (int i = 0; i < tokens[1].length(); i++) {
        source_language[tokens[1][i]] = i;
    }
    for (int i = 0; i < tokens[2].length(); i++) {
        target_language[tokens[2][i]] = i;
    }
    int decimal = get_decimal(source_language,alien_number); 
    stringstream count;
    count << COUNT;
    string output = "Case #" + count.str() + ": ";
    COUNT = COUNT + 1;
    int num_chars = 0;
    double tokens_length = tokens[2].length();
    double num;
    while (1) { 

        num = pow(tokens_length,num_chars);
        if (num > decimal) {
            break;
        }
        num_chars = num_chars + 1;
    }
    for (int i = num_chars-1; i >= 0; i--) {
        for (int j = 0; j < tokens[2].length(); j++) {
            int value = ((int) pow((double) tokens[2].length(), i)) * target_language[tokens[2][j]];
            string s;
            stringstream ss;
            ss << tokens[2][j];
            ss >> s;
            if (value == decimal) {
                stringstream newstream;
                output.append(s);
                newstream << tokens[2][0];
                string zero;
                zero.append(newstream.str());
                for (int k = 0; k < i; k++) {
                    output.append(zero);
                }
                output.append("\n");
                return output;
            }
            else if (value > decimal) {
                stringstream newstream;
                decimal = decimal - ((int) pow((double) tokens[2].length(), i)) * target_language[tokens[2][j-1]];
                newstream << tokens[2][j-1];
                string previous;
                newstream >> previous;
                output.append(previous);
                break;
            }
            else if (j == tokens[2].length()-1) {
                stringstream newstream;
                output.append(s);
                decimal = decimal - ((int) pow((double) tokens[2].length(), i)) * target_language[tokens[2][j]];
            }
        }
    }
    output.append("\n");
    return output;
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
