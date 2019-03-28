#include <unistd.h>

#include <drivers/gpio/gpio.h>

#define LED4_PIN        (1 << 12)

int main(int argc, char *argv[]) {
    int cnt;

    gpio_setup_mode(GPIO_PORT_D, LED4_PIN, GPIO_MODE_OUTPUT);
    gpio_set(GPIO_PORT_D, LED4_PIN, 0);

    for(cnt = 0; cnt < 100; cnt++) {
        sleep(1);
        gpio_toggle(GPIO_PORT_D, LED4_PIN);
    }

    return 0;
}
