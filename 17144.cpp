#include <cstdio>
#define up -1
#define down 1
#define left -1
#define right 1

int main(){
    int R,C,T;
    scanf("%d %d %d",&R,&C,&T);
    int arr[55][55]={0};
    int add[55][55]={0};
    int i,j;
    int cleaner[2];
    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j] == -1) {
                cleaner[0] = i;
                cleaner[1] = j;
            }
        }
    }
    //index 0 ~ R
    int cnt=0;
    int tmp;
    int check[4]={0};
    for(int k=0;k<T;k++){
        for(i=0;i<R;i++){
            for(j=0;j<C;j++){
                cnt = 0;
                tmp = arr[i][j];
                if(tmp > 0){
                    if(i+up>=0 && arr[i+up][j] != -1)  {
                        cnt++;
                        check[0]=1;
                    }
                    if(i+down<R && arr[i+down][j] != -1) {
                        cnt++;
                        check[1]=1;
                    }
                    if(j+left>=0 && arr[i][j+left] != -1) {
                        cnt++;
                        check[2]=1;
                    }
                    if(j+right<C) {
                        cnt++;
                        check[3]=1;
                    }
                    arr[i][j] -= tmp/5*cnt;
                    if(check[0]) {add[i+up][j] += tmp/5; check[0] = 0;}
                    if(check[1]) {add[i+down][j]+= tmp/5; check[1] = 0;}
                    if(check[2]) {add[i][j+left]+=tmp/5; check[2] = 0;}
                    if(check[3]) {add[i][j+right]+=tmp/5; check[3] = 0;}
                    //printf("cnt : %d\n",cnt);
                }
            }
        }
        printf("1\n");
        for(i=0;i<R;i++){
            for(j=0;j<C;j++){
                arr[i][j] += add[i][j];
                add[i][j] = 0;
                //printf("%d ",arr[i][j]);
            }
            //printf("\n");
        }
        int x1 = cleaner[0]-1;
        int x2 = cleaner[0];
        
        for(i=x1-1;i>0;i--) arr[i][0] = arr[i-1][0];
        for(j=0;j<C-1;j++) arr[0][j] = arr[0][j+1];
        for(i=0;i<x1;i++) arr[i][C-1] = arr[i+1][C-1];
        for(j=C-2;j>0;j--) arr[x1][j+1] = arr[x1][j];
        arr[x1][1] = 0;
        for(i=x2+1;i<R-1;i++) arr[i][0] = arr[i+1][0];
        for(j=0;j<C-1;j++) arr[R-1][j] = arr[R-1][j+1];
        for(i=R-2;i>=x2;i--) arr[i+1][C-1] = arr[i][C-1];
        for(j=C-2;j>0;j--) arr[x2][j+1] = arr[x2][j];
        arr[x2][1] = 0;
    }
    printf("2\n");
    int count=0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++) {printf("%d ",arr[i][j]);count+=arr[i][j];}
        printf("\n");
    }
    printf("%d\n",count+2);
    return 0;
}
