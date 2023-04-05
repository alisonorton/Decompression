#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <iterator> 
#include <algorithm> 

using namespace std;

map <string, string> input;
vector <string> lines;

/*****************************************************
 * MAIN
******************************************************/
int main(int argc, char** argv)
{
    //Error checking the file
    if (argc == 1) {
        std::cout << "You forgot the file name." << endl;
        exit(0);
    }

    ifstream ifs;
    ifs.open(argv[1], ios::in);
    if (!ifs) {
        std::cout << "Could not find file " << argv[1] << endl;
        exit(0);
    }

    string tmp;
    string key;
    string value;
    //getline(ifs, tmp, ' ');
    getline(ifs, tmp);

    cout << tmp << endl;
    bool stop = false;

    //Populating vector
    while (tmp[0] != '*'){
        lines.push_back(tmp);
        getline(ifs, tmp);
    }

    //Spliting lines in vector and populating map
    for(int i = 0; i < lines.size(); i++){
        string test = lines[i];
        char separator = ' ';
        int j = 0;
        string s;

        for(int k = 0; k < test.size(); k++){
            if(test[k] != separator){
                s += test[k];
            }
            else {
                key = s;
                s.clear();
            }
        }

        if (s == "space") {
            value = " ";
        } 
        else if (s == "newline") {
            value = "\n";
        }
        else {
        value = s;
        }

        input[key] = value;
    }

    int bits;
    getline(ifs, tmp);
    bits = stoi(tmp); //Num of bits
    cout << bits << endl;

    int numBytes = bits/8;
    if(bits % 8 != 0){
        numBytes++;
    }

    char *c = new char[numBytes];
    ifs.read(c, numBytes);
    ifs.close();
        
    // Convert binary data to binary string
    string binaryString;
    for(int i = 0; i < numBytes; i++){
        binaryString += bitset<8>(c[i]).to_string();
    }
    binaryString = binaryString.substr(0, bits);




    // Decode binary string using prefix codes
    string currentPrefix;
    string decodedText;
    for (char binaryChar : binaryString) {
        currentPrefix += binaryChar;
        if (input.count(currentPrefix) > 0) {
            decodedText += input.at(currentPrefix);
            currentPrefix.clear();
        }
    }

    //cout << "Decoded Text: " << decodedText << endl;


    // Create the output file name
    string inputFilename = string(argv[1]);
    size_t lastDot = inputFilename.find_last_of(".");
    string baseFilename = inputFilename.substr(0, lastDot);
    string outputFilename = baseFilename + "2.txt";

    // Write the decoded text to the output file
    ofstream ofs;
    ofs.open(outputFilename, ios::out);
    if (!ofs) {
        std::cout << "Could not create output file " << outputFilename << endl;
        exit(0);
    }

    ofs << decodedText;
    ofs.close();

    return 0;
}
