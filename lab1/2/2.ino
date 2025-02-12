void setup() {
  // put your setup code here, to run once:
  DDRB &= ~(1 << 0) & ~(1 << 1);
  DDRC |= (1 << 0) | (1 << 1);

  PORTC &= ~(1 << 0) & ~(1 << 1);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(PINB & (1 << 0))
  {
    PORTC |= (1 << 0);
  }
  else
  {
    PORTC &= ~(1 << 0);
  }

  if(PINB & (1 << 1))
  {
    PORTC |= (1 << 1);
  }
  else
  {
    PORTC &= ~(1 << 1);
  }

}
