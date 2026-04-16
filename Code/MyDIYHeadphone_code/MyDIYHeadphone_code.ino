/* Projet : Casque Bluetooth
   Auteur : Laure WOLFF
   Date : avril 2026
*/

#define CONFIG_BT_ENABLED 1
#define CONFIG_BT_CLASSIC_ENABLED 1
#define ESP32 1

#define CONFIG_BT_ENABLED 1
#define CONFIG_BT_CLASSIC_ENABLED 1

#include <AudioLogger.h>
#include <AudioTools.h>
#include <AudioToolsConfig.h>

#include <A2DPVolumeControl.h>
#include <BluetoothA2DP.h>
#include <BluetoothA2DPCommon.h>
#include <BluetoothA2DPOutput.h>
#include <BluetoothA2DPSink.h>
#include <BluetoothA2DPSinkQueued.h>
#include <BluetoothA2DPSource.h>
#include <config.h>

const int VOL_UP   = 0; 
const int VOL_DOWN = 2; 
const int PAUSE_PLAY   = 1;

BluetoothA2DPSink MyDIYHeadphone;

void setup() {
  pinMode(VOL_UP, INPUT);
  pinMode(VOL_DOWN, INPUT);
  pinMode(PAUSE_PLAY, INPUT);

  i2s_pin_config_t my_pin_config = {
        .bck_io_num = 6,    
        .ws_io_num = 7,     
        .data_out_num = 8, 
        .data_in_num = I2S_PIN_NO_CHANGE
    };
  MyDIYHeadphone.set_pin_config(my_pin_config);
    
  //auto config = MyDIYHeadphone.default_configuration();
  MyDIYHeadphone.start("LW_Headphone");
  MyDIYHeadphone.set_volume(75);

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
