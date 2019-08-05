#include<cstdio>
int N,M;
int cnt = 0;
int result[8];
void recur(int n){
    if(cnt == M){
        for(int i=0;i<M;i++) printf("%d ",result[i]);
        printf("\n");
    }
    else{
        for(int i=n;i<=N;i++){
            result[cnt++] = i;
            recur(i);
            cnt--;
        }
    }
}
int main(){
    scanf("%d %d",&N,&M);
    recur(1);
    return 0;
}
