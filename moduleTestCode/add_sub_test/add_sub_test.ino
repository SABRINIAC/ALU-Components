int aPins[] = {0, 1, 2, 3, 4, 5, 6, 7}; 
int bPins[] = {8, 9, 10, 11, 12, 13, 14, 15}; 
int outPins[] = {16, 17, 18, 19, 20, 21, 22, 26}; 

int carryFlagPin = 27;
int carryFlagOutPin = 28;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  while(!Serial){;}

  for(int i=0; i<8; i++){
    pinMode(aPins[i], OUTPUT);
    pinMode(bPins[i], OUTPUT);
  }
  pinMode(carryFlagPin, OUTPUT);

  for(int i=0; i<8; i++){
    pinMode(outPins[i], INPUT);
  }
  pinMode(carryFlagOutPin, INPUT);
}

bool useCarryFlag = false;
int borrow = 0;

int a = 0b00000000;
int b = 0b00000000;
int fails = 0;

void loop() {
  if(b > 0xFF){ return; }

  digitalWrite(carryFlagPin, borrow==1 ? HIGH : LOW);

  writeInput(a, aPins);
  writeInput(b, bPins);
  delay(1);
  int r = readResult();
  int cf = digitalRead(carryFlagOutPin)==HIGH ? 1 : 0;

  int operation = a - b - borrow;
  int expected = operation & 0xFF;
  //int expectedCarryOut = (operation & 0x100) >> 8; // the 9th bit, for ADD
  int expectedCarryOut = (a < (b + borrow)) ? 1 : 0; // for SUB, check if a is less than b

  bool pass = (r == expected);
  if(useCarryFlag) { pass &= (cf == expectedCarryOut); }

  Serial.print( pass ? "PASS" : "FAIL" );
  Serial.print(" | A: ");
  print8(a);
  Serial.print(", B: ");
  print8(b);
  Serial.print(" ; Out: ");
  print8(r);
  Serial.print(" ~ Carry out: ");
  Serial.print(cf);
  Serial.print(", Expected: ");
  print8(expected);
  Serial.print(" ~ Carry out: ");
  Serial.print(expectedCarryOut);
  Serial.println("");

  if( !pass ){ fails++; return; }
  //return;

  a++;
  if(a > 0xFF){
    a = 0x00;
    b++;
  }
  if( b > 0xFF ){
    Serial.print("Testing done! Total fails: ");
    Serial.println(fails);
  }
}

void print8(uint8_t value) {
  for(int i = 7; i >= 0; i--) {
    Serial.print((value >> i) & 1);
  }
}

void writeInput(int num, int pins[]){
  for(int i=0; i<8; i++){
    int digit = num & 0b1;
    digitalWrite(pins[i], digit == 1 ? HIGH : LOW);
    num >>= 1;
  }
}

int readResult(){
  int out = 0;
  for(int i=7; i>=0; i--){
    out <<= 1;
    out |= digitalRead(outPins[i])==HIGH ? 1 : 0;
  }
  return out;
}