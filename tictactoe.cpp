#include <iostream>
#include <vector>
#include <array>

using namespace std;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

string printer (array<array<int, 3>, 3> inp) {
    int ok2 =0;
    int ok1 =0;
    int ok0 =0;
    cout << "------------\n";
    // ----------------------------------
    while (ok0 != 3) {
        for (int i=0; i<inp.size(); i++){
            cout << inp[i][0];
            ok0++;
        }
    }
    cout<<"\n";
    // ----------------------------------
    while (ok1 != 3) {
        for (int i=0; i<inp.size(); i++){
            cout << inp[i][1];
            ok1++;
        }
    }
    cout<<"\n";
    // ----------------------------------
    while (ok2 != 3) {
        for (int i=0; i<inp.size(); i++){
            cout << inp[i][2];
            ok2++;
        }
    }
    cout<<"\n";
    // ----------------------------------
    cout << "------------\n";
    return "done";
}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

int checker (int adv , array<array<int, 3>, 3> inp) {
    int v2 =0;
    int v1 =0;
    int v0 =0;
    // ----------------------------------
    int h2 =0;
    int h1 =0;
    int h0 =0;
    // ----------------------------------
    int o1 =0;
    int o0 =0;
    // ----------------------------------
    //verticals
    for (int i=0; i<inp.size(); i++) {
        if (inp[i][2] == adv) {
            v2++;
        }
    }
    // ----------------------------------
    for (int i=0; i<inp.size(); i++) {
        if (inp[i][1] == adv) {
            v1++;
        }
    }
    // ----------------------------------
    for (int i=0; i<inp.size(); i++) {
        if (inp[i][0] == adv) {
            v0++;
        }
    }
    //end of verticals
    // ----------------------------------
    //start of horizontals
    for (int i=0; i<inp[0].size(); i++) {
                if (inp[0][i] == adv) {
                       h0++;
                }
    }
    // ----------------------------------
    for (int i=0; i<inp[1].size(); i++) {
                if (inp[1][i] == adv) {
                       h1++;
                }
    }
    // ----------------------------------
    for (int i=0; i<inp[2].size(); i++) {
                if (inp[2][i] == adv) {
                       h2++;
                }
    }
    //end of horizontals
    // ----------------------------------
    //start of diagonal
    if (inp[0][2] == adv) {
        o0++;
    }
    if (inp[1][1] == adv) {
        o0++;
    }
    if (inp[2][0] == adv) {
        o0++;
    }
    // ----------------------------------
    if (inp[0][0] == adv) {
        o1++;
    }
    if (inp[1][1] == adv) {
        o1++;
    }
    if (inp[2][2] == adv) {
        o1++;
    }
    //end of diagonal
    // ----------------------------------
    if (
        v2 == 3 ||
        v1 == 3 ||
        v0 == 3 ||
        h2 == 3 ||
        h1 == 3 ||
        h0 == 3 ||
        o1 == 3 ||
        o0 == 3
    ) {
        return adv;
    } else return 0;

}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

void prompter (int adv, array<array<int, 3> , 3> &inp) {
    cout << "Hello " << adv << "\n";
    cout << "Choose your column number \n";
    int col;
    cin >> col;
    cout << "\n Choose your row number \n";
    int row;
    cin >> row;
    inp[col][row] = adv;

}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

int main () {
    int winner = 0;
    array<array<int, 3>, 3> mn{};

    
    
    while (winner == 0) {
        printer(mn);

        prompter(1, mn);        
        winner = checker(1, mn);
        if (winner == 1) {
            cout << "1 has won";
            break;
        }
        printer(mn);

        prompter(2, mn);
        winner = checker(2, mn);
        if (winner == 2) {
            cout << "2 has won";
            break;
        }
        printer(mn);        
    }

    return winner;
}