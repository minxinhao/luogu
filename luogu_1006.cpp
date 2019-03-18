#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 55;
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

int playboard[maxn][maxn];


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


    int num_x , num_y ;
    scanf("%d%d",&num_x,&num_y);
    for (int i = 1; i <= num_x; ++i)
    {
        for (int j = 1; j <= num_y; ++j)
        {
            scanf("%d",&playboard[i][j]);
        }
    }

    for (int i = 1; i <= num_x; ++i)
    {
        for(int j = 1; j <= num_y ; j++)
        {
            for(int k = 1 ; k <= num_x ; k++)
            {
                for(int l = 1 ; l <= num_y ; l++)
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
    printf("%d\n", dp[num_x][num_y][num_x][num_y]);



    return 0;
}