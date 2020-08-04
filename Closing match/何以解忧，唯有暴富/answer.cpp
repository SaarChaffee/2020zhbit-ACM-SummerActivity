#include<iostream>
#include<cmath>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	long double a,b;
	while(cin>>a>>b){
		//ceil(1.2)==2
		//ceil(1.9)==2 math  ceil round floor
		cout<<ceil(b/a)<<endl;
	}
	return 0;
}
