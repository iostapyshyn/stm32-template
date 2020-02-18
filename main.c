#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

/* Set STM32 to 24 MHz. */
static void clock_setup(void)
{
	rcc_clock_setup_in_hse_8mhz_out_24mhz();

	/* Enable GPIOC clock. */
	rcc_periph_clock_enable(RCC_GPIOB);
}

static void gpio_setup(void)
{
	/* Set GPIO5 (in GPIO port B) to 'output push-pull'. */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO5);
}

int main(void)
{
	int i;

	clock_setup();
	gpio_setup();

	/* Set one LED for wigwag effect when toggling. */
	gpio_set(GPIOB, GPIO5);

	/* Blink the LEDs (PB5) on the board. */
	while (1) {
		gpio_toggle(GPIOB, GPIO5); /* Toggle LEDs. */
		for (i = 0; i < 2000000; i++) /* Wait a bit. */
			__asm__("nop");
	}

	return 0;
}
