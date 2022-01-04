//统计字符数

#include<stdio.h>
#include<string.h>
int main()
{
	int s[26],i,max;
	char str[1001];
	scanf("%s",str);
	for(i=0;i<26;i++)
		{
			s[i]=0;
		}
	for(i=0;i<strlen(str);i++)
		{
			s[str[i]-'a']++;
		}
	max=0;
	for(i=1;i<26;i++)
		{
			if(s[i]>s[max])
				{
					max=i;
				}
		}
	printf("%c %d",max+'a',s[max]);
	return 0;
}

//鞍点

#include<stdio.h>

#define N 5

int a[N][N];
int max[N],min[N];

int main()
{
	int i,j;
	for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
				{
					scanf("%d",&a[i][j]);
				}
		}
	for(i=0;i<N;i++)
		{
			max[i]=-1;
			min[i]= ~((unsigned int)0)>>1;
		}
	for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
				{
					if(a[i][j]>max[i])
						max[i]=a[i][j];
					if(a[i][j]<min[j])
						min[j]=a[i][j];
				}
		}
	int flag=1;
	for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
				{
					if(max[i]==min[j])
						{
							flag=0;
							printf("%d %d %d\n",i+1,j+1,max[i]);
							break;
						}
					
				}
		}
	if(flag)
		printf("not found");
	return 0;
}

//斐波那契

#include<stdio.h>

int fib(int m)
{
	if(m==1)
		return 0;
	if(m==2||m==3)
		return 1;
	int a=1,b=1,aw=0;
	while(m>=3)
		{
			aw=aw+a;
			a=b;
			b=aw;
			m=m-1;
		}
	return aw;
} 

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",fib(n));
	return 0;
}


//P型编码

#include<stdio.h>
#include<string.h>
int n,l;
char ch[3000],cn;
int main()
{
	scanf("%s",&ch);
	l=strlen(ch);
	for(int i=0;i<l;)
		{
			cn=ch[i];n=0;
			while(ch[i]==cn) {i++;n++;}
			printf("%d%c",n,cn);
		}
	printf("\n");
	return 0;
}

//2的n次方

#include<stdio.h>
int a[100000];
int main()
{
	int n=0;
	scanf("%d",&n);
	a[1]=1;
	int k = 1;
	for(int i = 1; i <= n; ++i)
		{
			int x=0;
			for(int j = 1; j  <=k; ++j)
				{
					a[j] = a[j]*2+x;
					x = a[j]/10;
					a[j] = a[j]%10;
					if(x!=0 && j==k) k++;
				}
		}
	for(int i = k; i >= 1; --i) printf("%d",a[i]); 
	return 0;
}

//n阶乘

#include<stdio.h>
int a[100000];
int main()
{
	int n=0,l=1;
	scanf("%d",&n);
	a[0]=0; 
	a[1]=1;
	for(int i = 1;  i <= n; ++i)
		{
			for(int j = 1; j <= l; ++j)
				{
					a[j] = a[j]*i;
					a[j] = a[j-1]/10+a[j];
					a[j-1] = a[j-1]%10;
					if(a[j]>=10 && j >= l) l++;
				}
		}
	for(int i = l; i >= 1; --i)
		printf("%d",a[i]);
	return 0;
}

//奇数单增

#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a,b[500],t=0,count=0;
	int i,j=0;
	
	for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(a%2!=0)
				{
					b[j]=a;
					j++;
					count++;
				}
		}
	
	for(i=0;i<j-1;i++)
		{
			int c=0,d=0;
			for(c=0;c<j-i-1;c++)
				{
					if(b[c]>b[c+1])
						{
							t=b[c];
							b[c]=b[c+1];
							b[c+1]=t;
						}
				}
		}
	
	if(j==1)	printf("%d",b[0]);
	else
		{
			for(i=0;i<j-1;i++)
				{
					printf("%d,",b[i]);
				}
			printf("%d",b[count-1]);
		}
	
	return 0;
}

//同行列对角线

