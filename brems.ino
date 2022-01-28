uint8_t b[]= {0x00, 0x40, 0x80, 0xC0};

int i;

boolean boStart;
boolean boTiming;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  while (!Serial);
}

void printHex(uint8_t num) {
  char hexCar[2];

  sprintf(hexCar, "%02X", num);
  Serial.print(hexCar);
}

void loop() {
  // put your main code here, to run repeatedly:
  boTiming = boTiming ^ B1;
  digitalWrite(2, boTiming);
  if (Serial.available() > 0)
  {
    if (Serial.read() == 83){
      boStart = boStart ^ B1;
    }
  }

  if (boStart == true){
  for(i=0; i<sizeof(b); i++){
    Serial.write(b[i]);
    //printHex(b[i]);
    delay(3);
 }
 b[0] = b[0] + 1;
 b[0] = b[0] & 63;
  }
}
