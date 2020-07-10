#include <iostream>
#include <math.h>
using namespace std;
long long a[1010];
int main()
{
	int n, m;
	long long num;
	while (cin >> n)
	{
		m = 0;
		num = n;
		while (num < pow(2, 31))
		{
			int temp = num;
			int reverse = 0;
			while (temp != 0)
			{
				reverse *= 10;
				reverse += (temp % 10);
				temp /= 10;
			}
			if (reverse == num)
			{
				a[m] = num;
				cout << m << endl;
				cout << n;
				for (int i = 1; i <= m; i++)
				{
					cout << "--->" << a[i];
				}
				cout << endl;
				break;
			}
			else
			{
				a[m++] = num;
				num += reverse;
			}
		}
	}
	return 0;
}
