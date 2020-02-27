#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int N;
    bool Lets[26];
    cin >> N;
    char tmp;
    int tmpval, tmpval1;
    for(int i=0; i < N; ++i){
        cin >> tmp;
        if(tmp == 'F') Lets[i] = 0;
        else Lets[i] = 1;
    }
    stack <bool> S;

    while( cin >> tmp ){
        if('A' <= tmp && 'Z'>= tmp){
            S.push(Lets[tmp-'A']);
        }else if(tmp == '-'){
            tmpval = !(S.top());
            S.pop();
            S.push(tmpval);
        }else if(tmp == '*'){
            tmpval = S.top();
            S.pop();
            tmpval1 = S.top();
            S.pop();
            tmpval = tmpval && tmpval1;
            S.push(tmpval);
        }else{
            tmpval = S.top();
            S.pop();
            tmpval1 = S.top();
            S.pop();
            tmpval = tmpval || tmpval1;
            S.push(tmpval);
        }
    }
    tmpval = S.top();
    if(tmpval) cout << "T" << endl;
    else cout << "F" << endl;
}