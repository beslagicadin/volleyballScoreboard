//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,1);

int data = 0;

int D1=0,G1=0;
int Sg=0, Sd=0;
void setup() {
  Serial.begin(9600);
/*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
  lc.setRow(0,0,001);
  lc.setDigit(0,1,0,false);
  lc.setDigit(0,2,0,false);
  lc.setDigit(0,3,0,false);
  lc.setDigit(0,4,0,false);
  lc.setDigit(0,5,0,false);
  lc.setDigit(0,6,0,false);
}




void loop() { 
  if(Serial.available()>0)
    {
      data=Serial.parseInt();
      
      if(data==1)
        domaciPlus();
        
      if(data==2)
        domaciMinus();
        
      if(data==3)
        gostiPlus();
        
      if(data==4)
        gostiMinus();  
    }
    
    
    
    
    
  //writeArduinoOn7Segment();
  
}

void setG()
{
  if((G1-D1)==2)
  {
    D1=0;
    G1=0;
    Sg++;
  } 
}

void gostiPlus()
  {
    G1++;
    int prva=G1/10;
    if(G1>9)
      {
        //gosti1
        lc.setDigit(0,1,prva,false);
        //gosti2
        lc.setDigit(0,2,G1%10,false);
      }
    else
      {
        //gosti1
        lc.setDigit(0,2,G1,false);
        lc.setDigit(0,1,0,false);
       if(G1==25)
        {Serial.println("G25");
        }
      }
   }

   void domaciPlus()
  {
    D1++;
    int prva=D1/10;
    if(D1>9)
      {
        //domacii1
        lc.setDigit(0,5,prva,false);
        //gosti2
        lc.setDigit(0,4,D1%10,false);
      }
    else
      {
        //domaci1
        lc.setDigit(0,4,D1,false);
        lc.setDigit(0,5,0,false);
      }
     if(D1==25)
      {
        Serial.println("D25");
        }
   }
void domaciMinus()
  {
    D1--;
    int prva=D1/10;
    if(D1>9)
      {
        //domacii1
        lc.setDigit(0,5,prva,false);
        //gosti2
        lc.setDigit(0,4,D1%10,false);
      }
    else
      {
        //domaci1
        lc.setDigit(0,4,D1,false);
        lc.setDigit(0,5,0,false);
      }
   }
void gostiMinus()
  {
    G1--;
    int prva=G1/10;
    if(G1>10)
      {
        //gosti1
        lc.setDigit(0,1,prva,false);
        //gosti2
        lc.setDigit(0,2,G1%10,false);
      }
    else
      {
        //gosti1
        lc.setDigit(0,2,G1,false);
        lc.setDigit(0,1,0,false);
      }
   }
void writeArduinoOn7Segment() {
lc.setDigit(0,0,8,false);
lc.setDigit(0,1,1,false);
lc.setDigit(0,2,5,false);
lc.setDigit(0,3,2,false);
lc.setDigit(0,4,8,false);
lc.setChar(0,5,2,false);
lc.setChar(0,6,2,false);
} 

