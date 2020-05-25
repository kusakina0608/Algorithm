//
// Created by Kina on 2020/02/21.
//
#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int di[]={0, 0, 1, -1};
int dj[]={1, -1, 0, 0};

void ShowCheese(int** cheese, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout<<cheese[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}
void ShowVisited(bool** visited, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout<<visited[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}
void EatenByFairy(int** cheese, int day, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(cheese[i][j]==day){
                cheese[i][j]=0;
            }
        }
    }
}

void InitCheck(bool** check, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            check[i][j]=false;
        }
    }
}

int NCluster(int** cheese, bool** check, int size){
    /*cout<<"치즈 상태"<<endl;
    ShowCheese(cheese, size);
    cout<<"초기 방문 상태"<<endl;
    ShowVisited(check, size);*/
    queue<pair<int, int>> q;
    int count=0;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(cheese[i][j]!=0 && check[i][j]==false){
                count++;
                q.push(make_pair(i, j));
                check[i][j]=true;
                while(!q.empty()){
                    int ii=q.front().first;
                    int jj=q.front().second;
                    q.pop();
                    for(int k=0; k<4; k++){
                        int ni=ii+di[k];
                        int nj=jj+dj[k];
                        if(0<=ni && 0<=nj && ni<size && nj<size){
                            if(cheese[ni][nj]!=0 && check[ni][nj]==false){
                                q.push(make_pair(ni, nj));
                                check[ni][nj]=true;
                            }
                        }
                    }
                }
                /*cout<<"방문 상태"<<endl;
                ShowVisited(check, size);*/
            }
        }
    }
    return count;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int size, max=0;
        scanf("%d", &size);
        int** cheese=new int*[size];
        bool** check=new bool*[size];
        for(int i=0; i<size; i++) {
            cheese[i] = new int[size];
            check[i]=new bool[size];
            for (int j = 0; j < size; j++) {
                scanf("%d", &cheese[i][j]);
                if (max < cheese[i][j]) {
                    max = cheese[i][j];
                }
            }
        }
        int n_cluster=0, max_cluster=0;
        for(int day=0; day<=max; day++){
            EatenByFairy(cheese, day, size);
            InitCheck(check, size);
            n_cluster=NCluster(cheese, check, size);
            if(n_cluster>max_cluster)
                max_cluster=n_cluster;
        }
        printf("#%d %d\n", test_case, max_cluster);
        for(int i=0; i<size; i++){
            delete[] cheese[i];
            delete[] check[i];
        }
        delete[] cheese;
        delete[] check;
    }
    return 0;
}