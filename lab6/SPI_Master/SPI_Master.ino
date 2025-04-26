void setup()
{
  DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2);
  DDRB &= ~(1 << PB3);

  PORTB |= (1 << PB0);

  SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);

  Serial.begin(9600);
}

uint8_t spiTransfer(uint8_t data)
{
  PORTB &= ~(1 << PB0);

  SPDR = data;

  while (!(SPSR & (1 << SPIF)))
    ;

  PORTB |= (1 << PB0);

  return SPDR;
}

uint8_t dataToSend = 0;

void loop()
{

  if (dataToSend <= 100)
  {
    uint8_t dataToReceive = spiTransfer(dataToSend);

    Serial.print("Master Received: ");
    Serial.println(dataToReceive);

    delay(1000);

    dataToSend++;
  }
}
