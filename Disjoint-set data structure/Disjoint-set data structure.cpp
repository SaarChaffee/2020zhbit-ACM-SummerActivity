//��ʼ��
for(int i=0;i<n;++i)
	fa[i]=i
//�Ҹ����
int find(int x) 
{
	if(fa[x]!=x)//·��ѹ��
		fa[x]=find(fa[x]);
	return fa[x];
	/*
	�ǵݹ�·��ѹ�� 
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
//����
void join(int x,int y) 
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
		fa[fx]=fy; 
}
