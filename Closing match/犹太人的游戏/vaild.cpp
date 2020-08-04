#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,m,ok;
	string s;
	while(cin>>n>>m){
		ok=0;
		cout<<"get n: "<<n<<" get m: "<<m<<endl;
		for(int i=0;i<n;++i){
			cin>>s;
			for(int j=0;j<m;++j){
				if(s[j]=='o'){
					ok=1;
					break;
				}
			}
		}
		assert(ok);
	}
	return 0;
}
