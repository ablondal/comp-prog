#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    char newline;
    // cin >> newline;
    newline = cin.get();
    printf("%c\n", newline);
    stack<int> soldierStack;
    vector<int> supervisors(n + 1);
    while (cin.peek() != EOF && cin.peek() != '\n')
    {
        if(cin.peek() == '(' || cin.peek() == ')'){
            char bracket;
            cin >> bracket;
            if(bracket == ')'){
                printf("top: %d\n", soldierStack.top());
                soldierStack.pop();
            }
        }else{
            int id;
            cin >> id;
            printf("id: %d\n", id);
            if (!soldierStack.empty())
            {
                supervisors[id] = soldierStack.top();
            }
            soldierStack.push(id);
        }
    }
    for (int i = 1; i <= n; i++){
        printf("%d ", supervisors[i]);
    }
    printf("\n");
}