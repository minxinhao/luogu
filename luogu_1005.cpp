#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100,Mod = 10000;
// freopen("input.txt","r",stdin);
// freopen("result.txt","w",stdout);

// dp[i][j] = max( dp[i][j+1]+playbord[j]*2^(m-j+i-1) ,dp[i][j+1]+playbord[j]*2^(m-j+i-1)  )

int playborad[maxn];
int num_x , num_y ;

struct HP {
    int p[505], len;
    HP() {
        memset(p, 0, sizeof p);
        len = 0;
    } //这是构造函数，用于直接创建一个高精度变量 
    void print() {
        printf("%d", p[len]);  
        for (int i = len - 1; i > 0; i--) {  
            if (p[i] == 0) {
                printf("0000"); 
                continue;
            }
            for (int k = 10; k * p[i] < Mod; k *= 10) 
                printf("0");
            printf("%d", p[i]);
        }
    } //四位压缩的输出 
} dp[maxn][maxn] , base[maxn], res;

HP operator + (const HP &a, const HP &b) {
    HP c; c.len = max(a.len, b.len); int x = 0;
    for (int i = 1; i <= c.len; i++) {
        c.p[i] = a.p[i] + b.p[i] + x;
        x = c.p[i] / Mod;
        c.p[i] %= Mod;
    }
    if (x > 0)
        c.p[++c.len] = x;
    return c;
} //高精+高精 

HP operator * (const HP &a, const int &b) {
    HP c; c.len = a.len; int x = 0;
    for (int i = 1; i <= c.len; i++) {
        c.p[i] = a.p[i] * b + x;
        x = c.p[i] / Mod;
        c.p[i] %= Mod;
    }
    while (x > 0)
        c.p[++c.len] = x % Mod, x /= Mod;
    return c;
} //高精*单精 

HP max(const HP &a, const HP &b) {
    if (a.len > b.len)
        return a;
    else if (a.len < b.len)
        return b;
    for (int i = a.len; i > 0; i--)
        if (a.p[i] > b.p[i])
            return a;
        else if (a.p[i] < b.p[i])
            return b;
    return a;
} //比较取最大值 

void BaseTwo() {
    base[0].p[1] = 1, base[0].len = 1;
    for (int i = 1; i <= num_y + 2; i++){ //这里是m! m! m! 我TM写成n调了n年... 
        base[i] = base[i - 1] * 2;
    }
} //预处理出2的幂

int main(int argc, char const *argv[])
{
	// freopen("input.txt","r",stdin);
	// freopen("result.txt","w",stdout);
	scanf("%d%d",&num_x, &num_y);
	BaseTwo();

	while(num_x--)
	{
		memset(dp , 0 , sizeof(dp));
		memset(playborad , 0 , sizeof(playborad));
		for (int i = 1; i <= num_y; ++i)
		{
			scanf("%d",&playborad[i]);
		}

		for (int i = 1; i <= num_y; ++i)
		{
			for(int j = num_y ; j>=i ; j--)
			{
				dp[i][j]=max( dp[i][j+1]+(base[num_y - j + i -1]*playborad[j+1] ) ,
							  dp[i-1][j]+(base[num_y - j + i -1]*playborad[i-1] )) ;
			}
		}
		HP Res_Max ;
		for (int i = 1; i <= num_y; ++i)
		{
			Res_Max = max(Res_Max , dp[i][i]+base[num_y]*playborad[i]);
		}
		res=res+Res_Max;
	}
	res.print();
	return 0;
}