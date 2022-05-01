SYSTEM_THREAD(ENABLED);

const int LED_WAVE = D5;
const int LED_PAT = D7;

void setup() {
    pinMode(LED_WAVE, OUTPUT);
    pinMode(LED_PAT, OUTPUT);
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", handler);
}

void loop() {
    
    Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "wave", PUBLIC);
    delay(5000);
    Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "pat", PUBLIC);
    delay(5000);
}

void handler(const char *event, const char *data) {
    // using comparer to check for wave
    if (strcmp(data, "wave") == 0) 
    {
        digitalWrite(LED_PAT, LOW);
        digitalWrite(LED_WAVE, HIGH);
    }
    //using comparer to check for pat
    else if (strcmp(data, "pat") == 0) 
    {
        digitalWrite(LED_WAVE, LOW);
        digitalWrite(LED_PAT, HIGH);
    }
}
