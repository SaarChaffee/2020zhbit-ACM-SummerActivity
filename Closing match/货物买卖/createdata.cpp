#include<bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=a;i<b;++i)
#define _For(i,a,b) for(int i=a;i<=b;++i)
#define for_(i,a,b) for(int i=a;i>b;--i)
#define For_(i,a,b) for(int i=a;i>=b;--i)
#define ll long long

int main(){
	int n;
//	freopen("create.txt","r",stdin);
//	freopen("res.txt","w",stdout);
	srand((unsigned int)time(0));
	while(cin>>n,n){
	cout<<n<<endl;
	int last=0;
	for(int i=0;i<n-1;i++){//n-1次
		last+=(1+rand()%3);
		cout<<last<<" ";	
	}
	last+=(1+rand()%3);
	cout<<last<<endl;//最后一次 
	}
	cout<<0;
	return 0;
}
