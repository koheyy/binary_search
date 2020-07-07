#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int sum = 0;
  int num = 1;
  for(int i = 0; i < n; i++){
    sum = sum + A[i];
    if(sum > x){
      num = num + 1;
      sum = A[i];
    }
  }
  return num <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  int max = 0;
  int sum = 0;
  for(i = 0; i < n; i++){
    sum = sum + A[i];
    if(max < A[i]) max = A[i];
  }
  lb = max-1;
  ub = 1000000000;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }
  printf("%d\n",ub);
  return 0;
}
