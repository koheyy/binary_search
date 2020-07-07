#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int s = 0;
  for(int i = 0; i < n; i++){
    s = s + (A[i] + x - 1) / x;
  }
  return s <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  int mx = 0;
  for(i = 0; i < n; i++){
    if(A[i] > mx) mx = A[i];
  }
  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
    int mid = (lb + ub)/2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }
  printf("%d\n", ub);
  return 0;
}
