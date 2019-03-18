#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10;
// freopen("input.txt","r",stdin);
// freopen("result.txt","w",stdout);

/*f[i][j][k][l]=max(
    f[i−1][j][k−1][l],
    f[i−1][j][k][l−1],
    f[i][j−1][k−1][l],
    f[i][j−1][k][l−1])
    +a[i][j]+a[k][l];
*/

int dp[maxn][maxn][maxn][maxn];

int playboard[10][10];


int max(int a , int b)
{
    return (a>b)? a : b;
}



void init()
{
    memset(playboard , 0 ,sizeof(playboard));
    memset(dp , 0 ,sizeof(dp));
}

int main(int argc, char const *argv[])
{
    init();
    // freopen("input.txt","r",stdin);
    // freopen("result.txt","w",stdout);


    int size_board ;
    scanf("%d",&size_board);


    int site_x , site_y , site_value ;
    scanf("%d%d%d",&site_x , &site_y , &site_value) ;
    while( site_x != 0 || site_y!=0 || site_value!=0 )
    {
        playboard[site_x][site_y] = site_value ;
        scanf("%d%d%d",&site_x , &site_y , &site_value) ;
    }

    for (int i = 1; i <= size_board; ++i)
    {
        for(int j = 1; j <= size_board ; j++)
        {
            for(int k = 1 ; k <= size_board ; k++)
            {
                for(int l = 1 ; l <= size_board ; l++)
                {
                    dp[i][j][k][l] = max(
                        max(dp[i][j-1][k-1][l]  , 
                            dp[i-1][j][k-1][l]),
                        max(dp[i][j-1][k][l-1],
                            dp[i-1][j][k][l-1])
                        )+playboard[i][j]+playboard[k][l];
                    if (i==k && j==l)
                    {
                        dp[i][j][k][l] -= playboard[i][j];
                    }
                }
            }
        }
    }
    printf("%d\n", dp[size_board][size_board][size_board][size_board]);



    return 0;
}