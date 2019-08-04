#include<cstdio>

typedef struct shark{
    int s;
    int d;
    int z;
}shark;

int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
int R,C,M;
int check(shark sh1[101][101],int i,int j,int size){
    if(sh1[i][j].z > size) return 1;
    return 0;
}

int main(){ 
    scanf("%d %d %d",&R,&C,&M);

    shark sh[101][101]={0};
    shark sh1[101][101]={0};
    int r,c,s,d,z;
    int i,j,k,l;
    for(i=1;i<=M;i++){
        scanf("%d %d %d %d %d",&r,&c,&s,&d,&z);
        sh[r][c].s = s;
        sh[r][c].d = d;
        sh[r][c].z = z;
    }
    int count=0;
    int tmp,tmp1;
    for(i=1;i<=C;i++){
        for(j=1;j<=R;j++){
            if(sh[j][i].z) {
                count+=sh[j][i].z;
                sh[j][i].s = 0;
                sh[j][i].d = 0;
                sh[j][i].z = 0;
                break;
            }
        }
        //낚시

        for(l=1;l<=R;l++){
            for(k=1;k<=C;k++){
                if(sh[l][k].z){
                    switch(sh[l][k].d){
                        case 1 :
                            tmp = l-1;
                            if(tmp < sh[l][k].s){
                                tmp = sh[l][k].s - tmp;
                                if(((tmp-1)/(R-1))%2 == 0){
                                    tmp1 = 1+tmp%(R-1);
                                    tmp1 = (tmp1 == 1) ? R : tmp1;
                                    if(!check(sh1,tmp1,k,sh[l][k].z)) sh1[tmp1][k].d = 2;
                                    else break;
                                }
                                else{
                                    tmp1 = R-tmp%(R-1);
                                    tmp1 = (tmp1 == R) ? 1 : tmp1;
                                    if(!check(sh1,tmp1,k,sh[l][k].z)) 
                                        sh1[tmp1][k].d = 1;
                                    else break;
                                }
                            }
                            else{
                                tmp1 = l - sh[l][k].s;
                                if(!check(sh1,tmp1,k,sh[l][k].z)) 
                                    sh1[tmp1][k].d = 1;
                                else break;
                            }
                            sh1[tmp1][k].s = sh[l][k].s;
                            sh1[tmp1][k].z = sh[l][k].z;
                            break;
                        case 2 :
                            tmp = R-l;
                            if(tmp < sh[l][k].s){
                                tmp = sh[l][k].s - tmp;
                                if(((tmp-1)/(R-1))%2 == 0){
                                    tmp1 = R - tmp%(R-1);
                                    tmp1 = (tmp1 == R) ? 1 : tmp1;
                                    if(!check(sh1,tmp1,k,sh[l][k].z)) sh1[tmp1][k].d = 1;
                                    else break;
                                }
                                else {tmp1 = 1+tmp%(R-1); 
                                    tmp1 = (tmp1 == 1) ? R : tmp1;
                                    if(!check(sh1,tmp1,k,sh[l][k].z)) sh1[tmp1][k].d = 2;
                                    else break;
                                }

                            }
                            else {
                                tmp1 = l + sh[l][k].s; 
                                if(!check(sh1,tmp1,k,sh[l][k].z)) sh1[tmp1][k].d = 2;
                                else break;
                            }
                            sh1[tmp1][k].s = sh[l][k].s;
                            sh1[tmp1][k].z = sh[l][k].z;
                            break;
                        case 3 :
                            tmp = C-k;
                            if(tmp < sh[l][k].s){
                                tmp = sh[l][k].s - tmp;
                                if(((tmp-1)/(C-1))%2 == 0){//
                                    tmp1 = C - tmp%(C-1);
                                    tmp1 = (tmp1 == C) ? 1 : tmp1;
                                    if(!check(sh1,l,tmp1,sh[l][k].z)) 
                                        sh1[l][tmp1].d = 4;
                                    else break;
                                }
                                else {tmp1 = 1+tmp%(C-1); 
                                    tmp1 = (tmp1 == 1) ? C : tmp1;
                                    if(!check(sh1,l,tmp1,sh[l][k].z))
                                        sh1[l][tmp1].d = 3;
                                    else break;
                                }
                            }
                            else {tmp1 = k + sh[l][k].s; 
                                if(!check(sh1,l,tmp1,sh[l][k].z)) sh1[l][tmp1].d = 3;
                                else break;
                            }
                            sh1[l][tmp1].s = sh[l][k].s;
                            sh1[l][tmp1].z = sh[l][k].z;
                            break;
                        case 4 :
                            tmp = k-1;
                            if(tmp < sh[l][k].s){
                                tmp = sh[l][k].s - tmp;
                                if(((tmp-1)/(C-1))%2 == 0){//right
                                    tmp1 = 1 + tmp%(C-1);
                                    tmp1 = (tmp1 == 1) ? C : tmp1;
                                    if(!check(sh1,l,tmp1,sh[l][k].z)) sh1[l][tmp1].d = 3;
                                    else break;
                                }
                                else {tmp1 = C - tmp%(C-1); 
                                    tmp1 = (tmp1 == C) ? 1 : tmp1;
                                    if(!check(sh1,l,tmp1,sh[l][k].z)) 
                                        sh1[l][tmp1].d = 4;
                                    else break;
                                }
                            }
                            else {tmp1 = k - sh[l][k].s; 
                                if(!check(sh1,l,tmp1,sh[l][k].z)) sh1[l][tmp1].d = 4;
                                else break;
                            }
                            sh1[l][tmp1].s = sh[l][k].s;
                            sh1[l][tmp1].z = sh[l][k].z;
                            break;
                    }//switch                        
                }
                sh[l][k].d = 0;
                sh[l][k].s = 0;
                sh[l][k].z = 0;
            }
        }

        for(l=1;l<=R;l++){
            for(k=1;k<=C;k++){
                if(sh1[l][k].z){
                    sh[l][k].s = sh1[l][k].s;
                    sh[l][k].d = sh1[l][k].d;
                    sh[l][k].z = sh1[l][k].z;
                    sh1[l][k].s=0;
                    sh1[l][k].d=0;
                    sh1[l][k].z=0;
                }
            }
        }
        
    }
    printf("%d\n",count);
    return 0;
}
