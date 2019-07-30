#include <cstdio>
int check[10]={0};
int N,M;

void recur(int num, int arr[10]){
    if(num == M) {
        for(int i=0;i<M;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    else{
        for(int i=1;i<=N;i++){
            if(!check[i]){
                arr[num] = i;
                check[i] = 1;
                recur(++num,arr);
                --num;
                check[i] = 0;
            }
        }
    }
}
int main(){
    scanf("%d %d",&N,&M);
    int arr[10];
    recur(0,arr);
    return 0;
}

