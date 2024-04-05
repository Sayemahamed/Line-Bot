#include <Arduino.h>
bool right = false;
bool left = false;
int rightCount=0,leftCount=0;
void setup()
{
}
void loop()
{
  bool a = digitalRead(2);
  bool b = digitalRead(3);
  if (!a){
    right = true;
    rightCount=0;
  }
  else{
    right = false;
    rightCount++;
  }
  if (!b){
    left = true;
    leftCount=0;
  }
  else{
   left=false;
  leftCount++;
  }
  if(rightCount>8 and leftCount>8)
  delay(400);
    

  if(right)
  digitalWrite(8,1);
  else digitalWrite(8,0);
  if(left)
  digitalWrite(11,1);
  else digitalWrite(11,0);

  if(rightCount>3)
  digitalWrite(9,1);
  if(leftCount>3)
  digitalWrite(10,1);
  delay(40);
  digitalWrite(8,0);
  digitalWrite(9,0);
  digitalWrite(10,0);
  digitalWrite(11,0);
  delay(30);
}
