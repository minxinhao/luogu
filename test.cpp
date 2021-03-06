#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
const int maxn = 20;
// freopen("input.txt","r",stdin);
// freopen("result.txt","w",stdout);

int num ;
string words[2*maxn]  ;
std::vector<string> Result;

struct  node 
{
	int len ;
	int t ;
	int next ;
}edge[(2*maxn)*(2*maxn)];
int head[2*maxn], edge_count  , vis[2*maxn];

int get_len(int x , int y)
{
	string u = words[x];
	string v = words[y];
	int len_u = u.length(),len_v = v.length();
	len_v = min(len_u,len_v) ;
	int len = 1 ,flag = 0 ;
	while(len<len_v)
	{
		if (u.substr(len_u  - len , len) == v.substr(0 , len))
		{
			flag = 1;
			break ;
		}
		len++;
	}

	if (flag)
		return len ;
	else
		return 0 ;
}

void addegde(int u , int v)
{
	edge[edge_count].t  = v ;
	edge[edge_count].next  = head[u] ;
	edge[edge_count].len  = get_len(u , v) ;
	head[u] = edge_count++ ;
}

void init()
{
	for (int i = num+1; i <= 2*num; ++i)
	{
		words[i] = words[i-num];
	}
	edge_count = 0 ;
	memset(head ,  0 , sizeof(head));
	memset(vis ,  0 , sizeof(vis));

	for (int i = 0; i <= 2*num; ++i)
	{
		for(int j = 0; j <= 2*num ; ++j)
		{
			if (i==j)
			{
				continue ;
			}
			else
			{
				if (get_len(i , j))
				{
					addegde( i , j);
				}
			}
		}
	}
	for (int i = 0; i <= 2*num; ++i)
	{
		cout<<"i:"<<i<<" "<<words[i]<<endl;
	}

}

void dfs(int root , string res)
{
	if (head[root] == 0 )
	{
		Result.push_back(res);
	}
	vis[root] = 1;

	printf("root:%d , words:%s\n",root , words[root].c_str());
	for(int i = head[root]; i ; i = edge[i].next)
	{
		int t = edge[i].t ;
		
		if(!vis[t])
		{	
			string temp = words[t];
			dfs(t , res+temp.substr(edge[i].len , temp.length() - edge[i].len  ));
		}
	}

}

int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	freopen("result.txt","w",stdout);

	scanf("%d",&num);
	for (int i = 1 ; i <= num; ++i)
	{
		cin>>words[i];
	}
	cin>>words[0];

		
	init();

	dfs(0 , words[0]);

	for (int i = 0; i < Result.size(); ++i)
	{
		cout<<Result[i]<<" "<<Result[i].length()<<endl;
	}
	return 0;
}