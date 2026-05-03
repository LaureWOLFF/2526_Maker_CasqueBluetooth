#ifndef CONFIG_BT_ENABLED
#define CONFIG_BT_ENABLED 1
#endif

#include "AudioTools.h"
#include "BluetoothA2DPSink.h"

// Définition des boutons
const int VOL_UP     = 0; 
const int VOL_DOWN   = 2; 
const int PAUSE_PLAY = 1;

BluetoothA2DPSink MyDIYHeadphone;

void setup() {
  Serial.begin(115200);
  
  pinMode(VOL_UP, INPUT_PULLUP);
  pinMode(VOL_DOWN, INPUT_PULLUP);
  pinMode(PAUSE_PLAY, INPUT_PULLUP);

  // Config I2S spécifique ESP32-S3
  i2s_pin_config_t my_pin_config = {
        .bck_io_num = 6,    
        .ws_io_num = 7,     
        .data_out_num = 8, 
        .data_in_num = I2S_PIN_NO_CHANGE
  };
  
  MyDIYHeadphone.set_pin_config(my_pin_config);
  MyDIYHeadphone.start("LW_Headphone");
}

void loop() {
  if (digitalRead(PAUSE_PLAY) == LOW) {

    if (MyDIYHeadphone.get_audio_state() == ESP_A2D_AUDIO_STATE_STARTED) {
      MyDIYHeadphone.pause();
    } else {
      MyDIYHeadphone.play();
    }
    delay(1000); 
    }

    

  if (digitalRead(VOL_UP) == LOW) {
        MyDIYHeadphone.set_volume(MyDIYHeadphone.get_volume() + 5);
        delay(200); 
    }

  if (digitalRead(VOL_DOWN) == LOW) {
        MyDIYHeadphone.set_volume(MyDIYHeadphone.get_volume() - 5);
        delay(200); 
  }
}
