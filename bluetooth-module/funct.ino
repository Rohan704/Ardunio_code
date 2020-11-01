void forward()
{
  digitalWrite(d1, HIGH);
  analogWrite(p1, i);
  digitalWrite(d2, HIGH);
  analogWrite(p2, i);
  digitalWrite(d3, HIGH);
  analogWrite(p3, i);
  digitalWrite(d4, HIGH);
  analogWrite(p4, i);
}
void backward()
{
  digitalWrite(d1, LOW);
  analogWrite(p1, i);
  digitalWrite(d2, LOW);
  analogWrite(p2, i);
  digitalWrite(d3, LOW);
  analogWrite(p3, i);
  digitalWrite(d4, LOW);
  analogWrite(p4, i);
}

void leftshift()
{
  digitalWrite(d1, HIGH);
  analogWrite(p1, i);
  digitalWrite(d2, LOW);
  analogWrite(p2, i);
  digitalWrite(d3, HIGH);
  analogWrite(p3, i);
  digitalWrite(d4, LOW);
  analogWrite(p4, i); 
}

void rightshift()
{
  digitalWrite(d1, LOW);
  analogWrite(p1, i);
  digitalWrite(d2, HIGH);
  analogWrite(p2, i);
  digitalWrite(d3, LOW);
  analogWrite(p3, i);
  digitalWrite(d4, HIGH);
  analogWrite(p4, i); 
}

void halt()
{
  digitalWrite(d1, LOW);
  analogWrite(p1, 0);
  digitalWrite(d2, LOW);
  analogWrite(p2, 0);
  digitalWrite(d3, LOW);
  analogWrite(p3, 0);
  digitalWrite(d4, LOW);
  analogWrite(p4, 0);
}

void diagonalleftfront()
{
  digitalWrite(d1, HIGH);
  analogWrite(p1, i);
  digitalWrite(d3, HIGH);
  analogWrite(p3, i);
}
void diagonalleftback()
{
  digitalWrite(d1, LOW);
  analogWrite(p1, i);
  digitalWrite(d3, LOW);
  analogWrite(p3, i);
}

void diagonalrightfront()
{
  digitalWrite(d2, HIGH);
  analogWrite(p2, i);
  digitalWrite(d4, HIGH);
  analogWrite(p4, i);
}
void diagonalrightback()
{
  digitalWrite(d2, LOW);
  analogWrite(p2, i);
  digitalWrite(d4, LOW);
  analogWrite(p4, i);
}
