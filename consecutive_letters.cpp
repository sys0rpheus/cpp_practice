//so this code finds out a sequence of consecutive ascii characters in a string, the string is named s
//feel free to change the string and test the results.

#include <iostream>
using namespace std;
#include <vector>

int main (){
    string s = "skvurbdkcorherhgabcdfnykgbujfbrefgfngjh";
    int cons = 1;
    int curr = 0;
    int pst = 0;
    std::vector<int> lst = {};
    
    for (int i=1; i<s.length(); i++) { 
        // cout << static_cast<int>(s[i]) << "\n";
        curr = static_cast<int>(s[i]);
        pst = static_cast<int>(s[i-1]);
        if (curr == pst + 1) {
            cons++;
        } else {
            lst.push_back(cons);
            cons = 1;
        }
        // cout << s[i] << " - " << s[i-1] << " - " << curr << " - " << pst << " - " << cons << "\n";
    }
    lst.push_back(cons);
    // for (int i : lst) { 
    //     cout << i << "\n";
    // }

    int mx = 0;
    for (int i : lst) {
        if (i > mx) mx = i;
    }
    cout << mx;
}