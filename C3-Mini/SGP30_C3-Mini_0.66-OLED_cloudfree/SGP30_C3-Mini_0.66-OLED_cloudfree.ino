#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_SGP30.h>

#define OLED_RESET 0 // GPIO0
Adafruit_SSD1306 display(OLED_RESET);

Adafruit_SGP30 sgp30; 

void setup()
{
Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  if (sgp30.begin() == false)
  {

    while (1)
      ;
  }


}

void loop()
{

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(33, 8);
  display.println("Air.Quality");

  if (sgp30.IAQmeasure())
  {
    display.setCursor(35, 16);
    display.println("CO2: ");
    display.setCursor(60, 16);
    display.println(sgp30.eCO2);

    display.setCursor(35, 25);
    display.println("TVOC: ");
    display.setCursor(65, 25);
    display.setTextSize(1);
    display.println(sgp30.TVOC);

    display.display();
     delay(2000);
  }
  else
  {
    display.println("Error!");
    display.display();

    while (1)
    {
      ;
    }
    
  }
  
  
}
