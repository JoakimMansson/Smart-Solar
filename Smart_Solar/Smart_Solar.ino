#include <Servo.h>

Servo myServo;
int currentServoAngle = 90;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  //pinMode(9, OUTPUT);
  myServo.attach(9);

 
  // Make servo go to 90 degrees 
  myServo.write(currentServoAngle); 
  delay(1000); 

}

void loop() {
  int valueA0 = analogRead(A0);  // Reading the value from pin A0
  int valueA1 = analogRead(A1);  // Reading the value from pin A1

  Serial.print("A0: ");
  Serial.print(valueA0);
  Serial.print(" , A1: ");
  Serial.println(valueA1);

  /*
    MAX SERVO VALUE: 2000 us
    MIN SERVO VALUE: 1000 US
  */
  if (valueA0 - 50 > valueA1) {
    currentServoAngle = ((currentServoAngle - 5) + 180) % 180;
    myServo.write(currentServoAngle); 
  }
  else if (valueA0 + 50 < valueA1) {
    currentServoAngle = (currentServoAngle + 5) % 180;
    myServo.write(currentServoAngle); 
  }

  //analogWrite(9, 127);  // Write a PWM signal with a duty cycle of about 50% to pin D9
  //delay(1000);  // Wait for 1 second

  //analogWrite(9, 0);  // Turn off the PWM signal
  delay(500);  // Adding a delay of 1 second before the next reading
}
