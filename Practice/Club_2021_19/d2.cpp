#include <bits/stdc++.h>
using namespace std;

vector<long long> getWindDirections(vector<long long> &oneRound, string s, long long n, long long days){
    vector<long long> answer(4);
    long long whole = days / n;
    long long rem = days % n;
    for (int i = 0; i < 4; i++){
        answer[i] += oneRound[i] * whole;
    }
    for (int i = 0; i < rem; i++){
        if(s[i] == 'U'){
            answer[0]++;
        }else if(s[i] == 'D'){
            answer[1]++;
        }else if(s[i] == 'L'){
            answer[2]++;
        }else{
            answer[3]++;
        }
    }
    return answer;
}

bool works(vector<long long> &target, vector<long long> &oneRound, string s, int n, long long days){
    vector<long long> wind = getWindDirections(oneRound, s, n, days);
    for (int i = 0; i < 4; i++){
        days -= abs(target[i] - wind[i]);
    }
    return days >= 0;
}

long long binarySearch(vector<long long> &target, vector<long long> &oneRound, string s, int n, long long l, long long r){
    if(l >= r){
        return l;
    }
    long long mid = (l + r) / 2;
    if(works(target, oneRound, s, n, mid)){
        return binarySearch(target, oneRound, s, n, l, mid);
    }
    return binarySearch(target, oneRound, s, n, mid + 1, r);
}

int main(){
    long long x1, x2, y1, y2;
    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    vector<long long> target(4);
    long long zero = 0;
    target[0] = max(y2 - y1, zero);
    target[1] = max(y1 - y2, zero);
    target[2] = max(x1 - x2, zero);
    target[3] = max(x2 - x1, zero);
    vector<long long> oneRound(4);
    for (int i = 0; i < n; i++){
        if(s[i] == 'U'){
            oneRound[0]++;
        }else if(s[i] == 'D'){
            oneRound[1]++;
        }else if(s[i] == 'L'){
            oneRound[2]++;
        }else{
            oneRound[3]++;
        }
    }
    long long l = 0;
    long long r = 4000000000000000000;
    long long answer = binarySearch(target, oneRound, s, n, l, r);
    if(answer == r){
        printf("-1\n");
    }else{
        printf("%lld\n", answer);
    }
}
