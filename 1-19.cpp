#include <stdio.h>
#define MAXIUM 1000

int reverse(char input[]);

int main()
{
	char input[MAXIUM];
	int end;
	
	while((end=reverse(input))!=0)
		printf("%s",input);
	
	return 0;
}

int reverse(char input[])
{
	int len,i,n;
	char output[MAXIUM],c;
	
	for(len=0;(c=getchar())!=EOF&&c!='\n'&&len<MAXIUM-1;++len)
		input[len]=c;
	
	n=len-1;
	for(i=0;i<len;++i)
	{
		output[i]=input[n];
		n--;
	}
	
	for (i=0;i<len;++i)
		input[i]=output[i];
	
	input[i]='\n';
	input[i+i]='\0';
	for(++i;i<=MAXIUM;++i)
		input[i]=0;
	
	if(c=='\n')
		++len;
	
	return len;
}
