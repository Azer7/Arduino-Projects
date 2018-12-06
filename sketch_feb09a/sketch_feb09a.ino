void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(11, 255);
  delay(3000);
  analogWrite(11, 0);
  delay(9999999);
  
}
