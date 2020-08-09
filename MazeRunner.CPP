#include<fstream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
class score
{char name[20];
 int min,sec;
 public:
 void initname(char *s)
 {strcpy(name,s);}

 void initmin(int d)
 {min=d;}

 void initsec(int e)
 {sec=e;}

 char *nam()
  {return name;}

 int mi()
  {return min;}

 int se()
  {return sec;}




void display()
 {cout<<name<<"\t"<<min<<":"<<sec<<"\n";}
 }sc[11],g;


void sort(score sc[],int n)
{for(int i=0;i<=n;i++)
  for(int j=i+1;j<=n;j++)
  {if(sc[j].mi()>sc[i].mi())
    {g=sc[i];
     sc[i]=sc[j];
     sc[j]=g;}
   
   else if((sc[j].mi()==sc[i].mi())&&(sc[j].se()>sc[i].se()))
    {g=sc[i];
     sc[i]=sc[j];
     sc[j]=g;}
   
   else if((sc[j].mi()==sc[i].mi())&&(sc[j].se()==sc[i].se())&&
              (strcmp(sc[j].nam(),sc[i].nam())<0)) 
    {g=sc[i];
     sc[i]=sc[j];
     sc[j]=g;
     sc[i].display();}}}

struct villain
{int x1,y1,dir,xi,yi,dist;//for movement
 
void draw()
 {setfillstyle(SOLID_FILL,WHITE);
  bar(x1-13,y1-13,x1+13,y1+13);}//bar of dimensions 25*25

 void erase()
 {setfillstyle(SOLID_FILL,BLACK);
  bar(x1-13,y1-13,x1+13,y1+13);}

 


villain()
 {x1=y1=dist=xi=yi=0;dir=0;}
 
void ini(int x, int y,int d)
 {xi=x1=x;yi=y1=y;dist=d;dir=1; }


void move()
 {erase();
 if(x1==xi)
   dir=1;
  else if(x1==xi+dist)
   dir=-1;
  y1=yi;
  x1+=dir;
  draw();}}v[3];


struct villain1
{int x1,y1,dir,xi,yi,dist;//for movement
 void draw1()
  {setfillstyle(SOLID_FILL,WHITE);
  bar(x1-13,y1-13,x1+13,y1+13);}//bar of dimensions 25*25
 
 void erase1()
  {setfillstyle(SOLID_FILL,BLACK);
   bar(x1-13,y1-13,x1+13,y1+13);}

 villain1()
  {x1=y1=dist=xi=yi=0;dir=0;}
 
 void init(int x, int y,int d)
  {xi=x1=x;yi=y1=y;dist=d;dir=-1;}

 void move1()
 {erase1();
 


  if(y1==yi)
    dir=-1;
  else if(y1==yi-dist)
    dir=1;
  x1=xi;
  y1+=dir;
  draw1();
  }}h[3];


void main()
{ clrscr();
char name[20];
B:
gotoxy(32,12);
cout<<"Enter Your Name";
gotoxy(32,13);
gets(name);
if(name[0]=='\0')
goto B;//ensures that you give a name

clrscr();
gotoxy(32,9);
cout<<"Hello "<<name<<"!!"<<'\n';
gotoxy(32,10);cout<<"INSTRUCTIONS:"<<'\n';
gotoxy(11,12);cout<<"1.Press W to move up, A for left, S for down and D for right";
gotoxy(11,13);cout<<"2.Time continuously reduces irrespective of movement";
gotoxy(11,14);cout<<"3.Collect the blue box to open the blue gate";
gotoxy(11,15);cout<<"4.Collect the green box to get miniaturised";
gotoxy(11,16);cout<<"5.Move to the red box to open the finish line and the yellow line !!!";
gotoxy(11,17);cout<<"6.You can press space during the game to exit";
gotoxy(11,18);cout<<"7.Try to finish the game with the maximum time";


gotoxy(11,19);cout<<"8.If your time left becomes 0,you lose";
gotoxy(11,20);cout<<"9.Watch out for the white blocks. If you touch them,you are out";
getch();
clrscr();

/* request auto detection */
int gdriver = DETECT, gmode, errorcode;

int cool,w=0,over=0;//cool is variable used for loading bar,w used for checking if out

/* initialize graphics mode */
initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");

settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);

setcolor(BLUE);
outtextxy(70,200,"WELCOME TO THE AMAZING MAZE");
delay(5000);
cleardevice();

setcolor(WHITE);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
outtextxy(25,200,"YOUR GAME IS LOADING");
for (cool=0;cool<200;cool++)
{
setfillstyle(SOLID_FILL,RED);
bar(250,270,200+cool,290);
delay(20);
}
setcolor(YELLOW);

settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
delay(100);
outtextxy(125,320,"Press any key to continue");
getch();


cleardevice();

settextstyle(DEFAULT_FONT,HORIZ_DIR,0);

setcolor(WHITE);
line(0,450,620,450);//foll 5 lines are the lines on edge of screen
line(0,0,620,0);
line(620,0,620,450);
line(0,0,0,450);
line(500,0,500,450);

outtextxy(520,70,"Player Name");
outtextxy(520,85,name);

int i,x1=450,y1=410,x2,y2,d;//coordinates of the block, d is used in the file
x2=x1+25;
y2=y1+25;
setfillstyle(SOLID_FILL,RED);
bar(x1,y1,x2,y2);

settextstyle(TRIPLEX_FONT, HORIZ_DIR,4);
outtextxy(45,400,"FINISH");
settextstyle(DEFAULT_FONT, HORIZ_DIR,0);

line(201,155,201,450);
line(0,100,136,100);
line(165,51,165,346);
setcolor(YELLOW);
line(165,0,165,50);
setcolor(WHITE);
line(165,155,410,155);
line(351,251,351,401);
line(271,251,351,251);
line(351,401,500,401);
line(271,251,271,381);
line(310,290,310,450);


line(410,155,410,326);
line(225,86,500,86);
line(0,401,201,401);
line(136,100,136,346);
line(56,346,136,346);
line(56,151,56,346);
line(56,151,91,151);
line(105,220,136,220);
line(56,301,91,301);
setcolor(11);//finish line
line(161,401,200,401);

setfillstyle(SOLID_FILL,GREEN);//miniaturising block
bar(65,320,80,335);

//enemy blocks
v[0].ini(390,342,40);
v[1].ini(300,20,150);
v[2].ini(280,190,50);
h[0].init(195,110,90);
h[1].init(235,360,175);

setcolor(BLUE);
line(201,156,201,200);//line which disappears after taking blue block
setcolor(WHITE);

int flag=0,j=0,a=0;//a for checking number of times u touch miniaturising block
		   //j for miniaturising
		   //flag for checking if u touch blue block or red line
setfillstyle(SOLID_FILL,BLUE);
bar(470,40,485,55);

setcolor(4);
line(50,0,50,99);//red line for transporting block and opening finish
line(0,0,50,0);



line(0,99,50,99);
line(0,0,0,99);

int a1=0;//variable to ensure that a new enemy is generated only when the transporting line is touched for the first time

char m[2],n[2],o[2],k,q[2];

clock_t start;
clock_t end;
start=clock();
int min=2,sec=1;
char smin[3],ssec[3];

setcolor(WHITE);
outtextxy(525,360,"Time left");
setcolor(RED);

