#include <unistd.h>
#include <kernel/irq.h>
#include <drivers/gpio/gpio.h>

#define LED4_PIN        (1 << 12)
#define USER_BUTTON_PIN (1 << 0)

irq_return_t user_button_hnd(unsigned int irq_nr, void *data) {
    gpio_toggle(GPIO_PORT_D, LED4_PIN);
    return IRQ_HANDLED;
}

int main(int argc, char *argv[]) {
    gpio_setup_mode(GPIO_PORT_D, LED4_PIN, GPIO_MODE_OUTPUT);
    gpio_setup_mode(GPIO_PORT_A, USER_BUTTON_PIN,
        GPIO_MODE_INT_MODE_RISING);

    gpio_set(GPIO_PORT_D, LED4_PIN, 0);

    if (0 > gpio_irq_attach(GPIO_PORT_A, USER_BUTTON_PIN,
            user_button_hnd, NULL)) {
        return -1;
    }

    sleep(30);

    return 0;
}
