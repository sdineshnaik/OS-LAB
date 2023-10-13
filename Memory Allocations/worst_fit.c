#include<stdio.h>
#define MAX 20
void main()
{
	int i,j,bs[MAX],b,f,fs[MAX],frag[MAX],temp,heighest=0;
	static int bf[MAX],ff[MAX];
	printf("MEMORY ALLOCATION METHOD - Worst FIT\n");
	printf("Enter the no of Blocks:");
	scanf("%d",&b);
	printf("Enter the no of Files");
	scanf("%d",&f);
	for(i=1;i<=b;i++){
		printf("Enter the Block Size %d:",i);
		scanf("%d",&bs[i]);
		bf[i]=0;
	}
	for(i=1;i<=f;i++){
		printf("Enter the File size of %d:",i);
		scanf("%d",&fs[i]);
	}
	for(i=1;i<=f;i++)
	{
		for(j=1;j<=b;j++)
		{
			if(bf[j]!=1)
			{
				temp=bs[j]-fs[i];
				if(temp>=0)
				{
					if(heighest<temp){
					
						ff[i]=j;
						heighest=temp;
					}
				}
			}
		}
		frag[i]=heighest;
		bf[ff[i]]=1;
		heighest=0;
	}
	printf("\n%d---%d",bs[1],frag[1]);
	printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
	for(i=1;i<=f;i++)
	{
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,fs[i],ff[i],bs[ff[i]],frag[i]);
	}
}
