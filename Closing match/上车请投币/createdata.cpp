#include<bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=a;i<b;++i)
#define _For(i,a,b) for(int i=a;i<=b;++i)
#define for_(i,a,b) for(int i=a;i>b;--i)
#define For_(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
const char table[]={'a','b','c','d','e','f','g','h','i',
				'j','k','l','m','n','o','p','q',
				'r','s','t','u','v','w','x','y','z'
};

int main(){
	int len;
	freopen("out.txt","w",stdout);
	srand((unsigned int)time(0));
	for(int i=0;i<100;i++){//次数 
		len=1+rand()%9;
		for(int j=0;j<len;j++){//长度 
			cout<<table[rand()%26];	
		}
		cout<<endl;
	}
	for(int i=0;i<100;i++){
		cout<<(rand()%151-50)<<endl;
	}
	return 0;
}
