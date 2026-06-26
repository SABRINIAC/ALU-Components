#define carryFlagPin 0
#define throughCarryFlagPin 1
#define outCarryFlagPin 18
#define ABit0Pin 2
#define ABit7Pin 9
#define OutBit0Pin 10
#define OutBit7Pin 17

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  while(!Serial){;}

  for(int i=ABit0Pin; i<=ABit7Pin; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(carryFlagPin, OUTPUT);
  pinMode(throughCarryFlagPin, OUTPUT);

  for(int i=OutBit0Pin; i<=OutBit7Pin; i++){
    pinMode(i, INPUT);
  }
  pinMode(outCarryFlagPin, INPUT);
}

int testNumber = 0;
int testMode = 0;

void loop() {

  if(testMode > 3) {
    Serial.println("ALL TESTS COMPLETE");
    while(true){}
  }

  bool carryIn;
  bool throughCarry;

  switch(testMode) {
    case 0: // RRC
      carryIn = 0;
      throughCarry = 0;
      break;

    case 1: // RRC with carry=1
      carryIn = 1;
      throughCarry = 0;
      break;

    case 2: // RAR carry=0
      carryIn = 0;
      throughCarry = 1;
      break;

    case 3: // RAR carry=1
      carryIn = 1;
      throughCarry = 1;
      break;
  }

  writeA(testNumber);

  digitalWrite(carryFlagPin, carryIn ? HIGH : LOW);
  digitalWrite(throughCarryFlagPin, throughCarry ? HIGH : LOW);

  delay(1);

  int actual = readResult();
  int actualCarry = digitalRead(outCarryFlagPin);

  int expected;
  int expectedCarry = testNumber & 1;

  if(throughCarry) {
    // RAR
    expected = (testNumber >> 1) | (carryIn ? 0x80 : 0x00);
  } else {
    // RRC
    expected = (testNumber >> 1) | (expectedCarry ? 0x80 : 0x00);
  }

  bool pass =
    (actual == expected) &&
    (actualCarry == expectedCarry);

  Serial.print(pass ? "PASS " : "FAIL ");

  Serial.print("Mode=");
  Serial.print(testMode);

  Serial.print(" A=");
  print8(testNumber);

  Serial.print(" Result=");
  print8(actual);

  Serial.print(" Expected=");
  print8(expected);

  Serial.print(" Carry=");
  Serial.print(actualCarry);

  Serial.print(" ExpectedCarry=");
  Serial.println(expectedCarry);

  testNumber++;

  if(testNumber > 0xFF) {
    testNumber = 0;
    testMode++;

    Serial.println();
    Serial.println("====================================");
    Serial.print("STARTING MODE ");
    Serial.println(testMode);
    Serial.println("====================================");
    Serial.println();
  }
}

void print8(uint8_t value) {
  for(int i = 7; i >= 0; i--) {
    Serial.print((value >> i) & 1);
  }
}

void writeA(int num){
  for(int i=ABit0Pin; i<=ABit7Pin; i++){
    int digit = num & 0b1;
    digitalWrite(i, digit == 1 ? HIGH : LOW);
    num >>= 1;
  }
}

int readResult(){
  int out = 0;
  for(int i=OutBit7Pin; i>=OutBit0Pin; i--){
    out <<= 1;
    out |= digitalRead(i)==HIGH ? 1 : 0;
  }
  return out;
}