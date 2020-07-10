#include <iostream>
#include <cstring>
using namespace std;
int x,y;//初始坐标 
int sum;//走过的点的总和 
char map[25][25];//图 
bool mark[25][25];//图标记
int xw[4]={0,1,0,-1};
int yw[4]={-1,0,1,0};//坐标移动上右下左 

void dfs(int a,int b)//深搜 
{
	for(int i=0;i<4;i++){
		if((!mark[a+xw[i]][b+yw[i]])&&map[a+xw[i]][b+yw[i]]!='#')
		//如果当前位置往上/右/下/左，该位置可走且未标记过，走过去 
		{
			sum++;//走过的点+1 
			mark[a+xw[i]][b+yw[i]]=true;//标记一下 
			dfs(a+xw[i],b+yw[i]);//往下走 
		}
	}
}

int main()
{
	int a,b;//图的大小 
	while(cin>>a>>b)
	{
		if(a==0&&b==0)//大小都为0就结束 
			break;
		for(int i=0;i<25;i++)//图初始化为'#'，也就是默认不能走 
			for(int j=0;j<25;j++)
				map[i][j]='#';
		memset(mark,0,sizeof(mark));//标记初始化为0，没走过 
		sum=1; //初始化sum，走过的点为1（初始位置） 
		for(int i=1;i<=b;i++)
		{
			for(int j=1;j<=a;j++)//逐行输入图的内容 
			{
				cin>>map[i][j]; 
				if(map[i][j]=='@')//记录初始位置 
				{
					x=i;
					y=j;
					mark[i][j]=true;//标记一下 
				}
			}
		}
		dfs(x,y);//深搜 
		cout<<sum<<endl; 
	}
	return 0;
}
