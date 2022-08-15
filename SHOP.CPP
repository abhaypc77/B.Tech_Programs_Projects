#include<string.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>
//struct date {
  //int da_year;     /* current year */
 // char da_day;     /* day of the month */
 // char da_mon;     /* month (1 = Jan) */
//};

struct cust{int cno,famt,lamt,tot,adv,bal;
	    char cn[25],rs[5],rc[5],rx[5],ls[5],lc[5],lx[5],fdes[15],ldes[15],
	     retdt[10];
	     struct date d;
	     struct time t;
	     }c;

 int cnum=0;
 void showdet()
 {clrscr();

  cout<<"CUSTOMER NO:"<<c.cno;
  cout<<"\nDATE of order was:";
  printf("%d-%d-%d",c.d.da_day,c.d.da_mon,c.d.da_year);
  printf("\t\t\tTIME : %2d:%02d:%02d.%02d\n",
c.t.ti_hour, c.t.ti_min, c.t.ti_sec, c.t.ti_hund);
  cout<<"\n\nNAME:"<<c.cn;
  cout<<"\n\nRIGHT EYE:                          LEFT EYE:";
  cout<<"\n----------                          ---------";
  cout<<"\nSPH="<<c.rs;
  cout<<"\t\t\tSPH="<<c.ls;
  cout<<"\nCYL="<<c.rc;
  cout<<"\t\t\tCYL="<<c.lc;
  cout<<"\nAXIS="<<c.rx;
  cout<<"\t\t\tAXIS="<<c.lx;
  cout<<"\n\nFRAME:"<<c.fdes<<"\t\t\tLENS:"<<c.ldes;
  cout<<"\nCOST :"<<c.famt<<"\t\t\tCOST:"<<c.lamt;
  cout<<"\n\nTOTAL:"<<c.tot;
  cout<<"\nADVANCE:"<<c.adv;
  cout<<"\nBALANCE:"<<c.bal;
  cout<<"\n\nRET. DATE:"<<c.retdt;
  }






 void main()
 {int ch,cn;
  char vdt[10], p[10];
  fstream obj,obj1;
  textcolor(2);
 while(1)
 {
 clrscr();
 cout<<"   MAIN -MENU";
 cout<<"\n 1-----take an order";
 cout<<"\n 2-----give the order";
 cout<<"\n 3-----view the orders";
 cout<<"\n 4-----veiw all customers";
 cout<<"\n 5-----exit";
 cout<<"\n enter your choice ";
 cin>>ch;
 switch(ch)
 {case 1:
  clrscr();
  getdate(&(c.d));
  cout<<"\nDATE :";
  printf("%d-%d-%d",c.d.da_day,c.d.da_mon,c.d.da_year);
  gettime(&(c.t));
  printf("\t\t\ttime : %2d:%02d:%02d.%02d\n",
c.t.ti_hour, c.t.ti_min, c.t.ti_sec, c.t.ti_hund);
 obj.open("customer.dat",ios::binary|ios::app);
 obj1.open("cnum.dat",ios::in|ios::binary);
//obj1.seekg(2,ios::end);
obj1.read((char*) &cnum,sizeof(cnum));

 cnum++;
 cout<<"\nenter the details for your coustomer no:"<<cnum;

 c.cno=cnum;
 obj1.close();
 obj1.open("cnum.dat",ios::out|ios::binary);
 obj1.write((char*)&cnum,sizeof(cnum));
 obj1.close();
 cout<<"\n\nenter the customer name ";
 gets(c.cn);
 cout<<"enter the right eye details:";
 cout<<"\nenter sph ";
 cin>>c.rs;
 cout<<"enter cyl ";
 cin>>c.rc;
 cout<<"enter axis ";
 cin>>c.rx;
 cout<<"enter the left eye details:";
 cout<<"\nenter sph ";
 cin>>c.ls;
 cout<<"enter cyl ";
 cin>>c.lc;
 cout<<"enter axis ";
 cin>>c.lx;
 cout<<"enter the frame description ";
 gets(c.fdes);
 cout<<"enter the frame amount ";
 cin>>c.famt;
 cout<<"enter the lens description ";
 gets(c.ldes);
 cout<<"enter the lens amt ";
 cin>>c.lamt;
 c.tot=c.famt+c.lamt;
 cout<<"total="<<c.tot;
 cout<<"\nenter the advance ";
 cin>>c.adv;
 c.bal=c.famt+c.lamt-c.adv;
 cout<<"balance="<<c.bal;
 cout<<"\nenter the returning dates:";
 cin>>c.retdt;

 obj.write((char*) &c,sizeof(c));
 obj.close();

  break;
 case 2:
  cout<<"enter the customer no. ";
  cin>>cn;
  obj.open("customer.dat",ios::binary|ios::in);


  while(!obj.eof())
  {obj.read((char*) &c,sizeof(c));
  if(cn==c.cno)
     {showdet();
       //cout<<"\nstatus=("<<c.status<<")";
       //cin>>c.status;
	getch();
	obj.close();
	break;
       }
   }

   break;
  case 3:
   cout<<"enter the date ";
  cin>>vdt;
  obj.open("customer.dat",ios::binary|ios::in);
  while(!obj.eof())
  {obj.read((char*) &c,sizeof(c));
  if(strcmp(vdt,c.retdt)==0)
    {showdet();
      getch();
     }
  }

  obj.close();
  break;
  case 4:
  obj.open("customer.dat",ios::binary|ios::in);
  while(!obj.eof())
  {obj.read((char*) &c,sizeof(c));
      showdet();
      getch();

  }

  obj.close();
   break;
  case 5:
  exit(0);
}

 }
 }