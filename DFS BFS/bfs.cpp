#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int tmap[5][5];	 //ͼ
bool mark[5][5]; //ͼ���
int xw[4] = {-1, 0, 1, 0};
int yw[4] = {0, 1, 0, -1}; //�����ƶ���������
struct point
{
	int x, y, plong; //x,y�����꣬plong�ǲ���
	int direc[30];	 //�ߵ��õ��·��������Ƿ���
};
bool judge(int x, int y) //�ж��Ƿ�����
{
	if (x < 0 || y < 0 || x >= 5 || y >= 5) //������ͼ��Χ
		return false;
	if (mark[x][y]) //�߹�
		return false;
	if (tmap[x][y]) //ǽ��
		return false;
	return true;
}
point bfs()
{
	point now, next;					 //��ǰ�ĵ㣬��һ����
	now.x = 0, now.y = 0, now.plong = 0; //�ӣ�0��0������������Ϊ0
	mark[now.x][now.y] = true;
	queue<point> qpoint;
	qpoint.push(now);
	while (!qpoint.empty()) //������зǿ�
	{
		now = qpoint.front();
		qpoint.pop();
		if (now.x == 4 && now.y == 4) //��������յ�
			return now;
		for (int i = 0; i < 4; i++) //�ĸ�����
		{
			int nx = now.x;
			int ny = now.y;
			nx += xw[i];
			ny += yw[i];
			if (judge(nx, ny)) //�жϵ�ǰ�����ܲ�����
			{
				next = now;
				next.x = nx;
				next.y = ny;
				next.plong++;
				next.direc[now.plong] = i; //�����ߵķ���
				qpoint.push(next);		   //���õ�������
				mark[next.x][next.y] = true;
			}
		}
	}
	return now;
}
int main()
{
	for (int i = 0; i < 5; i++) //�����ͼ
		for (int j = 0; j < 5; j++)
			cin >> tmap[i][j];
	point now;
	now = bfs();
	int x = 0, y = 0;
	for (int i = 0; i < now.plong; i++) //��ԭ·��
	{
		cout << "(" << x << ", " << y << ")" << endl;
		x += xw[now.direc[i]];
		y += yw[now.direc[i]];
	}
	cout << "(" << x << ", " << y << ")";
	return 0;
}
