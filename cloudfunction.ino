int led_inbuilt = D7;

void led_toggle() {
    digitalWrite(led_inbuilt, !digitalRead(led_inbuilt));
}

void led_three_blinks() {
    // LED on for 333ms
    led_toggle();
    delay(333);
    // LED off
    led_toggle();
    
    // Gap
    delay(333);
    
    // LED on for 333ms
    led_toggle();
    delay(333);
    // LED off
    led_toggle();
    
    // Gap
    delay(333);
    
    // LED on for 333ms
    led_toggle();
    delay(333);
    // LED off
    led_toggle();
}

void led_diminishing_blinks() {
    int blink_duration = 1024;
    
    // Iterates until blink_duration is below 64    
    while (blink_duration >= 64) {
        // LED on for blink_duration
        led_toggle();
        delay(blink_duration);
        // LED off
        led_toggle();
        // Equally long gap after blink
        delay(blink_duration);
        
        // Halve blink_duration
        blink_duration = blink_duration / 2;
    }
}

void get_signal(const char *event, const char *data) {
    if (strcmp(data,"wave")==0) {
        led_three_blinks();
    }
    
    if (strcmp(data,"pat")==0) {
        led_diminishing_blinks();
    }
}

void setup() {
    pinMode(led_inbuilt, OUTPUT);
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", get_signal);
}

void loop() {
}
