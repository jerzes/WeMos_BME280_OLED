#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

unsigned long delayTime;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI   13
#define OLED_CLK   12
#define OLED_DC    16
#define OLED_CS    14
#define OLED_RESET 2
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);


void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }


  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();


  // Clear the buffer
  display.clearDisplay();
      unsigned status;
    
    // default settings
    status = bme.begin();  

}

void temp(){
  display.clearDisplay();
   Serial.print(bme.readTemperature());
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.cp437(true);
  display.setCursor(0,0);
  display.print("Temp ");
  display.setTextSize(1);
    display.write(167);
  display.setTextSize(2);
  display.print("C");
  display.setCursor(1,35);
  display.setTextSize(3);
  display.print(bme.readTemperature());
  display.setTextSize(1);
  display.print(" ");
  display.setTextSize(2);
  display.write(167);
  display.setTextSize(3);
  display.print("C");
  display.display();
}

void hum(){
  display.clearDisplay();
   Serial.print(bme.readHumidity());
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.cp437(true);
  display.setCursor(0,0);
  display.print("Wilg. %");
  display.setCursor(1,35);
  display.setTextSize(3);
  display.print(bme.readHumidity());
  display.print("%");
  display.display();
}

void pres(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Cisn. hPa");
  display.setCursor(1,35);
  display.setTextSize(3);
  display.print(bme.readPressure() / 100.0F);
  display.display();
}
void loop() {

temp();
delay(3000);
hum();
delay(3000);
pres();
delay(3000);

}
