#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#define min(a,b) (a<b)?a:b

using namespace std;

typedef struct word_node{
	word_node* c[26];
	int recc;
	int dels;
	word_node(){
		for(int i=0; i<26; ++i) c[i] = NULL;
		recc = 0;
	}
} node;
/*
string get_recc(node* curr){
	string r = "";
	while(curr->recc>1){
		r = r + (char)curr->recc;
		curr = curr->c[curr->recc-'a'];
	}
	return r;
}

int matchto(const string &a, int i, const string &b){
	int x = 0;
	while( i+x < a.size() && x < b.size() && a[i+x] == b[x] ){
		x++;
	}
	return x;
}*/

int jumpby(const string &s, int &i, node* &curr){
	int step = 0;
	while(s[i]==curr->recc && i<s.size()){
		
		curr = curr->c[s[i]-'a'];
		++i;
		step++;
	}
	return min(step, curr->dels+1);
}


void put_in_tree(const string &s, int i, node* curr){
	if(i==s.size()){
		if( curr->recc == 0 ){
			curr->recc = 1;
			curr->dels = 0;
		}
		return;
	}

	node* t = curr->c[s[i]-'a'];
	if (t){
		put_in_tree(s,i+1,t);
	}else{
		t = curr->c[s[i]-'a'] = new node();
		put_in_tree(s,i+1,t);
	}
	if(curr->recc == 0){
		curr->recc = s[i];
		curr->dels = s.size()-i;
	}
}

int main(){
	int n, m;
	string tmp;
	cin >> n >> m;

	node* Root = new node();
	node* curr;
	node* t;
	unordered_map <string, int> past;

	for(int i=0; i<n; ++i){
		cin >> tmp;
		put_in_tree(tmp,0,Root);
	}

	//cout << "Recc at root: " << get_recc(Root) << endl;

	int steps;
	int mat;
	int backs;
	string r;
	for(int i=0; i<m; ++i){
		cin >> tmp;
		if(past.find(tmp) != past.end()){
			cout << past[tmp] << endl;
			continue;
		}

		steps = 0;

		curr = Root;
		for(int i=0; i<tmp.size(); ){

			t = curr->c[tmp[i]-'a'];

			if ( t ){
				curr = t;
				steps++;
				//cout << "Type " << tmp[i] << endl;
				//cout << steps << " steps" << endl;
			} else {
				steps += tmp.size()-i;
				//cout << "Type " << tmp.substr(i,tmp.size()-i) << endl;
				break;
			}
			++i;

			/*r = get_recc(curr);
			if(r.size()){
			
				mat = matchto(tmp, i, r);

				backs = r.size() - mat;

				steps += min(mat,backs+1);

				//cout << "Jump by " << r.substr(0,mat) << endl;
				//cout << steps << " steps" << endl;
				for(int j=0; j<mat; ++j){
					curr = curr->c[tmp[i]-'a'];
					++i;
				}

			}
			--i;*/
			steps += jumpby(tmp, i, curr);

			//cout << r << endl;
			//cout << mat << endl;

			
		}

		cout << steps << endl;
		past[tmp] = steps;
	}
}