#include <stdio.h>
int main()
{
	int N,m,n;
	int i,j,k;
	scanf("%d%d%d", &N,&m,&n);
	if(n>=1 && n<=N && m>=1 && m<=N)
		{
			for(k=1;k<=N;k++)
				{
					printf("(%d,%d) ",m,k);
				}
			printf("\n");
			for(j=1;j<=N;j++)
				{
					printf("(%d,%d) ",j,n);
				}
			printf("\n");
			for(i=1;i<=N;i++)
				{
					for(j=1;j<=N;j++)
						{
							if((j-i) == (m-n))
								printf("(%d,%d) ", j,i);
						}
				}
			printf("\n");
			for(i=N;i>=1;i--)
				{
					for(j=N;j>=1;j--)
						{
							if((j+i) == (m+n))
								printf("(%d,%d) ", i,j);
						}
				}
		}
	return 0;
}

//幂的末尾

#include<stdio.h>
int swap(int a, int b)
{
	int t;
	t=a;
	a=b;
	b=t;
}
int main()
{
	int a,b,x=1,i;
	scanf("%d %d",&a,&b);
	for(i=1;i<=b;i++)
		{
			x*=a;
			x%=1000;
		}
	if(x<10)
		{
			printf("00%d",x);
		}
	else if(x<100)
		{
			printf("0%d",x);
		}
	else
		{
			printf("%d",x);
		}
	return 0;
}

//质数和与积

#include<stdio.h>
#include<math.h>
int isPrime(int a)
{
	if(a==2)	return 1;
	for(int i=2;i<=sqrt(a);i++)
		{
			if(a%i==0)
				{
					return 0;
				}
		}
	return 1;
}
int main()
{
	int s,i,x,m=0;
	scanf("%d",&s);
	for(i=s/2;i>=2;i--)
		{
			if(isPrime(i)&&isPrime(s-i))
				{
					x=(i*(s-i));
					if(x>m)
						{
							m=x;
						}
				}
		}
	printf("%d",m);
	return 0;
}

//f(x,n)

#include<stdio.h>
double re(double x,double n)
{
	if(n==1)
		return x/(1+x);
	else
		return x/(n+re(x,n-1));
}
int main()
{
	double x,n,f;
	scanf("%lf %lf",&x,&n);
	f=re(x,n);
	printf("%.2lf",f);
	return 0;
}

//单词排序

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
	char words[101][52]={0};
	int i,cnt=0,j,k;
	char word[5100];
	char buff[52];
	i=0;j=0,k=0;
	gets(word);
	char*token=strtok(word," ");
	while(token!=NULL)
		{
			strcpy(words[i],token);
			token=strtok(NULL," ");
			cnt++;
			i++;
		}
	for(i = 0; i < cnt-1; i++)
		{
			j = i;
			for(k = i + 1; k < cnt; k++)
				if(strcmp(words[j], words[k]) > 0)
				j = k;
			if (j != i) 
				{
					strcpy(buff, words[i]);
					strcpy(words[i], words[j]);
					strcpy(words[j], buff);
				}
		}
	for(i = 0; i < cnt; i++)
		{
			if(strcmp(words[i], words[i+1])==0)
				{
					continue;
				}
			if(i!=cnt-1)
				puts(words[i]);
			else
				printf("%s",words[i]);
		}
	
	return 0;
}

//Pell数列

#include <stdio.h>

#define MOD 32767
#define N 1000000
int pell[N+1];

void makePell(int n)
{
	int i;
	
	pell[1] = 1;
	pell[2] = 2;
	
	for(i=3; i<=n; i++)
		pell[i] = (2 * pell[i - 1] + pell[i - 2]) % MOD;
}

int main(void)
{
	int n, i;
	
	makePell(N);
	scanf("%d", &n);
	while(n--) 
		{
			scanf("%d", &i);
			
			printf("%d\n", pell[i]);
		}
	return 0;
}

//大整数+

#include<stdio.h>
#include<string.h>
#define BASE 10
#define N 200
char a[N+1],b[N+1] ;
char ans[N+1];
int main(){
	int anslen,carry,len,i,j;
	scanf("%s",a);
	scanf("%s",b);
	memset(ans,0,sizeof(ans));
	anslen=len=strlen(a);
	for(i=len-1,j=0;i>=0;i--)
		ans[j++]=a[i]-'0';
	len=strlen(b);
	if(len>anslen)
		anslen=len;
	carry=0;
	for(i=len-1,j=0;i>=0;i--,j++)
		{
			ans[j]+=b[i]-'0'+carry;
			carry=ans[j]/BASE;
			ans[j]%=BASE;
		} 
	while(carry>0){
		ans[j]+=carry;
		carry=ans[j]/BASE;
		a[j++]%=BASE;
	}
	if(j>anslen)
		anslen=j; 
	for(i=anslen-1;i>=0;i--)
		if(ans[i])  
		break;
	if(i<0)
		i=0;
	for(;i>=0;i--)
		printf("%d",ans[i]);
	printf("\n");
	return 0;
}

