
import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;

/*
<applet code="screensaver" width=300 height=200>
</applet>
*/

public class Screensaver extends Applet implements Runnable{
    Thread t;
 int x[]=new int[40];
 int y[]=new int[40];
int r[]=new int[40];
int b[]=new int[40];
//int g[]=new int[40];

int a[]=new int[40];
int i,j,rr,gg,bb;
    void display()
    {
    t=new Thread(this);
    t.start();
    }
   public void run()
   {try

   {
        while(true)
        {
        for( i=0;i<40;i++)
      {  x[i]=(int)(Math.random()*1000);
         r[i]=(int)(Math.random()*256);
         a[i]=(int)(Math.random()*256);

       b[i]=(int)(Math.random()*256);
       //g[i]=(int)(Math.random()*255);

       //c[i]=rand() % 15;
       y[i]=(int)(Math.random()*700);

     }


      for( j=0;j<50;j++)
      {
	repaint();
     Thread.sleep(50);

    
   }
    }
    }
    catch(Exception e)
    {}
   }
 public void init()
 {setBackground(Color.black);
   this.display();
 }

 public void paint(Graphics g)
    {
     //while(true)
     {                   g.setColor(Color.red);
                      // g.drawLine(100,100,200,200);
                                for( i=0;i<40;i++)
                                { rr=r[i];
                                  gg=a[i];
                                  bb=b[i];
                                                                     
                                    Color c=new Color(rr,gg,bb);
                                    g.setColor(c);
                                  g.drawOval(x[i], y[i], 2 + j, 2 + j);
                                   g.drawOval(x[i], y[i], 2 + j+1, 2 + j+1);

                                }
                                    //  g.wait(100);
                       // Thread.sleep(150);
                        //g.setColor(Color.black);
                        //g.drawOval(x[i], y[i], j, j);
                        // } //catch (InterruptedException ex) {
                        //  }


    }
     }
 
}



