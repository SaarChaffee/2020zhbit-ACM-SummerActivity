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
		//���Ϻ�����,�����ҵ��� 
		if((sx<ex&&sy<ey)||(ex<sx&&ey<sy)){
			//(bx,by)Ϊ���µĵ㣬(mx,my)Ϊ���ϵĵ� 
			bx=sx>ex?sx:ex;
			mx=bx==sx?ex:sx;
			by=bx==sx?sy:ey;
			my=mx==ex?ey:sy;
			//ÿһ�� 
			for(int i=mx;i<=bx;++i){
				//����ǵ�һ�� 
				if(i==mx){
					for(int j=my;j<=by;++j){
						//��һ��ֻҪ���ǵ�һ�� 
						if(j!=my){
							//һ����������� 
							dest[i][j]+=dest[i][j-1];
						}
					}
				}
				//�ڲ��ǵ�һ�е���� 
				else{
					for(int j=my;j<=by;++j){
						if(j!=my){
							dest[i][j]+=min(dest[i][j-1],dest[i-1][j]);
						}
						else{
							//ֻ�е�һ��ʹ���Ϸ���ֵ 
							dest[i][j]+=dest[i-1][j];
						}
					}				
				}
			} 
			//tol=dest[bx][by];
		}
		//���Ϻ�����,��ͬ��ͬ��,��������� 
		//if ( (sx<ex&&sy>ey)||(ex<sx&&ey>sy) )
		else{
			//(bx,by)Ϊ���µĵ㣬(mx,my)Ϊ���ϵĵ� 
			bx=sx>ex?sx:ex;
			mx=bx==sx?ex:sx;
			by=bx==sx?sy:ey;
			my=mx==ex?ey:sy;
			//��ͬһ��ʱ,�޷�ֱ�ӿ�bx��ȡֵ������my��by��ȡֵ 
			if(sx==ex){
				by=sy<ey?sy:ey;
				my=by==sy?ey:sy;
			}
			//ÿһ�� 
			for(int i=mx;i<=bx;++i){
				//����ǵ�һ�� 
				if(i==mx){
					for(int j=my;j>=by;--j){
						if(j!=my){
							//һ���������ұ� 
							dest[i][j]+=dest[i][j+1];
						}
					}
				}
				//�ڲ��ǵ�һ�е���� 
				else{
					for(int j=my;j>=by;--j){
						if(j!=my){
							dest[i][j]+=min(dest[i][j+1],dest[i-1][j]);
						}
						else{
							//ֻ�е�һ��ʹ���Ϸ���ֵ 
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
