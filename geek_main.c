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

    printf("��ѡ����Ҫ�޸ĵ�����\n");
    printf("1.�޸ĳ���\n");
    printf("2.�޸ĳ���ʱ��\n");
    printf("3.�޸ĵ���ʱ��\n");
    printf("4.�޸ĳ����ص�\n");
    printf("5.�޸ĵ���ص�\n");
}

void Print_menu()
{
    printf("-------��ʱ�̱����ϵͳ-------\n");
    printf("1.���ӳ���\n");
    printf("2.ɾ������\n");
    printf("3.�޸ĳ���\n");
    printf("4.��ѯ����\n");
    printf("5.��ʾ���г���\n");
    printf("������ѡ��:(����6�˳�����!)\n");

}
int add_train(struct train **p,int *len)
{
    if (*len > MAX)
    {
        printf("ʱ�̱�����,���ʧ��\n");
        return 0;
    }
    int n = *len;
    printf("�����복��:\n");
    scanf("%s",(*p)[n].num);
    printf("���������ʱ��:\n");
    scanf("%s",(*p)[n].s_time);
    printf("�����뵽��ʱ��:\n");
    scanf("%s",(*p)[n].e_time);
    printf("������ʼ��վ:\n");
    scanf("%s",(*p)[n].s_add);
    printf("�������յ�վ:\n");
    scanf("%s",(*p)[n].e_add);
	//���Դ���
	system("cls");
    (*len)++;
    return 1;
    
}

int del_train(struct train **p,int *len)
{
    char tmp[128] = {0};
    printf("��������Ҫɾ���ĳ���:");
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
    printf("��������Ҫ�޸ĵĳ���:");
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
                    printf("�����복��:\n");
                    scanf("%s",(*p)[i].num);
                    break;
                case 2:
                    printf("���������ʱ��:\n");
                    scanf("%s",(*p)[i].s_time);
                    break;
                case 3:
                    printf("�����뵽��ʱ��:\n");
                    scanf("%s",(*p)[i].e_time);
                    break;
                case 4:
                    printf("������ʼ��վ:\n");
                    scanf("%s",(*p)[i].s_add);
                    break;
                case 5:
                    printf("�������յ�վ:\n");
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

    printf("��������Ҫ��ѯ�ĳ���:");
    scanf("%s",tmp);
    int i;
    for ( i = 0; i < len; i++)
    {
        if (strcmp((*p)[i].num,tmp) == 0)
        {
            printf("�ó���Ϊ:\n");
            printf("����:%s ����ʱ��:%s ����ʱ��:%s ʼ��վ:%s �յ�վ:%s\n",
            (*p)[i].num,(*p)[i].s_time,(*p)[i].e_time,(*p)[i].s_add,(*p)[i].e_add);
            return 1;     
        }
    }
    printf("���޸ó�����Ϣ!\n");
    return 0;
}

int print_train(struct train *p,int len)
{
    int i;
    for ( i = 0; i < len; i++)
    {
        printf("����:%s ����ʱ��:%s ����ʱ��:%s ʼ��վ:%s �յ�վ:%s\n",
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
                printf("��ӳɹ�\n");
            }
            break;
        case 2:
        	if (del_train(&List,&len) == 1)
            {
                printf("ɾ���ɹ�\n");
            }
            break;
        case 3:
            if (re_train(&List,len) == 1)
            {
                printf("�޸ĳɹ�\n");
            }
            
            break;
        case 4:
            if (search_train(&List,len) == 1)
            {
                printf("�������!\n");
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

