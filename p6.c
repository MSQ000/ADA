#include<stdio.h>

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}

void main()
{
    int i,j,n,capacity;
    int w,wt[20],ve[20],v[20][20];
    printf("Enter the number of items:\n");
    scanf("%d",&n);
    printf("\n-----\nWeight values\n-----\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&wt[i]);
        scanf("%d",&ve[i]);
    }
    printf("Enter the Capacity of Knapsack :\n");
    scanf("%d",&capacity);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=capacity;j++)
        {
            if(i==0 || j==0)
            {
                v[i][j]=0;
            }
            else if(j-wt[i]>=0)
            {
                v[i][j]=max(v[i-1][j],v[i-1][j-wt[i]]+ve[i]);
            }
            else
            {
                v[i][j]=v[i-1][j];
            }
            printf("%4d",v[i][j]);
        }
        printf("\n");
    }
    w=capacity;
    printf("The items in the Knapsack are :\n");
    for(i=n;i>0;i--)
    {
        if(v[i][w]==v[i-1][w]) continue;
        else
        {
            w=w-wt[i];
            printf("%3d",wt[i]);
        }
    }
    printf("\nTotal profit: %d",v[n][capacity]);
    getchar();
}
