#include <iostream>
#include <vector>
#define f first
#define s second
using namespace std;
int main()
{

	vector<pair<int, int>> v;
	int n, w, x, y, smax = 0, sum = 0;
	cin >> w >> n;

	v.push_back(make_pair(0, 0));

	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	int W[100][100];
	int tmp = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (v[i].f > j)
			{
				W[i][j] = W[i - 1][j];
			}
			else
			{
				W[i][j] = max(W[i - 1][j], W[i - 1][j - v[i].f] + v[i].s);
			}
		}
	}

	cout << W[n][w] << endl;

	vector<int> kq;
	for (int i = n; i >= 0; i--)
	{
		if (W[i][w] != W[i - 1][w])
		{
			kq.push_back(i);
			w = w - v[i].s;
		}
	}
	if (kq[kq.size() - 1] == 0)
		kq[kq.size() - 1] = 1;
	for (int i = kq.size() - 1; i >= 0; i--)
	{
		cout << kq[i] << " ";
	}
}