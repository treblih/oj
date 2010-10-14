/*
 * =====================================================================================
 *
 *       Filename:  989.c
 *
 *    Description:  Su Doku
 *
 *        Created:  13.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<string.h>
 
#define MAX 81
 
/*按行对数独进行存储*/
int shudu[MAX];
 
void Printfshudu();
int succes(int x,int y,int key);
int DFS(int count);
 
int main()
{
    int i,j;
    char str[10];
    int n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        for(i=0;i<9;++i)
        {
            gets(str);
            for(j=0;j<9;++j)
            {
                /*将字符转化为整型*/ 
                shudu[i*9+j]=str[j]-'0';
            }
        }
        DFS(MAX-1);
        Printfshudu();
    }
    //system("pause");
    return 0;
}
 
/*打印数独*/
void Printfshudu()
{
    int i;
    for(i=0;i<MAX;++i)
    {
        if(i%9==8)
            printf("%d\n",shudu[i]);
        else 
            printf("%d",shudu[i]);
    }
}
 
/*从后往前递归构造数组*/
int DFS(int count)
{
    int i;
    /*如果构造成功，返回1*/
    if(count<0)
    {
        return 1;
    }
    /*当前位置不为空时，跳过*/
    if(shudu[count]!=0)
    {
        return DFS(count-1);
    }
    else
    /*否则对当前位置进行枚举测试*/
    for(i=1;i<10;++i)
    {
        /*满足条件时填入数字*/
        if(succes(count/9,count%9,i))
        {
            shudu[count]=i;
            /*继续搜索，如果构造成功，返回1*/
            if(DFS(count-1))
                return 1;
            /*构造不成功，还原当前位置*/
            shudu[count]=0;
        }
    }
    /*构造不成功，返回0*/
    return 0;
}
 
/*判断key填入x行，y是否满足条件*/
int succes(int x,int y,int key)
{
    int i,j;
    for(i=0;i<9;++i)
    {
        /*判断y所在列是否合法*/
        if(shudu[i*9+y]==key)
            return 0;
        /*判断x所在行是否合法*/
        if(shudu[x*9+i]==key)
            return 0;
    }
    /*m为（x，y）所在的小九宫格左顶点行坐标*/
    int m=x-x%3;
    /*n为(x，y)所在的小九宫格左顶点列坐标*/
    int n=y-y%3;
    /*判断（x，y）所在的小九宫格是否合法*/
    for(i=m;i<m+3;++i)
    {
        for(j=n;j<n+3;++j)
        {
            if(shudu[i*9+j]==key)
                return 0;
        }
    }
    return 1;
}
