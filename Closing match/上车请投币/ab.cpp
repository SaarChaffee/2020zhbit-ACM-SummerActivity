#include<iostream>
using namespace std;
#define LL long long
int main(){
	LL x,y,a,b;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>x>>y,x&y){
		a=(x+y)/2;
		b=x-a;
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}
