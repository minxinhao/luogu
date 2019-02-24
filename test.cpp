#include <cstdio>
long long a[1000001];
int main()
{
    //freopen("input.txt","r",stdin);
    long long inf=999999999999999,ans=-1,n=0,m=0;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    long long l=1,r=inf;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        long long su=0,t=0;
        for(long long i=1;i<=n;i++)
        {
            su+=a[i];
            if(su>=mid)
            {
                t++;
                su=0;
            }
            if(su<0)
            {
                su=0;
            }
        }
        //printf("low:%.20lld\thigh:%.20lld\tmid:%.20lld\tnumber:%.20lld\tm:%lld\n",l , r ,mid,t ,m);

        if(t<=m)
        {
            r=mid-1;
            if(t==m)
            {
                ans=mid;
            }
        }
        else
        {
            l=mid+1;
        }
    }
    if(ans!=-1)
    {
        printf("%lld ",ans);
        ans=-1,l=1,r=inf;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            long long su=0,t=0;
            for(long long i=1;i<=n;i++)
            {
                su+=a[i];
                if(su>=mid)
                {
                    t++;
                    su=0;
                }
                if(su<0)
                {
                    su=0;
                }
            }
            //printf("low:%.20lld\thigh:%.20lld\tmid:%.20lld\tnumber:%.20lld\tm:%lld\n",l , r ,mid,t ,m);
            if(t<=m-1)
            {
                r=mid-1;

            }
            else
            {
                l=mid+1;
                if(t==m)
                {
                    ans=mid;
                }
            }
        }
        printf("%lld",ans);
    }
    else
    {
        printf("-1");
    }
    return 0;
}