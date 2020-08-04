#include<iostream>
#include<math.h>
using namespace std;
const int M=1000007;
int main(){
	#define LOCAL
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	#endif
	int n,res,a,b,c;
	while(~scanf("%d",&n)){
		if(n==1){
			puts("1");
			continue;
		}
		if(n==2){
			puts("2");
			continue;
		}
		a=1;
		b=2;
		c=0;
		for(int i=3;i<=n;++i){
			c=(a+b)%M;
			a=b;
			b=c;
		}
		printf("%d\n",c);
	}
	return 0;
}
