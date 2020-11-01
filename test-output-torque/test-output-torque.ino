#define d1 12
#define p1 11

#define d2 4
#define p2 5

#define d3 7
#define p3 6

#define d4 2
#define p4 9
int i;
int j=A0;
void setup() {
  // put your setup code here, to run once:
  pinMode(d1, OUTPUT);
  pinMode(p1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(p4, OUTPUT);
  pinMode(j, INPUT);
  Serial.begin(9600);
}

void loop() {
  j=analogRead(A0);
  i=map(j,0,1024,0,255);
  Serial.println(i);
  delay(1);
  // put your main code here, to run repeatedly:
 // forward();
//  delay(3000);
 backward();
//  delay(3000);
//  leftshift();
//  delay(3000);
//  rightshift();
//  delay(3000);
//  diagonalleftfront();
//  delay(3000);
//  diagonalleftback();
//  delay(3000);
//  diagonalrightfront();
//  delay(3000);
//  diagonalrightback();
//  delay(3000);
//  clockwise();
//  delay(3000);
//  anticlockwise();
//  delay(3000);
}
