
int r=0;
const int A = 5;
const int B = 6;
const int in1 = 12;
const int in2 = 11;
const int in3 = 10;
const int in4 = 9;

const int ir1 = 2;//front
const int ir2 = 3;
const int ir3 = 4;
//const int ir4 = 7;//back

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void loop() {

if (digitalRead(ir1)){
  moveforward();
 // delay(1000);
}
else if( check_ir(ir1) && digitalRead(ir2) && (r == 1|| r == 0)){
  moveback();
  delay(800);
  turnright();
  delay(1800);
  r = 2;
}
else if( check_ir(ir1) && digitalRead(ir3) ){
  moveback();
  delay(800);
  turnleft();
  delay(1800);
  r = 1;
}
else{
  stop();
  return 0;
}
 
      

}

void moveback() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(A, 120);
  analogWrite(B, 120);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

}
void turnright() {
  digitalWrite(in2, 0);
  digitalWrite(in1, LOW);
  analogWrite(A, 205);
  analogWrite(B, 205);
  digitalWrite(in4, 1);
  digitalWrite(in3, 0);
}
// Function to stop the robot
void turnleft() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  analogWrite(A, 205);
  analogWrite(B, 205);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(A, 200);
  analogWrite(B, 200);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void moveforward(){
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  analogWrite(A, 120);
  analogWrite(B, 120);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}


int check_ir( int ir_pin ){
  int val = digitalRead(ir_pin);
  if (val==0){
    return 1;
  }
  else{
    return 0;
  }
}