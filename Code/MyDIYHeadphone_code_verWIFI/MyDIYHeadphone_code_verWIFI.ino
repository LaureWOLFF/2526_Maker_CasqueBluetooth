#include "Arduino.h"
#include "WiFi.h"
#include "Audio.h" // Bibliothèque de Schreibfaul1

// --- CONFIGURATION PINS ESP32-S3 ---
// Vérifie bien tes branchements physiques !
#define I2S_BCLK      6
#define I2S_LRCK      7
#define I2S_DOUT      8

// --- TES ACCÈS WI-FI ---
const char* ssid =     "Mon-casque";
const char* password = "mdp";

Audio audio;

void setup() {
    Serial.begin(115200);
    
    // 1. Connexion au réseau
    WiFi.begin(ssid, password);
    Serial.print("Connexion au Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnecté !");

    // 2. Configuration du DAC (I2S)
    // C'est ici qu'on définit les pins 6, 7 et 8
    audio.setPinout(I2S_BCLK, I2S_LRCK, I2S_DOUT);
    
    // 3. Réglage du volume (Echelle de 0 à 21)
    // Attention, commence doucement pour tes oreilles !
    audio.setVolume(12); 

    // 4. Flux de test : Radio FIP (MP3 128kbps)
    // Si ce flux démarre, tes haut-parleurs vont chanter.
    audio.connecttohost("http://direct.fipradio.fr/live/fip-midfi.mp3");
}

void loop() {
    // Crucial : La bibliothèque a besoin de cette fonction pour décoder le son
    audio.loop(); 
}

// --- OPTIONS DE DEBUG (Affichent les infos dans le moniteur série) ---
void audio_info(const char *info){
    Serial.print("Audio Info: "); Serial.println(info);
}

void audio_bitrate(const char *info){
    Serial.print("Qualité : "); Serial.print(info); Serial.println(" bits/s");
}
