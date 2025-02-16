
void INT0_init(void)
{
    SREG &= ~(1 << 7);
    EICRA |= (1 << ISC01) | (1 << ISC00);
    EIMSK |= (1 << INT0);

    SREG |= (1 << 7);
}

ISR(INT0_vect)
{
  PORTC ^= (1 << 0);
}

void setup() {
  // put your setup code here, to run once:
  INT0_init();
  
  DDRD &= ~(1 << 2);
  DDRC |= (1 << 0);

  PORTC &= ~(1 << 0);

}

void loop() {
  // put your main code here, to run repeatedly:

}
