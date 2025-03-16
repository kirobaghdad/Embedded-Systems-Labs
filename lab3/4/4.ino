void Timer2_init(void)
{
  TCCR2A = (1 << WGM21);
  TCCR2B = 0;
  OCR2A = 1;
  TCCR2B = (1 << CS22) | (1 << CS21);

  TCCR2A |= (1 << COM2A0);
}

void setup()
{
  // put your setup code here, to run once:
  DDRB |= (1 << 3);
  Timer2_init();

  sei();
}

void loop()
{
  // put your main code here, to run repeatedly:
}