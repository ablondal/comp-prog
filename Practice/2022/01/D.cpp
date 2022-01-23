#include <iostream>
using namespace std;

string myFunction(string str, int size){
    bool key = false;
    for (int i=1;i<size;i++){
        if (str[i]!='?' && str[i-1]=='?'){
            int j = i-1;
            while(str[j] == '?'){
                if(str[j+1] =='B'){
                    str[j] = 'R';
                    j--;
                }
                else{
                    str[j] = 'B';
                    j--;
                }
            }
            key = true;
        }
    }
    for (int i=0;i<size-1;i++){
        if (str[i]!='?' && str[i+1]=='?'){
            int j = i+1;
            while(str[j] == '?'){
                if(str[j-1] =='B'){
                    str[j] = 'R';
                    j++;
                    
                }
                else{
                    str[j] = 'B';
                    j++;
                }
            }
            key = true;
        }
    }
    if(!key){
        for (int i=0;i<size;i++){
            if(i==0){
                str[i] = 'B';
            }
            while(str[i] == '?'){
                if(str[i-1] =='B'){
                    str[i] = 'R';
                    i++;
                    
                }
                else{
                    str[i] = 'B';
                    i++;
                }
            }

        }
    }
    
    return str;
}

class cases{
public:
    int num=0;
    string str="";
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test = 0;
    cin>>test;
    cases c[test];
    for (int i=0;i < test;i++){
        cin>>c[i].num;
        cin>>c[i].str;
        c[i].str = myFunction(c[i].str,c[i].num);
        
    }
    for (int i=0;i < test;i++){
        cout<<c[i].str<<endl;
    }
    
    return 0;
}