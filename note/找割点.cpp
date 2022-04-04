#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int MAXN=30000;
int visited[MAXN];
int d[MAXN]; 
int t;
int low[MAXN];
int cutpoint[MAXN];
int children[MAXN];
int cnt=0;
int map[1500][1500];
int edgenum[1500];
struct gebian{
    int u,v;
};
gebian g[500000];
int gcnt=0;
int m,n,from,to;
void dfscv_init(){
	gcnt=0;
	t=0;
	for(int i=1;i<=n;i++){
		d[i]=0;
		low[i]=0;
		visited[i]=0;
		cutpoint[i]=0;
		children[i]=0;
	}
}
void DFSCV(int u,int parent){
    t++;
    d[u]=t;
    low[u]=d[u];
    visited[u]=1;
    for(int i=1;i<=n;i++){
	if(map[u][i]!=0){
		int v=i;
        if(visited[v]==0){
            children[u]++;
            DFSCV(v,u);
            low[u]=min(low[u],low[v]);
    if(d[u]<low[v]){
        gebian x;
        x.u=min(u,v);
        x.v=max(u,v);
        g[++gcnt]=x;
    }
        }
        else if(v!=parent)
            low[u]=min(low[u],d[v]);
	}
    }
}
int dfsvisited[2000];
void dfs(int x){
	dfsvisited[x]=1;
	for(int i=1;i<=1000;i++){
		if(map[x][i]!=0&&dfsvisited[i]==0)
			dfs(i);
	}
}
bool liantong(){
	int start;
	for(int i=1;i<=1000;i++)
		for(int j=1;j<=1000;j++){
			if(map[i][j]!=0){
				start=i;
				break;
			}
		}
	dfs(start);
	for(int i=1;i<=n;i++){
		if(dfsvisited[i]==0)
			return false;
	}
	return true;
}
bool notend(){
	for(int i=1;i<=1000;i++)
		if(edgenum[i]!=0)
			return true;
	return false;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>from>>to;
        map[from][to]++;
				map[to][from]++;
				edgenum[from]++;
				edgenum[to]++;
    }
    int jishudu=0;
		for(int i=1;i<=1000;i++){
			if(edgenum[i]%2==1)
				jishudu++;
		}
		if((jishudu!=2 && jishudu!=0)||liantong()==false){
			printf("0");
			return 0;
		}
	printf("1\n");
	int nodea=0;
		for(int i=1;i<=1000;i++){
			if(edgenum[i]%2==1){
				nodea=i;
			}
		}
	if(nodea==0)
		nodea=1;
	while(notend()==true){
		
						printf("%d ",nodea);
    dfscv_init(); 
    for(int i=1;i<=n;i++)
        if(visited[i]==0)
                DFSCV(i,-1);
    
	    int flag=0;
	    int ge=0;
    for(int i=1;i<=n;i++){
		if(map[nodea][i]!=0){
			ge=0; 
			for(int j=1;j<=gcnt;j++){
				if((g[j].u==i&&g[j].v==nodea)||(g[j].u==nodea&&g[j].v==i))
					ge=1;
			}
				if(ge==0){
					map[nodea][i]--;
					map[i][nodea]--;
					edgenum[i]--;
					edgenum[nodea]--;
					nodea=i;
					flag=1;
					break;
				}
		}
	}
	if(flag==0){
		for(int i=1;i<=n;i++){
			if(map[nodea][i]!=0){
				map[nodea][i]--;
				map[i][nodea]--;
				edgenum[i]--;
				edgenum[nodea]--;
				nodea=i;
				break;
			}
		}
	}
	}
	printf("%d",nodea);
    return 0;
} 
