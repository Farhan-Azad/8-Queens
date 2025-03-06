#include <iostream>
using namespace std;

int main(){
    int q[8], c = 0;
    int counter = 1;
    q[0] = 0; // Starting by placing a queen in the top left corner



    na:
        c++;
        // If c is 8, then we have a solution, so we print it.
        if(c == 8) goto print; 
        q[c] = - 1;

    nt:
        q[c]++;
        if (q[c] == 8) goto backtrack;
        for (int i = 0; i < c; i++){
            // Run a row test and diagonal tests
            if(c - i == abs(q[c] - q[i]) || q[i] == q[c]) goto nt; 
        }

        goto na;

    backtrack:
        c--;
        if (c == -1) return 0;
        goto nt;

    print:
        cout << "Solution #" << counter++ << ": ";
        for (int i = 0; i < 8; i++) {
            cout << q[i];
        }
        cout << endl;

        for (int i = 0; i < 8; i++){
           for (int j = 0; j < 8; j++){
                    if (q[j] == i) 
                    cout << 1;
                else 
                    cout << 0;
           }
           cout << endl;
        }
        cout << endl;
        goto backtrack;

        return 0;
    }