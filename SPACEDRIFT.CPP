#include <graphics.h>
#include <conio.h>
#include <process.h>
#include <dos.h>
#include <fstream.h>
#include <stdlib.h>
#include <stdio.h>


int score=0,s=1,level=1;
int chic=0 ;
char choice;
float D[10]={392.00,261.63,369.99,329.63,311.13};
struct hALLOFAME
{
	char name[30];
	int Score ;
}Gamer = {"\0", 0 };
void ProcessHighScore1()
{
	fstream  file ;
	if( chic == 1 )
	{
	file.open("C:\\TURBOC3\\Projects\\Score.dat", ios :: app | ios :: binary );
	file.write((char*)&Gamer, sizeof(Gamer)) ;
	file.close() ;
	}
 }

void status(int s)
{ settextstyle(4, 0, 1);
  setcolor(WHITE);
  outtextxy(450,50,"Status:");
   settextstyle(3, 0, 2);
  setcolor(YELLOW);
  outtextxy(450,100,"INSTRUCTIONS");
   settextstyle(3, 0, 1);

  outtextxy(450,125,"Movement:Arrow Keys");
  outtextxy(450,150,"SHOOT:SPACE");
  outtextxy(450,175,"PAUSE:P");
  outtextxy(450,200,"QUIT: ESCAPE");
	if(s==1)
	{settextstyle(4, 0, 1);
	setcolor(BLUE);
	outtextxy(517,50,"Paused");
	outtextxy(517,50, "Stopped");
	  setcolor(LIGHTGREEN);
	  outtextxy(517,50,"Playing");
	}
	else if(s==2)
	{settextstyle(4, 0, 1);
	 setcolor(BLUE);
	outtextxy(517,50, "Stopped");
	  outtextxy(517,50,"Playing");
	 setcolor(YELLOW);
	outtextxy(517,50,"Paused");
	}
	else
	{settextstyle(4, 0, 1);
	 setcolor(BLUE);
	outtextxy(517,50,"Paused");
	  outtextxy(517,50,"Playing");
	 setcolor(RED);
	outtextxy(517,50, "Stopped");
	}
  settextstyle(3, 0, 1);
  setcolor(GREEN);
  outtextxy(485,278,"LEVEL: ");
	 gotoxy(70,19);
	 cout<<"\b"<<level;
}



enum Directions { Still, Right, Left};



void Gun(int x,int Direction )
 {
  if( Direction == Still ) //Still
 {
 setfillstyle( SOLID_FILL, LIGHTBLUE );
 setcolor(RED);
 line(  15, 330, 50, 330);
 line(  33, 300, 15, 330);
 line(  50, 330, 33, 300);
floodfill(34,320, RED);
 }
 else
 if( Direction == Right ) //Right
 {setfillstyle( SOLID_FILL, BLACK );
 setcolor(BLACK) ;
 line(  x-10, 330, x+35-10, 330);
 line(  x+18-10, 300, x-10, 330);
 line(  x+35-10, 330, x+18-10, 300);
 floodfill(x+18+1-10,320, BLACK);

   setfillstyle( SOLID_FILL, BLACK );
 setcolor(BLACK);
 line(  x-10, 330, x-35-10, 330);
 line(  x-18-10, 300, x-10, 330);
 line(  x-35-10, 330, x-18-10, 300);
 floodfill(x-29,320, BLACK);


 setfillstyle( SOLID_FILL, LIGHTBLUE );
 setcolor(RED);
 line(  x, 330, x+35, 330);
 line(  x+18, 300, x, 330);
 line(  x+35, 330, x+18, 300);
 floodfill(x+18+1,320, RED);
 }
 else

 if( Direction == Left ) //Left
 {setfillstyle( SOLID_FILL, BLACK );
 setcolor(BLACK) ;
 line(  x+10, 330, x-35+10, 330);
 line(  x-18+10, 300, x+10, 330);
 line(  x-35+10, 330, x-18+10, 300);
 floodfill(x+20-18-5,320, BLACK);

  setfillstyle( SOLID_FILL, BLACK );
 setcolor(BLACK);
 line(  x+10, 330, x+35+10, 330);
 line(  x+18+10, 300, x+10, 330);
 line(  x+35+10, 330, x+18+10, 300);
 floodfill(x+29,320, BLACK);

 setfillstyle( SOLID_FILL, LIGHTBLUE );
 setcolor(RED);
 line(  x, 330, x-35, 330);
 line(  x-18, 300, x, 330);
 line(  x-35, 330, x-18, 300);
 floodfill(x-18-5,320, RED);


 }

 }







