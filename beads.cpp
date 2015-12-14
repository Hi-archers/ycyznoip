/*
	LANG:C++11
	PROG:beads
	USER:smallpa2
	By Jiangyi Liu
*/
#ifdef DEBUG
#include<iostream>
#else
#include<fstream>
#endif
#include<cstring>
using namespace std;
int len,maxn;
char beads[3000],btmp[3000];
int countF(char color,char* start,char* end);
int countB(char color,char* start,char* end);
int main(){
	#ifndef DEBUG
	ifstream cin("beads.in");
	ofstream cout("beads.out");
	#endif
	cin>>len;
	cin>>beads;
	memcpy(beads+len,beads,len);
	for(int i=0;i<len;i++){
		int j=i+len-1;
		memcpy(btmp,beads,len*3);
		int cfr=countF('r',btmp+i,btmp+j);
		int cbr=countB('r',btmp+j,btmp+i);

		memcpy(btmp,beads,len*3);
		int cfb=countF('b',btmp+i,btmp+j);
		int cbb=countB('b',btmp+j,btmp+i);

		memcpy(btmp,beads,len*3);
		int end1=max(cfr,cfb);
		int end2=max(cbr,cbb);
		maxn=max(maxn,end1+end2);
			
	}
	if(maxn<=len)
		cout<<maxn<<endl;
	else
		cout<<len<<endl;
}

int countF(char color,char* start,char* end){
	int num=0;
	for(char* ptr=start;ptr<=end;ptr++){
		if(*ptr==color || *ptr=='w'){
			num++;
			*ptr='d';
		}else
			break;
	}
	return num;
}
int countB(char color,char* start,char* end){
	int num=0;
	for(char* ptr=start;ptr>=end;ptr--){
		if(*ptr==color || *ptr=='w'){
			num++;
			*ptr='d';
		}
		else
			break;
	}
	return num;
}
