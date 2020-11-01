/***************************BLUETOOTH CONTROLLED CAR CODE**************************/

//Declare the arduino pins

#define d1 12
#define p1 11

#define d2 4
#define p2 5

#define d3 7
#define p3 6

#define d4 2
#define p4 9
int i = 150;

void setup()
{
  //initlize the mode of the pins
 pinMode(d1, OUTPUT);
  pinMode(p1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(p4, OUTPUT);

   //set the serial communication rate
  Serial.begin(9600);
}

void loop()
{
  //check whether arduino is reciving signal or not 
  while(Serial.available() == 0);
  char val = Serial.read() ;//reads the signal
 // int i=Serial.read();
  Serial.print(val);

  /*********For Forward motion*********/
  
  if (val == 'F')
  {
    Serial.println("FORWARD");
 forward();
    
  }

 
    /*********For Backward Motion*********/
  else if(val == 'B')
  {
  Serial.println("BACK");
backward();
  
  }
   /*********Right*********/
  else if(val == 'R')
  {
  Serial.println("RIGHT");
  leftshift();
  }
   /*********Left*********/
  else if(val == 'L')
  {
   Serial.println("LEFT");
 rightshift();
  
  }

  else if(val == 'I')
  {
   Serial.println("LEFT");
diagonalleftfront();
  
  }

  else if(val == 'J')
  {
   Serial.println("LEFT");
 diagonalleftback();
  
  }

  else if(val == 'G')
  {
   Serial.println("LEFT");
 diagonalrightfront();
  
  }

  else if(val == 'H')
  {
   Serial.println("LEFT");
 diagonalrightback();
  
  }
//   /*********Horn*********/
// else if(val == 'V')
//  {
//  digitalWrite(horn,HIGH);
//  }
//else if(val == 'v')
//  {
//    digitalWrite(horn,LOW);
//  }
//  
//  /*********Front Lights*********/
//  else if(val == 'W')
//  {
//  digitalWrite(fl,HIGH);
//  }
//  else if(val == 'w')
//  {
//    digitalWrite(fl,LOW);
//  }
//  /*********Back Lights*********/
//  else if(val == 'U')
//  {
//    digitalWrite(bl,HIGH);
//  }
//  else if(val == 'u')
//  {
//    digitalWrite(bl,LOW);
//  }
//  /*********STOP*********/
  else
  {
  Serial.println("Invalid!!!");
halt();

  }
  
}
