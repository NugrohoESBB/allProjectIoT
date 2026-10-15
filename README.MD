# All of Labschool project
# 
# ESP8266 30 Pin NodeMCU PIN-OUT
![Wiring](https://github.com/NugrohoESBB/projectToT/blob/main/esp8266-nodemcu-pinout.jpg)

# 

## 1. Irrigation System
Run Website -> not available

## Schematic
![Wiring](https://github.com/NugrohoESBB/projectToT/blob/main/irrigationSystem/Wiring%20Irrigation%20System.jpg)

## Documentation
## Soil Moisture Sensor Pin Use to ESP8266 NodeMCU

| PIN Soil | Type     | Pin ESP8266 NodeMCU| 
| :-------- | :------- |  :------- |
| `DATA` | `Communication` |`A0` |
| `GND` | `Ground` |`GND`|
| `VCC` | `Power` | `3.3V`|

## Relay 1 Channel Pin Use to ESP8266 NodeMCU

| PIN Relay | Type     | Pin ESP8266 NodeMCU| 
| :-------- | :------- |  :------- |
| `IN` | `Communication` |`D1 (GPIO5)` |
| `GND` | `Ground` |`GND`|
| `VCC` | `Power` | `3.3V`|

## Water Pump & Battery Pin Use to Relay 1 Channel

| PIN Water Pump & Battery | Type     | Pin Relay & Battery| 
| :-------- | :------- |  :------- |
| `VCC` | `Power` | `NO`|
| `VCC Battery` | `Power` | `COM`|
| `GND` | `Ground` |`GND Battery`|

## Buzzer Pin Use to ESP8266 NodeMCU

| PIN Buzzer | Type     | Pin ESP8266 NodeMCU| 
| :-------- | :------- |  :------- |
| `VCC` | `Power & Communication` | `D2 (GPIO4)`|
| `GND` | `Ground` |`GND`|

## Buzzer Pin Use to WeMos D1 Mini (3 Pin Version)

| PIN Buzzer | Type     | Pin WeMos D1 Mini| 
| :-------- | :------- |  :------- |
| `DATA` | `Communication` |`D2 (GPIO4)` |
| `GND` | `Ground` |`GND`|
| `VCC` | `Power` | `5V`|

## LED Traffic Light Pin Use to ESP8266 NodeMCU

| PIN LED | Type     | Pin ESP8266 NodeMCU| 
| :-------- | :------- |  :------- |
| `Red` | `Power & Communication` | `D5 (GPIO14)`|
| `Yellow` | `Power & Communication` | `D6 (GPIO12)`|
| `Green` | `Power & Communication` | `D7 (GPIO13)`|
| `GND` | `Ground` |`GND`|

## Formula for reading the soil moisture sensor as a percentage
```c++
int readSoilPercent() {
  long sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += analogRead(PIN_SOIL);
    delay(5);
  }
  int raw = sum / 10;
  int pct = map(raw, SOIL_DRY, SOIL_WET, 0, 100);
  return constrain(pct, 0, 100);
}
```

# 

## 2. Hydroponic Water Level System
Run Website -> not available

## Schematic
![Wiring](https://github.com/NugrohoESBB/projectToT/blob/main/hydroponicWaterLevel/Wiring%20Hydroponic%20Water%20Level.jpg)

## Documentation
## Water Level Sensor Pin Use to ESP8266 NodeMCU

| PIN Water Level | Type     | Pin ESP8266 NodeMCU| 
| :-------- | :------- |  :------- |
| `DATA` | `Communication` |`A0` |
| `GND` | `Ground` |`GND`|
| `VCC` | `Power` | `D0 (GPIO16)`|

## Relay 1 Channel Pin Use to ESP8266 NodeMCU

| PIN Relay | Type     | Pin ESP8266 NodeMCU| 
| :-------- | :------- |  :------- |
| `IN` | `Communication` |`D1 (GPIO5)` |
| `GND` | `Ground` |`GND`|
| `VCC` | `Power` | `3.3V`|

## Water Pump & Battery Pin Use to Relay 1 Channel

| PIN Water Pump & Battery | Type     | Pin Relay & Battery| 
| :-------- | :------- |  :------- |
| `VCC` | `Power` | `NO`|
| `VCC Battery` | `Power` | `COM`|
| `GND` | `Ground` |`GND Battery`|

## Buzzer Pin Use to ESP8266 NodeMCU

| PIN Buzzer | Type     | Pin ESP8266 NodeMCU| 
| :-------- | :------- |  :------- |
| `VCC` | `Power & Communication` | `D2 (GPIO4)`|
| `GND` | `Ground` |`GND`|

## Buzzer Pin Use to WeMos D1 Mini (3 Pin Version)

| PIN Buzzer | Type     | Pin WeMos D1 Mini| 
| :-------- | :------- |  :------- |
| `DATA` | `Communication` |`D2 (GPIO4)` |
| `GND` | `Ground` |`GND`|
| `VCC` | `Power` | `5V`|

## LED Traffic Light Pin Use to ESP8266 NodeMCU

| PIN LED | Type     | Pin ESP8266 NodeMCU| 
| :-------- | :------- |  :------- |
| `Red` | `Power & Communication` | `D5 (GPIO14)`|
| `Yellow` | `Power & Communication` | `D6 (GPIO12)`|
| `Green` | `Power & Communication` | `D7 (GPIO13)`|
| `GND` | `Ground` |`GND`|

## Formula for reading the water level as a percentage
```c++
int readLevelPercent() {
  digitalWrite(PIN_SENSOR_PWR, HIGH);
  delay(50);
  long sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += analogRead(PIN_LEVEL);
    delay(5);
  }
  digitalWrite(PIN_SENSOR_PWR, LOW);
  int raw = sum / 10;
  int pct = map(raw, LEVEL_EMPTY, LEVEL_FULL, 0, 100);
  return constrain(pct, 0, 100);
}
```

# 

## 3. Parking Gate System
Run Website -> not available

## Schematic
![Wiring](https://github.com/NugrohoESBB/projectToT/blob/main/parkingGate/parking%20system.png)

## Schematic (Powerbank Version)
![Wiring](https://github.com/NugrohoESBB/projectToT/blob/main/parkingGate/parking%20system%20(powerbank%20version).png)

## Documentation
## HC-SR04 (Ultrasonic Sensor) Pin Use to ESP8266 NodeMCU

| PIN Water Level | Type     | Pin ESP8266 NodeMCU| 
| :-------- | :------- |  :------- |
| `ECHO` | `Communication` |`D2 (GPIO4)` |
| `TRIG` | `Communication` |`D1 (GPIO5)` |
| `GND` | `Ground` |`GND`|
| `VCC` | `Power` | `5V`|

## Servo Pin Use to ESP8266 NodeMCU

| PIN Relay | Type     | Pin ESP8266 NodeMCU| 
| :-------- | :------- |  :------- |
| `DATA (Orange)` | `Communication` |`D5 (GPIO14)` |
| `GND (Brown)` | `Ground` |`GND`|
| `VCC (Red)` | `Power` | `5V`|

## Formula for reading the distance in cm from the ultrasonic sensor
```c++
float readDistanceCm() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  long duration = pulseIn(PIN_ECHO, HIGH, 30000);
  if (duration == 0) {
    return 999.0;
  }
  return duration * 0.0343 / 2.0;
}
```

# 

## 4. Parking Slot Detection System
Run Website -> not available

## Schematic
![Wiring](https://github.com/NugrohoESBB/projectToT/blob/main/parkingSlot/parking%20slot%20detection.png)

## Schematic (Powerbank Version)
![Wiring](https://github.com/NugrohoESBB/projectToT/blob/main/parkingSlot/parking%20slot%20detection%20(powerbank%20version).png)

## Documentation
## IR Sensor Pin Use to ESP8266 NodeMCU

| PIN Water Level | Type     | Pin ESP8266 NodeMCU| 
| :-------- | :------- |  :------- |
| `DATA` | `Communication` |`D5 (GPIO14)` |
| `GND` | `Ground` |`GND`|
| `VCC` | `Power` | `3.3V or 5V`|

## LCD 16x2 with I2C Pin Use to ESP8266 NodeMCU

| PIN LCD | Type     | Pin ESP8266 NodeMCU| 
| :-------- | :------- |  :------- |
| `SDA` | `Communication Serial` |`D2 (SDA)` |
| `SCL` | `Communication Serial` |`D1 (SCL)`|
| `GND` | `Ground` |`GND`|
| `5V` | `VCC` | `5V`|

## LED Traffic Light Pin Use to ESP8266 NodeMCU

| PIN LED | Type     | Pin ESP8266 NodeMCU| 
| :-------- | :------- |  :------- |
| `Red` | `Power & Communication` | `D6 (GPIO12)`|
| `Yellow` | `Power & Communication` | `D7 (GPIO13)`|
| `Green` | `Power & Communication` | `D0 (GPIO16)`|
| `GND` | `Ground` |`GND`|

## Troubleshooting: LCD Initialization Error on ESP8266
When compiling the ESP8266 sketch, one of the following errors may occur due to differences in the installed `LiquidCrystal_I2C` library.

**Error 1:**
```text
error: 'class LiquidCrystal_I2C' has no member named 'init'
```

**Solution:** Replace `lcd.init();` with `lcd.begin();`.

**Error 2:**
```text
error: 'class LiquidCrystal_I2C' has no member named 'begin'
```

**Solution:** Replace `lcd.begin();` with `lcd.init();`.

# 
# 
# 

# All of ToT Project
# 
# ESP32 30 Pin NodeMCU PIN-OUT
![Wiring](https://github.com/NugrohoESBB/projectToT/blob/main/ESP32-DevKit-V1-Pinout-Diagram.png)

# 

## 1. Smart Learning Signal Station
Run Website -> not available

Project IoT berbasis ESP32 yang menggabungkan display OLED, sensor suhu dan kelembapan, sensor gerak, sensor cahaya, signal bar 5 LED, buzzer, serta relay untuk mengontrol USB Lamp.

## Schematic
![Wiring](https://github.com/NugrohoESBB/allProjectIoT/blob/main/projectToT/learningSignalStation/smart%20learning%20signal%20station.png)

## Schematic (Breadboard Version)
![Wiring](https://github.com/NugrohoESBB/allProjectIoT/blob/main/projectToT/learningSignalStation/smart%20learning%20signal%20station%20(breadboard%20version).png)

## Library Installation (Arduino IDE)
Kode program memakai 7 header. Tiga di antaranya sudah bawaan ESP32 dan empat library perlu diinstall.

| Header | Library | Author | Perlu Install? |
| :-------- | :------- | :------- | :------- |
| `WiFi.h` | `WiFi` | `Espressif (ESP32 core)` | `Tidak, sudah bawaan` |
| `WebServer.h` | `WebServer` | `Espressif (ESP32 core)` | `Tidak, sudah bawaan` |
| `Wire.h` | `Wire` | `Espressif (ESP32 core)` | `Tidak, sudah bawaan` |
| `WiFiManager.h` | `WiFiManager` | `tablatronix` | `Ya` |
| `DHT.h` | `DHT sensor library` | `Adafruit` | `Ya` |
| `Adafruit_GFX.h` | `Adafruit GFX Library` | `Adafruit` | `Ya` |
| `Adafruit_SSD1306.h` | `Adafruit SSD1306` | `Adafruit` | `Ya` |

Library pendukung (dependency) yang ikut dibutuhkan:
| Library | Dibutuhkan Oleh | Keterangan |
| :-------- | :------- | :------- |
| `Adafruit Unified Sensor` | `DHT sensor library` | `Wajib, jika tidak ada akan error Adafruit_Sensor.h` |
| `Adafruit BusIO` | `Adafruit SSD1306 / GFX` | `Biasanya ikut terinstall otomatis` |

### Step 1: Install Board ESP32
1. Install **Arduino IDE versi 1.8.19** dari arduino.cc/en/software
2. Buka **File > Preferences**, isi **Additional boards manager URLs** dengan:

```text
https://espressif.github.io/arduino-esp32/package_esp32_index.json
```

3. Buka **Tools > Board > Boards Manager**, cari `esp32`, lalu install **esp32 by Espressif Systems**.

### Step 2: Install Library
1. Buka **Tools > Manage Libraries** (atau tekan `Ctrl+Shift+I`).
2. Cari dan install satu per satu:
| Cari di Library Manager | Pilih |
| :-------- | :------- |
| `WiFiManager` | `WiFiManager by tablatronix` |
| `DHT sensor library` | `DHT sensor library by Adafruit` |
| `Adafruit Unified Sensor` | `Adafruit Unified Sensor by Adafruit` |
| `Adafruit GFX Library` | `Adafruit GFX Library by Adafruit` |
| `Adafruit SSD1306` | `Adafruit SSD1306 by Adafruit` |

3. Jika muncul pop-up dependency, pilih **Install all**.
> **Catatan Library WebServer.h:** `WebServer.h` bukan library terpisah di Library Manager. File ini baru tersedia setelah paket board **esp32 by Espressif Systems** terinstall dan board ESP32 dipilih di **Tools > Board**. Jika tidak ada di Library Manager, itu normal.

Cara mengecek `WebServer.h` sudah ada:
1. Pilih board **ESP32 Dev Module** di **Tools > Board**.
2. Buka **File > Examples**, lalu cari kelompok **Examples for ESP32 Dev Module > WebServer**. Jika contoh `HelloServer` muncul, `WebServer.h` sudah tersedia.
3. Lokasi file di Windows: `C:\Users\<nama-user>\AppData\Local\Arduino15\packages\esp32\hardware\esp32\<versi>\libraries\WebServer`.

### Step 3: Upload Kode
1. Simpan sketch dalam folder dengan nama yang sama dengan file `.ino`. Contoh: `smart_learning_signal_station/smart_learning_signal_station.ino`.
2. Pilih **Tools > Board > esp32 > ESP32 Dev Module**.
3. Sambungkan ESP32 ke USB, lalu pilih **Tools > Port** yang sesuai.
4. Klik **Verify** (ikon centang) untuk cek kode **(langkah ini bisa dilewati)**.
5. lalu klik **Upload** (ikon panah).
6. Buka **Tools > Serial Monitor** dengan baud rate `115200`.

## Troubleshooting Library
| Error / Masalah | Penyebab | Solusi |
| :-------- | :------- | :------- |
| `WiFiManager.h: No such file or directory` | `Library WiFiManager belum terinstall` | `Install WiFiManager by tablatronix` |
| `Adafruit_Sensor.h: No such file or directory` | `Dependency DHT belum ada` | `Install Adafruit Unified Sensor` |
| `Adafruit_GFX.h` atau `Adafruit_SSD1306.h` tidak ditemukan | `Library OLED belum terinstall` | `Install Adafruit GFX Library dan Adafruit SSD1306` |
| `WebServer.h: No such file or directory` | `Board yang dipilih bukan ESP32 (misalnya ESP8266 atau Arduino)` | `Pilih Tools > Board > esp32 > ESP32 Dev Module` |
| `WebServer.h: No such file or directory` | `Paket board esp32 belum terinstall atau belum selesai terunduh` | `Install esp32 by Espressif Systems di Boards Manager, lalu restart Arduino IDE` |
| `WebServer.h` error aneh (misalnya `http_parser.h` tidak ditemukan) | `Ada library WebServer manual di Documents/Arduino/libraries yang bentrok dengan bawaan board` | `Hapus folder WebServer di Documents/Arduino/libraries, lalu restart Arduino IDE` |
| `WebServer.h` tidak terbaca padahal board benar | `Ada file bernama WebServer.h di folder sketch yang menimpa bawaan` | `Ganti nama atau pindahkan file tersebut, lalu Verify ulang` |
| `Failed to connect to ESP32: Timed out waiting for packet header` | `ESP32 belum masuk mode upload` | `Tahan tombol BOOT saat proses upload dimulai` |
| Port COM tidak muncul | `Kabel USB hanya untuk charging atau driver belum ada` | `Ganti kabel data, install driver CP210x atau CH340` |
| OLED tidak menyala | `Alamat I2C atau wiring salah` | `Cek SDA ke D21, SCL ke D22, dan alamat 0x3C di kode` |

#

## Documentation
## Power Rail Use to ESP32 DevKit
| PIN ESP32 | Type     | Connected To |
| :-------- | :------- | :------- |
| `3V3` | `Power 3.3V` | `Plus (+) breadboard rail` |
| `GND` | `Ground` | `Minus (-) breadboard rail` |
| `VIN` | `Power 5V` | `VCC Relay, NO Relay, Battery (+)` |
> **Warning:** Jangan hubungkan `VIN (5V)` ke rail plus breadboard 3.3V. `VIN` hanya untuk relay dan baterai.

## OLED 0.96" I2C Pin Use to ESP32 DevKit
| PIN OLED | Type     | Pin ESP32 DevKit |
| :-------- | :------- | :------- |
| `VCC` | `Power` | `3.3V (rail +)` |
| `GND` | `Ground` | `GND (rail -)` |
| `SDA` | `Communication Serial` | `D21 (GPIO21)` |
| `SCL` | `Communication Serial` | `D22 (GPIO22)` |

## DHT22 Pin Use to ESP32 DevKit
| PIN DHT22 | Type     | Pin ESP32 DevKit |
| :-------- | :------- | :------- |
| `VCC (+)` | `Power` | `3.3V (rail +)` |
| `DATA (out)` | `Communication Digital` | `D26 (GPIO26)` |
| `GND (-)` | `Ground` | `GND (rail -)` |

## PIR Motion Sensor Pin Use to ESP32 DevKit
| PIN PIR | Type     | Pin ESP32 DevKit |
| :-------- | :------- | :------- |
| `VCC` | `Power` | `3.3V (rail +)` |
| `OUT` | `Communication Digital` | `D27 (GPIO27)` |
| `GND` | `Ground` | `GND (rail -)` |
> **Note:** PIR membutuhkan 30 sampai 60 detik untuk kalibrasi awal setelah diberi daya.

## LDR Light Sensor Pin Use to ESP32 DevKit
LDR dirangkai sebagai pembagi tegangan (voltage divider) dengan resistor.

| PIN LDR | Type     | Pin ESP32 DevKit |
| :-------- | :------- | :------- |
| `Leg 1` | `Power` | `3.3V (rail +)` |
| `Leg 2` | `Communication Analog` | `D34 (GPIO34)` |
| `Resistor 220 Ω (between Leg 2 and GND)` | `Ground` | `GND (rail -)` |
> **Note:** Jangan hubungkan LDR langsung ke plus dan minus tanpa resistor.

## LED Signal Bar Pin Use to ESP32 DevKit
Setiap LED wajib memakai resistor 220 Ω dengan pola: `GPIO → anoda (kaki panjang) → katoda (kaki pendek) → resistor 220 Ω → GND`.

| PIN LED | Type     | Pin ESP32 DevKit |
| :-------- | :------- | :------- |
| `LED 1 Red (Anode)` | `Power & Communication` | `D13 (GPIO13)` |
| `LED 2 Yellow (Anode)` | `Power & Communication` | `D25 (GPIO25)` |
| `LED 3 Green (Anode)` | `Power & Communication` | `D14 (GPIO14)` |
| `LED 4 Blue (Anode)` | `Power & Communication` | `D15 (GPIO15)` |
| `LED 5 White (Anode)` | `Power & Communication` | `D4 (GPIO4)` |
| `Cathode (all LED)` | `Ground` | `Resistor 220 Ω then GND (rail -)` |

## Buzzer Pin Use to ESP32 DevKit
| PIN Buzzer | Type     | Pin ESP32 DevKit |
| :-------- | :------- | :------- |
| `Red (+)` | `Power & Communication` | `D18 (GPIO18)` |
| `Black (-)` | `Ground` | `GND (rail -)` |
> **Note:** Jangan hubungkan kabel merah buzzer ke rail plus, karena buzzer akan menyala terus.

## Relay Module Pin Use to ESP32 DevKit
| PIN Relay | Type     | Pin ESP32 DevKit / Connected To |
| :-------- | :------- | :------- |
| `VCC` | `Power` | `VIN (5V)` |
| `GND` | `Ground` | `GND (rail -)` |
| `IN1` | `Communication Digital` | `D19 (GPIO19)` |
| `NO (Normally Open)` | `Power Switch Input` | `VIN (5V)` |
| `COM (Common)` | `Power Switch Output` | `USB Female Connector (red wire, +5V)` |
| `NC (Normally Closed)` | `Not Used` | `-` |

## USB Female Connector (USB Lamp) Pin Use to Relay and ESP32 DevKit
| PIN USB Female | Type     | Connected To |
| :-------- | :------- | :------- |
| `Red (+5V / VBUS)` | `Power` | `COM Relay` |
| `Black (GND)` | `Ground` | `GND (rail -)` |
> **Note:** Jalur 5V ke lampu harus melewati relay (`NO` dan `COM`). Jika `VIN` disambung langsung ke konektor, lampu akan menyala terus.

## Battery Holder Pin Use to ESP32 DevKit
| PIN Battery Holder | Type     | Pin ESP32 DevKit |
| :-------- | :------- | :------- |
| `Red (+)` | `Power` | `VIN (5V)` |
| `Black (-)` | `Ground` | `GND (rail -)` |

# 

# NUBARA © Nugroho Eko S Batubara 2020 - 2026. All Rights Reserved.

