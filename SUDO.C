#include<conio.h>
#include<stdio.h>

int a[9][9];

void insert()
{int i,j;
 //clrscr();
 for(i=0;i<9;i++)
 {printf("\nenter the col no.%d\n",i+1);
  for(j=0;j<9;j++)
   scanf("%d",&a[j][i]);
 }
}

void  display()
{int i,j;
 //clrscr();
for (i=0;i<9;i++)
   {  if(i%3==0)
       printf("\n");
      printf("\n\t\t");
      for (j=0;j<9;j++)
      {if(j%3==0)
       printf(" ");
       printf("%d ",a[i][j]);
       }
    }
 }
void correct()
{int i,j,n;
 printf("enter the row no.");
 scanf("%d",&i);
 printf("enter the coloumn no.");
 scanf("%d",&j);
 printf("now enter the correct value");
 scanf("%d",&n);
 a[i-1][j-1]=n;
 //clrscr();
  printf("value updated");
  display();
   printf("\npress n for any correction\n else press any key to continue");
   if(getch()=='n')
   correct();

  }



int avail(int i,int j,int n)
{int t1=1,t2=1,x;
  for(x=0;x<9;x++)
   {if(a[i][x]==n)
      {t1=0;
       break;
       }
    }
 for(x=0;x<9;x++)
   {if(a[x][j]==n)
      {t2=0;
       break;
       }
    }

 if(t1==1&&t2==1)
 return (1);
 else
 return(0);
}




 void checks(int i,int j)
{int n,x,y,t,p,count,l1,l2;
 for(n=1;n<10;n++)
  {p=0;
   for(x=i;x<i+3;x++)
     {for(y=j;y<j+3;y++)
       {if(a[x][y]==n)
	  {p=1;
	   break;
	  }
	}
      }
    if(p==0)
   { count=0;
    for(x=i;x<i+3;x++)
     {for(y=j;y<j+3;y++)
       {t=0;
	if(a[x][y]==0)
	t=avail(x,y,n);
	if(t==1)
	{count++;
	l1=x;
	l2=y;
	}

       }
      }
     if(count==1)
     a[l1][l2]=n;
   }
 }
}

int full()
{int x,y,co=0;
 for(x=0;x<9;x++)
 for(y=0;y<9;y++)
  if(a[x][y]==0)
    co=1;
  return(co);
}

int availc(int j,int n)
{int t=1,x;
 for(x=0;x<9;x++)
   {if(a[x][j]==n)
      {t=0;
      break;
      }
    }
 return(t);
}

int avails(int i,int j,int n)
{int t=1,x,y,u,v;
if(i<3&&j<3)
  {x=0;
   y=0;
  }
  else
  if(i<3&&j>2&&j<6)
   {x=0;
    y=3;
   }
  else
  if(i<3&&j>5)
   {x=0;
    y=6;
   }
  else
  if(i>2&&i<6&&j<3)
   {x=3;
    y=0;
   }
    else
  if(i>2&&i<6&&j>2&&j<6)
   {x=3;
    y=3;
   }
   else
  if(i>2&&i<6&&j>5)
   {x=3;
    y=6;
   }
   else
  if(i>5&&j<3)
   {x=6;
    y=0;
   }
    else
  if(i>5&&j>2&&j<6)
   {x=6;
    y=3;
   }
   else
  if(i>5&&j>5)
   {x=6;
    y=6;
   }
 for(u=x;u<x+3;u++)
 {for(v=y;v<y+3;v++)
   {if(a[u][v]==n)
       {t=0;
	break;
	}
    }
  }
   return(t);
}
int availc1(int i,int n)
{int t=1,x;
 for(x=0;x<9;x++)
   {if(a[i][x]==n)
      {t=0;
      break;
      }
    }
 return(t);
}


void checkc(int j )
{int n,count,l1,l2,p,x,t1,t2;
 for(n=1;n<10;n++)
 {p=0;
  for(x=0;x<9;x++)
    {if(a[x][j]==n)
       {p=1;
       break;
       }
     }

  if(p==0)
  {count=0;
  for(x=0;x<9;x++)
    {if(a[x][j]==0)
      {
       t1=availc1(x,n);
       t2=avails(x,j,n);
       if(t1==1&&t2==1)
	 {l1=x;
	  l2=j;
	  count++;
	 }
	}
      }
    if(count==1)
    a[l1][l2]=n;
  }
}

}


void checkr(int i)
{int n,count,l1,l2,p,x,t1,t2;
 for(n=1;n<10;n++)
 {p=0;
  for(x=0;x<9;x++)
    {if(a[i][x]==n)
       {p=1;
       break;
       }
     }

  if(p==0)
  {count=0;
  for(x=0;x<9;x++)
    {if(a[i][x]==0)
      {
       t1=availc(x,n);
       t2=avails(i,x,n);
       if(t1==1&&t2==1)
	 {l1=i;
	  l2=x;
	  count++;
	 }
	}
      }
    if(count==1)
    a[l1][l2]=n;
  }
}

}





 int main()
 {int i,j,co=1;
 //clrscr();
 printf(" please follow the following rules\n");
 printf(" ---------------------------------");
 printf("\n\n1---enter your sudoku column wise\n\n2---enter '0' for null values\n\n3---you can make any correction \n    only after entering all entries");
 printf("\n\n\n press any key to continue....");
   getch();
   insert();
    display();
   printf("\npress n for any correction \n else press any key to continue...");
   if(getch()=='n')
   correct();
    while(co==1)
   {
     for(i=0;i<9;i=i+3)
     {for (j=0;j<9;j=j+3)
      {checks(i,j);
       co=full();
       if(co==0)
	{//clrscr();
	display();
	 printf("\n\n\n\nCOPY RIGHT");
	 printf("\n----------");
	 printf("\nAbhay prakash chaudhary");
	 printf("\ncomputer science");
	 printf("\nB.Tech(2nd year)");
	 getch();
	//exit(0);
	}
       }
      }

      for(i=0;i<9;i++)
      checkr(i);
      for(j=0;j<9;j++)
      checkc(j);

     }
  return(1);
}
