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
        //cout << "in the FOR loop" << endl;
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
            value = s;
            cout << "Key: " << key << " Char: " << value << endl;

            input[key] = value;

            cout << lines[i] << endl;
        }


        int bits;
        getline(ifs, tmp);
        bits = stoi(tmp); //Num of bits
        cout << bits << endl;
        
}