for(i=0;;i++)
{
  end=clock();
  if((end-start)/CLK_TCK>1)
    {setfillstyle(SOLID_FILL,BLACK);
     bar(510,400,560,430);
     end=clock();
     start=clock();
     
  if(min==0&&sec==0)
     {over=1;
      outtextxy(520,400,"Bye Bye");
      getch();
      goto A;}
     
  else if(sec==0)
     {sec=59;
      min--;}

     
   
   else
     sec--;
     
     itoa(min,smin,10);
     itoa(sec,ssec,10);
     setfillstyle(SOLID_FILL,BLACK);
     bar(535,370,570,390);
     setcolor(WHITE);
     outtextxy(540,380,smin);
     outtextxy(547,380,":");
     outtextxy(553,380,ssec);
     setcolor(RED);
  }

  v[0].move();
  v[1].move();
  v[2].move();
  h[0].move1();
  h[1].move1();
  if(a1==1)
    h[2].move1();
  delay(60);

  //collision with enemies
  if(((x1<=(v[0].x1-13)&&(x2>=(v[0].x1-13)))||(x1<=(v[0].x1+13)&&
       (x2>=(v[0].x1+13))))&&((y1<=(v[0].y1+13)&&(y2>=(v[0].y1+13)))
       ||(y2>=(v[0].y1-13)&&(y1<=(v[0].y1-13)))))
   {outtextxy(520,400,"Bye Bye");
    w=2;getch();
    break;}
  
  if(((x1<=(v[1].x1-13)&&(x2>=(v[1].x1-13)))||(x1<=(v[1].x1+13)&&
       (x2>=(v[1].x1+13))))&&((y1<=(v[1].y1+13)&&(y2>=(v[1].y1+13)))
       ||(y2>=(v[1].y1-13)&&(y1<=(v[1].y1-13)))))
   {outtextxy(520,400,"Bye Bye");
    w=2;getch();
    break;}
  

if(((x1<=(v[2].x1-13)&&(x2>=(v[2].x1-13)))||(x1<=(v[2].x1+13)&&
     (x2>=(v[2].x1+13))))&&((y1<=(v[2].y1+13)&&(y2>=(v[2].y1+13)))
     ||(y2>=(v[2].y1-13)&&(y1<=(v[2].y1-13)))))
   {outtextxy(520,400,"Bye Bye");
    w=2;getch();
    break;}
  
if(((x1<=(h[0].x1-13)&&(x2>=(h[0].x1-13)))||(x1<=(h[0].x1+13)&&
     (x2>=(h[0].x1+13))))&&((y1<=(h[0].y1+13)&&(y2>=(h[0].y1+13)))
     ||(y2>=(h[0].y1-13)&&(y1<=(h[0].y1-13)))))
   {outtextxy(520,400,"Bye Bye");
    w=2;getch();
    break;}
  
if(((x1<=(h[1].x1-13)&&(x2>=(h[1].x1-13)))||(x1<=(h[1].x1+13)&&
     (x2>=(h[1].x1+13))))&&((y1<=(h[1].y1+13)&&(y2>=(h[1].y1+13)))
     ||(y2>=(h[1].y1-13)&&(y1<=(h[1].y1-13)))))
   {outtextxy(520,400,"Bye Bye");
    w=2;getch();
    break;}
  
if(a1==1)//checking for enemy generated after the transporting line is touched or the first time
  if(((x1<=(h[2].x1-13)&&(x2>=(h[2].x1-13)))||(x1<=(h[2].x1+13)&&
        (x2>=(h[2].x1+13))))&&((y1<=(h[2].y1+13)&&(y2>=(h[2].y1+13)))
        ||(y2>=(h[2].y1-13)&&(y1<=(h[2].y1-13)))))
   {outtextxy(520,400,"Bye Bye");
    w=2;getch();
    break;}

 if(kbhit())
 {
 k=getch();
 if(k=='a')
  {setfillstyle(SOLID_FILL,BLACK);
   bar(x1,y1,x2,y2);
   x1-=(25-j);x2-=(25-j);//j to check if miniaturising block is taken          

  
 
   if (j==0)
   setfillstyle(SOLID_FILL,RED);
   else
   setfillstyle(SOLID_FILL,GREEN);//miniaturised block
   bar(x1,y1,x2,y2);}
 
 else if(k=='d')
  {setfillstyle(SOLID_FILL,BLACK);
   bar(x1,y1,x2,y2);
   x1+=(25-j);x2+=(25-j);
   if (j==0)
   setfillstyle(SOLID_FILL,RED);
   else
   setfillstyle(SOLID_FILL,GREEN);
   bar(x1,y1,x2,y2);}
 
 else if(k=='w')
  {setfillstyle(SOLID_FILL,BLACK);
   bar(x1,y1,x2,y2);
   y1-=(25-j);y2-=(25-j);
   if (j==0)
   setfillstyle(SOLID_FILL,RED);
   else
   setfillstyle(SOLID_FILL,GREEN);
   bar(x1,y1,x2,y2);}
 
 else if(k=='s')
  {setfillstyle(SOLID_FILL,BLACK);
   bar(x1,y1,x2,y2);
   y1+=(25-j);y2+=(25-j);
   if (j==0)
   setfillstyle(SOLID_FILL,RED);
   else
   setfillstyle(SOLID_FILL,GREEN);
   bar(x1,y1,x2,y2);}

  

else if(k==32) //k=32 is ASCII value for space used to exit the program
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}

  //when blue block is touched part of blue line opens
  if((x2>201&&x1<201&&y2<475&&y1>130&&flag==0) || (x2>201&&x1<201&&y2<475&&y1>175&&flag!=0))
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}
  else if((x2<151&&x1>0)&&(y2>100&&y1<100))
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}
  
//to change coord of line after taking red line to escape from enemy
  else if((x2>165&&x1<165&&y2<371&&y1>0&&flag!=2)||
            (x2>165&&x1<165&&y2<371&&y1>75&&flag==2))
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}
  
 else if((x2<435&&x1>140)&&(y2>155&&y1<155))
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
  break;}
 
else if((x2>351&&x1<351)&&(y2<426&&y1>226))
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}
 
else if((x2<376&&x1>246)&&(y2>251&&y1<251))
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}
 

else if((x2<525&&x1>326)&&(y2>401&&y1<401))
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}

else if((x2>271&&x1<271)&&(y2<406&&y1>226))
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}

else if((x2>310&&x1<310)&&(y2<475&&y1>265))
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}

else if((x2>410&&x1<410)&&(y2<351&&y1>130))
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}
 
