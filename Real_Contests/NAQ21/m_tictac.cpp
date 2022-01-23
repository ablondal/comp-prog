#include <bits/stdc++.h>

using namespace std;

string maps[9] = {"000","001", "010", "011", "100", "101", "110", "111"};
char matrix[3][3];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    string s;
    string bin;
    while(n--){
        bin.clear();
        cin >> s;
        
        long long state = 0;
        for(int i=0; i<s.size(); ++i){
            state*= 8;
            state += (s[i]-'0');
        }


        
        // while(s.length() < 8){
        //     s = "0" + s;
        // }
        // // map octal to binary
        // for(int i = 0; i < s.length(); ++i){
        //     bin += maps[s[i] - '0'];
        // }
        
        // reset board
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                matrix[i][j] = '.';
            }
        }

        int cnt = 0;

        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                if (state & 1) {
                    cnt++;
                    matrix[i][j] = '!';
                }
                state >>= 1;
            }
        }
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                if (matrix[i][j] == '!'){
                    if (state & 1){
                        matrix[i][j] = '1';
                    } else {
                        matrix[i][j] = '0';
                    }
                }
                state >>= 1;
            }
        }

        // bits are right to left, i wanna go left to right 
        // reverse(bin.begin(), bin.end());
        
        // compute board, count number of set cells (cnt)
        // int cnt = 0;
        // for(int i = 0; i < 3; ++i){
        //     for(int j = 0; j < 3; ++j){
        //         if(bin[i*3+j]=='1'){
        //             ++cnt;
        //             matrix[i][j] = bin[i * 3 + j + 9];
        //         }
        //     }
        // }
        
        bool done = false;
        
        // check state from board
        for(int i = 0; i < 3; ++i){
            // verticals
            if( matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2]){
                if(matrix[i][0] == '0'){
                    cout << "O wins" << '\n';
                    done = true;
                    break;
                }
                else if(matrix[i][0] == '1'){
                    cout << "X wins" << '\n';
                    done = true;
                    break;
                }
            }
            // horizontals
            if(matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i]){
                if(matrix[0][i] == '0'){
                    cout << "O wins" << '\n';
                    done = true;
                    break;
                }
                else if(matrix[0][i] == '1'){
                    cout << "X wins" << '\n';
                    done = true;
                    break;
                }
            }
        }
        if(done) continue;
        // diagonal 1
        if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]){
            if(matrix[0][0] == '0'){
                cout << "O wins" << '\n';
                done = true;
            }
            else if(matrix[0][0] == '1'){
                cout << "X wins" << '\n';
                done = true;
            }
        }
        // diagonal 2
        if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]){

            if(matrix[0][2] == '0'){
                cout << "O wins" << '\n';
                done = true;
            }
            else if(matrix[0][2] == '1'){
                cout << "X wins" << '\n';
                done = true;
            }
        }
        if(done) continue;
        if(cnt == 9){
            cout << "Cat's\n";
        }
        else cout << "In progress\n";
    }
    return 0;
}
