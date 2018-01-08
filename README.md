# alexa-christmas-tree

This is a project I made to turn my Christmas tree into an Alexa Voice Service device.

It's hacked together, but it works.

## Requirements

* Arduino
* A device that
  * Alexa Voice Service sample app can be installed (https://github.com/alexa/alexa-avs-sample-app)
  * Can connect to the arduino through a serial port
* WS2811 RGB 12mm Pixels LED String DC 5V
* 5V 8A LED Strip Power Supply Converter Adapter For WS2811 LED String Light
* Female Jack Connector Plug Adapter Adaptor (to connect the Power Supply to the LED string)
* Jumper cables

## Set up

1. Connect up all the electrical components
  * Positive and negative from LED string to Power Supply
  * Data from LED string to Arduino pin 6
  * negative from LED string to Arduino ground
  * Arduino connected to the device that AVS will be installed
2. Install the WS2811 Arduino library from AdaFruit. https://github.com/adafruit/Adafruit_NeoPixel
3. Upload the `arduino\alexa_ui.ino` to your Arduino.
4. Set up AVS on the device using the instructions here https://github.com/alexa/alexa-avs-sample-app/wiki
5. Copy the `avs\AVSController.java` file to replace the `alexa-avs-sample-app/samples/javaclient/src/main/java/com/amazon/alexa/avs/AVSController.java` file in the AVS sample app.
6. Recompile the AVS sample app and run it, when you ask alexa questions the lights should react in a similar way to an echo.
