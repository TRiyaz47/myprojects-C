#include<stdio.h>
#include<conio.h>
#include<math.h>

int getlen_c(char a[])
{
int i;
for(i=0;a[i]!='\0';i++);
return i;
}

void prt_c(char *a)
{
int i,len_a;
for(i=0;a[i]!='\0';i++)
	printf("%c",a[i]);
}

char *d2b(int n)
{
	int i,temp;
	char a[50];
	temp=n;
	for(i=0;temp>=1;i++)
	{
		a[i]=temp%2;
		temp=temp/2;
		if(a[i]==1)
			a[i]=49;
		if(a[i]==0)
			a[i]==48;
	}
	a[i]='\0';
return a;
}

long b2d(char a[])
{
	int b[50],i,base=2,len_a;
	long temp,n=0,n1=0,n2=0;
	len_a=getlen_c(a);
	//Converting string into an array
	for(i=0;i<len_a;i++)
	{
		if(a[i]==48)
			b[i]=0;
		if(a[i]==49)
			b[i]=1;
	}
	//Calculating
	for(i=(len_a-1);i>=0;i--)
	{
		temp=pow(base,n);
		n2=(b[i]*temp);
		n1=n1+n2;
		n++;
	}
	return n1;
}

char *d2h(long num)
{
	int a[50],i,len_num;
	long temp;
	char b[50];
	temp=num;
	for(i=0;temp>10;i++)
		temp=temp/10;
	len_num=i;
	for(i=(len_num-1);num>15;i--)
	{
		a[i]=num%16;
		num=num/16;
	}
	a[i]=num;
	for(i=0;i<len_num;i++)
	{
		if(a[i]>=10)
			b[i]=a[i]+55;
		if(a[i]<10)
			b[i]=a[i]+48;
	}
	b[i]='\0';
	return b;
}

long h2d(char a[])
{
	int len_a,len_b,i,b[50],base=16,n=0;
	long n1=0,n2=0,temp;
	len_a=getlen_c(a);
	len_b=len_a;

	for(i=0;i<len_a;i++)
	{
		if(a[i]>=65)    //Character
			b[i]=a[i]-55;
		else           //Numbers
			b[i]=a[i]-48;
	}
	for(i=(len_b-1);i>=0;i--)
	{
		temp=pow(base,n);
		n2=b[i]*temp;
		n1=n1+n2;
		n++;
	}
	return n1;
}

void main()
{
clrscr();
char a[50]="1010111100010000";
long num;
num=b2d(a);
printf("\nnum=%ld",num);

getch();
}
