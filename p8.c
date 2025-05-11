#include<stdio.h>
#define max 10

int s[max],x[max],d;

void sumofsub(int p,int k,int r)
{
    int i;
    x[k]=1;

    if(p+s[k]==d)
    {
        for(i=1;i<=k;i++)
        if(x[i]==1)
         printf("%d\t",s[i]);
        printf("\n");
    }
    else if(p+s[k]+s[k+1]<=d)
        sumofsub(p+s[k],k+1,r-s[k]);
    if((p+r-s[k]>=d)&&(p+s[k+1]<=d))
    {
        x[k]=0;
        sumofsub(p,k+1,r-s[k]);
    }
}

void main()
{
    int i,n,sum=0;
    printf("Enter the max no:\n");
    scanf("%d",&n);
    printf("Enter the subset in increasing order:\n");
    for(i=1;i<=n;i++)
     scanf("%d",&s[i]);
    printf("Enter the max subset:\t");
    scanf("%d",&d);
    for(i=1;i<=n;i++)
        sum=sum+s[i];
    if(sum<d||s[1]>d)
        printf("No possible subset\n");
    else
        sumofsub(0,1,sum);
    getchar();
}
