//  CPP_335_23_0015_0052

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;

int QUARTERVALUE = 25;
int DIMEVALUE = 10;
int NICKELVALUE = 5;
int PENNYVALUE = 1;
int TENSVALUE = 10;
int ONESVALUE = 1;
int FIVESVALUE = 5;
int TWENTIESVALUE = 20;
int FIFTIESVALUE = 50;
int HUNDREDSVALUE = 100;
int dollars, twenties, tens, fives, ones;
int cents, quarters, dimes, nickels, pennies;

class ChangeMachine {
    
};

// Takes in input and parses into Vector
void getInput() {
    
}

// Calculates change based on input
void getChange() {
    
}

int main(int argc, const char * argv[]) {
    // Read input file
    string output;
    
    ifstream infile;
    infile.open ("coindata.txt");
    while(!infile.eof())
    {
        getline(infile, output);
        
    }
    infile.close();
    
    // Parse input file into Vector with a stream
    string buf;
    stringstream ss(output);
    vector<string> coins;

    while (ss >> buf)
        coins.push_back(buf);
    
    // print out vector with for each
//    for (auto c : coins)
//        cout << c << " ";
    
    int coinValue = 0;
    
    for (int i=0; i<coins.size(); i++) {
        if (i%2 == 0) {
            switch ( i ) {
                case 0:
                    coinValue += stoi(coins[i+1]) * 100;
                    break;
                case 2:
                    coinValue += stoi(coins[i+1]) * 25;
                    break;
                case 4:
                    coinValue += stoi(coins[i+1]) * 10;
                    cout << coins[i+1];
                    break;
                case 6:
                    coinValue += stoi(coins[i+1])* 5;
                    break;
                case 8:
                    coinValue += stoi(coins[i+1]) * 1;
                    break;
                case 10:
                    coinValue += stoi(coins[i+1]) * 1;
                    break;
            }
        }
    }
    cout<< coinValue;
    
    int change = coinValue;
    
    // calculate change
    dollars = (int) change;

    twenties = (int) (((dollars % HUNDREDSVALUE) % FIFTIESVALUE) / TWENTIESVALUE);
    tens = (int) ((((dollars % HUNDREDSVALUE) % FIFTIESVALUE) % TWENTIESVALUE) / TENSVALUE);
    fives = (int) (((((dollars % HUNDREDSVALUE) % FIFTIESVALUE) % TWENTIESVALUE) % TENSVALUE) /FIVESVALUE);
    ones = (int) (((((((dollars % HUNDREDSVALUE) % FIFTIESVALUE) % TWENTIESVALUE) % TENSVALUE) % FIVESVALUE) /ONESVALUE));
    
    cents = change - dollars;
    cents *= 100;
    quarters = (int) (cents / QUARTERVALUE);
    dimes = (int) ((cents % QUARTERVALUE) / DIMEVALUE);
    nickels = (int) (((cents % QUARTERVALUE) % DIMEVALUE) / NICKELVALUE);
    pennies = (int) ((((cents % QUARTERVALUE) % DIMEVALUE) % NICKELVALUE) / PENNYVALUE);
    
    cout << twenties << " twenty dollar bill(s), " << tens << " ten dollar bill(s), " << fives << " five dollar bill(s), " << ones << " one dollar bill(s), " << quarters << " quarter(s), " << dimes << " dime(s), " << nickels << " nickel(s), and " << pennies << " penny(ies)";
    
    return 0;
}