int tyu=0;
void MoveGun()
{
int x =15, d = 10; ;


Gun(x, Still );
char ch ;
randomize() ;
int a=rand()%55+15;
int w=1;
 while( 1 )
 {

	setfillstyle(SOLID_FILL,LIGHTBLUE);
	for(int j=0;d<310 || j<300;j++)
		       { if(s!=-1)
			    {d++;
			    }

			    if(score>=(5*w))
			    {w++;
			    settextstyle(5, 0, 3);
			     setcolor(RED);
			     outtextxy(100,100,"SPEED Increasing");
			       sound(554.37);delay(200);nosound();
			       sound(659.25);delay(150);nosound();
			       sound(554.37);delay(125);nosound();
			       sound(554.37);delay(125);nosound();
			       sound(659.25);delay(100);nosound();
			       sound(554.37);delay(100);nosound();
			       sound(554.37);delay(100);nosound();
			       sound(659.25);delay(100);nosound();
			       sound(554.37);delay(100);nosound();
			       sound(622.25);delay(100);nosound();
			       sound(554.37);delay(100);nosound();
			       sound(493.88);delay(100);nosound();
			     setcolor(BLACK);
			     outtextxy(100,100,"SPEED Increasing");
			     level++;

			      }
			    delay(11-w);
			    setcolor(0);
			    bar3d(  a,d,a+10 ,d+10,0,0);

	       if( kbhit() )
	       {
		ch = getch();
		break;
		     }


     }


   switch(ch)
	  {
	//Right arrow
	  case 77   :if(s!=-1){ //pause
		     if(x<(getmaxx() -260))
		 { tyu=0;
		  x += 10 ;
		  Gun(x, Right );


		  status(1);}}
		  break;
	//Left arrow
	  case 75  :if(s!=-1){  //pause

		if( x>40 )
	       {	tyu=30;
		x -= 10 ;
		Gun(x, Left );

		status(1);}  }
		break;
	  case 'i': clrscr();
		    setbkcolor(WHITE);
		    cout<<"loser";
		    break;
	//Spacebar
	  case ' ' :   if(s!=-1)      //pause
		      { status(1);
		       randomize();
			for(int j=0; j<300;d++,j++)
		       {

			       delay(10);
			       setcolor(0);
				 bar3d(  a,d,a+10 ,d+10,0,0);

					setcolor(YELLOW);
					rectangle(  x-10-tyu,280-j, x+50-tyu,290-j);

					setcolor(BLACK) ;
					rectangle(  x-10-tyu,280-j+10, x+50-tyu,290-j+10);




		    //Collision
if(((x-10-tyu<a&&x+50>a)||(x-10-tyu<a+10&&x+50>a+10))&&((280-j)<d)&&(280-j+10>d))//bulletmeetsobstacle
	{ sound(1500);delay(30);nosound();
	  score++;
	   setcolor( BLACK );
	 setfillstyle(SOLID_FILL, BLACK);
	bar(1,0,418,297);


	 gotoxy(70,20);
	 cout<<"\b"<<score;
	   setcolor(RED);
	  settextstyle(1,0,1);
	  outtextxy(485,298,"SCORE:");
	   delay(100);
	 a=rand()%300+55;
	 d = 10 ;

	 break ;
	 }//if





	 if(d>=310 ) //game over
	 { status(2);
	  delay(50);

	  cleardevice();
	  setbkcolor(BLACK);

	  delay(1000);
	  setcolor(RED);
	  settextstyle(1,0,8);
	  outtextxy(75,180,"GAME OVER");
	  setcolor(RED);
	  settextstyle(1,0,4);
	  outtextxy(75,260,"YOUR SCORE: ");
	  gotoxy(37,18);
	  cout<<score;
	  Gamer.Score=score;
	  ProcessHighScore1();
	      for( int f=0; f<2;f++)
  {   sound(554.37);delay(400);nosound();delay(100);
			       sound(659.25);delay(350);nosound();delay(100);
			   sound(554.37);delay(325);nosound(); delay(100);
			   sound(554.37);delay(325);nosound(); delay(100);
			    sound(659.25);delay(350);nosound();delay(100);
			    sound(554.37);delay(350);nosound();delay(100);
			  sound(554.37);delay(350);nosound();  delay(100);
			  sound(659.25);delay(300);nosound();  delay(100);			  sound(554.37);delay(350);nosound();
			  sound(622.25);delay(350);nosound();  delay(100);
			  sound(554.37);delay(300);nosound();
			  sound(493.88);delay(350);nosound(); }

	  setcolor(RED);
	  settextstyle(1,0,1);
	  outtextxy(95,360,"PRESS ANY KEY");
	  score=0;
	 level=1;
	  return ;



	  }
	  }
	  }
	  break;

	  case 27 :      status(3);
			 delay(600);
			 exit(0) ;
	  //pause
	  case 'p':      status(2);
			 s*=-1;
			 ch='\0';
			 break;


	  }//switch
 }//while

}


