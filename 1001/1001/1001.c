#include<stdio.h>
/*一位乘多位 结果保存在另一数组 同时记录长度*/
int m_s(int m[150],int s,int r[150],int l)
{
    int i;
    for(i=0;i<l;i++)
        r[i]=m[i]*s;
    for(i=0;i<l+1;i++)
    {
        r[i+1]+=(r[i]/10);
        r[i]%=10;
    }
    if(r[l+1]!=0)
        l++;
    return l;
}
/*多位乘多位 结果保存在第一个多位数组 同时记录长度 默认第二个多位数长为5 */
int m_m(int m1[150],int m2[150],int l1)
{
    int temp[5][150];
    int i,j;
    for(i=0;i<5;i++)
        for(j=0;j<l1+5+1;j++)
            temp[i][j]=0;
    for(i=0;i<5;i++)
        l1=m_s(m1,m2[i],temp[i]+i,l1);
    int t;
    for(i=0;i<l1+5;i++)
        m1[i]=0;
    for(i=0;i<l1+5+1;i++)
    {
        t=temp[0][i]+temp[1][i]+temp[2][i]+temp[3][i]+temp[4][i];
        m1[i]+=t%10;
        if(m1[i]>9)
        {
            m1[i+1]+=m1[i]/10;
            m1[i]%=10;
        }
        m1[i+1]+=t/10;
    }
    if(m1[l1+4])
        return l1+5;
    else
        return l1+4;
}
/*求指数 每次调用多位乘多位*/
int m_exp(int m[5],int e,int s[150])
{
    int i,l=5;
    for(i=0;i<5;i++)
    {
        s[i]=m[i];
    }
    for(i=0;i<e-1;i++)
    {
        l=m_m(s,m,l);
    }
    return l;
}
int main()
{
    int m[5],x[150];
    int i,j;
    int n,l;
    int pos;
    int r1,r2;
    char s[6];
    while(scanf("%s%d",s,&n)==2)
    {
        for(i=0,j=0;i<6;i++)
        {
            if(s[5-i]!='.')
            {
                m[j++]=s[5-i]-'0';
            }
            else
                pos=i;
        }
        if(m[0]==0 && m[1]==0 && m[2]==0 && m[3]==0 && m[4]==0)
        {
            printf("0\n");
            continue;
        }
        l=m_exp(m,n,x);
        for(i=0;i<l;i++)
            if(x[i]!=0 && i<pos*n)
                break;
        r2=i;
        for(i=l-1;i>0;i--)
            if(x[i]!=0)
                break;
        r1=i;
        for(i=r1;i>pos*n-1;i--)
            printf("%d",x[i]);
        if(pos*n>r2)
        {
            printf(".");
            for(i=pos*n-1;i>r2-1;i--)
                printf("%d",x[i]);
        }
        printf("\n");

    }
    return 0;
}
    /*for(i=l-1;i>-1;i--)
            printf("%d",x[i]);
        printf("\n\n");*/
    /*测试m_s正确性
    for(i=0;i<150;i++)
        m[i]=0;
    for(i=0;i<20;i++)
        m[i]=i/2;
    for(i=0;i<21;i++)
        printf("%d",m[20-i]);
    printf("\n");
    m_s(m,8,20);
    for(i=0;i<21;i++)
        printf("%d",m[20-i]);
    */

    /*测试m_m正确性
    int m1[5];
    for(i=0;i<150;i++)
        m[i]=0;
    for(i=0;i<5;i++)
        m[i]=6;
    for(i=0;i<5;i++)
        m1[i]=9;
    for(i=0;i<5;i++)
        printf("%d",m[4-i]);
    printf(" ");
    for(i=0;i<5;i++)
        printf("%d",m1[4-i]);
    printf("\n");
    m_m(m,m1,5);
    for(i=0;i<10;i++)
        printf("%d ",m[9-i]);
*/
    /*测试m_exp正确性
    m[0]=1;m[1]=2;m[2]=3;m[3]=4;m[4]=0;
    for(i=0;i<150;i++)
        s[i]=0;
    l=m_exp(m,20,s);
    for(i=0;i<l;i++)
        printf("%d",s[l-1-i]);
    printf("\n");
*/
