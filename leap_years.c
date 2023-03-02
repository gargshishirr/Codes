//
// Created by Shishir Garg on 09/06/22.
//

//
// Created by Shishir Garg on 09/06/22.
//

#include<stdio.h>


int main(){
    int n;
    int count=0;
    scanf("%d", &n);
    printf("the number of leap years between 1 and %d are \n",n);
    for (int i=1; i<n;i++){
        if(i%4==0){
            count++;
            printf("%d\n",i);
        }

    }
    printf("\t number of leap years=%d",count);

return 0;
}