#include <stdio.h>

#define MAXIUM 1000

int len(char input[], int limit);
void output(char inputn[],char out[],int lc, int chrs);
int emp(char inputt[], int limitt);

int main()
{
	int empty;
	int length,outcount=0;
	char line[MAXIUM],outline[MAXIUM];
	empty=0;
	
	while((empty=emp(line,MAXIUM)!=1))
	{
		length = len(line,MAXIUM);
		if(length > 5)
		{
			++outcount;
			output(line,outline,outcount,length);
		}
	}
	
	if(outcount > 0)
		printf("%s",outline);
		
	return 0;
}

int len(char input[], int lim)
{
	char c;
	int i;
	
	for(i=0;i<lim-1&&(c=getchar())!=EOF&&c!='\n';++i)
		input[i]=c;
		
	if(c=='\n')
	{
		input[i]=c;
		input[i++]='\0';
	}
	else if(c!=EOF)
	{
		int n=i;
		for(i-=3;i<n;++i)
		{
			input[i]='.';
		}
		input[i]='\n';
		i++;
		input[i]='\0';
		for(i--;(c=getchar())!='\n';++i)
			;
	}
	
	return i;
}

int emp(char inputt[], int limitt)
{
	int empty=0;
	char c=getchar();
	int i;

	if(c==EOF)
		empty=1;
		
	return empty;
}

void output(char inputn[],char out[],int lc, int chrs)
{
	int i=0,n=0;
	for(i=(lc-1)*(chrs+1);i<n*(lc+1);++i)
		for(n=0;n<chrs;++n)
			out[i]=inputn[n];
	
	out[i]='\n';
	out[++i]='\0';
}
