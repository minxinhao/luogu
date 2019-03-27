#include<cstdio>
int pra[21]={0,0,1,2,2,3,4,6,9,14,22,35,56,90,145,234,378,611,988,1598,2585};
int prx[21]={0,0,0,0,1,2,4,7,12,20,33,54,88,143,232,376,609,986,1596,2583};
int main(){
    int a,n,m,x;
    freopen("input.txt","r",stdin);
    freopen("result.txt","w",stdout);
    scanf("%d%d%d%d",&a,&n,&m,&x);
    int X=(m-a*pra[n-1])/prx[n-1];
    printf("%d",a*pra[x]+X*prx[x]);
    return 0;
}