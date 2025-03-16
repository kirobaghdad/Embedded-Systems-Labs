
void setPWM(uint16_t n)
{
  OCR1A = n;
}

void TIMER1_init()
{
    TCCR1A = (1 << COM1A1) | (1 << WGM11);
    TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11) | (1 << CS10); // Prescaler 64
    ICR1 = 4999;

}

// Servo Motor
void setup() {
  // put your setup code here, to run once:
  DDRB |= (1 << 1);
  TIMER1_init();
}

uint16_t pos = 250;
uint8_t dir = 1;

void loop() {
  // put your main code here, to run repeatedly:
  setPWM(pos);


  if(dir)
  {
    pos += 5;
    if(pos >= 500)
      dir = 0;
  }
  else
  {
    pos -= 5;
    if(pos <= 250)
      dir = 1;
  }

  _delay_ms(20);

}
