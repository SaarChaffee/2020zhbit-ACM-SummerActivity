#include<iostream>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	long long n,res;
	while(cin>>n,n){
		res=0;
		// 4 100 
		// 5 101
		while(n){
			//if(n&1)
			res+=(n&1?0:1);
			n>>=1;
		}
		cout<<res<<endl;
	}
	return 0;
}
