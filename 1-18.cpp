#include <stdio.h>

#define MAXIUM 1000

int tc(char input[],int nc);
int len(char input[],int limit);
int outputl(char input[],char output[],int ochrs,int nchrs);
int emp(char input[],int nc);

int main()
{
	int oldchrs,newchrs,empty,count;
	char input[MAXIUM],output[MAXIUM];
	
	oldchrs=newchrs=empty=count=0;
	
	while((newchrs=len(input,MAXIUM))!=0)
	{
		if((empty=emp(input,newchrs))!=1)
		{
			newchrs=tc(input,newchrs);
		//	printf("empty:%d\n",empty);
			oldchrs=outputl(input,output,oldchrs,newchrs);
			++count;
		//	printf("count:%d",count);
		//	printf("oldchrs:%d;nchrs:%d\n",oldchrs,newchrs);
		}
	}
	
	if(count!=0)
	{
		printf("%s",output);
	}
	else
		printf("nothing here");
	
	return 0;
}

int len(char input[],int lim)
{
	int i;
	char c;
	
	for(i=0;i<(lim-1)&&(c=getchar())!=EOF&&c!='\n';++i)
		input[i]=c;
		
	if(c=='\n')
	{
		input[i]=c;
		++i;
	}
	
	return i;
}

int emp(char input[],int nc)
{
	char c;
	int bv,i;
	
	for(nc-=2;(input[nc]==' '||input[nc]=='\t')&&nc>=0;nc=nc-1)
		;
	
	if(nc<0)
		bv=1;
	else
		bv=0;
	
	return bv;
}

int tc(char input[],int nc)
{
	char c;
	int bv,i;
	
	for(nc-=2;(input[nc]==' '||input[nc]=='\t')&&nc>=0;)
	{
		input[nc]=input[nc+1];
		input[nc+1]=0;
		nc=nc-1;
	//	printf("%d\n",nc);
	}
	
	nc+=2;
	
	return nc;
}

int outputl(char input[],char output[],int oc,int nc)
{
	int i,n;
	n=0;
	i=oc;
//	printf("iold:%d\n",i);
//	printf("input:%s\n",input);
	for(;i<(oc+nc);++i)
	{
		output[i]=input[n];
		++n;
	}
//	printf("output:%s",output);
	oc=oc+nc;
//	printf("i:%d\n",i);
	
	output[i]='\0';
	
	return oc;
}
