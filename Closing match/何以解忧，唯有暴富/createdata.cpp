#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int main(){
	int n=20000;
	freopen("in.txt","w",stdout);
	while(n--){
		cout<<(rnd()%10000000)+1<<" "<<(rnd()%10000000)+1<<endl;
	}
	return 0;
}
