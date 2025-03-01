void Timer2_init(void)
{
  TCNT2 = 0;
  TCCR2A = (1 << WGM21);
  TCCR2B = (1 << CS22) | (1 << CS21) | (1 << CS20);
  TCCR2B |= (1 << FOC2A);

  OCR2A = 217;

  TIMSK2 |= (1 << OCIE2A);

  SREG |= (1 << 7);
}

ISR(TIMER2_COMPA_vect)
{
  // keep a track of number of overflows
  volatile static int count = 0;
  count++;
  
  if(count == 36)
  {  
    PORTB ^= (1 << 5);
    count = 0;
  }
}



void setup() {
  // put your setup code here, to run once:
  DDRB |= (1 << 5);
  PORTB = 0;

  Timer2_init();
}

void loop() {
  // put your main code here, to run repeatedly:

}
