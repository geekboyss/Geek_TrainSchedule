#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5

struct train
{
    char num[128];
    char s_time[128];
    char e_time[128];
    char s_add[128];
    char e_add[128];
};


void Print_re()
{

    printf("请选择需要修改的内容\n");
    printf("1.修改车号\n");
    printf("2.修改出发时间\n");
    printf("3.修改到达时间\n");
    printf("4.修改出发地点\n");
    printf("5.修改到达地点\n");
}

void Print_menu()
{
    printf("-------火车时刻表管理系统-------\n");
    printf("1.增加车次\n");
    printf("2.删除车次\n");
    printf("3.修改车次\n");
    printf("4.查询车次\n");
    printf("5.显示所有车次\n");
    printf("请输入选项:(输入6退出程序!)\n");

}
int add_train(struct train **p,int *len)
{
    if (*len > MAX)
    {
        printf("时刻表已满,添加失败\n");
        return 0;
    }
    int n = *len;
    printf("请输入车次:\n");
    scanf("%s",(*p)[n].num);
    printf("请输入出发时间:\n");
    scanf("%s",(*p)[n].s_time);
    printf("请输入到达时间:\n");
    scanf("%s",(*p)[n].e_time);
    printf("请输入始发站:\n");
    scanf("%s",(*p)[n].s_add);
    printf("请输入终点站:\n");
    scanf("%s",(*p)[n].e_add);
	//测试代码
	system("cls");
    (*len)++;
    return 1;
    
}

int del_train(struct train **p,int *len)
{
    char tmp[128] = {0};
    printf("请输入需要删除的车次:");
    scanf("%s",tmp);
    int a = *len;
    int i,j;
    struct train *temp = malloc(sizeof(struct train));

    for ( i = 0; i < a; i++)
    {
        if (strcmp((*p)[i].num,tmp) == 0)
        {
            for ( j = i; j < a; j++)
            {
                (*p)[j] = (*p)[j+1];
            }
            (*len)--;
            return 1;
        }
    }
    return 0;
}

int re_train(struct train **p,int len)
{
    int i;
    char temp[128] ={0};
    printf("请输入需要修改的车次:");
    scanf("%s",temp);
    for ( i = 0; i < len; i++)
    {
        if (strcmp((*p)[i].num,temp) == 0)
        {
            while (1)
            {
                Print_re();
                int x;
                scanf("%d",&x);
                switch (x)
                {
                case 1:
                    printf("请输入车次:\n");
                    scanf("%s",(*p)[i].num);
                    break;
                case 2:
                    printf("请输入出发时间:\n");
                    scanf("%s",(*p)[i].s_time);
                    break;
                case 3:
                    printf("请输入到达时间:\n");
                    scanf("%s",(*p)[i].e_time);
                    break;
                case 4:
                    printf("请输入始发站:\n");
                    scanf("%s",(*p)[i].s_add);
                    break;
                case 5:
                    printf("请输入终点站:\n");
                    scanf("%s",(*p)[i].e_add);
                    break;
                default:
                    break;
                }
                break;
            }
            return 1;
        }
        
        
    }
    return 0;
    
}

int search_train(struct train **p,int len)
{
    char tmp[128] = {0};

    printf("请输入需要查询的车次:");
    scanf("%s",tmp);
    int i;
    for ( i = 0; i < len; i++)
    {
        if (strcmp((*p)[i].num,tmp) == 0)
        {
            printf("该车次为:\n");
            printf("车次:%s 出发时间:%s 到达时间:%s 始发站:%s 终点站:%s\n",
            (*p)[i].num,(*p)[i].s_time,(*p)[i].e_time,(*p)[i].s_add,(*p)[i].e_add);
            return 1;     
        }
    }
    printf("暂无该车次信息!\n");
    return 0;
}

int print_train(struct train *p,int len)
{
    int i;
    for ( i = 0; i < len; i++)
    {
        printf("车次:%s 出发时间:%s 到达时间:%s 始发站:%s 终点站:%s\n",
        p[i].num,p[i].s_time,p[i].e_time,p[i].s_add,p[i].e_add);
    }
    
}
int main()
{
    struct train *List = malloc(sizeof(struct train)*MAX);
    int len = 0;

    while (1)
    {
        Print_menu();
        int num;
        scanf("%d",&num);
        switch (num)
        {
        case 1:
            if(add_train(&List,&len) == 1)
            {
                printf("添加成功\n");
            }
            break;
        case 2:
        	if (del_train(&List,&len) == 1)
            {
                printf("删除成功\n");
            }
            break;
        case 3:
            if (re_train(&List,len) == 1)
            {
                printf("修改成功\n");
            }
            
            break;
        case 4:
            if (search_train(&List,len) == 1)
            {
                printf("查找完毕!\n");
            }
            
            break;
        case 5:
            print_train(List,len);
            break;
        default:
            exit(0);
        }
    }
    
    return 0;
    
}

