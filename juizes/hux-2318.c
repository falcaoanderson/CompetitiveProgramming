#include <stdio.h>

int dp[1000010];
int func(int n){
  if(dp[n]!=0){return dp[n];}
  if(n==0){return 0;}
  if(n==1){return 1;}

  return dp[n]=func(n-1) + func(n-2);
}

void main(void){
  int y,k;
  float x,z;
  scanf("%f%i%f%i",&x,&y,&z,&k);//cin >> x >> y >> z >> k;

  if(x > func(y)){
    printf("Nao foi dessa vez!! Troy nao teve coragem o suficiente.\n");
  }else {
    printf("Esse pode ser o comeco de algo novo!! Troy vai cantar!!\n");
  }
  if(z > func(k)){
    printf("Nao foi dessa vez!! Gabriella nao teve coragem o suficiente.\n");
  }else {
    printf("Esse pode ser o comeco de algo novo!! Gabriella vai cantar!!\n");
  }
}
