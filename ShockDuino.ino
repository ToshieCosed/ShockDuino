#include "rffunc.h" // Get rffunc.h from https://github.com/Johonis/arduino-pet-collar-control
#include "StringSplitter.h" //Install this library from: https://github.com/aharshac/StringSplitter
String command_ = "Vibrate"; //Temp Value
String commandvalue_ = "0"; //Temp Value
int shockpower_ = 0; //Store the shock power
int vibepower_ = 0; //Store the vibe power

const int shock = 0;
const int vibrate = 1;
const int sound = 2;


//Put Batteries back into collar right at startup on Arduino.
void setup() {
 
  pinMode(outPin, OUTPUT);
  Serial.begin(9600);
  int str = 0;
  
  buttonPress();
}

void buttonPress()
{
  //0 = shock, 1 = vibration, 2 = sound
  int strength = 50;
  int type = 1;
  execute(strength, type);
  execute(strength, type);
  execute(strength, type);
  execute(strength, type);
}

void loop() {
  // put your main code here, to run repeatedly:t
//execute(1, 100);
recv_func(); //Receive over serial, the commands, can be changed to any input system for Arduino.
delay(500);
}

void recv_func(){


 if (Serial.available() > 0 ){
    Serial.println("Trying to read serial now, last command was: : " + command_);
    String str = Serial.readString();
    //Search the string for various params
    
    
    int result = (str.indexOf("SetShockPower"));
    Serial.println("The index of containing SetShockPower was " + String(result));
    if (result >-1){
    command_ = "SetShock";
    StringSplitter *splitter = new StringSplitter(str, ',', 2);  // new StringSplitter(string_to_split, delimiter, limit)
    int itemCount = splitter->getItemCount();
    for(int i = 0; i < itemCount; i++){
    String item = splitter->getItemAtIndex(i);
    if (i==1){commandvalue_ = item;
    Serial.println("String is " + String(command_) + " : " + String(commandvalue_) );
    }
    }

    shockpower_ = commandvalue_.toInt();
    }

    result = (str.indexOf("SetVibePower"));
    Serial.println("The index of containing SetVibePower was " + String(result));
    if (result >-1){
    command_ = "SetVibe";
    StringSplitter *splitter = new StringSplitter(str, ',', 2);  // new StringSplitter(string_to_split, delimiter, limit)
    int itemCount = splitter->getItemCount();
    for(int i = 0; i < itemCount; i++){
    String item = splitter->getItemAtIndex(i);
    if (i==1){commandvalue_ = item;
    Serial.println("String is " + String(command_) + " : " + String(commandvalue_) );
    }
    }
    vibepower_ = commandvalue_.toInt();
    }

    result = (str.indexOf("SendShockSignal"));
    if (result >-1){
    execute(shockpower_, shock);
    }

    result = (str.indexOf("SendVibeSignal"));
    if (result >-1){
    execute(vibepower_, vibrate);
    }
    }

    
 
 
    }


