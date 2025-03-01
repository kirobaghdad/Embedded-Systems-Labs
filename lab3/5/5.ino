
int overflow = 0;

ISR(TIMER1_OVF_vect)
{
  overflow++;
}

void TIMER1_init(void)
{
  TCCR1A = 0;
  TCNT1 = 0;

  TIFR1 = (1 << ICF1);
  TCCR1B = (1 << 6) | (1 << 0);
  TCCR1A =  (1 << FOC1A);
  TIMSK1 |= (1 << TOIE1);

  SREG |= (1 << 7);
}

void setup() {
  // put your setup code here, to run once:
  DDRB |= (1 << 0);
  Serial.begin(9600);
  TIMER1_init();
}


float t;

void loop() {
  // put your main code here, to run repeatedly:

  while(!(TIFR1 & (1 << ICF1)));
  TIFR1 = (1 << ICF1);
  Serial.println("First Push!");
  t = ICR1;
  TCNT1 = 0;
  overflow = 0;

  _delay_ms(20);

  while(!(TIFR1 & (1 << ICF1)));
  TIFR1 = (1 << ICF1);

  t = ((ICR1 - t) + overflow * 65536.0) * (1.0 / (16000000.0));

  Serial.println("Second Push!");
  Serial.print("Time between 2 Pushes is ");
  Serial.println(t);
}
