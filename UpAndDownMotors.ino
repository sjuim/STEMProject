/* The pin settings for the first motor */
int PUL1 = 7; //define Pulse pin
int DIR1 = 6; //define Direction pin
int ENA1 = 5;

/* The pin settings for the second motor */
int PUL2 = 10;
int DIR2 = 9;
int ENA2 = 8;

// Public method called by system to setup
void setup() {
  pinMode (PUL1, OUTPUT);
  pinMode (DIR1, OUTPUT);
  pinMode (ENA1, OUTPUT);

  pinMode (PUL2, OUTPUT);
  pinMode (DIR2, OUTPUT);
  pinMode (ENA2, OUTPUT);
}

// Public method called by system to execute commands in a loop
void loop() {
  for(int i = 0; i < 2; i++){
     moveUp(25600);
  }
  moveUp(12800);
  pauseForClean();
  for(int i = 0; i < 2; i++){
    moveDown(25600);
  }
  moveDown(12800);
}

void moveUp(int steps){
  setDirection(true);
  moveMotor(steps);
}

void moveDown(int steps){
  setDirection(false);
  moveMotor(steps);
}

/* Move motor the specified number of steps, assuming that
 * the direction has already been set.
 */
void moveMotor(int steps) {
  allowControl(true);
  for (int i=0; i<steps; i++)    
  {
    giveCurrent(true);
    shortPause();
    giveCurrent(false);
    shortPause();
  }
}

void setDirection(boolean isForward){
  int signal = isForward ? LOW : HIGH;
  digitalWrite(DIR1, signal);
  digitalWrite(DIR2, signal);
}

void giveCurrent(boolean cur){
  int signal = cur ? HIGH : LOW;
  digitalWrite(PUL1, signal);
  digitalWrite(PUL2, signal);
}

void shortPause(){
  delayMicroseconds(50);
}

void allowControl(boolean enable){
  int signal = enable ? HIGH : LOW;
  digitalWrite(ENA1, signal);
  digitalWrite(ENA2, signal);
}

void pauseForClean(){
  for(int i = 0; i < 120; i++){
    delay(1000);
  }e
}
