void Timer2_init(void)
{
  TCCR2A = 0;
  TCNT2 = 0;
  TIMSK2 = (1 << TOIE2);
  TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);
  TCCR2B |= (1 << FOC2A);
  SREG |= (1 << 7);
}

ISR(TIMER2_OVF_vect)
{
  // keep a track of number of overflows
  static int count = 0;
  count++;
  
  if(count >= 31)
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
