#include <avr/io.h>
#include <util/delay.h>

void setPWM(uint8_t duty)
{
	OCR0A = duty;
}

void PWM_init(void)
{
	DDRD |= (1 << DDD6);

	TCCR0A = (1 << WGM01) | (1 << WGM00);
	TCCR0A |= (1 << COM0A1);

	TCCR0B = (1 << CS01) | (1 << CS00);

	setPWM(0);
}

int main(void)
{
	PWM_init();

	while (1)
	{
		// Fade up
		for (uint8_t i = 0; i < 255; i++)
		{
			setPWM(i);
			_delay_ms(10);
		}

		// Fade down
		for (uint8_t i = 255; i > 0; i--)
		{
			setPWM(i);
			_delay_ms(10);
		}
	}
}