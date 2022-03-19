#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int MAXN=30000;
int head[MAXN];
int visited[MAXN];
int d[MAXN]; 
int t;
int low[MAXN];
int cutpoint[MAXN];
int children[MAXN];
int cnt=0;
struct Edge{
    int to;
    int nxt;
};
Edge edge[500000];
void addedge(int u,int v){
    edge[cnt].to=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt++;
}
void DFSCV(int u,int parent){
    t++;
    d[u]=t;
    low[u]=d[u];
    visited[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].nxt){
        int v=edge[i].to;
        if(visited[v]==0){
            children[u]++;
            DFSCV(v,u);
            low[u]=min(low[u],low[v]);
            if(parent==-1&&children[u]>=2)
                cutpoint[u]=1;
            else if(parent!=-1&&low[v]>=d[u])
                cutpoint[u]=1;
        }
        else if(v!=parent)
            low[u]=min(low[u],d[v]);
    }
}
void init(){
    for(int i=0;i<MAXN-1;i++)
        head[i]=-1;
}
int main(){
    int m,n,from,to;
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        cin>>from>>to;
        addedge(from,to);
        addedge(to,from);
    }
    for(int i=1;i<=n;i++)
        if(visited[i]==0)
                DFSCV(i,-1);
    int cutpointcnt=0;
    for(int i=1;i<=n;i++)
        if(cutpoint[i]==1)
            cutpointcnt++;
    printf("%d\n",cutpointcnt);
    for(int i=1;i<=n;i++)
            if(cutpoint[i]==1)
                printf("%d\n",i);
                 
//printf("\n\n");
//for(int i=1;i<=n;i++) 
//  printf("%d ",low[i]);
//  printf("\n");
//for(int i=1;i<=n;i++) 
//  printf("%d ",d[i]);
//  printf("\n");
//for(int i=1;i<=n;i++) 
//  printf("%d ",children[i]);
    return 0;
} 
/**************************************************************
    Problem: 1001
    User: 201220183
    Language: C++
    Result: ÕýÈ·
    Time:40 ms
    Memory:0 kb
****************************************************************/
