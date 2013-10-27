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


int cmpin(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}

int cmpde(const void *a, const void *b)
{
	return *(int*)b-*(int*)a;
}

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	for(int cnt=1;cnt<=t;cnt++)
	{
		int n;
		scanf("%d",&n);
		
		int odd[N],even[N],cntodd,cnteven;
		cntodd = cnteven = 0;
		bool iseven[N];
		
		for(int i=0; i<n; i++)
		{
			int tmp;
			scanf("%d",&tmp);
			
			if(tmp%2 == 0)
			{
				even[cnteven] = tmp;
				cnteven++;
				iseven[i] = 1;
			}
			else
			{
				odd[cntodd] = tmp;
				cntodd++;
				iseven[i] = 0;
			}
		}
		
		qsort(even,cnteven,sizeof(int),cmpde);
		qsort(odd,cntodd,sizeof(int),cmpin);
		
		printf("Case #%d: ",cnt);
		
		for(int i=0,j=0,k=0; i<n; i++)
		{
			if(iseven[i])
			{
				printf("%d",even[j++]);
			}
			else
			{
				printf("%d",odd[k++]); 
			}
			if(i!=n-1)
				printf(" ");
		}
		printf("\n");
	} 
} 
