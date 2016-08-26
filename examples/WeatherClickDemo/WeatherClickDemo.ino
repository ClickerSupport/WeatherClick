/* Weather Click Demonstration
 * 
 * Reads the temperature, pressure and humidity. Uses the pressure
 * to calculate the approximate height above sea level.
 * 
 * The click must be set to I2C mode (the default) and this assumes
 * the address is set to 0. If you should set the address to 1 then provide
 * the I2C slave address of 77 to the weather.begin() function.
 */

#include <WeatherClick.h>

WeatherClick weather;

// Set this to the pressure at sea level. It is used to
// calculate your approximate altitude. Units are hPa (aka Millibars).
const float SeaLevelPressure = 1020.0;

void setup() {
    Serial.begin(115200);
    weather.begin();
}

void loop() {
    delay(1000);
    Serial.printf("Temperature: %6.2f C, Pressure: %6.2f hPa, Humidity: %6.2f %%\r\n",
        weather.readTemperature(), weather.readPressure() / 100.0, weather.readHumidity());
    Serial.printf("        Approximate altitude: %6.2f m\r\n",
        weather.readAltitude(SeaLevelPressure));
    Serial.println();
}
