
#include<bits/stdc++.h>

using namespace std;

int main() {
    int numofsymbol, numofstates, initialstate, numofas;

    // Input: Number of input symbols
    cout << "Number of input symbols : ";
    cin >> numofsymbol;

    char inputsymbol[numofsymbol];
    cout << "Input symbols : ";
    for (int i = 0; i < numofsymbol; i++) {
        cin >> inputsymbol[i];
    }

    // Input: Number of states
    cout << "Enter number of states : ";
    cin >> numofstates;

    // Input: Initial state
    cout << "Initial state : ";
    cin >> initialstate;

    // Input: Number of accepting states
    cout << "Number of accepting states : ";
    cin >> numofas;

    int accepting[numofas];
    cout << "Accepting states : ";
    for (int i = 0; i < numofas; i++) {
        cin >> accepting[i];
    }

    // Input: Transition table
    int transitiontable[numofstates + 1][numofsymbol];
    cout << "Transition table :\n";
    for (int i = 1; i <= numofstates; i++) {
        for (int j = 0; j < numofsymbol; j++) {
            cout << "state: " << i << " to " << inputsymbol[j] << " -> ";
            cin >> transitiontable[i][j];
        }
    }

    // Input: String to validate
    cout << "Input string : ";
    string Inputstring;
    cin >> Inputstring;

    int currentstate = initialstate;
    bool isValid = true;

    // Validate the input string
    for (char c : Inputstring) {
        bool symbolFound = false;
        for (int j = 0; j < numofsymbol; j++) {
            if (c == inputsymbol[j]) {
                currentstate = transitiontable[currentstate][j];
                symbolFound = true;
                break;
            }
        }
        if (!symbolFound) {
            isValid = false;
            break;
        }
    }

    // Check if the current state is one of the accepting states
    if (isValid) {
        isValid = false;
        for (int i = 0; i < numofas; i++) {
            if (currentstate == accepting[i]) {
                isValid = true;
                break;
            }
        }
    }

    // Output the result
    if (isValid) {
        cout << "Valid string" << endl;
    } else {
        cout << "Invalid string" << endl;
    }

    return 0;
}
