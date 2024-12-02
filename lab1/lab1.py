from time import sleep

from machine import Pin

LED_PINS = [42, 41, 40]
count = 0
current_led = 0

for led in LED_PINS:
    Pin(led, Pin.OUT)

sw = Pin(2, Pin.IN, Pin.PULL_UP)
Pin(LED_PINS[0]).value(1)

while True:
    while sw.value() == 1:
        pass
    sleep(0.01)
    count += 1
    current_led = count % 3

    for i in range(len(LED_PINS)):
        if i == current_led:
            Pin(LED_PINS[i]).value(1)
        else:
            Pin(LED_PINS[i]).value(0)
    print(count)
    while sw.value() == 0:
        pass
    sleep(0.01)
