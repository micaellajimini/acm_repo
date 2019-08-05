#include<cstdio>
int N,M;
int result[7];
int cnt=0;
void recur(){
    if(cnt == M){
        for(int i=0;i<M;i++) printf("%d ",result[i]);
        printf("\n");
    }
    else{
        for(int i=1;i<=N;i++){
            result[cnt++] = i;
            recur();
            cnt--;
        }
    }
}

int main(){
    scanf("%d %d",&N,&M);
    recur();

    return 0;
}
