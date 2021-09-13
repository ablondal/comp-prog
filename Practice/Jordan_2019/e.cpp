#include <bits/stdc++.h>
using namespace std;

int main(){
    string sequence = "";
    for (int i = 0; i < 50; i++){
        sequence += "LD";
    }
    for (int i = 0; i < 10; i++){
        sequence += "UULDLD";
    }
    sequence += "UUUURRRRRRRRRRRLLLLDDDRUUURRRDDDLULUUUUUUUUUUUUDDDDUU";
    int t;
    string line;
    cin >> t;
    getline(cin, line);
    for (int i = 0; i < t; i++){
        getline(cin, line);
        cout << sequence.size() << endl;
        cout << sequence << endl;
    }
}