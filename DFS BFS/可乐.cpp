#include<queue>
#include<string.h>
#include<iostream>
using namespace std;
int S,N,M;
int flag,number;
int vis[101][101][101];	//标记数组 
struct eu{
	int a,b,c;	//相当于S,N,M 
	int step;	//步数 
};
int IsOver( int s,int n,int m )	//判断是否能平分 
{
    if( (s == m && s != 0 && n == 0 )|| ( s == n && n != 0 && m==0 )|| ( m == n && m !=0 && s == 0 ) )
        return 1;
    return 0;
}
int IsLeagal( int s,int n,int m )	//判断是否越界 
{
    if( s < 0 || s > S || n < 0 || n > N || m < 0 || m > M )
        return 0;
    return 1;
}

void bfs()
{
	queue<eu> q;
	eu next,now;	
	now.a=S;
	now.b=0;
	now.c=0;
	now.step=0;
	q.push(now);
	memset(vis,0,sizeof(vis));
	vis[S][0][0] = 1;
	while(q.size()){
		now=q.front();
		q.pop();
		if(flag)
/*列出12种情况 
1.从第1个杯子倒到第2个杯子去，能倒满第2个杯子和不能倒满第2个杯子； 
2.从第1个杯子倒到第3个杯子去，能倒满第3个杯子和不能倒满第3个杯子； 
3.从第2个杯子倒到第1个杯子去，能倒满第1个杯子和不能倒满第1个杯子； 
4.从第2个杯子倒到第3个杯子去，能倒满第3个杯子和不能倒满第3个杯子； 
5.从第3个杯子倒到第1个杯子去，能倒满第1个杯子和不能倒满第1个杯子； 
6.从第3个杯子倒到第2个杯子去，能倒满第2个杯子和不能倒满第2个杯子； 

*/		
		//1->2
		if(now.a>(N-now.b)){//能倒满 
			next.a=now.a-(N-now.b);
			next.b=N;
			next.c=now.c;
			next.step=now.step+1;
			
		}
		else{	//不能倒满 
			next.a=0;
			next.b=now.a+now.b;
			next.c=now.c;
			next.step=now.step+1;
		}	
		if(IsLeagal(next.a,next.b,next.c)&&!vis[next.a][next.b][next.c]){	//判断是否越界和该点是否被使用 
			vis[next.a][next.b][next.c]=1;
			if(IsOver(next.a,next.b,next.c)){	//判断是否能平分 
				flag=1;
				number=next.step;
				return ;
			}
			q.push(next);
		}
		//1->3
		if(now.a>(M-now.c)){
			next.a=now.a-(M-now.c);
			next.b=now.b;
			next.c=M;
			next.step=now.step+1;
			
		}
		else{
			next.a=0;
			next.b=now.b;
			next.c=now.c+now.a;
			next.step=now.step+1;
		}	
		if(IsLeagal(next.a,next.b,next.c)&&!vis[next.a][next.b][next.c]){
			vis[next.a][next.b][next.c]=1;
			if(IsOver(next.a,next.b,next.c)){
				flag=1;
				number=next.step;
				return ;
			}
			q.push(next);
		}
		//2->3
		if(now.b>(M-now.c)){
			next.a=now.a;
			next.b=now.b-(M-now.c);
			next.c=M;
			next.step=now.step+1;
			
		}
		else{
			next.a=now.a;
			next.b=0;
			next.c=now.b+now.c;
			next.step=now.step+1;
		}	
		if(IsLeagal(next.a,next.b,next.c)&&!vis[next.a][next.b][next.c]){
			vis[next.a][next.b][next.c]=1;
			if(IsOver(next.a,next.b,next.c)){
				flag=1;
				number=next.step;
				return ;
			}
			q.push(next);
		}
		//3->2
		if(now.c>(N-now.b)){
			next.a=now.a;
			next.b=N;
			next.c=now.c-(N-now.b);
			next.step=now.step+1;
			
		}
		else{
			next.a=now.a;
			next.b=now.b+now.c;
			next.c=0;
			next.step=now.step+1;
		}	
		if(IsLeagal(next.a,next.b,next.c)&&!vis[next.a][next.b][next.c]){
			vis[next.a][next.b][next.c]=1;
			if(IsOver(next.a,next.b,next.c)){
				flag=1;
				number=next.step;
				return ;
			}
			q.push(next);
		}
		//3->1
		if(now.c>(S-now.a)){
			next.a=S;
			next.b=now.b;
			next.c=now.c-(S-now.a);
			next.step=now.step+1;
			
		}
		else{
			next.a=now.c+now.a;
			next.b=now.b;
			next.c=0;
			next.step=now.step+1;
		}	
		if(IsLeagal(next.a,next.b,next.c)&&!vis[next.a][next.b][next.c]){
			vis[next.a][next.b][next.c]=1;
			if(IsOver(next.a,next.b,next.c)){
				flag=1;
				number=next.step;
				return ;
			}
			q.push(next);
		}
		//2->1
		if(now.b>(S-now.a)){
			next.a=S;
			next.b=now.b-(S-now.a);
			next.c=now.c;
			next.step=now.step+1;
			
		}
		else{
			next.a=now.a+now.b;
			next.b=0;
			next.c=now.c;
			next.step=now.step+1;
		}	
		if(IsLeagal(next.a,next.b,next.c)&&!vis[next.a][next.b][next.c]){
			vis[next.a][next.b][next.c]=1;
			if(IsOver(next.a,next.b,next.c)){
				flag=1;
				number=next.step;
				return ;
			}
			q.push(next);
		}
	}
}

int main()
{
	while(cin>>S>>N>>M){
		
		if(S==0&&N==0&&M==0) break;
		if(N>M)		
        {
           int t;
           t=N;
		   N=M;
		   M=t;
        }
		if(S%2==1){	//可乐瓶体积为奇数不能平分 
			cout<<"NO"<<endl;
			continue;
		}
		flag=0;
		bfs();
		if(flag)
		cout<<number<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
}
