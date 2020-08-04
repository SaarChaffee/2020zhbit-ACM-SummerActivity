#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int main(){
	int n=13;
	freopen("in.txt","w",stdout);
	while(n--){
		cout<<rnd()%10000000<<endl;
	}
	cout<<0<<endl;
	return 0;
}
