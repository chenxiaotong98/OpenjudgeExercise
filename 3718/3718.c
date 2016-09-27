#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    unsigned int a1;
    unsigned int a2;
    int i,j;
    char flag[300000];
    for(i=0;i<n;i++)
    {
        scanf("%u %u",&a1,&a2);
        flag[i]='N';
        for(j=0;j<16;j++)
        {
            if(a1==a2)
            {
                flag[i]='Y';break;
            }

            else
                a1=(a1*2)%65536+(a1/32768);
        }
    }
    for(i=0;i<n;i++)
    {
        if(flag[i]=='Y')
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
