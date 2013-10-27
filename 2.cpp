#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#define MIN(x,y) (x)<(y)?(x):(y)
using namespace std;

const int N=1010;

void fun(unsigned long long n,unsigned long long &p,unsigned long long &q)
{
	p = q = 1;
	int num[100];
	memset(num,0,sizeof(num));
	
	int ct = 0;
	while(n)
	{
		num[ct++] = n&1;
		n >>= 1;
	}
	for(; num[ct]==0; ct--) ;
	ct--;
	for( ; ct>=0; ct--)
	{
		if(num[ct])
		{
			p += q;
		}
		else
		{
			q += p;
		}
	}
}

void fun2(unsigned long long &n,unsigned long long p,unsigned long long q)
{
	n = 0;
	unsigned long long tmp = 1;
	while(p!=1 || q!=1)
	{
		if(p<q)
		{
			q -= p;
		}
		else
		{
			n |= tmp;
			p -= q;
		}
		tmp <<= 1;
	}
	n |= tmp;
} 

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	for(int cnt=1;cnt<=t;cnt++)
	{
		int type;
		scanf("%d",&type);
		
		unsigned long long n,p,q;
		
		if(type == 1)
		{
			scanf("%llu",&n);
			
			fun(n,p,q);
			
			printf("Case #%d: %llu %llu\n",cnt,p,q);
		}
		
		else
		{
			scanf("%llu%llu",&p,&q);
			fun2(n,p,q);
			printf("Case #%d: %llu\n",cnt,n);
		}
		
	} 
} 
