# 🎧 2526_Maker_CasqueBluetooth: Création d'un casque bluetooth DIY

## 📌 Présentation du Projet

Le but de ce projet est de créer un casque bluetooth en mobilisant les compétences apprises lors de l'option **Maker** de deuxième année de l'**ENSEA**. Pour réaliser ce casque, le choix du microcontroleur c'est porté sur l'utilisation d'un **ESP32-S3-MINI-1-N8**. La structure mécanique a été entièrement modélisée sur **Onshape** avec une attention particulière portée à l'intégration électronique et à la durabilité tandis que la conception électronique a été réalisée sur Kicad.

### Caractéristiques Principales
* **Micronctroleur :** ESP32-S3-MINI-N8.
* **Diamètre des oreillettes :** 82 mm.
* **Interface :** Contrôle du volume et lecture via 3 boutons physiques (GPIO 0, 1, 2).
* **Connectivité :** USB-C 16 pins.
* **Architecture Audio :** Flux numérique I2S (Pins 6, 7, 8) vers DAC/Ampli.

---

## 🛠 Technologies & Outils
* **Mécanique :** Onshape (Modélisation 3D).
* **Électronique :** KiCad (Conception du PCB).
* **Développement :** Arduino IDE 1.8.19.

## 📋 État du Prototype
* **Hardware :** PCB soudé et fonctionnel (LED verte OK).
* **Mécanique :** Impression 3D terminée et finalisée.
* **Firmware :** En cours d'optimisation pour la reconnaissance USB Audio.

---

## ⚡L'impasse du Bluetooth classique sur l'ESP32-S3

Lors de la progammation du PCB, un problème est intervenu. Il est impossible de compiler le code car l'ESP32-S2-MINI-N8. En effet conttairement au téléphone qui a un protocole bluetooth pour l'audio de A2DP (Classic), l'ESP32 ne finctionne que en Bluetooth LE. Cette erreur dans le choix du composant a empecher de réliser  la finialisation de ce pojet. Car la bibliothèque de référence `ESP32-A2DP` est= incompatible avec cette puce. Le S3 est conçu pour le **Bluetooth LE (Low Energy)** et le futur standard **LE Audio**, qui nécessite un smartphone très récent.

    1. Modification du PCB
Pour palierà ce problème, une possibilité eest d'ajoutéé un module Bluetooth Audio dédié gérant le profil A2DP. Ainsi ainsi l'ESP32 serait utilisé pour traiter l'information (la munique) et le module pour la transmmetre. Cependant, le PCB devait être modifier et avec le délai serré, il était impossible de commander un nouveau PCB modifié.

    2. La solution Wi-Fi
Il existe une possibilitée d'utiliser le Wi-Fi pour le streaming (Spotify Connect). Cependant, le casque devenait dépendant d'un réseau Wi-Fi local, perdant son utilité en déplacement.

      3. La Solution USB DAC
Pour sauver le projet sans changer le PCB déjà soudé, une autre solution est envisageable vers un mode **USB DAC**. 
En utilisant les pins natives **D- (GPIO 19)** et **D+ (GPIO 20)** de l'ESP32-S3, le casque est reconnu comme une carte son externe par le téléphone. Ainsi, il y a la possibilité de transformer le prototype d'un casque bluetooth à un casque filiaire.


