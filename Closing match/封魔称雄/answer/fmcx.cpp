#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char arc[200][200];
int book[200][200];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, flag, times;
class node
{
public:
	int x;
	int y;
} start, out;
queue<node> nq;
void queclear()
{
	while (!nq.empty())
	{
		nq.pop();
	}
}
void bfs()
{
	times = 0;
	node ntmp, mmp;
	nq.push(start);
	while (!nq.empty())
	{
		ntmp = nq.front();
		nq.pop();
		for (int i = 0; i < 4; i++)
		{
			int tmpx = dir[i][0] + ntmp.x;
			int tmpy = dir[i][1] + ntmp.y;
			if (tmpx == out.x && tmpy == out.y)
			{
				flag++;
				queclear();
				ntmp.x = tmpx;
				ntmp.y = tmpy;
				nq.push(ntmp);
				return;
			}
			if (tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < m && arc[tmpx][tmpy] != '#' && book[tmpx][tmpy] == 0)
			{
				book[tmpx][tmpy] = ++times;
				mmp.x = tmpx;
				mmp.y = tmpy;
				nq.push(mmp);
			}
		}
	}
	return;
}
void becomewall()
{
	node ntmp, mmp;
	while (!nq.empty())
	{
		ntmp = nq.front();
		nq.pop();
		for (int i = 0; i < 4; i++)
		{
			int tmpx = dir[i][0] + ntmp.x;
			int tmpy = dir[i][1] + ntmp.y;
			if (tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < m && arc[tmpx][tmpy] != '#' && book[tmpx][tmpy] != 0 && book[tmpx][tmpy] <= times)
			{
				if (arc[tmpx][tmpy] == 'S')
				{
					return;
				}
				mmp.x = tmpx;
				mmp.y = tmpy;
				nq.push(mmp);
				arc[tmpx][tmpy] = '#';
				times = book[tmpx][tmpy];
			}
		}
	}
	return;
}
int main()
{
	int x;
	cin >> x;
	while (x--)
	{
		cin >> n >> m;
		memset(book, 0, sizeof book);
		queclear();
		flag = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arc[i][j];
				if (arc[i][j] == 'S')
				{
					start.x = i;
					start.y = j;
				}
				if (arc[i][j] == 'O')
				{
					out.x = i;
					out.y = j;
				}
			}
		}
		bfs();
		if (flag)
		{
			becomewall();
			memset(book, 0, sizeof book);
			bfs();
			if (flag == 2)
			{
				cout << "GoodEnd" << endl;
			}
			else
			{
				cout << "NormalEnd" << endl;
			}
		}
		else
		{
			cout << "BadEnd" << endl;
		}
	}
	return 0;
}
