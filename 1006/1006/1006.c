/*
中国剩余定理
n1==p*28*33*x;28*33*x==1 mod 23
n2==e*23*33*y;23*33*y==1 mod 28
n3==i*23*28*z;23*28*z==1 mod 33
n+d==n1+n2+n3
*/

#include<stdio.h>
int main()
{
    int p,e,i,d;
    int x,y,z;
    int temp;
    for(x=0,temp=28*33;x<23;x++)
        if((x*temp)%23==1)
            break;
    x=x*28*33;
    for(y=0,temp=23*33;y<28;y++)
        if((y*temp)%28==1)
            break;
    y=y*23*33;
    for(z=0,temp=23*28;z<33;z++)
        if((z*temp)%33==1)
            break;
    z=z*23*28;
    int triple_peak;
    int no=1;
    while(scanf("%d %d %d %d",&p,&e,&i,&d),p!=-1 && e!=-1 && i!=-1 && d!=-1)
    {
        triple_peak=(p*x+e*y+i*z)%21252;
        if(triple_peak<d ||triple_peak==d)
            triple_peak+=21252;
        printf("Case %d: the next triple peak occurs in %d days.\n",no++,triple_peak-d);
    }
    return 0;
}

/*
#include<stdio.h>
int main()
{
    int no=1;
    int p,i,e,d,t;
    while(1)
    {
        scanf("%d %d %d %d",&p,&e,&i,&d);
        if(p==-1 && e==-1 && i==-1 && d==-1)
            break;
        t=(p*5544+e*14421+i*1288-d+21252)%21252;
        if(t==0)
            t=21252;
        printf("Case %d: the next triple peak occurs in %d days.\n",no++,t);
    }
    return 0;
}
*/
