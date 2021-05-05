#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void trans(int rest)
{
	int n3=0;
	int n2,n1;
	if(rest>=10000)
	{
    	if(rest>=100000000)
    	{
    		n3=rest/100000000;
    		n2=(rest%100000000)/10000;
    		n1=rest%10000;
    		printf("%d억%d만%d원",n3,n2,n1);
		}
    	else
    	{
    		n2=rest/10000;
    		n1=rest%10000;
    		printf("%d만%d원",n2,n1);
		}
		
    }
    else if(rest!=0)
    {
    	n3=rest/1000;
    	n2=(rest%1000)/100;
    	n1=(rest%100)/10;
		printf("%d천%d백%d원",n3,n2,n1); 
	}
    else if(rest==0)
    	printf("0원");
}
int main(){
    int money;
    int ok;
    int cho;
    int range;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n주식을 하면 생기는 일 0.1v\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n[제작 : 인성고 팩토리얼]\n");
	for(;cho!=1;)
	{
		printf("\n\n메뉴\n1 : 게임 시작\n2 : 게임 방법\n3 : 정보\n=> ");
		scanf("%d",&cho);
		if(cho==2)
			printf("\n\n자신의 자산에서 배팅 금액을 차감합니다. \n주사위를 굴려 각 25%의 확률로 배팅한 금액의 모두를 잃거나, 절반을 잃거나, 1.5배를 따거나, 2배를 딸 수 있고\n그 돈을 다시 보유 자산에 합계시킵니다.\n보유 자산이 1만원 미만이 되면 파산하여 게임오버가 됩니다.\n정해진 턴 안에 보유 자산이 20억을 초과하면 게임에서 승리합니다.\n(아 오버플로우때문에 21억 넘기면 안된다고ㅋㅋ)\n");
    	else if(cho==3)
    		printf("\n\n동아리 조원 : 정집인, 최준혁, 안준영\n21.03.18) 0.1v 배포\n");
    }
    printf("\n\n몇 턴 안에 승리하시겠습니까? (10턴 이상, 200턴 이하)\n=> ");
    for(ok=0;ok==0;){
    	scanf("%d",&range);
    	if(range>=10&&range<=200)
    		ok++;
    	else
    		printf("유효한 범위 내의 턴 수를 입력해주세요.\n=> ");
    }
  	printf("\n\n시작 금액을 입력하세요 (5억을 초과할 수 없습니다.)\n=> ");	
    for(ok=0;ok==0;)
    {
		scanf("%d원",&money); 
    	if(money<=500000000&&money>=10000)
    	{
    		ok++;
		}
		else if(money<10000)
			printf("보유 자산이 너무 적습니다. 1만원 이상을 입력해주십시오. \n=>");
		else
		    printf("최대 자산을 초과하였습니다. 다시 입력하세요.\n=>");
    }
    int bet;
    int ran;
    int tempb=0;
    int tempm;
    printf("현재 재산 : ");
    trans(money);
    srand(time(NULL));
    int i=1;
    for(;i<=range;i++){
    	tempm=money;
       	printf("\n\n================================\n\n<%d번째 배팅>\n\n배팅할 금액을 입력하시오(1만원 이상 10억 미만) \n(현재 자산 : ",i);
    	trans(money);
		printf(") => ");
		for(ok=0;ok==0;)
    	{
    		scanf("%d",&bet);
        	if(bet<=1000000000&&bet>=10000)
        	{
        		if(bet<=money)
            	{
                	ok++;
                	tempb=bet;
            	}
            	else
            	{	
					printf("자산이 부족합니다. (현재 재산 : ");
            	    trans(money);
					printf(")\n다시 입력 해주십시오 => ");
				}
			}
        	else
        		printf("범위에 맞도록 다시 입력해주십시오 = >"); 
        }        
        money-=bet;
        printf("==> 남은 현금 : ");
        trans(tempm);
        printf(" - ");
        trans(bet);
        printf(" = ");
        trans(money);
		printf("\n\n~~@~~@~~@~~@~~@~~@~~@~~@~~@~~@~~\n\n룰렛을 돌렸습니다!\n\n");
        ran=rand()%4;
        switch(ran){
            case 0:
                printf("모두 잃었습니다...\n=>");
                bet=0;
                break;
            case 1:
                printf("절반을 잃었습니다...\n=>");
                bet/=2;
                break;
            case 2:
                printf("1.5배로 불렸습니다!!\n=>");
                bet*=3;
                bet/=2;
                break;
            case 3:
                printf("2배를 받았습니다!!!!!\n=>");
                bet*=2;
                break;
        }
        printf("베팅 금액 : ");
        trans(tempb);
		printf(" ==> ");
		trans(bet);
		printf("\n\n현재 재산 : ");
		trans(money);
		printf(" + ");
		trans(bet);
		printf(" = ");
        money+=bet;
        trans(money);
        if(money<10000)
            break;
    }
    printf("\n\n===================================\n\n파산 하셨습니다ㅋㅋ");
}
