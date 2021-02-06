int PUL=7; //define Pulse pin
int DIR=6; //define Direction pin
int ENA=5; //define Enable Pin
void setup() {
  pinMode (PUL, OUTPUT);
  pinMode (DIR, OUTPUT);
  pinMode (ENA, OUTPUT);

}

void loop() {
  for(int i = 0; i < 20; i++){
    moveForward(6400);
    rub();
  }
  for(int i = 0; i < 20; i++){
    moveBackward(6400);
    rub();
  }
  pauseForWater();
}

void moveForward(int steps){
  setDirection(true);
  allowControl(true);
  for (int i=0; i<steps; i++)    //Forward 5000 steps
  {
    giveCurrent(true);
    setDelay();
    giveCurrent(false);
    setDelay();
  }
}

void moveBackward(int steps){
  setDirection(false);
  allowControl(true);
  for (int i=0; i<steps; i++)   //Backward 5000 steps
  {
    giveCurrent(true);
    setDelay();
    giveCurrent(false);
    setDelay();
  }
}

void rub(){
  for(int i = 0; i < 5; i++){
    moveForward(2560);
    moveBackward(2560);
  }
}

void setDirection(boolean isForward){
  int signal = isForward ? LOW : HIGH;
  digitalWrite(DIR, signal);
}

void giveCurrent(boolean cur){
  int signal = cur ? HIGH : LOW;
  digitalWrite(PUL,signal);
}

void setDelay(){
  delayMicroseconds(50);
}

void allowControl(boolean enable){
  int signal = enable ? HIGH : LOW;
  digitalWrite(ENA, signal);
}

void pauseForWater(){
  delay(5);
}
