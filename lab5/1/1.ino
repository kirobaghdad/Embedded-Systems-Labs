void ADC_init(void)
{
	ADMUX = (1 << REFS0);
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}
uint16_t x, y;

uint16_t ADC_readChannel(uint8_t ch_num)
{
	ADMUX = (ADMUX & 0xE0) | ch_num;

	ADCSRA |= (1 << ADSC);

	while(!(ADCSRA & ADIF));

  ADCSRA |= (1 << ADIF);

	return ADC;
}


void setup() {
  // put your setup code here, to run once:
  DDRC &= ~(1 << 0);
  // DDRC &= ~(1 << 1);

  ADC_init();

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  x = ADC_readChannel(0);
  // y = ADC_readChannel(1);

  Serial.println("Pot Reading = " + String(x));
  
  _delay_ms(300);
}
