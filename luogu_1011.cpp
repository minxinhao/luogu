#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 22;
// freopen("input.txt","r",stdin);
// freopen("result.txt","w",stdout);

struct add
{
    int add_1 ; // add_1 * a 
    int add_2 ; // add_2 * x
    int total_1 , total_2 ; // num of people in bus = total_1 * a + total_2*x
}UpBus[maxn];//表示上车人数变化的数列

int num_station , num_a , num_m , qur_station;

void init()
{
    UpBus[1].add_1 = 1;
    UpBus[1].add_2 = 0;
    UpBus[1].total_1 = 1;
    UpBus[1].total_2 = 0;


    UpBus[2].add_1 = 0;
    UpBus[2].add_2 = 1;
    UpBus[2].total_1 = 1;
    UpBus[2].total_2 = 0;

    for(int i = 3 ; i < (num_station) ; i++ )
    {
        UpBus[i].add_1 = UpBus[i-1].add_1+UpBus[i-2].add_1;
        UpBus[i].add_2 = UpBus[i-1].add_2+UpBus[i-2].add_2;
        //add UpBus[i-2]
        UpBus[i].total_1 = UpBus[i-1].total_1 + UpBus[i-2].add_1;
        UpBus[i].total_2 = UpBus[i-1].total_2 + UpBus[i-2].add_2; 
    }
    UpBus[num_station].add_1 = 0 ;
    UpBus[num_station].add_2 = 0 ;

}

int main(int argc, char const *argv[])
{
    // freopen("input.txt","r",stdin);
    // freopen("result.txt","w",stdout);
    scanf("%d%d%d%d", &num_a ,&num_station , &num_m ,&qur_station);
    init();//预处理出所有的上车数列

    // for (int i = 1; i <= num_station; ++i)
    // {
    //     printf("add_1 a: %d , add_2 x:%d, total_1 a :%d , total_2 x: %d \n", UpBus[i].add_1 ,UpBus[i].add_2 ,UpBus[i].total_1 ,UpBus[i].total_2  );
    // }
       

    //m = UpBus[numstation - 1].total_1 * a + UpBus[numstation - 1].total_2 * x
    //x = (m -  UpBus[numstation - 1].total_1*a) / UpBus[numstation - 1].total_2
    int var_x = (num_m - UpBus[num_station-1].total_1*num_a) / (UpBus[num_station-1].total_2);

    int res = UpBus[qur_station].total_1*num_a + UpBus[qur_station].total_2*var_x;
    //printf("%d\n", var_x);
    printf("%d\n", res);
    return 0;
}