//大整数-

#include<stdio.h>
#include<string.h>
int main()
{
	int  i,j,str1,str2,k=0;
	int  a1[255],a2[255],a3[255];
	char c1[255],c2[255];
	
	for(i=0;i<255;i++)
		{
			a1[i]=0;
			a2[i]=0;
		}
	
	scanf("%s",c1);
	scanf("%s",c2);
	
	
	str1=strlen(c1);
	str2=strlen(c2);
	
	j=0;
	for(i=str1-1;i>=0;i--)
		a1[j++]=c1[i]-'0';
	
	j=0;
	for(i=str2-1;i>=0;i--)
		a2[j++]=c2[i]-'0';
	
	for(i=0;i<255;i++)
		{
			a1[i]-=a2[i];
			if(a1[i]<0)
				{
					a1[i]+=10;
					a1[i+1]--;
				}
		}
	
	j=0;
	for(i=254;i>=0;i--)
		a3[j++]=a1[i];
	
	for(i=0;i<255;i++)
		{
			if(a3[i]!=0)   k=1;
			if(k==1)   printf("%d",a3[i]);
		}
	if(k==0)  printf("0");
	printf("\n");
	return 0;
	
}

//大整数因子

#include<stdio.h>
#include<string.h>
char a1[35];
int a[35],c[35];
int x;
int flag = 0;
int main()
{
	gets(a1);
	int n = strlen(a1);
	for(int i = 0; i < n; ++i)
		a[i] = a1[i]-'0';	 
	for(int k = 2; k <= 9; ++k)
		{
			x = 0;//新的被除数 
			for(int i = 0; i < n; ++i)
				{
					x = x*10+a[i];
					x = x%k;
				}
			if(x==0) 
				{
					flag = 1;
					printf("%d ",k);
				}
		}
	if(flag==0) 
		printf("none");
	return 0;
}

//猴子选大王

#include<stdio.h>
int main()
{
	int i,n,m,a[10000],j,q=1;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		a[i]=i;
	for(i=1;i<=n-1;i++)
		{	
			q=q+m-1;
			if(q>=n-i+2&&q<2*(n-i+2)-1)
				q=q-(n-i+1);
			else if(q>=2*(n-i+2)-1)
				{
					int k=(q-1)/(n-i+1);
					q=q-k*(n-i+1);
				}
			for(j=q;j<=n-i+1;j++)
				a[j]=a[j+1];
			if(q==n-i+1)
				q=1;
		}
	printf("%d",a[1]);
	return 0;
}

//e的值

#include<stdio.h> 
int main()
{
	double n,i,j,sum=0,c=1;
	scanf("%lf",&n);
	for(i=1;i<=n;i++)
		{
			for(j=0;j<i;j++)
				{
					c=c*(i-j);
				}
			sum=sum+1/c;
			c=1;
		}
	printf("%.10f",sum+1);
	return 0;
}

//第n小质数

#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,k=0,n;
	scanf("%d",&n);
	for(i=2; ;i++)
		{
			for(j=2;j<=sqrt(i);j++)
				{
					if(i%j==0)
						break;
				}
			if(j>sqrt(i))
				k++;
			if(k==n)
				break;
		}
	printf("%d\n",i);
	return 0;
}

//冒泡
#include<stdio.h>

void bubble51(int a[],int n)
{
	int i,t;
	for(i=0; i<n-1; i++)
		{
			for(int j=0; j<n-1; j++)
				if(a[j]<a[j+1])
					{
						t=a[j];
						a[j]=a[j+1];
						a[j+1]=t;
					}
		}
}
void bubble15(int a[],int n)
{
	int i,t;
	for(i=0; i<n-1; i++)
		{
			for(int j=0; j<n-1; j++)
				if(a[j]>a[j+1])
					{
						t=a[j];
						a[j]=a[j+1];
						a[j+1]=t;
					}
		}
}

int main()
{
	int a[5];
	for(int i=0;i<5;i++)
		{
			scanf("%d",&a[i]);
		}
	bubble15(a,5);
	for(int i=0;i<5;i++)
		{
			printf("%d",a[i]);
		}
	return 0;
}
