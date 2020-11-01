const int m1  = 7;  
const int m2  = 6;  
const int m3  = 5; 
const int m4  = 4;  
int EnableA=9;
int EnableB=10;


void setup() {
  Serial.begin(9600);
  
 
    pinMode(22,INPUT);
    pinMode(23,INPUT);
    pinMode(24,INPUT);
    pinMode(25,INPUT);
    pinMode(26,INPUT);
    pinMode(27,INPUT);
    pinMode(28,INPUT);
    pinMode(29,INPUT);
    pinMode(EnableA,OUTPUT);
    pinMode(EnableB,OUTPUT);                                  
    //Set pins as outputs
    pinMode(m1,OUTPUT);
    pinMode(m2,OUTPUT);
    pinMode(m3,OUTPUT);
    pinMode(m4,OUTPUT);
    analogWrite(EnableA,255);
    analogWrite(EnableB,255);
 wait();

}

void loop() {
  // Checking for junction crossing, if juction detected, 
  // keep moving forward
  if(digitalRead(24) || digitalRead(27))
  {
    Serial.println("forward");
  forward();
  }
  // Checking for sensor number 1 and 2, if line detected, move left
  else if(digitalRead(22) || digitalRead(23))
  {
    Serial.println("left");
  left();
  }

  // Checking for sensor number 5 and 6, if line detected, move right
  else if(digitalRead(29) || digitalRead(28))
  {
    Serial.println("right");
  right();
  }
  // Checking for sensors number 3 and 4, 
  // if line is detected by either of these sensor, move forward
 else if(digitalRead(25) || digitalRead(26))
 {
  Serial.println("forward");
  forward();
 }
 
  // If no line is detected, stay at the position
  else
  {
    Serial.println("wait");
  //wait();
  }

  // Put some delay to avoid the robot jig while making a turn
  delay(100);

}
