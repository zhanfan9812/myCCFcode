//Ö»ÓÐ90·Ö£¡£¡£¡£¡ 



#include<cstring>
#include<string.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
//#define debug

using namespace std;

int main(){
	map<char,string>ans;
	int m[26],t,n;
	memset(m,0,sizeof(m));
	char c;
	while((c=getchar())!='\n'){
		if(c!=':'){
			t=c-'a';
			m[t]=1;
		}else{
			m[t]++;
		}
	}
	#ifdef dubug
	for(int i=0;i<26;i++)
	    cout<<m[i]<<" ";
	#endif
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++){
		ans.clear();
	    char op[260],*p;
	    vector<string>t;
	    cin.getline(op,256);
	    p=strtok(op," ");
	    while(p){
	    	t.push_back(p);
	    	p=strtok(NULL," ");
		}
		#ifdef debug
		for(vector<string>::iterator it=t.begin();it!=t.end();it++){
			cout<<*it<<endl;
		}
		#endif
		cout<<"Case "<<i<<":";
		for(int j=1;j<t.size();j++){
			string temp=t[j];
			if(temp[0]!='-'){
				break;
			}else if(temp.size()!=2){
				break;
			}else if(m[temp[1]-'a']==0){
				break;
			}else{
				if(m[temp[1]-'a']==1)
				    ans[temp[1]]="NULL";
				if(m[temp[1]-'a']==2){
				    ans[temp[1]]=t[j+1];
				    j++;
				}
			}
		}
		for(map<char,string>::iterator mit=ans.begin();mit!=ans.end();mit++){
			if(mit->second=="NULL")
			    cout<<" -"<<mit->first;
			else
			    cout<<" -"<<mit->first<<" "<<mit->second;
		}
		cout<<endl;
	}
}
