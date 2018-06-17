# Setup
## Software
### Server
    sudo apt-get install apache2 php libapache2-mod-php
    cp index.php /var/www/html
    sudo chmod -R 777 /var/www/html

### Locally
#### Install arduino
Download and install arduino from [here](https://www.arduino.cc/en/Main/Software?)

#### Install ESP8266 libraries
Get ESP8266 and [ESP8266Wifi](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi) libraries and extract them in Arduino/libraries

## Mechanical
I have a plastic ball in which the ESP8266 is, covered by bubble wrap to isolate it.
There's aluminium foil inside the plastic ball, on half of the ball, this will be our capacitive sensor. One pin is linked to it. There should be enough bubble wrap to make the contact between the pin and the aluminium foil as they don't stick together naturally.