#include<cstdio>

int N,M;
int result[8];
int cnt=0;
void recur(int n){
    int i;
    if(cnt == M){
        for(i=0;i<M;i++) printf("%d ",result[i]);
        printf("\n");
    }
    else{
        for(i=n;i<=N;i++){
            result[cnt++] = i;
            recur(i+1);
            cnt--;
        }
    }
}
int main(){
    scanf("%d %d",&N,&M);
    cnt = 0;
    recur(1);
    return 0;
}
