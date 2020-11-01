int dir1=4;
int pwm1=3;

int dir2=5;
int pwm2=6;

int dir3=7;
int pwm3=9;

int dir4=12;
int pwm4=11;

int i=50;

void setup()
{
    pinMode(dir1,OUTPUT);
    pinMode(pwm1,OUTPUT);
    pinMode(dir2,OUTPUT);
    pinMode(pwm2,OUTPUT);
    pinMode(dir3,OUTPUT);
    pinMode(pwm3,OUTPUT);
    pinMode(dir4,OUTPUT);
    pinMode(pwm4,OUTPUT);
}


void loop()
{
    delay(5000);
    forward();
    delay(5000);
      
    backward();
    delay(5000);
    
    rightshift();
    delay(5000);
    
    leftshift();
    delay(5000);
    
    diagonalrightfront();
    delay(5000);
    
    diagonalrightback();
    delay(5000);
    
    diagonalleftfront();
    delay(5000);
    
    diagonalleftback();
    delay(5000);
    
}





void forward()
{
    digitalWrite(dir1,HIGH);
    analogWrite(pwm1,i);
    digitalWrite(dir2,LOW);
    analogWrite(pwm2,i);
    digitalWrite(dir3,LOW);
    analogWrite(pwm3,i);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm4,i);
    
}

void backward()
{
    digitalWrite(dir1,LOW);
    analogWrite(pwm1,i);
    digitalWrite(dir2,HIGH);
    analogWrite(pwm2,i);
    digitalWrite(dir3,HIGH);
    analogWrite(pwm3,i);
    digitalWrite(dir4,LOW);
    analogWrite(pwm4,i);
    
}

void rightshift()
{
    digitalWrite(dir1,LOW);
    analogWrite(pwm1,i);
    digitalWrite(dir2,LOW);
    analogWrite(pwm2,i);
    digitalWrite(dir3,HIGH);
    analogWrite(pwm3,i);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm4,i);
}

void leftshift()
{
    digitalWrite(dir1,HIGH);
    analogWrite(pwm1,i);
    digitalWrite(dir2,HIGH);
    analogWrite(pwm2,i);
    digitalWrite(dir3,LOW);
    analogWrite(pwm3,i);
    digitalWrite(dir4,LOW);
    analogWrite(pwm4,i);
}

void diagonalrightfront()
{
    digitalWrite(dir1,LOW);
    analogWrite(pwm1,0);
    digitalWrite(dir2,LOW);
    analogWrite(pwm2,i);
    digitalWrite(dir3,LOW);
    analogWrite(pwm3,0);
    digitalWrite(dir4,HIGH);
    analogWrite(pwm4,i);
}

void diagonalrightback()
{
    digitalWrite(dir1,LOW);
    analogWrite(pwm1,0);
    digitalWrite(dir2,HIGH);
    analogWrite(pwm2,i);
    digitalWrite(dir3,LOW);
    analogWrite(pwm3,0);
    digitalWrite(dir4,LOW);
    analogWrite(pwm4,i);
}


void diagonalleftfront()
{
    digitalWrite(dir1,HIGH);
    analogWrite(pwm1,i);
    digitalWrite(dir2,LOW);
    analogWrite(pwm2,0);
    digitalWrite(dir3,LOW);
    analogWrite(pwm3,i);
    digitalWrite(dir4,LOW);
    analogWrite(pwm4,0);
}

void diagonalleftback()
{
    digitalWrite(dir1,LOW);
    analogWrite(pwm1,i);
    digitalWrite(dir2,LOW);
    analogWrite(pwm2,0);
    digitalWrite(dir3,HIGH);
    analogWrite(pwm3,i);
    digitalWrite(dir4,LOW);
    analogWrite(pwm4,0);
}