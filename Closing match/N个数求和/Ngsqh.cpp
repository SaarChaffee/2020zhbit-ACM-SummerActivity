/* N个数求和标准程序 */
/*Ngsqh stander program*/
#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a,int b) {
    return b == 0 ? a : gcd(b,a % b);
}
int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);	 
    int n;
    while(cin>>n,n){
    	int a,b,c = 0,d = 1;
    	for(int i = 0;i < n;i ++) {
		    cin>>a;
		    getchar();
		    cin>>b;
		    c = c * b + a * d;
		    d *= b;
		    int g = abs(gcd(c,d));
		    c /= g;
		    d /= g;
    	}  
	    if(c < 0&&d>0) {// - +
	        putchar('-');
	        c = -c;
	    }
	    else if(c>0&&d<0){// + -
	    	putchar('-');
	        d = -d;
		}
		else if(c<0&&d<0){//- -
			c = -c;
			d = -d;
		}
		//+ +
	    if(c / d || !c) printf("%d",c / d);
	    if(c > d && c % d) putchar(' ');
	    if(c % d) printf("%d/%d",c % d,d);
	    puts("");
	}
}

