char down = 'f';

void setup() {
  // put your setup code here, to run once:
  DDRB &= ~(1 << 0);
  
  // pull-down
  PORTB |= (1 << 0);

  DDRC |= (1 << 0);
  PORTC |= (1 << 0);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(!(PINB & (1 << 0)))
  {
    delay(30);

    if(!(PINB & (1 << 0)))
    {
      if(down == 'f')
     { 
      PORTC ^= (1 << 0);
      down = 't';
     }
    }
  }
  else
  {
    down = 'f';
  }

}
