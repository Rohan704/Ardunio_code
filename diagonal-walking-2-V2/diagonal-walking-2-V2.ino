#include<VarSpeedServo.h>
#include <Psx.h>
#define dataPin 10
#define cmndPin 11
#define attPin 12
#define clockPin 13
Psx Psx;
unsigned int data = 0;

int fm=80;   //fm-fastmovement
int sm=25;   //sm-slowmovement
VarSpeedServo myservo1;
VarSpeedServo myservo2;
VarSpeedServo myservo3;
VarSpeedServo myservo4;
VarSpeedServo myservo5;
VarSpeedServo myservo6;
VarSpeedServo myservo7;
VarSpeedServo myservo8;
int pos=0;

void setup() {
Serial.begin(9600);
Psx.setupPins(dataPin, cmndPin, attPin, clockPin, 10);
myservo1.attach(2);
myservo2.attach(3);
myservo3.attach(4);
myservo4.attach(5);
myservo5.attach(6);
myservo6.attach(7);
myservo7.attach(8);
myservo8.attach(9);
}

void loop() {
data = Psx.read();
if(data==1)
{
  test();
}
else if(data==32)
{
  Boff();
}
else if(data==8)
{
  walk();
}
if(data==32768)
{
  liftL1();
}
else if(data==8192)
{
  liftL2();
}
else if(data==16384)
{
  liftR1();
}
else if(data==4096)
{
  liftR2();
}
else if(data==512)
{
  liftR2();
  liftL2();
}
else if(data==2048)
{
  liftR1();
  liftL1();
}
else if(data==256)
{
  liftL1();
  liftR2();
}
else if(data==1024)
{
  liftR1();
  liftL2();
}
else if(data==64)
{
  liftR1();
  liftL2();
  liftL1();
  liftR2();
  //delay(500);
}
else
{
  myservo1.write(120,40);
  myservo2.write(60,40);
  myservo3.write(120,40);
  myservo4.write(60,40);
  myservo5.write(120,40);     ////to changed to 120 after correcting mechnical issue(-20)error & subsequent change in further loop required
  myservo6.write(60,40);      ////to changed to 60 after correcting mechnical issue(+15)error & subsequent change in further loop required
  myservo7.write(120,40);
  myservo8.write(60,40);  
}
Serial.println(data);
}


void test()
{
for(pos=0;pos<=180;pos+=1)
{
  myservo1.write(pos,40);
  myservo2.write(pos,40);
  myservo3.write(pos,40);
  myservo4.write(pos,40);
  myservo5.write(pos,40);
  myservo6.write(pos,40);
  myservo7.write(pos,40);
  myservo8.write(pos,40);
  delay(10);
}
for(pos=180;pos>=0;pos-=1)
{
  myservo1.write(pos,40);
  myservo2.write(pos,40);
  myservo3.write(pos,40);
  myservo4.write(pos,40);
  myservo5.write(pos,40);
  myservo6.write(pos,40);
  myservo7.write(pos,40);
  myservo8.write(pos,40);
   delay(15);
}
}


void lift()
{
  for(pos=120;pos>=60;pos-=1)
  {
    myservo1.write(pos,40);
    myservo3.write(pos,40);
    myservo5.write(pos,40);
    myservo7.write(pos,40);
  }
  for(pos=60;pos<=120;pos+=1)
  {
    myservo2.write(pos,40);
    myservo4.write(pos,40);
    myservo6.write(pos,40);
    myservo8.write(pos,40);
  }
  delay(100);
}

void walk()
{  //lift servos 1 2 5 6 //
  for(pos=120;pos>=90;pos-=1)     
  {
    myservo1.write(pos,fm);
  }
 for(pos=120;pos>=90;pos-=1)
    {
    myservo5.write(pos,fm);
  }
  for(pos=60;pos<=90;pos+=1)
  {
    myservo2.write(pos,fm);
  }
    for(pos=60;pos<=90;pos+=1)
    {
     myservo6.write(pos,fm);
    }
 delay(300);

 
 //taking leg ahead moving servo 2 5 front//
// for(pos=90;pos<=110;pos+=1)
// {
//  myservo1.write(pos,fm);
// }
// for(pos=90;pos>=70;pos-=1)
// {
//  myservo6.write(pos,fm);
// }
  for(pos=90;pos>=40;pos-=1)   
  {
    myservo2.write(pos,fm);
  }
  for(pos=120;pos<=170;pos+=1)
  {
    myservo5.write(pos,fm);
  }
  
  //delay(115);
  
  for(pos=120;pos>=90;pos-=1)     
  {
    myservo7.write(pos,sm); 
  }
  for(pos=60;pos<=90;pos+=1)
  {
    myservo4.write(pos,sm);
  }
  for(pos=120;pos<=140;pos+=1)
  {
    myservo3.write(pos,sm);
  }
  for(pos=60;pos>=20;pos-=1)
  {
    myservo8.write(pos,sm);
  }
delay(300);

//////////////for robot to go ahead ,takes leg behind moving servos 1 2 5 6 //////////////////
for(pos=90;pos<=150;pos+=1)  
  {
    myservo1.write(pos,sm);
  }
  for(pos=90;pos>=30;pos-=1)
  {
    myservo6.write(pos,sm);
  }
  for(pos=40;pos<=90;pos+=1)
  {
    myservo2.write(pos,sm);
  }
  for(pos=170;pos>=90;pos-=1)
  {
    myservo5.write(pos,sm);
  }

//delay(2000);
  
  for(pos=20;pos<=90;pos+=1)
  {
    myservo8.write(pos,fm);
  }
  for(pos=140;pos>=90;pos-=1)
  {
    myservo3.write(pos,fm);
  }
//  delay(100);
  delay(150);
  
  for(pos=90;pos<=140;pos+=1)  
  {
    myservo7.write(pos,fm);
  }
  for(pos=90;pos>=40;pos-=1)
  {
    myservo4.write(pos,fm);
  }
  delay(300);
 }
