#include<stdio.h>
//standard program
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,tmp,i;
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++){
			scanf("%d",&tmp);
		}
		if(n==1){
			printf("0\n");
			continue;
		}
		if(n==2){
			printf("1\n");
			continue;
		}
		printf("%d\n",(n-2)*2+1);
	}
	return 0;
}