else if((x2<525&&x1>200)&&(y2>86&&y1<86))
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}

//flag=2-block touched red line and transported
//changes condition for x2 since if flag=2 part of finish line opens
else if((x2<226&&x1>0&&y2>401&&y1<401&&flag!=2)||
            (x2<161&&x1>0&&y2>401&&y1<401&&flag==2))
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}
  
else if((x2>136&&x1<136)&&(y2<371&&y1>75))
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}
   

else if((x2<151&&x1>41)&&(y2>346&&y1<346))
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}
   
else if((x2>56&&x1<56)&&(y2<371&&y1>126))
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}
   
else if((x2<116&&x1>31)&&(y2>151&&y1<151))
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}
   
else if((x2<151&&x1>80)&&(y2>220&&y1<220))
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}
  
else if((x2<116&&x1>31)&&(y2>301&&y1<301))
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}

else if(y2>=450)
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}
  
else if(y1<=0)
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}
  




else if(x1<=0)
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}
  
else if(x2>=500)
  {outtextxy(520,400,"Bye Bye");
   w=2;getch();
   break;}
 
//for blue block
  if((x2<510&&x1>445)&&(y2<80&&y1>15))
  {flag=1;
  setcolor(BLACK);
  line(201,156,201,200);//for opening blue line
  setcolor(RED);
  setfillstyle(SOLID_FILL,BLACK);//for hiding the block
  bar(476,40,485,55);}

  if((x2<105&&x1>40)&&(y2<360&&y1>295))
  {setfillstyle(SOLID_FILL,BLACK);
   bar(65,320,80,335);a++;//for hiding miniaturising block
   if(a==1)
  {setfillstyle(SOLID_FILL,BLACK);
   bar(x1,y1,x2,y2);
   x1+=5; //for changing x1 and y1 of newly created miniaturised block
   y1+=5;
   setfillstyle(SOLID_FILL,GREEN);//hero block’s color changes to green
   bar(x1,y1,x2,y2);
   j=5;}}

  if((x2>50&&x1<50&&y2<119&&y1>0)||(x2<50&&y2<119&&y1>0))
  {setfillstyle(SOLID_FILL,BLACK);//for top left red line
   bar(x1,y1,x2,y2);
   x1=170;y1=170;x2=195;y2=195;
   

   j=0;                //for default size
   flag=2;
   a1++;
   if(a1==1)
   {h[2].init(185,320,130);} //for generating new enemy
   
   else if(a1==2)
   {setfillstyle(SOLID_FILL,BLACK);
   bar(h[2].x1-13,h[2].y1-13,h[2].x1+13,h[2].y1+13);}
   setfillstyle(SOLID_FILL,RED);
   bar(x1,y1,x2,y2);
   setcolor(BLACK);
   line(161,401,200,401);
   line(165,1,165,50); //for opening top line for escaping from enemy
   setcolor(RED);
   line(50,0,50,99);
  }
  
if(y1>401&&y2>401&&x2<201&&x1>161)//block should be inside finish line
  {outtextxy(520,400,"You Won");
  delay(1000);
  cleardevice();
  settextstyle(TRIPLEX_FONT, HORIZ_DIR,4);
  outtextxy(180,180,"YOU WON!!! :D");
  settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
  outtextxy(120,250,"YOU FINISHED IN");
  outtextxy(415,250,smin);
  outtextxy(424,250,":");
  outtextxy(433,250,ssec);
  getch();
  int n=0;
  fstream f("score.dat",ios::in);
  while(f.read((char*)&sc[n],sizeof(sc[n])))
   n++;
  f.close();
  


  sc[n].initname(name);//adding the latest record to the class
  sc[n].initmin(min);
  sc[n].initsec(sec);
  sort(sc,n);
  cleardevice();
  remove("score.dat");
  fstream f1("score.dat",ios::out);
  if(n<10)//since a maximum of 10 records should be written in the file
   for(i=0;i<=n;i++)
    f1.write((char*)&sc[i],sizeof(sc[i]));
  
  else
   for(i=0;i<10;i++)
    f1.write((char*)&sc[i],sizeof(sc[i]));
  f1.close();
  goto C;}
}
}
A:
 if(over==1||w==2)
 {cleardevice();
  settextstyle(TRIPLEX_FONT, HORIZ_DIR,4);
  outtextxy(180,180,"YOU LOST!!! :P");
  getch();
  exit(0);
  cleardevice();}
C:
closegraph();
cout<<"Check if you have broken a record"<<endl;
ifstream f2("score.dat");
while(f2.read((char*)&g,sizeof(g)))
 g.display();
f2.close();
getch();
clrscr();
}
