#define ANALOG_PIN 4
int LEDs[] = {2, 42, 41 };
void setup() {
  for ( int i = 0 ; i < 3 ; i++ ) {
      pinMode(LEDs[i], OUTPUT);
  }
  analogSetAttenuation(ADC_11db);
}
void led_pwm( int pin, int percent ) {
  analogWrite(pin, percent/100.0 * 255);
  delay(15);
}
void loop() {
  int ldr = analogRead(ANALOG_PIN);
  int state = 5 - ( ldr - 500 ) / 3300.0 * 5 ;
  delay(100);
  printf("analog %d, state %d \n", ldr, state);
  for ( int i = 0 ; i < 3 ; i++ ){
  if ( i == state/2  )
      led_pwm( LEDs[i], state % 2 == 0 ? 50 : 100);
    else 
      led_pwm( LEDs[i], 0);
  }
}