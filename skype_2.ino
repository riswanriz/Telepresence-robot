#define m11 6 //setting 6-13 pins for motor driver and 2-5 pins for DTMF
#define m12 7
#define m21 8
#define m22 9
#define m31 10
#define m32 11
#define m41 12
#define m42 13
#define D0 2
#define D1 3
#define D2 4
#define D3 5
void forward()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
   digitalWrite(m31, LOW);
   digitalWrite(m32, LOW);
   digitalWrite(m41, LOW);
   digitalWrite(m42, LOW);
}
void backward()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH);
   digitalWrite(m31, LOW);
   digitalWrite(m32, LOW);
   digitalWrite(m41, LOW);
   digitalWrite(m42, LOW); 
}
void left()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH);
   digitalWrite(m31, LOW);
   digitalWrite(m32, LOW);
   digitalWrite(m41, LOW);
   digitalWrite(m42, LOW);
}
void right()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
   digitalWrite(m31, LOW);
   digitalWrite(m32, LOW);
   digitalWrite(m41, LOW);
   digitalWrite(m42, LOW);
}
void Stop()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
   digitalWrite(m31, LOW);
   digitalWrite(m32, LOW);
   digitalWrite(m41, LOW);
   digitalWrite(m42, LOW);
} 
void up()
{
    digitalWrite(m31,HIGH);
    digitalWrite(m32,LOW);
    digitalWrite(m11, LOW);
    digitalWrite(m12, LOW);
    digitalWrite(m21, LOW);
    digitalWrite(m22, LOW);
    digitalWrite(m41, LOW);
    digitalWrite(m42, LOW);


}
void down()
{
    digitalWrite(m31,LOW);
    digitalWrite(m32,HIGH);
    digitalWrite(m11, LOW);
    digitalWrite(m12, LOW);
    digitalWrite(m21, LOW);
    digitalWrite(m22, LOW);
    digitalWrite(m41, LOW);
    digitalWrite(m42, LOW);


}
void hold()
{
    digitalWrite(m41,HIGH);
    digitalWrite(m42,LOW);
    digitalWrite(m11, LOW);
    digitalWrite(m12, LOW);
    digitalWrite(m21, LOW);
    digitalWrite(m22, LOW);
    digitalWrite(m31, LOW);
    digitalWrite(m32, LOW);

}
void rel()
{
    digitalWrite(m41,LOW);
    digitalWrite(m42,HIGH);
    digitalWrite(m11, LOW);
    digitalWrite(m12, LOW);
    digitalWrite(m21, LOW);
    digitalWrite(m22, LOW);
    digitalWrite(m31, LOW);
    digitalWrite(m32, LOW);
    
}
void setup() 
{
  Serial.begin(9600);
  pinMode(D0, INPUT);// initializing 2,3,4&5 pins of arduino as input
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(m11, OUTPUT);//initializing 6,7,8,9,10,11,12&13 pins of arduino as output
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  pinMode(m31, OUTPUT);
  pinMode(m32, OUTPUT);
  pinMode(m41, OUTPUT);
  pinMode(m42, OUTPUT);

}
void loop() 
{
  int temp1=digitalRead(D0);
  int temp2=digitalRead(D1);
  int temp3=digitalRead(D2);
  int temp4=digitalRead(D3);
 
  if(temp1==0 && temp2==0 && temp3==1 && temp4==0)//if 2 is pressed,robo moves forward
  {
   Serial.println("2");
   forward();
  }
  else if(temp1==0 && temp2==1 && temp3==0 && temp4==0)//if 4 is pressed,robo moves left
  {
    Serial.println("4");
    left();
  }
  else if(temp1==0 && temp2==1 && temp3==1 && temp4==0)//if 6 is pressed,robo moves right
  {
    Serial.println("6");
    right();
  }
  else if(temp1==1 && temp2==0 && temp3==0 && temp4==0)//if 8 is pressed,robo moves backword

  {
    Serial.println("8");
    backward();
  }
   else if(temp1==0 && temp2==0 && temp3==0 && temp4==1)//if 1 is pressed,arm moves up
   {
    Serial.println("1");
    up();
   }
   else if(temp1==0 && temp2==0 && temp3==1 && temp4==1)//if 3 is pressed,arm moves down
   {
    Serial.println("3");
    down();
   }
   else if(temp1==0 && temp2==1 && temp3==1 && temp4==1)//if 7 is pressed,arm open the jaw 
   {
    Serial.println("7");
    hold();
   }
   else if(temp1==1 && temp2==0 && temp3==0 && temp4==1)//if 9 is pressed,arm close the jaw
   {
    Serial.println("9");
    rel();
   }
   else if(temp1==0 && temp2==1 && temp3==0 && temp4==1)//if 5 is pressed,robo stop
   {
    Serial.println("5");
    Stop();
   }
   

}

