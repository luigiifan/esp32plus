# ESP32+ PROJECT

### I. Features
- Compatible with ESP32 Devkit V4
- Power Expander 5V and 3.3V (Output only)
- Stepdown Buck Converter at 4.5-28V
- Fixes Booting mode while uploading code

### II. Technical Description
| Label  | Component  | Pin    | Switchable | Description |
| :------: | :-----: | :------: | :-----: | ----- |
| S1 | Pushbutton | GPIO 34 |  | Parallel with pull-up 10K Resistor to 3.3V |
| S2 | Pushbutton | GPIO 35 |  | Parallel with pull-up 10K Resistor to 3.3V |
| L1 | 3mm LED | GPIO 17 | ✅ | Series 330 ohm Resistor for current limiter, Toggle switch (IV) to enable |
| L2 | 3mm LED | GPIO 16 | ✅ | Series 330 ohm Resistor for current limiter, Toggle switch (III) to enable |
| L3 | 3mm LED | GPIO 4 | ✅ | Series 330 ohm Resistor for current limiter, Toggle switch (II) to enable |
| L4 | 3mm LED | GPIO 2 | ✅ | Series 330 ohm Resistor for current limiter, Toggle switch (I) to enable |
| SG1 | Buzzer DC | GPIO 32 | ✅ | Place (B) jumper on pins 1-2 to enable |
| DISP | OLED 128x32 | SDA (GPIO 21) <br> SCL (GPIO 22) | ✅ | Place (D) jumper on pins 1-2 to enable |
| C1 | Polar Capacitor | EN | | Determine ESP32 to FLASH mode upon power-up |
> [!WARNING]
> The voltage output from the <ins>Stepdown Buck Converter</ins> must be in the __3.3V-5V__ range to supply power correctly and avoid damaging the board.

### III. Schematic
[Download PDF](https://github.com/user-attachments/files/19268394/esp32_plus.pdf)

### IV. 3D Model & Drawing
<p><img src="https://raw.githubusercontent.com/luigiifan/esp32plus/master/ESP32_PLUS.gif" width="350")</p>
  
[Download PDF](https://github.com/user-attachments/files/19269748/ESP32_PLUS_DRAWING.pdf)
