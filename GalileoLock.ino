#include <Servo.h>
Servo myservo;
char charreceive;
String state="0";
String ip="38";
void setup() {
  // put your setup code here, to run once:
    pinMode(13, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
    digitalWrite(13,LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
    
    Serial1.begin(2400);
    while (!Serial1) {
    ; // wait for serial port to connect. Needed for Leonardo only
    }
    delay(50);

}

void loop() { 

    //Serial1.println(ip+state);
    delay(2000);
    //Serial1.print('a');
    
    while(Serial1.available()){
      charreceive=char(Serial1.read());
       }
      
      if(charreceive=='a'){
          blink(1);
          charreceive=' ';
          state="1";
          delay(500);
          myservo.attach(6);
          myservo.write(120);
          delay(2000);
          digitalWrite(6, LOW);
        }
      if(charreceive=='b') {
            blink(4);
            charreceive=' ';
            state="0";
            
      }
 
}

void blink(int c){
  for(int i=0;i<c;i++){
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);              // wait for a second
  }
}
void open(){
for(int i=0;i<1000;i++){
  digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
  delayMicroseconds(3000);              // wait for a second
  digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW
  delayMicroseconds(20000-3000);                  // wait for a second
  }
}
