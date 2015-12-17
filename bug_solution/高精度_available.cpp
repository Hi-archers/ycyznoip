//201412丁宇笑 由201412颜佳伟和201413魏子豪共同纠错
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
class bigint
{
public:
	static const int BASE=100000000;
	static const int WIDTH=8;
	vector<int>s;
	
	bigint(long long num=0) { *this=num;}
	
	bigint operator = (long long num)
	{
		s.clear();
		do{
			s.push_back(num % BASE);
			num/=BASE;
		}while(num>0);
		return *this;
	}
	
	bigint operator = (const string& str)
	{
		s.clear();
		int x,len=(str.length()-1)/WIDTH+1;
		for(int i=0;i<len;i++)
		{
			int end = str.length()-i*WIDTH;
			int start = max(0,end-WIDTH);
			sscanf(str.substr(start, end-start).c_str(),"%d",&x);
			s.push_back(x);
		}
		return *this;
	}
	friend ostream& operator << (ostream &out, const bigint& x)
	{
		out<<x.s.back();
		for(int i=x.s.size()-2;i>=0;i--)
		{
			char buf[20];
			sprintf(buf, "%08d",x.s[i]);
			for(int j=0;j<strlen(buf);j++) out<<buf[j];
		}
		return out;
	}
	friend istream& operator >> (istream &in,bigint& x)
	{
		string s;
		if(!(in>>s)) return in;
		x=s;
		return in;
	}
	bigint operator + (const bigint& b) const 
	{
		bigint c;
		c.s.clear();
		for(int i=0,g=0;;i++)
		{
			if(g==0&&i>=s.size()&&i>=b.s.size()) break;
			int x=g;
			if(i<s.size()) x+=s[i];
			if(i<b.s.size()) x+=b.s[i];
			c.s.push_back(x % BASE);
			g=x/BASE;
		}
		return c;
	}
	
};

int main()
{
	bigint a,b,c;
	cin>>a>>b;
	c=a+b;
	cout<<c;
	return 0;
}
