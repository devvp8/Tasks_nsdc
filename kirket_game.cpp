#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int cr,pr,tpr1=0,tcr1=0;
int playerBatting(int tcr,int ct2)
{
int tpr=0;
printf("So its your Batting now\n ");
do
{
printf("Enter your guess \n ");
scanf("%d",&pr);
if(pr<0 || pr>9)
printf("Invalid Input\n ");
else
{
cr=rand()%10;
printf("Computers Guess %d\n",cr);
tpr+=pr;
if(pr!=cr)
printf("Score till now %d\n",tpr);
if(tpr>tcr && ct2==1)
break;
}
}while(pr!=cr);
if(tpr<=tcr || ct2==0)
{
printf("Ohh no you got out\n ");
tpr-=pr;
printf("You scored %d runs\n",tpr);
}
return tpr;
}
int playerBowling(int tpr,int ct1)
{
int tcr=0;
printf("Its your Bowling now \n");
do
{
printf("Enter your guess\n ");
scanf("%d",&pr);
if(pr<0 || pr>9)
printf("Invalid Input\n ");
else
{
cr=rand()%10;
printf("Computers Guess %d\n",cr);
tcr+=cr;
if(pr!=cr)
printf("Score till now %d\n",tcr);
if(tcr>tpr && ct1==1)
break;
}
}while(pr!=cr);
if(tcr<=tpr || ct1==0)
{
tcr-=cr;
printf("Computer scored %d runs\n ",tcr);
}
return tcr;
}
int main()
{
int tc,ch,tr,pc,cc,ct1,ct2;
do
{
ct1=0,ct2=0;
printf("\n\n\tWELCOME TO HANDCRICKET ADDA ");
printf("\n\nPress -> for RULES ");
getch();
printf("******RULES******\n");
printf("You can enter number only from 0 to 9\n ");
printf("If You and computer guess the same number then the Batsman is out \n");
printf("The Player Scoring More Runs wins the Match \n");
printf("\n\n\nPress -> to START the Game ");
getch();
getch();
;
printf("Its toss time\n ");
printf("Enter odd number for odd and even number for even\n");
scanf("%d",&tc);
tr=rand()%2;
if((tc%2==tr))
{
printf("Congratulations you won the toss\n ");
do
{
printf("Press 1 to bat first and 0 to Bowl first\n ");
scanf("%d",&pc);
if(pc==1)
{
tpr1=playerBatting(tcr1,ct2);
ct1++;
printf("TARGET FOR COMPUTER %d runs\n ",tpr1+1);
tcr1=playerBowling(tpr1,ct1);
}
else if(pc==0)
{
tcr1=playerBowling(tpr1,ct1);
ct2++;
printf("TARGET FOR YOU %d runs\n ",tcr1+1);
tpr1=playerBatting(tcr1,ct2);
}
else
printf("Invalid Input\n ");
}while(pc!=0 && pc!=1);
}
else
{
printf("Oops! You Lost the toss\n ");
cc=rand()%2;
if(cc==1)
{
printf("Computer elects to Bat\n ");
tcr1=playerBowling(tpr1,ct1);
printf("TARGET for you is %d runs \n",tcr1+1);
ct2++;
tpr1=playerBatting(tcr1,ct2);
}
else
{
printf("Computer elects to Bowl\n ");
tpr1=playerBatting(tcr1,ct2);
printf("TARGET for computer is %d runs \n",tpr1+1);
ct1++;
tcr1=playerBowling(tpr1,ct1);
}
}
printf("SCORECARD\n");
printf("Player's Runs %d\n",tpr1);
printf("Computers Runs %d\n",tcr1);
if(tpr1>tcr1)
printf("Congratulations You Won!!\n");
if(tcr1>tpr1)
printf("Ohh noo You Lost\n");
if(tcr1==tpr1)
printf("Ohh Wow its a Tie\n ");
printf("Enter 1 to play again and 0 to exit\n ");
scanf("%d",&ch);
}while(ch==1);
printf("Thank You For Playing ");
getch();
}
