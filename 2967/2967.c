#include<stdio.h>
int main()
{
    int c;
    scanf("%d",&c);
    int i,j;
    unsigned int nsec,nmin,nhour,nday,nmonth,nyear,xsec,xmin,xhour,xday,xmonth,xyear;
    unsigned int days,secs;
    int month_days_is[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    int month_days_not[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    for(i=0;i<c;i++)
    {
        scanf("%u:%u:%u %u.%u.%u",&nhour,&nmin,&nsec,&nday,&nmonth,&nyear);
        for(days=0,j=2000;j<nyear;j++)
            days+=(((j%400==0)||(j%4==0 && j%100!=0))?366:365);
        if((nyear%400==0)||(nyear%4==0 && nyear%100!=0))
            for(j=1;j<nmonth;j++)
                days+=month_days_is[j];
        else
            for(j=1;j<nmonth;j++)
                days+=month_days_not[j];
        days+=nday;
        xyear=(days-1)/1000;
        xmonth=(days-xyear*1000+99)/100;
        xday=(days%100)?(days%100):100;
        secs=0;
        secs=(int)(float)(3600*nhour+60*nmin+nsec)*125/108;
        xhour=secs/10000;
        xmin=(secs-10000*xhour)/100;
        xsec=secs%100;
        printf("%u:%u:%u %u.%u.%u\n",xhour,xmin,xsec,xday,xmonth,xyear);
    }
    return 0;
}
