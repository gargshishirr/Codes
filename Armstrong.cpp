//
// Created by Shishir Garg on 09/06/22.
//

#include<stdio.h>
#include<math.h>
int main()
{
    int n,num,sum,count,a,final;
    printf("Enter any integer : ");
    scanf("%d",&n);
    printf("\nArmstrong numbers from 1 to %d are : ",n);
    int i=1;
    while(i<=n)
    {
        num = i;
        count = 0;
        while(i>0)
        {
            count++; //counting no. of digits in i
            i=i/10;
        }
        i = num;
        sum = 0;
        while(num>0)
        {
            int r = num%10;
            sum = sum+pow(r,count);
            num = num/10;
        }
        if(sum==i)
            printf("%d ",sum);
        i++;
    }
    return 0;
}