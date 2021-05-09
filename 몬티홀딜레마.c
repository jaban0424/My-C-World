#include <stdio.h>
#include <windows.h>

int main()
{	
	printf("시행 횟수 : ");
	int how;
	scanf("%d",&how);
    int door[4]={10,10,10,'\0'};
    char real[4]={'#','#','#','\0'};
    char draw[4]={'*','*','*','\0'};
    int wc;//where car?
    int wd;//which door?
    int rd,fc; 
    int oh=0,dam=0;
    for(int h=1;h<=how;h++)
    {
    	printf("<%d번째 시행>\n",h);
        for(int k=0;k<3;k++)
        {
           door[k]=10;
           real[k]='#';
           draw[k]='*';
      }
        wc=rand()%3;//어느 문에 넣을지 골라
        door[wc]=50;//거기에 차넣어
        real[wc]='$';
        printf("문 뒤  : ");
        puts(real);
        wd=rand()%3;//어느 문 열래?
        draw[wd]='+';//+는 선탟한 문 
        printf("참가자가 %d번째 문을 오픈\n",wd+1); 
        if(door[wd]==10)//만약 고른게 염소면?
        {
           if(wd==0)//0번을 골랐고
           {
               if(wc==1)//차가 1번에 있다면
               {
               draw[2]='#'; //2번에 있는 염소 오픈 
               draw[wd]='*';//고른 건 포기 
               draw[1]='+';//1번을 선택
               printf("3번의 염소 오픈\n");
               fc=1;
            }
            else if(wc==2)//차가 2번에 있다면  
            {
                  draw[1]='#'; //1번에 있는 염소 오픈 
               draw[wd]='*';//고른 건 포기 
               draw[2]='+';//2번을 선택
               printf("2번의 염소 오픈\n");
               fc=2;
            }
                 
           }
           else if(wd==1)//1번을 골랐고
           {
               if(wc==0)//차가 0번에 있다면
               {
                     draw[2]='#'; //2번에 있는 염소 오픈 
               draw[wd]='*';//고른 건 포기 
               draw[0]='+';//0번을 선택
               printf("3번의 염소 오픈\n");
               fc=0;
            }
            else if(wc==2)//차가 2에 있다면 
            {
                  draw[1]='#';
               draw[wd]='*';
               draw[2]='+';
               printf("2번의 염소 오픈\n");
               fc=2;
            }
                 
           }
           else if(wd==2)//2번을 골랐고
           {
               if(wc==0)//차가 0번에 있다면
               {
                     draw[1]='#'; 
               draw[wd]='*';
               draw[0]='+';
               printf("2번의 염소 오픈\n");
               fc=0;
            }
            else if(wc==1)
            {
                  draw[0]='#';
               draw[wd]='*';
               draw[1]='+';
               printf("1번의 염소 오픈\n");
               fc=1;
            }
                 
           }
        }
        else if(door[wd]==50)//고른게 차라면? 
       {
          if(wd==0)//0번을 골랐으면 
          {
             rd=rand()%2;//50퍼의 확률로
            if(rd==0)
            {
               draw[1]='#'; //1번에 있는 염소 오픈 
               draw[wd]='*';//고른 건 포기 
               draw[2]='+';//2번을 선택
               printf("2번의 염소 오픈\n");
               fc=2;
            }
            else//아니면 
            {
               draw[2]='#'; //2번에 있는 염소 오픈 
               draw[wd]='*';//고른 건 포기 
               draw[1]='+';//1번을 선택
               printf("3번의 염소 오픈\n");
               fc=1; 
            }    
         }
         else if(wd==1)
          {
             rd=rand()%2;
            if(rd==0)
            {
               draw[0]='#';  
               draw[wd]='*';
               draw[2]='+';
               printf("1번의 염소 오픈\n");
               fc=2;
            }
            else//아니면 
            {
               draw[2]='#'; 
               draw[wd]='*';
               draw[0]='+';
               printf("3번의 염소 오픈\n");
               fc=0;
            }    
         }
         else if(wd==2) 
          {
             rd=rand()%2;
            if(rd==0)
            {
               draw[0]='#'; 
               draw[wd]='*';
               draw[1]='+';
               printf("1번의 염소 오픈\n");
               fc=1;
            }
            else//아니면 
            {
               draw[1]='#'; 
               draw[wd]='*'; 
               draw[0]='+';
               printf("2번의 염소 오픈\n");
               fc=0;
            }    
         }
      }
      if(door[fc]==10) 
      {
         printf("남은 문엔 염소가 있어서 꽝"); 
         dam++;
      }
      else 
      {
         printf("남은 문엔 차가 있어서 당첨"); 
         oh++;
      }
      printf("\n===========================================\n\n");
    }
    for(int q=0;q<=rand();q++)
    {
        q++;
    }
    printf("당첨횟수 : %d    꽝 횟수 : %d",oh,dam); 
    int end;
    printf("\n\n종료하시려면 아무 숫자나 입력하십시오.");
    scanf("%d",end);
}
    
