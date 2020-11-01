//L293D
//Motor A
const int m1  =7 ;  // Pin 14 of L293
const int m2  = 6;  // Pin 10 of L293
//Motor B
const int m3  = 5; // Pin  7 of L293
const int m4  = 4;  // Pin  2 of L293


int EnableA=9;
int EnableB=10;
//This will run only one time.
void setup()
{
    pinMode(EnableA, OUTPUT);
    pinMode(EnableB, OUTPUT);
    //Set pins as outputs
    pinMode(m1, OUTPUT);
    pinMode(m2, OUTPUT);
    pinMode(m3, OUTPUT);
    pinMode(m4, OUTPUT);
    analogWrite(EnableA,255);
    analogWrite(EnableB,255);
}

void loop()
{
  forward();
  delay(5000);
  right();
 delay(5000);
 left();
 delay(5000);
 wait();
 delay(5000);
}


void forward()
{
   digitalWrite(m1,LOW);
   digitalWrite(m2,HIGH);
   digitalWrite(m3,LOW);
   digitalWrite(m4,HIGH);
  }

  void right()
  {
    digitalWrite(m1,LOW);
   digitalWrite(m2,LOW);
   digitalWrite(m3,LOW);
   digitalWrite(m4,HIGH);
  }

  void left()
  {
   digitalWrite(m1,LOW);
   digitalWrite(m2,HIGH);
   digitalWrite(m3,LOW);
   digitalWrite(m4,LOW);
  }
void wait()
{
   digitalWrite(m1,LOW);
   digitalWrite(m2,LOW);
   digitalWrite(m3,LOW);
   digitalWrite(m4,LOW);
}
