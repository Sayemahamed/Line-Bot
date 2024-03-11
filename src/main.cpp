#include <Arduino.h>
#include<stack>
bool rightF = false, rightR = false, pRightF = false, pRightR = false;
bool leftF = false, leftR = false, pLeftF = false, pLeftR = false;
bool lineFollowBot = false;
void reset(int timer){
    digitalWrite(8,0);
    digitalWrite(9,0);
    digitalWrite(10,0);
    digitalWrite(11,0);
    pRightF= rightF;
    rightF=false;
    pRightR =rightR;
    rightR=false;
    pLeftF =leftF;
    leftF= false;
    pLeftR= leftR;
    leftR= false;
    delay(timer);
}
void executeRemoteCommand(){
  if(leftF and !leftR){
    digitalWrite(11,1);
    digitalWrite(10,0);
  }
  if(leftR and !leftF){

    digitalWrite(10,1);
    digitalWrite(11,0);
  }
  if(rightF and !rightR){
    digitalWrite(8,1);
    digitalWrite(9,0);
  }
  if(rightR and !rightF){
    digitalWrite(9,1);
    digitalWrite(8,0);
  }
  delay(200);
}
void command()
{
  Serial.println("hello");
  int temp=Serial.read();
  Serial.println(temp);
  if (temp == 49)
  {
    leftF = true;
    leftR = false;
  }
  if(temp==51){
    leftR=true;
    leftF=false;
  }
  if(temp==50){
    rightF=true;
    rightR=false;
  }
  if(temp==52){
    rightR=true;
    rightF=false;
  }
}
void getCommand()
{
  if (Serial.available() > 0)
    command();
  if (Serial.available() > 0)
    command();
}
void setMode()
{
  if (Serial.available() > 0)
  {
    if (Serial.read() == 53)
      lineFollowBot = true;
  }
  if (Serial.available() > 0)
  {
    if (Serial.read() == 54)
      lineFollowBot = false;
  }
}
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  setMode();
  if (lineFollowBot)
  {
  }
  else
  {
    getCommand();
    // executeRemoteCommand();
    // reset(1);
  }
}
