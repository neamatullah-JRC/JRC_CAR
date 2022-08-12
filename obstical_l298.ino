
#define in1 D6 //Motor1  L298 Pin in1 
#define in2 D7 //Motor1  L298 Pin in1 
#define in3 D1 //Motor2  L298 Pin in1 
#define in4 D3 //Motor2  L298 Pin in1 

#define echo D8    //Echo pin
#define trigger D4 //Trigger pin


Servo myservo;

int distance_L, distance_F, distance_R;
long distance;

int set = 20;
 
void setup() {
  Serial.begin(9600);           // Initialize serial port
  Serial.println("Start");

  myservo.attach(D2);
  myservo.write(90);

  pinMode (trigpin, OUTPUT);
  pinMode (echopin, INPUT );
}
void loop() {
 distance_F = data();
 Serial.print("S=");
 Serial.println(distance_F);
  if (distance_F > set){
   Serial.println("Forward");
forword();
    }
    else{hc_sr4();}
}


long data(){
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  distance = pulseIn (echopin, HIGH);
  return distance / 29 / 2;
}


void compareDistance(){
  if (distance_L > distance_R){
  turnLeft();
    delay(350);
  }
  else if (distance_R > distance_L){
 turnRight();
    delay(350);
  }
  else{
 backword();
   delay(300);
  turnLeft();
    delay(500);
  }
}

void hc_sr4(){
    Serial.println("Stop");
    motor1.run(RELEASE);         // stopped
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
   
    myservo.write(0);
    delay(300);
    distance_R = data();
    delay(100);
    myservo.write(170);
    delay(500);
    distance_L = data();
    delay(100);
    myservo.write(90);
    delay(300);
    compareDistance();
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


