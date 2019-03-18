#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 16;
// freopen("input.txt","r",stdin);
// freopen("result.txt","w",stdout);

string str_map[maxn]= {
    "2(0)", // 2^0
    "2",    // 2^1
    "2(2)", // 2^2
    "2(2+2(0))",//2^3
    "2(2(2))", //2^4
    "2(2(2)+2(0))",//2^5
    "2(2(2)+2)",//2^6
    "2(2(2)+2+2(0))",//2^7
    "2(2(2+2(0)))",//2^8
    "2(2(2+2(0))+2(0))",//2^9
    "2(2(2+2(0))+2)",//2^10
    "2(2(2+2(0))+2+2(0))",//2^11
    "2(2(2+2(0))+2(2))",//2^12
    "2(2(2+2(0))+2(2)+2(0))",//2^13
    "2(2(2+2(0))+2(2)+2)",//2^14
    "2(2(2+2(0))+2(2)+2+2(0))"//2^15
};
int bits[maxn];


int main(int argc, char const *argv[])
{
    // freopen("input.txt","r",stdin);
    // freopen("result.txt","w",stdout);
    int num ;
    scanf("%d",&num);
    int count = 0 ;
    memset(bits, 0 , sizeof(bits));
    while(num)
    {
        bits[count++] = num&1;
        num=num>>1;
    }
    string res = "";
    int first = 1;
    for (int i = 15; i >=0; --i)
    {
        if (bits[i])
        {
            if (first)
            {
                res +=str_map[i];
                first = 0;
            }
            else
            {   
                res+="+";
                res +=str_map[i];
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
