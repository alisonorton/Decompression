#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

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

    
}
