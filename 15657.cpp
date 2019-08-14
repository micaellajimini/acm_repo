#include<cstdio>
#include<vector>

using namespace std;

int N,M;
vector<int> v;
vector<int> result;
int cnt=0;

void recur(int index){
    if(cnt == M){
        for(int i=0;i<result.size();i++) printf("%d ",result[i]);
        printf("\n");
    }
    else{
        for(int i=index;i<v.size();i++){
            result.push_back(v[i]);
            cnt++;
            recur(i);
            cnt--;
            result.pop_back();
        }
    }
}
int main(){
    scanf("%d %d",&N,&M);
    int temp;
    scanf("%d",&temp);
    v.push_back(temp);
    for(int i=1;i<N;i++){
        scanf("%d",&temp);
        if(temp > v[v.size()-1]) v.push_back(temp);
        else if(temp < v[0]) v.insert(v.begin(),temp);
        else{
            for(int j=0;j<v.size()-1;j++){
                if(v[j] < temp && temp < v[j+1]){
                    v.insert(v.begin()+j+1,temp);
                    break;
                }
            }
        }
    }
    //for(int i=0;i<v.size();i++) printf("%d ",v[i]);
    recur(0);
    return 0;
}

