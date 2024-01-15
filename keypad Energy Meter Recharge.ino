// Include the Arduino Stepper Library
#include <Stepper.h>
#include <Servo.h>

// Number of steps per output rotation
const int stepsPerRevolution = 800;

// Create Instance of Stepper library
Stepper myStepper1(stepsPerRevolution, 8, 9, 10, 11);
Stepper myStepper2(stepsPerRevolution, 4, 5, 6, 7);
Servo myservo;

int pre_row = 0;
int pre_col = 0;
int row = 0;
int col = 0;
//for data received 
const int arraySize = 5;
char receivedString[arraySize + 1]; 
int digits[arraySize];

void read_bluetooth();
void initial();
void press_1();
void press_2();
void press_3();
void press_4();
void press_5();
void press_6();
void press_7();
void press_8();
void press_9();
void press_0();
void press_enter();
void servo_press();





void setup()
{
  myservo.attach(3);
  // set the speed at 60 rpm:
  myStepper1.setSpeed(50);
  myStepper2.setSpeed(50);
  // initialize the serial port:
  Serial.begin(9600);
  //initial();
  myservo.write(0);
}

void loop() 
{
  if (Serial.available() > 0) {
    // Read the incoming byte
    read_bluetooth();
    for (int i = 0; i < arraySize; i++) {
      if (digits[i]==1) {
        Serial.println("Action 1 performed");
        press_1();
      }
      else if(digits[i]==2){
        Serial.println("Action 2 performed");
        press_2();
      }
      else if(digits[i]==3){
        Serial.println("Action 3 performed");
        press_3();
      }
      else if(digits[i]==4){
        Serial.println("Action 4 performed");
        press_4();
      }
      else if(digits[i]==5){
        Serial.println("Action 5 performed");
        press_5();
      }
      else if(digits[i]==6){
        Serial.println("Action 6 performed");
        press_6();
      }
      else if(digits[i]==7){
        Serial.println("Action 7 performed");
        press_7();
      }
      else if(digits[i]==8){
        Serial.println("Action 8 performed");
        press_8();
      }
      else if(digits[i]==9){
        Serial.println("Action 9 performed");
        press_9();
      }
      else if(digits[i]==0){
        Serial.println("Action 0 performed");
        press_0();
      }
      else {
        Serial.println("Invalid");
      }
      
    }
    press_enter();

  }
  delay(5000);
}


void initial() {
  myStepper1.step(5000);
  myStepper2.step(5000);
  delay(2000);
}

void read_bluetooth(){
     Serial.readBytes(receivedString, arraySize);
 // Null-terminate the receivedString
    receivedString[arraySize] = '\0';
   
     delay(10);
     
    // Convert each character to an integer and store in an array
    for (int i = 0; i < arraySize; i++) {
      digits[i] = receivedString[i] - '0';
    }
 // Display the received string on Serial Monitor
    Serial.print("Received String: ");
    Serial.println(receivedString);
   // Convert each character to an integer and store in an array
   // int digits[arraySize];
    for (int i = 0; i < arraySize; i++) {
      digits[i] = receivedString[i] - '0';
    }

    // Display the received array on Serial Monitor
    Serial.print("Received Array: ");
    for (int i = 0; i < arraySize; i++) {
      Serial.print(digits[i]);
    }
    Serial.println();

    // Optional: You can perform further actions with the received array here

    // Reset array for the next set of digits
    memset(receivedString, 0, sizeof(receivedString));

    // Delay and flush Serial buffer to ensure a clean start for the next attempt
    delay(100);
    while (Serial.available() > 0) {
      char dummy = Serial.read();
    }
   
}

void press_1() {
  row = 10*40;
  col = 10*40;
  myStepper2.step(pre_row-row);
  myStepper1.step(pre_col-col);
  delay(1000);
  servo_press();
  delay(1000);
  pre_row = row;
  pre_col = col;
}

void press_2() {
  row = 10*40;
  col = 30*40;
  myStepper2.step(pre_row-row);
  myStepper1.step(pre_col-col);
  delay(2000);
  pre_row = row;
  pre_col = col;
}

void press_3() {
  row = 10*40;
  col = 50*40;
  myStepper2.step(pre_row-row);
  myStepper1.step(pre_col-col);
  delay(1000);
  servo_press();
  delay(1000);
  pre_row = row;
  pre_col = col;
}

void press_4() {
  row = 30*40;
  col = 10*40;
  myStepper2.step(pre_row-row);
  myStepper1.step(pre_col-col);
  delay(1000);
  servo_press();
  delay(1000);
  pre_row = row;
  pre_col = col;
}

void press_5() {
  row = 30*40;
  col = 30*40;
  myStepper2.step(pre_row-row);
  myStepper1.step(pre_col-col);
  delay(1000);
  servo_press();
  delay(1000);
  pre_row = row;
  pre_col = col;
}

void press_6() {
  row = 30*40;
  col = 50*40;
  myStepper2.step(pre_row-row);
  myStepper1.step(pre_col-col);
  delay(1000);
  servo_press();
  delay(1000);
  pre_row = row;
  pre_col = col;
}

void press_7() {
  row = 50*40;
  col = 10*40;
  myStepper2.step(pre_row-row);
  myStepper1.step(pre_col-col);
  delay(1000);
  servo_press();
  delay(1000);
  pre_row = row;
  pre_col = col;
}

void press_8() {
  row = 50*40;
  col = 30*40;
  myStepper2.step(pre_row-row);
  myStepper1.step(pre_col-col);
  delay(1000);
  servo_press();
  delay(1000);
  pre_row = row;
  pre_col = col;
}

void press_9() {
  row = 50*40;
  col = 50*40;
  myStepper2.step(pre_row-row);
  myStepper1.step(pre_col-col);
  delay(1000);
  servo_press();
  delay(1000);
  pre_row = row;
  pre_col = col;
}

void press_0() {
  row = 70*40;
  col = 30*40;
  myStepper2.step(pre_row-row);
  myStepper1.step(pre_col-col);
  delay(1000);
  servo_press();
  delay(1000);
  pre_row = row;
  pre_col = col;
}
void press_enter() {
  row = 70*40;
  col = 50*40;
  myStepper2.step(pre_row-row);
  myStepper1.step(pre_col-col);
  delay(1000);
  servo_press();
  delay(1000);
  pre_row = row;
  pre_col = col;
}

void servo_press() {
  myservo.write(90);              // tell servo to go to position in variable 'pos'
  delay(200);
  myservo.write(0);              // tell servo to go to position in variable 'pos'
  delay(200);
}
