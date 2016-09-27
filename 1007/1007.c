#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct str{
    char str_name[50];
    unsigned int inverse_n;
};

int Mycompare(const void* elem1, const void* elem2)
{
    struct str* p1,*p2;
    p1=(struct str*)elem1;
    p2=(struct str*)elem2;
    return (p1->inverse_n-p2->inverse_n);

}

int main()
{
    int number,length;
    scanf("%d %d",&length,&number);
    struct str group[100];
    int i,j,k;
    for(i=0;i<number;i++)
    {
        scanf("%s",group[i].str_name);
        group[i].inverse_n=0;
    }
    for(i=0;i<number;i++)
    {
        for(j=0;j<length;j++)
        {
            for(k=j+1;k<length;k++)
            {
                if(group[i].str_name[k]<group[i].str_name[j])
                    group[i].inverse_n++;
            }
        }
    }
    /*for(i=0;i<number;i++)
    {
        printf("%d\n",inverse_n[i]);
    }*/
    qsort(group,number,sizeof(struct str),Mycompare);
    for(i=0;i<number;i++)
    {
        printf("%s\n",group[i].str_name);
    }
    return 0;
}
