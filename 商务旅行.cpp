/*
codevs 1036
ID:WZH
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN=30005,MAXD=20;

int n,u,v,m,sum;
int anc[MAXN][MAXD+10],deep[MAXN];

struct node *head[MAXN];
struct node
{
	inline void add(int u,int v)
	{
		node *p=new node;
		p->next=head[u];
		head[u]=p;
		p->u=u;
		p->v=v;
	}
	int u;
	int v;
	node *next;
};

void init()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	 {
	 	scanf("%d%d",&u,&v);
	 	head[u]->add(u,v);
	 	head[v]->add(v,u);
	 }
}

void dfs(int u,int k)
{
	deep[u]=k;
	for(int i=1;i<=20;i++)
	anc[u][i]=anc[ anc[u][i-1] ][i-1];
	for(node *p=head[u];p!=NULL;p=p->next)
	 {
	 	if(!deep[p->v])
	 	 {
	 	anc[p->v][0]=u;
		dfs(p->v,k+1);	
		 }
	 }
}

void swim(int &x,int h)
{
	for(int i=0;h>0;i++)
     {
     	if(h&1) x=anc[x][i];
     	h>>=1;
	 }
}
/*inline void swap(int &x,int &y)
{
	int t;
	t=x;x=y;y=t;
}*/
int lca(int u,int v)
{
	if(deep[v]>deep[u]) swap(u,v);
	swim(u,deep[u]-deep[v]);
	if(u==v) return u;
	while(1)
      {
      	int i;
      	for(i=0; anc[u][i] != anc[v][i];i++);
      	if(i==0) return anc[u][0];
      	u=anc[u][i-1];
      	v=anc[v][i-1];
	  }
	return -1;
}

int main()
{
	//int a,b;
	//cin>>a>>b;
	//swap(a,b);
	//cout<<a<<" "<<b;	
	init();
    
	for(int i=0;i<=MAXD;i++) anc[1][i]=1;
	dfs(1,1);
	scanf("%d%d",&m,&u);
	for(int i=1;i<m;i++)
	 {
	 	scanf("%d",&v);
	 	int dis=lca(u,v);
	 	sum+=deep[u]+deep[v]-2*deep[dis];
	 	u=v;
	 }
	printf("%d\n",sum);
	return 0;
}
