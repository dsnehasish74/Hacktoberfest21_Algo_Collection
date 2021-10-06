//count of digits in a string by acid000

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int count =0;
    char s[10010];
    scanf("%s",s);
    int a[10010];
    for (int i=0;i<strlen(s);i++){
        if( s[i]>=48 && s[i]<=57){
            a[s[i]-48]=a[s[i]-48]+1;
        }
    }
    for(int i=0;i<=9;i++){
        if(a[i]==1){
            count=count+1;
        }
    }
    printf("count of digits are %d",count);
    
    return 0;
}
