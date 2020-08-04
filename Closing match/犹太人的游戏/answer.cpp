#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int dest[101];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,m,flag;
	string s;
	while(cin>>n>>m){
		memset(dest,0,sizeof dest);
		flag=0;
		for(int i=0;i<n;++i){
			cin>>s;
			for(int j=0;j<m;++j){
				if(s[j]=='x'){
					continue;
				}
				dest[j]++;
			}
		}
		if(m==1){
			puts("win");
			continue;
		}
		for(int j=0;j<m;++j){
			flag=flag^dest[j];
		}
		if(!flag){
			puts("fail");
		}
		else{
			puts("win");
		}
	}
	return 0;
}
