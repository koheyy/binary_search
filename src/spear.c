#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int s = 0;
  for(int i = 0; i < n; i++){
    s = s + A[i] / x;
  }
  if(s >= k) return 1;
  return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  int mx = 0;
  for(i = 0; i < n; i++){
    if(A[i] >= mx) mx = A[i];
  }
  lb = 1;
  ub = mx;
  if(p(1) == 0) return printf("%d\n", 0);
  if(p(mx)) return printf("%d\n", mx);
  while(ub - lb > 1){
    int mid = (ub + lb) / 2;
    if(p(mid)) lb = mid;
    else ub = mid;
  }
  printf("%d\n", lb);
  return 0;
}
