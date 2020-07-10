#include"iostream"
 
using namespace std;
 
const int maxn = 0x3f3f3f;
int pre[maxn];
 
int fi(int k)
{
	if(pre[k]!=k)
		pre[k]=fi(pre[k]);
	return pre[k];
}
 
void join(int a,int b)
{
	int x=fi(a);
	int y=fi(b);
	if(x!=y)
		pre[x]=y;
}
 
int main()
{
	int n,m;
	while(1)
	{
		cin >> n;
		if(n == 0) break;
		cin >> m;
		for(int i=1;i<=n;i++)
			pre[i] = i;
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin >> a >> b;
			join(a,b);
		}
		int s=0;
		for(int i=1;i<=n;i++)
		{
			if(pre[i] == i)
				s++;
		}
		cout << s-1 << endl;
	}
	return 0;
}
