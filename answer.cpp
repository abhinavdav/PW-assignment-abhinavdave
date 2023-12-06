#include <bits/stdc++.h>
using namespace std;

void printo(queue<int> queueofnumbers){
	cout<<"[";
	int n = queueofnumbers.size();
	while(!queueofnumbers.empty()){
		int x = queueofnumbers.front();
		cout<<x;
		if(queueofnumbers.size()>1)
			cout<<",";
		queueofnumbers.pop();
	}
	cout<<"]"<<endl;
	return;
}

int main(){
	string str;
	cin>>str;
	
	if(str != "init"){
		cout<<"wrong initialization"<<endl;
		return 0;
	}
	int n;
	cin>>n;
	int capacity = n/4;
	queue<int> AV, ANV, BV, BNV, NA;
	string S;
	
	while(getline(cin,S)){
		if(S == "fin") 
			break;
		string T;
	    stringstream X(S);
	    vector<string> v;
	    while (getline(X, T, ' ')) {
	        v.push_back(T);
	    } 
    	if(v.size()< 4)
    		continue;
    	
    	if(v[0] != "reg"){
    		cout<<"input error"<<endl;
    		return 0;
    	}
    	
    	if(v[2] == "A"){
    		if(v[3] == "V"){
    			if(AV.size() < capacity){
    				AV.push(stoi(v[1]));
    			}
    			else{
    				NA.push(stoi(v[1]));
    			}
    		}
    		else if(v[3] == "NV"){
    			if(ANV.size() < capacity){
    				ANV.push(stoi(v[1]));
    			}
    			else{
    				NA.push(stoi(v[1]));
    			}
    		}
    		else{
    			continue;
    		}
    	}
    	else if(v[2] == "B"){
    		if(v[3] == "V"){
    			if(BV.size() < capacity){
    				BV.push(stoi(v[1]));
    			}
    			else{
    				NA.push(stoi(v[1]));
    			}
    		}
    		else if(v[3] == "NV"){
    			if(BNV.size() < capacity){
    				BNV.push(stoi(v[1]));
    			}
    			else{
    				NA.push(stoi(v[1]));
    			}
    		}
    		else{
    			continue;
    		}
    	}	
	}
	
	cout<<"BV"<<" : ";
	printo(BV);
	
	cout<<"AV"<<" : ";
	printo(AV);
	
	cout<<"BNV"<<" : ";
	printo(BNV);
	
	cout<<"ANV"<<" : ";
	printo(ANV);
	
	cout<<"NA"<<" : ";
	printo(NA);
	
	return 0;
}