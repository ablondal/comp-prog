#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e15;

using arr = array<long long, 3>;

void sortOps(vector<arr> &ops) {
    int i = 0;
    while(i < 2*ops.size()){
        int j = 0;
        while(j+1 < ops.size()){
            arr op1 = ops[j], op2 = ops[j+1];
            if(op1[0] == 0){
                if(op2[0] == 0 && op2[1] < op1[1]){
                    // Ex. D 3, D 2 -> D 2, D 2
                    ops[j] = op2;
                    ops[j+1] = op1;
                    ops[j+1][1]--;
                }
            }else{
                if(op2[0] == 0){
                    if(op2 < op1){
                        if(op1[1] == op2[1]){
                            // Ex. I 2 A, D 2 -> remove both
                            // ops.erase(ops.begin() + j);
                            // ops.erase(ops.begin() + j);
                            // i--;
                            ops[j] = ops[j+1] = {1, (long long) 1e16, 0};
                            // break;
                        }else if(op1[1] < op2[1]){
                            // Ex. I 2 A, D 3 -> D 2, I 2 A
                            ops[j] = op2;
                            ops[j+1] = op1;
                            ops[j][1]--;
                        }else{
                            // Ex. I 3 A, D 2 -> D 2, I 2 A
                            ops[j] = op2;
                            ops[j+1] = op1;
                            ops[j+1][1]--;
                        }
                    }
                }else{
                    if(op2[1] <= op1[1]){
                        // Ex. I 2 A, I 2 B -> I 2 B, I 3 A
                        ops[j] = op2;
                        ops[j+1] = op1;
                        ops[j+1][1]++;
                    }
                }
            }
            j++;
        }
        i++;
    }
    while(!ops.empty() && ops.back()[0] == 1 && ops.back()[1] > inf){
        ops.pop_back();
    }
}

int main() {
    vector<arr> ops1, ops2;
    char type;
    long long index;
    char letter;
    cin >> type;
    while(type != 'E'){
        if(type == 'D'){
            cin >> index;
            ops1.push_back({0, index, 0});
        }else{
            cin >> index >> letter;
            ops1.push_back({1, index, letter});
        }
        cin >> type;
    }
    cin >> type;
    while(type != 'E'){
        if(type == 'D'){
            cin >> index;
            ops2.push_back({0, index, 0});
        }else{
            cin >> index >> letter;
            ops2.push_back({1, index, letter});
        }
        cin >> type;
    }
    sortOps(ops1);
    sortOps(ops2);
    // printf("ops1\n");
    // for(int i = 0; i < ops1.size(); i++){
    //     for(int j = 0; j < ops1[i].size(); j++){
    //         printf("%lld ", ops1[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("ops2\n");
    // for(int i = 0; i < ops2.size(); i++){
    //     for(int j = 0; j < ops2[i].size(); j++){
    //         printf("%lld ", ops2[i][j]);
    //     }
    //     printf("\n");
    // }
    if(ops1 == ops2){
        cout << 0 << endl;
    }else{
        cout << 1 << endl;
    }
}