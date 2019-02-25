#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn = 200;
struct site
{
    long long x;
    long long y;
};
std::vector<site> pro_horse;
long long des_x , des_y ;
long long horse_x , horse_y;
long long dp[maxn][maxn];
long long res = 0;

int check_site(site temp)
{
    if (temp.x <0 || temp.x >20)
    {
        return 0 ;
    }
    if (temp.y <0 || temp.y >20)
    {
        return 0 ;
    }
    return 1;
}
void get_pro_horse(long long horse_x ,long long horse_y)
{

    site temp ;
    temp.x = horse_x ;
    temp.y = horse_y ;
    pro_horse.push_back(temp);
    /*
    * check : horse_x - 2 , horse_y+-1
    */
    temp.x = horse_x - 2;
    temp.y = horse_y - 1;
    if(check_site(temp))
    {
        pro_horse.push_back(temp);
    }
    temp.y = horse_y + 1;
    if(check_site(temp))
    {
        pro_horse.push_back(temp);
    }
    
    /*
    * check : horse_x + 2 , horse_y+-1
    */
    temp.x = horse_x + 2;
    if(check_site(temp))
    {
        pro_horse.push_back(temp);
    }
    temp.y = horse_y - 1;
    if(check_site(temp))
    {
        pro_horse.push_back(temp);
    }

    /*
    * check : horse_x-1 , horse_y+-2
    */
    temp.x = horse_x - 1;
    temp.y = horse_y + 2;
    if(check_site(temp))
    {
        pro_horse.push_back(temp);
    }
    temp.y = horse_y - 2;
    if(check_site(temp))
    {
        pro_horse.push_back(temp);
    }

    /*
    * check : horse_x+1 , horse_y+-2
    */
    temp.x = horse_x + 1;
    temp.y = horse_y + 2;
    if(check_site(temp))
    {
        pro_horse.push_back(temp);
    }
    temp.y = horse_y - 2;
    if(check_site(temp))
    {
        pro_horse.push_back(temp);
    }
    return ;
}
int horse_arr(long long x, long long y)
{
    for (int i = 0; i < pro_horse.size(); ++i)
    {
        if (pro_horse[i].x == x && pro_horse[i].y==y)
        {
            //printf("horse arrivable\n");
            return 1;
        }
    }
    return 0 ;
}
void dfs(long long x , long long y)
{

    //printf("cur_x:%lld,cur_y:%lld\n",x ,y );
    if (x==des_x && y==des_y)
    {
        res++;
        return ;
    }
    if (  !horse_arr(x+1, y) && x<des_x)
    {
        dfs(x+1 , y);
    }
    if ( !horse_arr(x, y+1) && y<des_y )
    {
        dfs(x , y+1);
    }
    //printf("return\n");
    return ;
}
int main(int argc, char const *argv[])
{
    //freopen("input.txt","r",stdin);
    cin>>des_x>>des_y>>horse_x>>horse_y;
    //cout<<des_x<<des_y<<horse_x<<horse_y<<endl;
    memset(dp , 0 , sizeof(dp));
    get_pro_horse(horse_x,horse_y);
    
    for (int i = 0; i < 21; ++i)
    {
        if (horse_arr(i,0))
        {
            dp[i][0]=0;
        }
        else
        {
            dp[i][0]=1;
        }
    }
     
    for (int i = 0; i < 21; ++i)
    {
        if (horse_arr(0,i))
        {
            dp[0][i]=0;
        }
        else
        {
            dp[0][i]=1;
        }
    }
    for (int i = 1; i <=des_x; ++i)
    {
        for(int j = 1 ; j<=des_y;++j)
        {
           if (horse_arr(i,j))
           {
                dp[i][j]=0;
           }
           else
           {
                dp[i][j]= dp[i-1][j] + dp[i][j-1];
           }
        }
    }
    // for (int i = 0; i < pro_horse.size(); ++i)
    // {
    //     printf("%lld %lld\n",pro_horse[i].x,pro_horse[i].y );
    // }
    printf("%lld\n",dp[des_x][des_y] );
    return 0;
}