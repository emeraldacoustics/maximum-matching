#include <cstring>
#include <vector>

using namespace std;

class MaximumMatching
{
public:
	static const int maxn = 1000;
	static const int maxm = 1000;

	int n, m;
	vector<int> E[maxn];
	int xlnk[maxn];
	int ylnk[maxm];
	bool vis[maxm];

	void resize(const int & n, const int & m)
	{
		for (int i = 0; i < this->n; i++)
			E[i].clear();
		this->n = n;
		this->m = m;
	}

	void add_edge(const int & u, const int & v)
	{
		E[u].push_back(v);
	}

	bool dfs(const int & u)
	{
		for (const auto & v : E[u])
		{
			if (!vis[v])
			{
				vis[v] = true;
				if (ylnk[v] == -1 || dfs(ylnk[v]))
				{
					xlnk[u] = v;
					ylnk[v] = u;
					return true;
				}
			}
		}
		return false;
	}

	int maximum_matching()
	{
		int ans = 0;
		memset(xlnk, -1, sizeof xlnk[0] * n);
		memset(ylnk, -1, sizeof ylnk[0] * m);
		for (int i = 0; i < n; i++)
		{
			memset(vis, false, sizeof vis[0] * m);
			if (dfs(i))
				ans++;
		}
		return ans;
	}
};
