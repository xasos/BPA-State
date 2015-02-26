//  CPP_335_23_0015_0052


// Start at 4: 13 -> 90 mins


#include <iostream>
#include <fstream>
using namespace std;

class ChangeMachine {
    
};

int main(int argc, const char * argv[]) {
    string output;
    ifstream infile;
    infile.open ("coindata.txt");
    while(!infile.eof())
    {
        getline(infile, output);
        cout<< output;
    }
    infile.close();
    
    return 0;
}

