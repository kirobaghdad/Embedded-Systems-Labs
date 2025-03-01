int counter = 0;

void printNum(const unsigned int counter)
{
	switch(counter)
	{
		case 0:
			PORTD = 0b00111111;
			break;
		case 1:
			PORTD = 0b00000110;
			break;
		case 2:
			PORTD = 0b01011011;
			break;
		case 3:
			PORTD = 0b01001111;
			break;
		case 4:
			PORTD = 0b01100110;
			break;
		case 5:
			PORTD = 0b01101101;
			break;
		case 6:
			PORTD = 0b01111101;
			break;
		case 7:
			PORTD = 0b00000111;
			break;
		case 8:
			PORTD = 0b01111111;
			break;
		case 9:
			PORTD = 0b01101111;
			break;
	}
}

void Timer2_init(void)
{
  TCNT2 = 0;
  TCCR2A = 0;
  TCCR2B |= (1 << CS22) | (1 << CS21);
  TCCR2B |= (1 << FOC2A);
  TIMSK2 |= (1 << TOIE2);

  SREG |= (1 << 7);
}

ISR(TIMER2_OVF_vect)
{
  // keep a track of number of overflows
  volatile static int count = 0;
  count++;
  
  if(count == 244)
  {  
    counter++;

    if(counter == 10)
      counter = 0;
    
    Serial.println(counter);
    printNum(counter);

    count = 0;
  }
}



void setup() {
  // put your setup code here, to run once:
  DDRD = 0x7F;
  Serial.begin(9600);
  Timer2_init();
}

void loop() {
  // put your main code here, to run repeatedly:

}
