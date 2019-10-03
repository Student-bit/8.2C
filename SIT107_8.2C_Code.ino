  
/*  */

//Libraries
#include <DHT.h>

//Constants
#define L 36.2
#define H 37.2
#define F 38.0
#define DHTPIN 2     
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE);

//Variables
float temp; //Stores temperature value

void setup()
{
    Serial.begin(9600);
    dht.begin();
}
void loop()
{
    temp= dht.readTemperature();
    
    Serial.print("Vital Temp: ");
    Serial.print(temp);
    Serial.print(" Celsius");
    
    if(temp < L) {
      Serial.println(" Hypothermia Warning!");
      digitalWrite(LED_BUILTIN, HIGH);
    }
    
    else if(temp > H && temp < F) {
      Serial.println(" Mild High Temperature");
      digitalWrite(LED_BUILTIN, LOW);
    }

    else if(temp >= F) {
      Serial.println(" Fever Warning!");
      digitalWrite(LED_BUILTIN, HIGH);
    }
    
    else {
      Serial.println(" normal");
      digitalWrite(LED_BUILTIN, LOW);
    }
    delay(2000); 
}