void ProcessHighScore2()
{       int v;
	hALLOFAME U[20];
	fstream  file ;
	file.open("C:\\TURBOC3\\Projects\\Score.dat", ios :: in | ios :: binary );
	int x=0;

	file.read((char*)&Gamer, sizeof(Gamer)) ;
	while(!file.eof())
	{
	  U[x]=Gamer;
	  file.read((char*)&Gamer, sizeof(Gamer)) ;
	  x++;
	  }

	  v=file.tellg()/32;


      hALLOFAME kemp;
      for( x=0; x<v; x++)
      {for(int q=0; q<v-x-1;q++)
      {if(U[q].Score<U[q+1].Score)
       {  kemp=U[q];
	  U[q]=U[q+1];
	  U[q+1]=kemp;
       }
      }
      }


     for(int r=0; r<5;r++)
	   {


		cout<<"\n\t\t\t"<<U[r].name<<"\t\t   "<<U[r].Score <<"\n";
		file.read((char*)&Gamer, sizeof(Gamer)) ;


	   }


}



void rew1()
{
fstream fule;
char ch;
fule.open("C:\\TURBOC3\\Projects\\rew.txt",ios::app|ios::binary);
if(!fule)
cout<<"fulll";
else
{
//setbkcolor(BLACK);
outtextxy(200,30," ENTER REVIEW");
ch='\"';

while(ch!=13)
{
fule.put(ch);
ch=getche();

}
}
fule.put('\"');
fule.put('\n');
fule.put('\t');
fule.put('\t');
outtextxy(200,60," ENTER NAME");
ch='-';
while(ch!=13)
{
fule.put(ch);
ch=getche();
}

fule.put('\n');
fule.put('\n');
fule.put('\n');




fule.close();
}

void rew2()
{
fstream fule;
char ch;
fule.open("C:\\TURBOC3\\Projects\\rew.txt",ios::in);
if(!fule)
cout<<"no reviews yet";
else
{
cout<<"\n\n\t";
fule.get(ch);
while(!fule.eof())
{
cout<<ch;
fule.get(ch);
}
}
fule.close();
}

