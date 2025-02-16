
void INT1_init(void)
{
    SREG &= ~(1 << 7);
    EICRA |= (1 << ISC11);
    EIMSK |= (1 << INT1);

    SREG |= (1 << 7);
}



ISR(INT1_vect)
{
  for(int i = 0; i < 5; i++)
  {
    PORTC |= (1 << 0) | (1 << 1) | (1 << 2);
    _delay_ms(500);

    PORTC &= ~(1 << 0) & ~(1 << 1) & ~(1 << 2);
    _delay_ms(500);

  }

}


void setup() {
  INT1_init();
  // put your setup code here, to run once:
  DDRC |= (1 << 0) | (1 << 1) | (1 << 2);
  DDRD &= ~(1 << 3);

  PORTD |= (1 << 3);

  PORTC &= ~(1 << 0) | ~(1 << 1) | ~(1 << 2);
}

void loop() {
  // put your main code here, to run repeatedly:

  PORTC |= (1 << 0);
  PORTC &= ~(1 << 1) & ~(1 << 2);

  delay(500);

  PORTC |= (1 << 1);
  PORTC &= ~(1 << 0) & ~(1 << 2);

  delay(500);

  PORTC |= (1 << 2);
  PORTC &= ~(1 << 0) & ~(1 << 1);

  delay(500);

}
