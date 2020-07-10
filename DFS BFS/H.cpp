#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

int nmap[10][10];
bool vis[10][10];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct node
{
    int x, y; //x是横坐标，y是纵坐标

} pre[10][10]; //前驱数组

queue<node> q; //定义队列

void bfs()
{
    while (!q.empty())
    {                         //只要队列不为空，就一直循环
        node now = q.front(); //now是现在队列最前面的值
        q.pop();              //将这个值从队列中弹出
        if (now.x == 4 && now.y == 4)
            break; //如果搜索到了终点，表示找到了最短路径，结束循环
        for (int i = 0; i < 4; i++)
        {                               //遍历now的四个邻居
            node next;                  //now的邻居
            next.x = now.x + dir[i][0]; //邻居的横坐标
            next.y = now.y + dir[i][1]; //邻居的纵坐标
            if (next.x >= 0 && next.x <= 4 && next.y >= 0 && next.y <= 4 && vis[next.x][next.y] != 1 && nmap[next.x][next.y] != 1)
            {                              //如果符合条件，没有超过迷宫的范围，且book数组中没有被标记，且迷宫里不是墙壁(1)是路(0)
                vis[next.x][next.y] = 1;   //标记这个位置走过了
                q.push(next);              //将这个邻居压入数组
                pre[next.x][next.y] = now; //这个邻居的前驱节点是now，因为是从now找到了这条路，先经过了now再经过这条路即这个邻居
            }
        }
    }
}

void display(node endd) //输入终点，从终点开始递归一层层找前驱节点
{
    if (endd.x == 0 && endd.y == 0)
    {                       //如果找到起点，输出，结束递归，开始回溯
        printf("(0, 0)\n"); //输出起点
        return;
    }
    display(pre[endd.x][endd.y]);
    printf("(%d, %d)\n", endd.x, endd.y); //回溯时依次输出经过的坐标
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> nmap[i][j];
        }
    }
    memset(vis, 0, sizeof(vis));
    node n;        //定义起点
    n.x = 0;       //起点横坐标0
    n.y = 0;       //起点纵坐标0
    q.push(n);     //将起点压入队列
    bfs();         //开始搜索迷宫
    node p;        //定义终点
    p.x = p.y = 4; //终点的横纵坐标
    display(p);    //终点输入递归
    return 0;
}
