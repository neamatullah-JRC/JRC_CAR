#define in1 8 
#define in2 7 
#define in3 6 
#define in4 5
#define R_S A0 
#define L_S A1 

void setup() { 
Serial.begin(9600); 

  pinMode(R_S, INPUT); 
  pinMode(L_S, INPUT);  

  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT); 
  pinMode(in3, OUTPUT); 
  pinMode(in4, OUTPUT); 

}


void loop() {
  

  if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 0))
  {
    forword();
  }
  if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 0))
  {
    turnRight();
  }
  if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 1))
  {
    turnLeft();
  }
  if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 1))
  {
    Stop();
  }


Serial.println(digitalRead(R_S)); 
Serial.println(digitalRead(L_S));


  delay(10);
}


void forword() { //forword

  digitalWrite(in1, HIGH); //Right Motor forword Pin
  digitalWrite(in2, LOW);  //Right Motor backword Pin
  digitalWrite(in3, LOW);  //Left Motor backword Pin
  digitalWrite(in4, HIGH); //Left Motor forword Pin
   Serial.println("Forword");  

}

void backword() { //backword
    Serial.println("Backword"); 

  digitalWrite(in1, LOW);  //Right Motor forword Pin
  digitalWrite(in2, HIGH); //Right Motor backword Pin
  digitalWrite(in3, HIGH); //Left Motor backword Pin
  digitalWrite(in4, LOW);  //Left Motor forword Pin


}

void turnRight() { //turnRight
    Serial.println("Right"); 
  digitalWrite(in1, LOW);  //Right Motor forword Pin
  digitalWrite(in2, HIGH); //Right Motor backword Pin
  digitalWrite(in3, LOW);  //Left Motor backword Pin
  digitalWrite(in4, HIGH); //Left Motor forword Pin


}
void turnLeft() { //turnLeft
    Serial.println("Left"); 
  digitalWrite(in1, HIGH);  //Right Motor forword Pin
  digitalWrite(in2, LOW); //Right Motor backword Pin
  digitalWrite(in3, HIGH);  //Left Motor backword Pin
  digitalWrite(in4, LOW); //Left Motor forword Pin

}
void Stop() { //stop
Serial.println("stop"); 
 
  digitalWrite(in1, LOW); //Right Motor forword Pin
  digitalWrite(in2, LOW); //Right Motor backword Pin
  digitalWrite(in3, LOW); //Left Motor backword Pin
  digitalWrite(in4, LOW); //Left Motor forword Pin

}
