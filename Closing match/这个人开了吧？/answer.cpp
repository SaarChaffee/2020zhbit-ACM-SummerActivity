#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int dest[2000][2000];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,m,sx,sy,ex,ey,bx,by,mx,my,tol;
	while(cin>>n>>m){
		tol=0;
		memset(dest,0,sizeof dest);
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				scanf("%d",&dest[i][j]);
				if(dest[i][j]==100){
					ex=i;ey=j;
				}	
			}
		}
		cin>>sx>>sy;
		//左上和右下,左往右迭代 
		if((sx<ex&&sy<ey)||(ex<sx&&ey<sy)){
			//(bx,by)为右下的点，(mx,my)为左上的点 
			bx=sx>ex?sx:ex;
			mx=bx==sx?ex:sx;
			by=bx==sx?sy:ey;
			my=mx==ex?ey:sy;
			//每一行 
			for(int i=mx;i<=bx;++i){
				//如果是第一列 
				if(i==mx){
					for(int j=my;j<=by;++j){
						//第一列只要不是第一个 
						if(j!=my){
							//一定来自于左边 
							dest[i][j]+=dest[i][j-1];
						}
					}
				}
				//在不是第一列的情况 
				else{
					for(int j=my;j<=by;++j){
						if(j!=my){
							dest[i][j]+=min(dest[i][j-1],dest[i-1][j]);
						}
						else{
							//只有第一个使用上方的值 
							dest[i][j]+=dest[i-1][j];
						}
					}				
				}
			} 
			//tol=dest[bx][by];
		}
		//右上和左下,或同行同列,右往左迭代 
		//if ( (sx<ex&&sy>ey)||(ex<sx&&ey>sy) )
		else{
			//(bx,by)为左下的点，(mx,my)为右上的点 
			bx=sx>ex?sx:ex;
			mx=bx==sx?ex:sx;
			by=bx==sx?sy:ey;
			my=mx==ex?ey:sy;
			//在同一列时,无法直接靠bx的取值来决定my和by的取值 
			if(sx==ex){
				by=sy<ey?sy:ey;
				my=by==sy?ey:sy;
			}
			//每一行 
			for(int i=mx;i<=bx;++i){
				//如果是第一列 
				if(i==mx){
					for(int j=my;j>=by;--j){
						if(j!=my){
							//一定来自于右边 
							dest[i][j]+=dest[i][j+1];
						}
					}
				}
				//在不是第一列的情况 
				else{
					for(int j=my;j>=by;--j){
						if(j!=my){
							dest[i][j]+=min(dest[i][j+1],dest[i-1][j]);
						}
						else{
							//只有第一个使用上方的值 
							dest[i][j]+=dest[i-1][j];
						}	
					}	
				}
			}
			//tol=dest[bx][by];
		}
		tol=dest[bx][by];
		cout<<tol<<endl;
	}
	return 0;
}
