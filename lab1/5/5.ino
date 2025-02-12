int count = 0;
char up = 'f';
char down = 'f';

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

void setup() {
  // put your setup code here, to run once:

  DDRC &= ~(1 << 0) & ~(1 << 1);
  DDRD = 0xff;

  printNum(count);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(PINC & (1 << 0))
  {
    delay(30);

    if(PINC & (1 << 0))
    {
      if(up == 'f')
      {
        up = 't';
        if(count != 9)
        {
          count++;

          printNum(count);
        }

      }
    }
  }
  else
  {
    up = 'f';
  }


  if(PINC & (1 << 1))
  {
    delay(30);
    
    if(PINC & (1 << 1))
    {
      if(down == 'f')
      {
        if(count != 0)
        {
          down = 't';
          count--;

          printNum(count);
        }

      }
    }
  }
  else
  {
    down = 'f';
  }

}
