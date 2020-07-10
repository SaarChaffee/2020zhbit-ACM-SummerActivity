#include <iostream>
#include <cstring>
using namespace std;
int x,y;//��ʼ���� 
int sum;//�߹��ĵ���ܺ� 
char map[25][25];//ͼ 
bool mark[25][25];//ͼ���
int xw[4]={0,1,0,-1};
int yw[4]={-1,0,1,0};//�����ƶ��������� 

void dfs(int a,int b)//���� 
{
	for(int i=0;i<4;i++){
		if((!mark[a+xw[i]][b+yw[i]])&&map[a+xw[i]][b+yw[i]]!='#')
		//�����ǰλ������/��/��/�󣬸�λ�ÿ�����δ��ǹ����߹�ȥ 
		{
			sum++;//�߹��ĵ�+1 
			mark[a+xw[i]][b+yw[i]]=true;//���һ�� 
			dfs(a+xw[i],b+yw[i]);//������ 
		}
	}
}

int main()
{
	int a,b;//ͼ�Ĵ�С 
	while(cin>>a>>b)
	{
		if(a==0&&b==0)//��С��Ϊ0�ͽ��� 
			break;
		for(int i=0;i<25;i++)//ͼ��ʼ��Ϊ'#'��Ҳ����Ĭ�ϲ����� 
			for(int j=0;j<25;j++)
				map[i][j]='#';
		memset(mark,0,sizeof(mark));//��ǳ�ʼ��Ϊ0��û�߹� 
		sum=1; //��ʼ��sum���߹��ĵ�Ϊ1����ʼλ�ã� 
		for(int i=1;i<=b;i++)
		{
			for(int j=1;j<=a;j++)//��������ͼ������ 
			{
				cin>>map[i][j]; 
				if(map[i][j]=='@')//��¼��ʼλ�� 
				{
					x=i;
					y=j;
					mark[i][j]=true;//���һ�� 
				}
			}
		}
		dfs(x,y);//���� 
		cout<<sum<<endl; 
	}
	return 0;
}
