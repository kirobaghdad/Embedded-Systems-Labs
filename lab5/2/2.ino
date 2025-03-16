// x -> false, y -> true
bool turn = false;

uint16_t x, y;

ISR(ADC_vect)
{
  if(turn == false)
    x = ADC;
  else
    y = ADC;
}

void ADC_init(void)
{
	ADMUX = (1 << REFS0);
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0) | (1 << ADIE);
}


void ADC_readChannel(uint8_t ch_num)
{
  if(ch_num == 0)
    turn = false;
  else
    turn = true;

	ADMUX = (ADMUX & 0xE0) | ch_num;

	ADCSRA |= (1 << ADSC);
}


void setup() {
  // put your setup code here, to run once:
  SREG |= (1 << 7);

  DDRC &= ~(1 << 0);
  // DDRC &= ~(1 << 1);

  ADC_init();

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  ADC_readChannel(0);
  
  // _delay_ms(5);

  // ADC_readChannel(1);

  Serial.println("Pot Reading = " + String(x));
  
  _delay_ms(300);
}
