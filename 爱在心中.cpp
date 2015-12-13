#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <stack>
#include <map>
const int maxn=11005;   //点 
const int maxx=1100;    //边 
using namespace std;

inline int min(int a,int b){if(a>b)return b;return a;}        //使用内联自己写的函数判断大小效率提高三倍 
inline int max(int a,int b){if(a<b)return b;return a;}

int dfn[maxx],low[maxx],sccno[maxx];           

bool vis[maxx],flag[maxx][maxx];            

int dfs_clock,scc_cnt,n,m,u,v,ans,num[maxx],k;   //scc_cnt 是强联通分量的编号   sccno属于那个强联通分量 

stack<int> s;

struct node *head[maxn];

struct node
{
	int u;
	int v;
	node *next;
	inline void add(int u,int v)
	{
		node *p=new node;
		p->u=u;
		p->v=v;
		p->next=head[u];
		head[u]=p;
	}
};

void tarjan(int u)
{
	vis[u]=true;
	dfn[u]=low[u]=++dfs_clock;
	s.push(u);
	 for(node *p=head[u];p!=NULL;p=p->next)
	  {
	    if(!vis[p->v])
	     {
	     	tarjan(p->v);
	     	low[u]=min(low[p->v],low[u]);
		 }
		else if(!sccno[p->v])
		 {
		 	low[u]=min(low[u],dfn[p->v]);
		 }
	  }
	if(low[u]==dfn[u])
	 {
	 	scc_cnt++;
	  for(;;)
	 	  {
	 	int x=s.top();s.pop();
		 sccno[x]=scc_cnt;
		 num[scc_cnt]++;
		if(x==u) break;
		  }
		if(num[scc_cnt]==1) k++;
	 }
}

void init()
{
	scanf("%d%d",&n,&m);
	 for(int i=1;i<=m;i++)
	  {
	  	scanf("%d%d",&u,&v);
	  	head[u]->add(u,v);
	  }
}

void outit(int k)
{
	for(int i=1;i<=n;i++)
	 if(sccno[i]==k) printf("%d ",i);
	printf("\n");
}
void love()
{
	for(int i=1;i<=n;i++)
	 for(node *p=head[i];p!=NULL;p=p->next) 
	    flag[sccno[p->u]][sccno[p->v]]=true; 
	
	for(int k=1;k<=scc_cnt;k++)    //传递闭包 
	 for(int i=1;i<=scc_cnt;i++)  
	  for(int j=1;j<=scc_cnt;j++)
	   if(flag[i][k]&&flag[k][j])  flag[i][j]=true;
	   
	for(int i=1;i<=scc_cnt;i++)
	 if(num[i]>1)
	 {
	 	int k=i;
	 	for(int j=1;j<=scc_cnt;j++)
	 	 if(i!=j && ! flag[j][i]) {k=0;break;}
	 	if(k) {outit(k);return;}
	 }
	 printf("%d\n",-1);
}
int main()
{
	init();
	for(int i=1;i<=n;i++)
	 if(!vis[i]) tarjan(i);
	 
	printf("%d\n",scc_cnt-k);
	
	love();
	return 0;
}
