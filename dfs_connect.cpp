#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 10000;


char playboard[maxn][maxn];
int ID[maxn][maxn];
int components;
long long Component[maxn];
int size_playboard;
int num_qur ;
int possible[4][2];
int temp_x , temp_y;

void init()
{
	components=0;
	memset(ID , -1 ,sizeof(ID));
}

int  point_check(int x , int y)
{
	if (x<0 || x>=size_playboard )
	{
		return 0;
	}
	if (y<0 || y>=size_playboard )
	{
		return 0;
	}
	return 1;
}

void dfs(int i , int j )
{
	ID[i][j]=components;
	Component[components] ++  ;
	possible[0][0] = i-1 ;
	possible[0][1] = j ;
	possible[1][0] = i ;
	possible[1][1] = j+1 ;
	possible[2][0] = i ;
	possible[2][1] = j-1 ;
	possible[3][0] = i+1 ;
	possible[3][1] = j ;

	printf("i:%d,j:%d,ID:%d,value:%c\n",i,j,ID[i][j] ,playboard[i][j]);
	for (int  t= 0;  t< 4; ++t)
	{
		temp_x = possible[t][0];
		temp_y= possible[t][1];
		
		if (temp_x<0 || temp_x>=size_playboard )
		{
			continue;
		}
		if (temp_y<0 || temp_y>=size_playboard )
		{
			continue;
		}
		if( ID[temp_x][temp_y]==-1 && (playboard[temp_x][temp_y] !=playboard[i][j]) )
		{
			dfs(temp_x,temp_y);
		}
	}
}
int  main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	init();
	scanf("%d%d",&size_playboard,&num_qur);

	for (int i = 0; i < size_playboard; ++i)
	{
		scanf("%s",playboard[i]);
	}

	for (int i = 0; i < size_playboard; ++i)
	{
		for(int j = 0 ; j<size_playboard;++j)
		{
			if(ID[i][j]==-1)
			{
				dfs(i,j);
				components++;
			}
		}
	}


	// for (int i = 0; i < size_playboard; ++i)
	// {
	// 	for(int j = 0 ; j<size_playboard;++j)
	// 	{
	// 		printf("i:%d , j:%d , ID:%d,num_point:%lld\n",i,j,ID[i][j],Component[ID[i][j]] );
	// 	}
	// }

	for (int i = 0; i < num_qur; ++i)
	{
		int x, y ;
		scanf("%d%d",&x,&y);
		printf("%lld\n",Component[ID[x-1][y-1] ]  );
	}
	return 0;
}

