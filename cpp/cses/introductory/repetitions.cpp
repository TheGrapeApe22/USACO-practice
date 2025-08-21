#include <iostream>

using namespace std;

int main() {
    string input;
    cin >> input;
    
    int numReps = 1;
    int maxNumReps = 1;
    char prevChar = input[0];
    for (int i = 1; i < input.size(); i++) {
        if (input[i] != prevChar) {
            prevChar = input[i];
            numReps = 0;
        }
        numReps++;
        maxNumReps = max(maxNumReps, numReps);
    }
    
    cout << maxNumReps << endl;
}