void main()
{
int GD = DETECT, GM ;
initgraph( &GD, &GM, "C:\\TurboC3\\BGI " ) ;
 delay(1000);
  sound(450);delay(200);nosound();
int u=0;
  for(int i=0;i<3000;i++)
{    int p=random(640);
 int q=random(480);
     bar3d(p,q,p+15,q+15,1,1);
     delay(1);
       if(u==4)
	u=0;

    if (i%150==0)
    sound(D[u++]);


}
sound(D[4]);delay(500);nosound();
  setbkcolor(WHITE);
  setcolor(RED);
  settextstyle(1,0,8);
  outtextxy(75,180,"SPACE DRIFT");
  delay(1000);
  setcolor(RED);
  settextstyle(2,0,5);
  outtextxy(500,400,"PRESS ANY KEY");

getch();
clrscr();
cleardevice();
 setbkcolor(BLACK);
  setcolor(YELLOW);
  settextstyle(1,0,7);
  outtextxy(100,25,"INSTRUCTIONS");
    settextstyle(2, 0, 5);
  setcolor(YELLOW);
  outtextxy(100,90,"1.Use Arrow keys to move left and right.");
  outtextxy(100,125,"2.Press SPACE to PhotonBlast.");
  outtextxy(100,175,"3.Press 'P' to Freeze time for a few seconds");
  outtextxy(100,225,"4.Press ESC to leave space.");
  outtextxy(100,275,"5.Level increases every 5 points.");
       delay(500);
       settextstyle(2, 0, 7);
  setcolor(RED);
  outtextxy(15,300,"If your PhotonBlast misses the AlienShots, YOU LOSE.");

  setcolor(YELLOW);
  settextstyle(2,0,5);
  outtextxy(500,400,"PRESS ANY KEY");

getch();

while(1)
{
cleardevice();
setcolor(LIGHTBLUE);
 settextstyle(3,0,7);
outtextxy( 170,10 ,"SPACEDRIFT" );
setcolor(GREEN);
 settextstyle(3,0,2);

outtextxy( 200, 100,"1. PLAY THE GAME" );
outtextxy( 200, 130,"2. WALL OF GAME" );
outtextxy( 200, 160,"3. REVIEWS" );
outtextxy( 200, 190,"4. EXIT" );

choice=getch();

switch(choice )
{

case '1' :

	cleardevice();
	   chic=1;
setcolor(RED);
 settextstyle(3,0,2);
	outtextxy(100 , 20,"ENTER YOUR GAMENAME");
	gotoxy(45,3);
	gets( Gamer.name ) ;
	cleardevice();
	setbkcolor(BLACK);
	//border

	setfillstyle( SOLID_FILL, BLUE );
	 setcolor(WHITE);
	 int left = getmaxx()  - 220;
	  int top = getmaxy();
	int right = 0;
	 int bottom = 0;
	rectangle(left,top,right,bottom);
	 floodfill(left +20,top-25, WHITE);

	 status(3);

	     MoveGun();//gun design

		  break;
case  '4': exit(0);
case '2': //highscore
		cleardevice();

	 setcolor(BLUE);
	 settextstyle(3,0,2);
	 outtextxy(200,30,"Name					Score");
	   gotoxy(30,12);
	   ProcessHighScore2() ;
	  chic = 0;
	   //bubblesort
	 break;

case '3': char jk;
	  cleardevice();
	  setbkcolor(BLACK);
	  outtextxy(200,30,"1. ENTER REVIEW");
	  outtextxy(200,60,"2. DISPLAY REVIEWS");

	  jk=getch();
	  if(jk=='1')
	  {cleardevice();
	  rew1();}
	  else if(jk=='2')
	  {cleardevice();
	  rew2();  }
	  else
	  {cleardevice();
	  outtextxy(200,30,"INVALID");
	  getch();}


	   break;

default: cout<<"INVALID";}//SWITCH
getch();
}//while

closegraph() ;
}


