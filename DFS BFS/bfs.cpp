#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int tmap[5][5];	 //图
bool mark[5][5]; //图标记
int xw[4] = {-1, 0, 1, 0};
int yw[4] = {0, 1, 0, -1}; //坐标移动左下右上
struct point
{
	int x, y, plong; //x,y是坐标，plong是步数
	int direc[30];	 //走到该点的路径（存的是方向）
};
bool judge(int x, int y) //判断是否能走
{
	if (x < 0 || y < 0 || x >= 5 || y >= 5) //超出地图范围
		return false;
	if (mark[x][y]) //走过
		return false;
	if (tmap[x][y]) //墙壁
		return false;
	return true;
}
point bfs()
{
	point now, next;					 //当前的点，下一个点
	now.x = 0, now.y = 0, now.plong = 0; //从（0，0）出发，步数为0
	mark[now.x][now.y] = true;
	queue<point> qpoint;
	qpoint.push(now);
	while (!qpoint.empty()) //如果队列非空
	{
		now = qpoint.front();
		qpoint.pop();
		if (now.x == 4 && now.y == 4) //如果到达终点
			return now;
		for (int i = 0; i < 4; i++) //四个方向
		{
			int nx = now.x;
			int ny = now.y;
			nx += xw[i];
			ny += yw[i];
			if (judge(nx, ny)) //判断当前方向能不能走
			{
				next = now;
				next.x = nx;
				next.y = ny;
				next.plong++;
				next.direc[now.plong] = i; //保存走的方向
				qpoint.push(next);		   //将该点放入队列
				mark[next.x][next.y] = true;
			}
		}
	}
	return now;
}
int main()
{
	for (int i = 0; i < 5; i++) //输入地图
		for (int j = 0; j < 5; j++)
			cin >> tmap[i][j];
	point now;
	now = bfs();
	int x = 0, y = 0;
	for (int i = 0; i < now.plong; i++) //还原路径
	{
		cout << "(" << x << ", " << y << ")" << endl;
		x += xw[now.direc[i]];
		y += yw[now.direc[i]];
	}
	cout << "(" << x << ", " << y << ")";
	return 0;
}
