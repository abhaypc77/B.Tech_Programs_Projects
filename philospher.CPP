#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
struct semaphore{int h,e,t;
		 }s[5];

int x,y,r1=25,r2=200,i,p;
// char c='y';
void pp1(int c)
{circle(x-r2+35,y-50,r1);
if(c==1)
{line(x-r2+90,y-130,x,y);
line(x-r2+50,y+50,x,y);
}
}
void pp2(int c)
{circle(x,y-r2+30,r1);
if(c==1)
{line(x+r2-90,y-130,x,y);
line(x-r2+90,y-130,x,y);
}
}
void pp3(int c)
{circle(x+r2-35,y-50,r1);
if(c==1)
{line(x+r2-50,y+50,x,y);
line(x+r2-90,y-130,x,y);
}
}
void pp4(int c)
{circle(x+110,y+r2-70,r1);
if(c==1)
{line(x,y+r2-50,x,y);
line(x+r2-50,y+50,x,y);
}
}
void pp5(int c)
{circle(x-110,y+r2-70,r1);
if(c==1)
{line(x-r2+50,y+50,x,y);
line(x,y+r2-50,x,y);
}
}
void test(int i)
{ if(i==0)
    {if(s[1].e!=1&&s[4].e!=1)
      s[0].e=1;
     }
  else
    {if(s[i-1].e!=1&&s[(i+1)%5].e!=1)
     s[i].e=1;
     }
}
void main()
{int gd=DETECT,gm,c;
clrscr();
cout<<"\n\n  THIS PROGRAM DOES NOT SUPPORT THE CONCEPT OF THREADING OR MULTIPROCESSING";
cout<<"\n\n  ONLY ONE TASK IS THROWN TO THE PROCESSOR AT A GIVEN THAT IS ONLY ONE";
cout<<"\n\n  PHILLOSPHER IS ACTIVE STATE AT A TIME.";
cout<<"\n\n\n\n\t PRESS ANY KEY TO CONTINUE......";
getch();
clrscr();
initgraph(&gd,&gm,"c:\\tc\\bgi");
x=getmaxx()/2;
y=getmaxy()/2;
setcolor(5);

outtextxy(0,10,"     *** DINING PHILLOSPHER PROBLEM'S SOLUTION-(VERSION 1.1)***");
setcolor(14);
outtextxy(0,y*2-20,"YELLOW=THINKING ");
setcolor(2);
outtextxy(0,y*2-20,"                   GREEN=EATING ");
setcolor(4);
outtextxy(0,y*2-20,"                                   RED=HUNGRY ");
setcolor(6);
outtextxy(0,y*2-20,"                                                      *** DESIGNED BY: ABHAY *** ");

setcolor(6);
circle(x,y,r2);
setcolor(14);
pp1(1);
outtextxy(x-r2+35,y-50,"T");
pp2(1);
outtextxy(x,y-r2+30,"T");
pp3(1);
outtextxy(x+r2-35,y-50,"T");
pp4(1);
outtextxy(x+110,y+r2-70,"T");
pp5(1);
outtextxy(x-110,y+r2-70,"T");
while(i<50)
{getch();
//delay(200);
p=random(10);
switch(p)
{case 0:
 test(p);
 if(s[p].e==1)
 {setcolor(2);
  outtextxy(x-r2+35,y-50,"E");
  c=0;
  }
 else
 {outtextxy(x-r2+35,y-50,"H");
  setcolor(4);
 c=0;
 }
 pp1(c);
 break;
 case 1:
 test(p);
 if(s[p].e==1)
 {setcolor(2);
 outtextxy(x,y-r2+30,"E");
  c=0;
 }
 else
 {setcolor(4);
 outtextxy(x,y-r2+30,"H");
 c=0;
 }
pp2(c);
 break;
 case 2:
 test(p);
 if(s[p].e==1)
 {setcolor(2);
 outtextxy(x+r2-35,y-50,"E");
 c=0;
 }
else
 {setcolor(4);
 outtextxy(x+r2-35,y-50,"H");
 c=0;
 }
 pp3(c);
 break;
 case 3:
 test(p);
 if(s[p].e==1)
 {setcolor(2);
 outtextxy(x+110,y+r2-70,"E");
 c=0;
}
else
{ setcolor(4);
 outtextxy(x+110,y+r2-70,"H");
c=0;
}
 pp4(c);
 break;
 case 4:
 test(p);
 if(s[p].e==1)
 {setcolor(2);
 outtextxy(x-110,y+r2-70,"E");
 c=0;
}
else
 {setcolor(4);
 outtextxy(x-110,y+r2-70,"H");
 c=0;
 }
pp5(c);
 break;
  case 5:
 s[0].e=0;
 setcolor(14);
 outtextxy(x-r2+35,y-50,"T");
 pp1(0);
 break;
 case 6:
 s[1].e=0;
 setcolor(14);
 outtextxy(x,y-r2+30,"T");
 pp2(0);
 break;
 case 7:
 s[2].e=0;
 setcolor(14);
 pp3(0);
 outtextxy(x+r2-35,y-50,"T");
 break;
 case 8:
 s[3].e=0;
 setcolor(14);
 pp4(0);
 outtextxy(x+110,y+r2-70,"T");
  break;
 case 9:
 s[4].e=0;
 setcolor(14);
 outtextxy(x-110,y+r2-70,"T");
 pp5(0);

 break;

 }
 i++;
}

getch();
closegraph();
}