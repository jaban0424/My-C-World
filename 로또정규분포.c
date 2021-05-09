#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define T 100000

int main(){
	printf("시행횟수 입력 후 이 글씨가 매우 작아질 때 까지 컨트롤+스크롤 다운 한 후에 엔터를 치시오.\n(적정값 : 100,000 : 약 25초 소요)\n==>");
	int s;
	scanf("%d",&s);
	int i,j;
	int how[270];
	int sum[T+1];
	for(i=0;i<T;i++)
		sum[i]=0;
		
	for(i=0;i<270;i++)
		how[i]=0;
	//int num[7]; 보류  
	int ran;
	for(i=0;i<T;i++)
	{
		for(j=0;j<6;j++)
		{
			//ran=time(NULL)%45+1;
			ran=rand()%45+1;
			sum[i]+=ran;
		}
	}
	for(i=0;i<T;i++)
		printf("%d ",sum[i]);
	for(i=0;i<T;i++)
		how[sum[i]]++;
	for(i=0;i<270;i++)
		printf("%d은 %d번 나왔습니다.\n",i+1,how[i]);
	for(i=0;i<270;i++)
	{
		printf("%d : ",i+1);
		for(j=0;j<how[i]/(T/10000);j++)
			printf("*");
		printf("\n");
	}
	
	char ret;
RE:
	printf("프로그램을 종료하시겠습니까? (y/n) => ");
	scanf("%c",&ret);
	if(ret='y')
		return 0;
	else 
		goto RE;
	}
