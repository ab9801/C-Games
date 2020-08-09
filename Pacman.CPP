#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<dos.h>
int flag=0;
struct pac
{
	int x,x1;
	int y,y1;
	void move()
	{
		if(kbhit()!=0)
		{
			int ch=getch();
			if(ch == 119)
			{
				if(y>30)
				{
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,BLACK);
				pieslice(x,y,135,360,10);
				pieslice(x,y,45,0,10);
				//circle(x,y,15);
				y-=10;
				setcolor(YELLOW);
				setfillstyle(SOLID_FILL,YELLOW);
				pieslice(x,y,135,360,10);
				pieslice(x,y,45,0,10);
				}
			}
			if(ch == 97)
			{
				if(x>40)
				{
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,BLACK);
				pieslice(x,y,0,135,10);
				pieslice(x,y,225,360,10);
				//circle(x,y,15);
				x-=10;
				setcolor(YELLOW);
				setfillstyle(SOLID_FILL,YELLOW);
				pieslice(x,y,0,135,10);
				pieslice(x,y,225,360,10);
				}
			}
			if(ch == 115)
			{
				if(y<450)
				{
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,BLACK);
				pieslice(x,y,0,225,10);
				pieslice(x,y,325,360,10);
				//circle(x,y,15);
				y+=10;
				setcolor(YELLOW);
				setfillstyle(SOLID_FILL,YELLOW);
				pieslice(x,y,0,225,10);
				pieslice(x,y,325,360,10);
				}
			}
			if(ch == 100)
			{
				if(x<600)
				{
				setcolor(BLACK);
				setfillstyle(SOLID_FILL,BLACK);
				pieslice(x,y,45,325,10);
				//circle(x,y,15);
				x+=10;
				setcolor(YELLOW);
				setfillstyle(SOLID_FILL,YELLOW);
				pieslice(x,y,45,325,10);
				}
			}
			if(ch==27)
			exit(0);
		}
		/*if(kbhit()==0)
		{
			if((x-x1)>0&&(y-y1)>0)
			{
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,BLACK);
			sector(x1,y1,0,180,8,18);
			x1+=5; //Moves Right
			y1+=5; //Moves Down
			delay(100);
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,RED);
			sector(x1,y1,0,180,8,18);
			}
			if((x-x1)>0&&(y-y1)<0)
			{
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,BLACK);
			sector(x1,y1,0,180,8,18);
			x1+=5; //Moves Right
			y1-=5; //Moves Up
			delay(100);
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,RED);
			sector(x1,y1,0,180,8,18);
			}
			if((x-x1)<0&(y-y1)>0)
			{
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,BLACK);
			sector(x1,y1,0,180,8,18);
			x1-=5; //Moves Left
			y1+=5; //Moves Down
			delay(100);
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,RED);
			sector(x1,y1,0,180,8,18);
			}
			if((x-x1)<0&&(y-y1)<0)
			{
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,BLACK);
			sector(x1,y1,0,180,8,18);
			x1-=5; //Moves Left
			y1-=5; //Moves Up
			delay(100);
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,RED);
			sector(x1,y1,0,180,8,18);
			}
			if((x-x1)==0&&(y-y1)<0)
			{
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,BLACK);
			sector(x1,y1,0,180,8,18);
			y1-=5; //Moves Up
			delay(100);
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,RED);
			sector(x1,y1,0,180,8,18);
			}
			if((x-x1)==0&&(y-y1)>0)
			{
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,BLACK);
			sector(x1,y1,0,180,8,18);
			y1+=5; //Moves Down
			delay(100);
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,RED);
			sector(x1,y1,0,180,8,18);
			}
			if((x-x1)<0&&(y-y1)==0)
			{
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,BLACK);
			sector(x1,y1,0,180,8,18);
			x1-=5; //Moves Left
			delay(100);
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,RED);
			sector(x1,y1,0,180,8,18);
			}
			if((x-x1)>0&&(y-y1)==0)
			{
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,BLACK);
			sector(x1,y1,0,180,8,18);
			x1+=5; //Moves Right
			delay(100);
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,RED);
			sector(x1,y1,0,180,8,18);
			}
		}*/
	}
};

void main()
{
	int gdriver = DETECT, gmode, errcode;
	initgraph(&gdriver, &gmode, "C:\\tc\\bgi");
	getch(); //gets a character to start the program
	pac p;
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
	outtextxy(170,10,"WELCOME");
	outtextxy(170,100,"Please Wait");
	/*for(float a=90;a<=325;) //loop for the loading screen
	{
	setfillstyle(SOLID_FILL,YELLOW);
	pieslice(310,290,45,a,40);
	a+=0.7;
	}*/
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
	outtextxy(155,345,"Press any key to continue");
	getch();
	cleardevice();
	rectangle(20,10,620,470);
	p.x=320;    p.y=290;    //For Pacman
	p.x1=400;   p.y1=50;	//For Enemy 1
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,RED);
	sector(p.x1,p.y1,0,180,8,18);
	for(int i=0;;i++)
	p.move();
	}
