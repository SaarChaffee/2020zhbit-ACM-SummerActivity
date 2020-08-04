#include<stdio.h>
//standard program
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,m,l,r,v;
	int i,j;
	while(scanf("%d%d",&n,&m)&&(n+m)){
		int money[1010];
		for(i=1;i<=m;++i){
			scanf("%d%d%d",&l,&r,&v);
			for(j=l;j<=r;++j){
				money[j]=v;
			}
		}
		scanf("%d%d",&l,&r);
		int ans,last;
		ans=last=0;
		for(i=l;i<=r;++i){
			if(last!=money[i]){
				ans+=money[i];
				last=money[i];
			}			
		}
		printf("%d\n",ans);
	}
	return 0;
}
