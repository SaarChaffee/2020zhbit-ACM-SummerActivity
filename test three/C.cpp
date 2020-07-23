#include <iostream>
#include <algorithm>

using namespace std;

typedef struct _sticks
{
    int length; //木棒的长度
    bool vis;   //木棒是否被使用过
} Sticks;
Sticks sticks[70];

int total, l; //total能组成的木棒的组数,l:组成的木棒的长度
int num, sum; //num输入的整数，sum总长度

bool cmp(Sticks a, Sticks b)
{
    return a.length > b.length;
}

int dfs(int s, int len, int pos) //s已组成的木棒数目,len已经组成的长度，pos搜索的木棒的下标的位置
{
    if (s == total)
        return 1;
    for (int i = pos + 1; i < num; i++)
    {
        if (sticks[i].vis) //如果这个木棒已经用过，则继续下一根
            continue;
        if (len + sticks[i].length == l)
        {
            sticks[i].vis = true;
            if (dfs(s + 1, 0, -1)) //已经组成一条整合棒，继续判断剩下没组的
                return true;
            sticks[i].vis = false;
            return false;
        }
        else if (sticks[i].length + len < l)
        {
            sticks[i].vis = true;
            if (dfs(s, len + sticks[i].length, i))
                return true;
            sticks[i].vis = false;
            if (len == 0) //剪枝：如果当前搜索时，前边的长度为0，而第一根没有成功的使用，说明第一根始终要被废弃，所以这种组合必定不会成功
                return false;
            while (sticks[i].length == sticks[i + 1].length) //剪枝：如果当前和上一次搜到的木棒是一样长的则没必要再搜一次了
                i++;
        }
    }
    return false;
}

int main()
{
    while (cin >> num && num)
    {
        sum = 0; //初始化总长
        for (int i = 0; i < num; i++)
        {
            cin >> sticks[i].length;
            sum += sticks[i].length;
            sticks[i].vis = false;
        }
        sort(sticks, sticks + num, cmp);          //将木棒按照长度从长到短的顺序排序，因为最小的整合棒也会大于等于最长的那根
        for (l = sticks[0].length; l <= sum; l++) //从木棒的最长的那根开始搜索
        {
            if (sum % l != 0) //剪枝：如果不能被整除说明不能组成整数根木棒，搜下一个
                continue;
            total = sum / l;   //得到木棒总数目
            if (dfs(1, 0, -1)) //开始找
            {
                cout << l << endl;
                break;
            }
        }
    }
    return 0;
}