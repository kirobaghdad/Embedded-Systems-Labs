void setup() {
  // put your setup code here, to run once:

  DDRD |= (1 << 6);
  PORTD |= (1 << 6);

}

void loop() {
  // put your main code here, to run repeatedly:
  PORTD ^= (1 << 6);//
  delay(1000);
}
