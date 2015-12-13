#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
char a;
bool f;
int w,h,j,i;
int main()
{
	cin>>h>>w>>a>>f;
	if(f==true)
	{
		while(j<h)
		{
			for(i=1;i<=w;i++)
			{
				cout<<a;
			}
			j++;
			cout<<endl;
		}
	}
	else if(f==false)
	{
		for(i=1;i<=w;i++)
		{
			cout<<a;
		}
		cout<<endl;
		while(j<h-2)
		{
			cout<<a;
			for(i=1;i<=w-2;i++)
			{
				cout<<" ";
			}
			cout<<a<<endl;
			j++;
		}
		for(i=1;i<=w;i++)
		{
			cout<<a;
		}
	}
	return 0;
}
