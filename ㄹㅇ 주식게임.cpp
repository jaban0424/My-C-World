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
    		printf("%d��%d��%d��",n3,n2,n1);
		}
    	else
    	{
    		n2=rest/10000;
    		n1=rest%10000;
    		printf("%d��%d��",n2,n1);
		}
		
    }
    else if(rest!=0)
    {
    	n3=rest/1000;
    	n2=(rest%1000)/100;
    	n1=(rest%100)/10;
		printf("%dõ%d��%d��",n3,n2,n1); 
	}
    else if(rest==0)
    	printf("0��");
}
int main(){
    int money;
    int ok;
    int cho;
    int range;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n�ֽ��� �ϸ� ����� �� 0.1v\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n[���� : �μ��� ���丮��]\n");
	for(;cho!=1;)
	{
		printf("\n\n�޴�\n1 : ���� ����\n2 : ���� ���\n3 : ����\n=> ");
		scanf("%d",&cho);
		if(cho==2)
			printf("\n\n�ڽ��� �ڻ꿡�� ���� �ݾ��� �����մϴ�. \n�ֻ����� ���� �� 25%�� Ȯ���� ������ �ݾ��� ��θ� �Ұų�, ������ �Ұų�, 1.5�踦 ���ų�, 2�踦 �� �� �ְ�\n�� ���� �ٽ� ���� �ڻ꿡 �հ��ŵ�ϴ�.\n���� �ڻ��� 1���� �̸��� �Ǹ� �Ļ��Ͽ� ���ӿ����� �˴ϴ�.\n������ �� �ȿ� ���� �ڻ��� 20���� �ʰ��ϸ� ���ӿ��� �¸��մϴ�.\n(�� �����÷ο춧���� 21�� �ѱ�� �ȵȴٰ���)\n");
    	else if(cho==3)
    		printf("\n\n���Ƹ� ���� : ������, ������, ���ؿ�\n21.03.18) 0.1v ����\n");
    }
    printf("\n\n�� �� �ȿ� �¸��Ͻðڽ��ϱ�? (10�� �̻�, 200�� ����)\n=> ");
    for(ok=0;ok==0;){
    	scanf("%d",&range);
    	if(range>=10&&range<=200)
    		ok++;
    	else
    		printf("��ȿ�� ���� ���� �� ���� �Է����ּ���.\n=> ");
    }
  	printf("\n\n���� �ݾ��� �Է��ϼ��� (5���� �ʰ��� �� �����ϴ�.)\n=> ");	
    for(ok=0;ok==0;)
    {
		scanf("%d��",&money); 
    	if(money<=500000000&&money>=10000)
    	{
    		ok++;
		}
		else if(money<10000)
			printf("���� �ڻ��� �ʹ� �����ϴ�. 1���� �̻��� �Է����ֽʽÿ�. \n=>");
		else
		    printf("�ִ� �ڻ��� �ʰ��Ͽ����ϴ�. �ٽ� �Է��ϼ���.\n=>");
    }
    int bet;
    int ran;
    int tempb=0;
    int tempm;
    printf("���� ��� : ");
    trans(money);
    srand(time(NULL));
    int i=1;
    for(;i<=range;i++){
    	tempm=money;
       	printf("\n\n================================\n\n<%d��° ����>\n\n������ �ݾ��� �Է��Ͻÿ�(1���� �̻� 10�� �̸�) \n(���� �ڻ� : ",i);
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
					printf("�ڻ��� �����մϴ�. (���� ��� : ");
            	    trans(money);
					printf(")\n�ٽ� �Է� ���ֽʽÿ� => ");
				}
			}
        	else
        		printf("������ �µ��� �ٽ� �Է����ֽʽÿ� = >"); 
        }        
        money-=bet;
        printf("==> ���� ���� : ");
        trans(tempm);
        printf(" - ");
        trans(bet);
        printf(" = ");
        trans(money);
		printf("\n\n~~@~~@~~@~~@~~@~~@~~@~~@~~@~~@~~\n\n�귿�� ���Ƚ��ϴ�!\n\n");
        ran=rand()%4;
        switch(ran){
            case 0:
                printf("��� �Ҿ����ϴ�...\n=>");
                bet=0;
                break;
            case 1:
                printf("������ �Ҿ����ϴ�...\n=>");
                bet/=2;
                break;
            case 2:
                printf("1.5��� �ҷȽ��ϴ�!!\n=>");
                bet*=3;
                bet/=2;
                break;
            case 3:
                printf("2�踦 �޾ҽ��ϴ�!!!!!\n=>");
                bet*=2;
                break;
        }
        printf("���� �ݾ� : ");
        trans(tempb);
		printf(" ==> ");
		trans(bet);
		printf("\n\n���� ��� : ");
		trans(money);
		printf(" + ");
		trans(bet);
		printf(" = ");
        money+=bet;
        trans(money);
        if(money<10000)
            break;
    }
    printf("\n\n===================================\n\n�Ļ� �ϼ̽��ϴ٤���");
}
