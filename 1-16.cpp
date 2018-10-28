#include <stdio.h>
#define MAXIUM 1000

int len(char input[], int mchrs);
void trans(char input[],char output[]);
void output(int maxcharacters, int samelines, char output[], char inputold[], char inputnew[]);

int main()
{
	int chrs, mchrs=0,sline=0;
	char line[MAXIUM] ,outline[MAXIUM];
	int linecount=1;
	
	printf("About the Program :\n\n");
	printf("Type a sentence and you will know the length\n");
	printf("You can also find out the longest ones\n");
	printf("Type Ctrl+Z to finish entering\n\n");
	
	while((chrs=len(line,MAXIUM))!=0)
	{
		printf("line %d , characters %d\n",linecount,chrs-1);
		++linecount;
		
		if(chrs > mchrs)
		{
			sline=0;
			mchrs=chrs;
			
			trans(line,outline);
		 } 
		 else if(chrs == mchrs)
		 {
		 	++sline;
		 	
		 	output(mchrs,sline,outline,outline,line);
		 }
	} 
	if( mchrs > 0)
		printf("The Longest line(s) is : \n%swith %d characters",outline,mchrs-1);
	
	return 0;
 } 
 
 int len(char input[],int limit)
 {
 	int c,i;
 	
 	for (i=0;i<(limit-1)&&(c=getchar())!=EOF&&c!='\n';++i)
 		input[i] = c;
 	
 	if(c=='\n')
 	{
 		input[i]=c;
 		++i;
	}
	 
	input[i]='\0';
	
	return i;
 }
 
 void trans(char input[], char output[])
 {
 	int i=0;
 	
 	while((output[i]=input[i])!='\0')
 		++i;
 }
 
 void output(int mchrs, int sline, char output[], char inputo[], char inputn[])
 {
 	int i;
 	
 	for (i=0;i<=mchrs*sline;++i)
 		output[i] = inputo[i];
 	i--;
 	
 	int n;
 	
 	for (n=0;n<=mchrs;++n)
 		output[i+n] = inputn[n];
 	
 	i=mchrs*(sline+1)+1;
 	output[i] = '\0';
 }
