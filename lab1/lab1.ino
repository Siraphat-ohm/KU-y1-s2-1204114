#define SW_PIN 2

int LED_PINS[] = {42, 41, 40};
int count = 0;
int current_led = 0;
int sw_value;


void setup() {

  Serial.begin(9600);
  sw_value = 0;
  for (int i = 0; i < 3; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }
  pinMode(SW_PIN, INPUT_PULLUP);
  digitalWrite(LED_PINS[0], 1);
}

void loop() {
  while (digitalRead(SW_PIN) == 1); 
  delay(10);
  count++;
  printf("%d\n", count);
  while (digitalRead(SW_PIN) == 0); 
  delay(10);

    current_led = count % 3;

    printf("count %d\n", count);
    for (int i = 0; i < 3; i++) {
      if ( current_led != i ) 
        digitalWrite(LED_PINS[i], 0);
      digitalWrite(LED_PINS[current_led], 1);
      
    }
}
