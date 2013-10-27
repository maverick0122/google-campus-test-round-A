#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#define MIN(x,y) (x)<(y)?(x):(y)
using namespace std;

const int N=110;
string single[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
string many[11] = {"","","double","triple","quadruple","quintuple","sextuple","septuple","octuple","nonuple","decuple"};

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	for(int cnt=1;cnt<=t;cnt++)
	{
		char num[N];
		char format_s[3*N];
		int format[N];
		string ans = "";
		
		scanf("%s%s",num,format_s);
		
		memset(format,0,sizeof(format));
		
		char *tmp = strtok(format_s,"-");
		int i,j,k;
		for(i=0; tmp; i++)
		{
			format[i] = atoi(tmp);
			//cout<<format[i]<<endl;
			tmp = strtok(NULL,"-");
		}
		
		int n = i;
		int sum = 0;
		for(i=0; i<n; i++)
		{
			char now = 0;
			int ct = 0;
			
			for(j=0; j<format[i]; j++)
			{
				if(now==0 || num[sum+j-1] != num[sum+j])
				{
					if(now>0)
					{
						if(ct>1 && ct<11)
						{
							ans += many[ct];
							ans += " ";
							ans += single[now-'0'];
							ans += " ";
						}
						else
						{
							for(k=0; k<ct; k++)
							{
								ans += single[now-'0'];
								ans += " ";
							}
						}
					}
					now = num[sum+j];
					ct = 1;
				}
				else
				{
					ct++;
				}
			}
			if(now>0)
			{
				if(ct>1 && ct<11)
				{
					ans += many[ct];
					ans += " ";
					ans += single[now-'0'];
					ans += " ";
				}
				else
				{
					for(k=0; k<ct; k++)
					{
						ans += single[now-'0'];
						ans += " ";
					}
				}
			}
			
			sum += format[i];
		}
		if(ans[ans.length()-1] == ' ')
		{
			ans = ans.substr(0,ans.length()-1);
		}
		
		printf("Case #%d: %s\n",cnt,ans.c_str());
	} 
} 
