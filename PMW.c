#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22  // Pino onde o servomotor está conectado
#define LED_PIN 12    // Pino onde o LED RGB está conectado
#define PWM_FREQ 50   // Frequência do PWM em Hz
#define PWM_WRAP 20000 // Período do PWM para 50Hz (20ms)

void set_servo_angle(uint slice, uint level) {
    pwm_set_gpio_level(SERVO_PIN, level);
    sleep_ms(5000); // Aguarda 5 segundos

    // Controla o LED RGB com base no nível do PWM
    uint led_brightness = (level - 500) * 255 / 1900; // Mapeia 500-2400 para 0-255
    pwm_set_gpio_level(LED_PIN, led_brightness);
}

int main() {
    stdio_init_all();

    // Configura o pino do servo como saída PWM
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(SERVO_PIN);

    // Configura o PWM para 50Hz
    pwm_set_clkdiv(slice, 125.0); // 125MHz / 125 = 1MHz
    pwm_set_wrap(slice, PWM_WRAP); // Período de 20ms
    pwm_set_enabled(slice, true);

    // Configura o pino do LED como saída PWM
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
    uint led_slice = pwm_gpio_to_slice_num(LED_PIN);
    pwm_set_clkdiv(led_slice, 4.0); // 125MHz / 4 = 31.25MHz
    pwm_set_wrap(led_slice, 255);   // Período de 8.16µs (frequência de 122.55kHz)
    pwm_set_enabled(led_slice, true);

    // Posiciona o servo em 180 graus (2400us)
    set_servo_angle(slice, 2400);

    // Posiciona o servo em 90 graus (1470us)
    set_servo_angle(slice, 1470);

    // Posiciona o servo em 0 graus (500us)
    set_servo_angle(slice, 500);

    // Movimentação suave entre 0 e 180 graus
    while (true) {
        for (uint level = 500; level <= 2400; level += 5) {
            pwm_set_gpio_level(SERVO_PIN, level);
            uint led_brightness = (level - 500) * 255 / 1900; // Atualiza o brilho do LED
            pwm_set_gpio_level(LED_PIN, led_brightness);
            sleep_ms(10);
        }
        for (uint level = 2400; level >= 500; level -= 5) {
            pwm_set_gpio_level(SERVO_PIN, level);
            uint led_brightness = (level - 500) * 255 / 1900; // Atualiza o brilho do LED
            pwm_set_gpio_level(LED_PIN, led_brightness);
            sleep_ms(10);
        }
    }

    return 0;
}