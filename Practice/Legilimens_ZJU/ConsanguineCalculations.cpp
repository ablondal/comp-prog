#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isBloodLegal(string mom, string dad, string kid){
	if(mom=="AB+") mom="C+";
	else if(mom=="AB-") mom="C-";
	if(dad=="AB+") dad="C+";
	else if(dad=="AB-") dad="C-";
	if(kid=="AB+") kid="C+";
	else if(kid=="AB-") kid="C-";
	if(mom[1]=='-' && dad[1]=='-' && kid[1]=='+') return 0;
	if((dad[0]=='C' || mom[0]=='C') && kid[0]=='O') return 0;
	if((dad[0]=='O' || mom[0]=='O') && kid[0]=='C') return 0;
	if((dad[0]=='A' || dad[0]=='B') && dad[0]==mom[0] && kid[0]=='C') return 0;
	if(kid[0]=='B' && (mom[0]=='O' || mom[0]=='A') && (dad[0]=='O' || dad[0]=='A')) return 0;
	if(kid[0]=='A' && (mom[0]=='O' || mom[0]=='B') && (dad[0]=='O' || dad[0]=='B')) return 0;
	return 1;
}

int main(){
	string mom,dad,kid;
	int c = 0;
	string bloodtypes[8] = {"O+","O-","A+","A-","B+","B-","AB+","AB-"};
	vector <string> canbe;
	cin>>mom>>dad>>kid;
	while(mom!="E"){
		c++;
		cout << "Case "<<c<<": ";
		canbe.clear();
		if(mom=="?"){
			for(int i=0;i<8;++i){
				if(isBloodLegal(bloodtypes[i],dad,kid)) canbe.push_back(bloodtypes[i]);
			}
			if(canbe.size()>1){
				cout << "{" << canbe[0];
				for(int j=1;j<canbe.size();++j){
					cout << ", " << canbe[j];
				}
				cout << "} ";
			}else if(canbe.size()==1){
				cout << canbe[0] << ' ';
			}else{
				cout << "IMPOSSIBLE ";
			}
		}else{cout << mom << ' ';}
		if(dad=="?"){
			for(int i=0;i<8;++i){
				if(isBloodLegal(mom,bloodtypes[i],kid)) canbe.push_back(bloodtypes[i]);
			}
			if(canbe.size()>1){
				cout << "{" << canbe[0];
				for(int j=1;j<canbe.size();++j){
					cout << ", " << canbe[j];
				}
				cout << "} ";
			}else if(canbe.size()==1){
				cout << canbe[0] << ' ';
			}else{
				cout << "IMPOSSIBLE ";
			}
		}else{cout << dad << ' ';}
		if(kid=="?"){
			for(int i=0;i<8;++i){
				if(isBloodLegal(mom,dad,bloodtypes[i])) canbe.push_back(bloodtypes[i]);
			}
			if(canbe.size()>1){
				cout << "{" << canbe[0];
				for(int j=1;j<canbe.size();++j){
					cout << ", " << canbe[j];
				}
				cout << "}\n";
			}else if(canbe.size()==1){
				cout << canbe[0] << '\n';
			}else{
				cout << "IMPOSSIBLE\n";
			}
		}else{cout << kid << '\n';}
		cin >> mom>>dad>>kid;
	}
}