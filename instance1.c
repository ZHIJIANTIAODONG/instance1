//1.2.3.4能够组成多少个互不相同且无重复的三位数字？都是多少？
//百位十位个位都是1.2.3.4，
//先求出二位数字
//11.12.13.14
//21.22.23.24
//#include <stdio.h>
/*int main()
{
    int i=0,j=0,z=0,num=0;
    int count=0;
    for(i=1;i<5;i++)
    {
        for(j=1;j<5;j++)
        {
            for(z=1;z<5;z++)
            {
                if(i!=j && j!=z && i!=z)
                {
                num=i*100 + j*10 +z;
                printf("%d\n",num);
                count++;
                }
            }
        }
    }
    printf("%d\n",count);
}*/
//进行优化
/*int main()
{
    int i=0,j=0,z=0,num=0;
    int count=0;
    for(i=1;i<5;i++)
    {
        for(j=1;j<5;j++)
        {
            if(i==j)//十位与百位相同，跳出当前循环
            {
                continue;
            }
            for(z=1;z<5;z++)
            {
                if(j==z || i==z)//十位与个位相同，跳过当前循环，个位与百位
                {
                    continue;
                }
                {
                num=i*100 + j*10 +z;
                printf("%d\n",num);
                count++;
                }
            }
        }
    }
    printf("%d\n",count);
}*/
//深度优先搜索法看不懂，
/*#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

int  b[4],arr[4];//定义两个数组用来类比
int Count=0;//计数器
void DFS(int step){
    if(step==5){
        if(arr[1]!=arr[2]&& arr[1]!=arr[3]&&arr[2]!=arr[3]){//判断哪些符合条件
            Count++;
            printf("%d%d%d\n",arr[1],arr[2],arr[3]);//输出可用排列
        }
        return ;
    }

    for(int i=1;i<=4;i++){
        if(b[i]==0){
            arr[step]=i;
            b[i]=1;//排除重复
            DFS(step+1);//自己调用自己
            b[i]=0;
        }
    }
    return ;
}

int main(void)
{
    DFS(1);
    printf("共有%d种",Count);
    return 0;
}*/
//链表的方式，不懂不懂
#include <stdio.h>

#define NUM 4  // 数字个数
#define LEN 3  // 排列出的数字的长度

struct number {
    int val;
    struct number *next;
} list[NUM];

void permutation(struct number *list, int m)
{
    static int array[LEN];
    struct number *p, *piror, *head;
    if(m)  // 如果此次还未排列好，则选择剩余数字继续排列
        for(piror=NULL, p=list, head=list; p; piror=p, p=p->next)
        {
            array[LEN - m] = p->val;  // 将排列结果临时存入数组
            if(piror)  // 如果本次选择的数字不在表头
            {
                 piror->next = p->next;  // 重组链表进行下一位数的排列
                 permutation(head, m-1);
                 piror->next = p;  // 还原链表
            }
            else permutation(p->next, m-1);
        }
    else  // 否则打印出此次排列出的数字
    {
        int i;
        for(i=0; i<LEN; i++)
            printf("%d%c", array[i], i==LEN-1? '\n': ',');
    }
}

int main()
{
    int i;
    // 初始化链表
    for(i=0; i<NUM; i++)
    {
        list[i].val = i + 1;
        list[i].next = list + i + 1;
    }
    list[NUM - 1].next = NULL;

    // 递归打印排列结果
    permutation(list, LEN);
    return 0;
}