//初始化
for(int i=0;i<n;++i)
	fa[i]=i
//找根结点
int find(int x) 
{
	if(fa[x]!=x)//路径压缩
		fa[x]=find(fa[x]);
	return fa[x];
	/*
	非递归路径压缩 
	int r=x;
	while(fa[r]!=r)
		r=fa[r];
	int t;
	while(fa[x]!=r)
	{
		t=fa[x];
		fa[x]=r;
		x=t;
	}
	return r;
	*/  
} 
//连接
void join(int x,int y) 
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
		fa[fx]=fy; 
}
