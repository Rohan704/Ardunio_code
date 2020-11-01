void liftL1()
{
  myservo1.write(60,20);
  myservo2.write(120,20);
//  myservo3.write(140,20);
//  myservo4.write(40,20);
//  myservo5.write(110,20);
//  myservo6.write(70,20);
//  myservo7.write(110,20);
//  myservo8.write(70,20);
}

void liftL2()
{
//  myservo1.write(140,20);
//  myservo2.write(40,20);
  myservo3.write(60,20);
  myservo4.write(120,20);
//  myservo5.write(110,20);
//  myservo6.write(70,20);
//  myservo7.write(110,20);
//  myservo8.write(70,20);
}

void liftR1()
{
//  myservo1.write(110,20);
//  myservo2.write(70,20);
//  myservo3.write(110,20);
//  myservo4.write(70,20);
//  myservo5.write(140,20);
//  myservo6.write(40,20);
  myservo7.write(60,20);
  myservo8.write(120,20);
}

void liftR2()
{
//  myservo1.write(110,20);
//  myservo2.write(70,20);
//  myservo3.write(110,20);
 // myservo4.write(70,20);
  myservo5.write(60,20);
 myservo6.write(120,20);
//  myservo7.write(140,20);
//  myservo8.write(40,20);
}

void Boff()
{
  myservo1.write(150,20);
  myservo2.write(30,20);
  myservo3.write(150,30);
  myservo4.write(30,20);
  myservo5.write(150,30);
  myservo6.write(30,20);
  myservo7.write(150,30);
  myservo8.write(30,20);
  delay(500);
  myservo1.detach();
  myservo2.detach();
  myservo3.detach();
  myservo4.detach();
  myservo5.detach();
  myservo6.detach();
  myservo7.detach();
  myservo8.detach();
  delay(1000);
}
