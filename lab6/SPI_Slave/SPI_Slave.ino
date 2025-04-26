#include <avr/io.h>

#define MOSI PB3
#define MISO PB4
#define SCK PB5
#define SS PB2

void SPI_Init() {
    DDRB &= ~((1<<MOSI) | (1<<SCK) | (1<<SS));
    DDRB |= (1<<MISO);
    SPCR = (1<<SPE);
}

uint8_t SPI_Receive_Send() {

    while (!(SPSR & (1<<SPIF)));

    uint8_t d = SPDR;
    SPDR = d + 100;

    return d;
}

void setup() {
    SPI_Init();
    Serial.begin(9600);
}

void loop() {
    uint8_t data = 0;

    data = SPI_Receive_Send();
      
    if(data != 255) {
      Serial.print("Slave Received: ");
      Serial.println(data);
    }
}
