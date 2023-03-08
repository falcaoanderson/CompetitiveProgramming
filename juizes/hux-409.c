#include <stdio.h>

int main(){
    int n;

    scanf("%i",&n);

    printf("%i\n", 3 + (n-1)/2 + 4*(n-1-(n-1)/2));

    return 0;
}
