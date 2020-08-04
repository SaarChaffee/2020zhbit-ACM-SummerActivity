#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const int max=100;
int main(){
	int n=1000,a,b;
	freopen("in.txt","w",stdout);
	while(n--){
		a=(rnd()%100)+1;
		b=(rnd()%100)+1;
		cout<<a<<" "<<b<<endl;
		for(int i=0;i<a;++i){
			for(int j=0;j<b;++j)
				putchar((rnd()&1?'x':'o'));
			puts("");
		}
	}
	return 0;
}

