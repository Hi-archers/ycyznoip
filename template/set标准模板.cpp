#include <iostream>
#include <cstdio>
#include <stack>
#include <set>
using namespace std;
int m,x;
struct node
{
	int c;
	friend bool operator < (const node &a,const node &b)
	{
	return	a.c>b.c;
	}
}h[100];

int main()
{
	cin>>m;
	set<node>S;
	for(int i=1;i<=m;i++)
	 {
	 	cin>>h[i].c;
	 	S.insert(h[i]);
	 }
	for(set<node>::iterator i=S.begin();i!=S.end();i++)
	 {
	 	cout<<i->c<<" ";
}
	return 0;
}
