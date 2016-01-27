#include<stdio.h>

int maxPoz(int n, int p[], int w[]){
  int max=p[0];
  int poz=0;
  for(int i=1; i<=n; i++){
    if(p[i]>max){
      max=p[i];
      poz=i;
    }

  }
  return poz;

}


void ranac(int c, int n, int p[], int w[]){
    int br=1;
    int vrednost = 0;
    int x[] = {0,0,0,0,0,0};
  do
  {
    int poz = maxPoz(n,p,w);
    if(w[poz]<=c){
      x[poz]=1;
      vrednost+=p[poz];
      c-=w[poz];
      p[poz]=0;

    }
    else{
      x[poz]=0;
      p[poz]=0;
      poz = maxPoz(n,p,w);

    }
    br++;
  }while(c && br<=n);
  printf("X: ");

  for (int j = 1; j <= n; j++)
    printf("%d ",x[j]);
  printf("\n");
  printf("vrednost: %d\n  |%d|%d|%d|",vrednost,c,br,n);
}


int main(){
  int c;
  int n;
  scanf("%d",&n);
  scanf("%d",&c);
  int p[] = {0,5,12,4,3,1};
  int w[] = {0,4,7,3,2,1};

  ranac(c,n,p,w);

  return 0;
}
