// Socket client

#include <DHT.h>
#include <WiFi.h>
#include <sstream>

// Declaration part
int DHTDataPin = 5;
int port = 8080;
const char* ipAddress = "192.168.198.35";

const char* ssid = "Wi-Fi";
const char* password = "ThierryTeach";

WiFiClient server;
DHT dht(DHTDataPin, DHT11);
std::ostringstream jsonSerializer;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("\nConnecting to the WiFi Network.");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nWe're connected now.");
  Serial.print("Local ESP32 IP: ");
  Serial.print(WiFi.localIP());
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  const char* land_plot = "KN87 St7 Kigali";

  jsonSerializer << "{ \"land_plot\":\"" << land_plot
                 << "\", \"temperature\": " << temp
                 << ", \"humidity\": " << hum << "}\n";

  if (server.connect(ipAddress, port)) {
    if (server.connected()) {
      server.write(jsonSerializer.str().c_str());
      //Serial.println(jsonSerializer.str().c_str());
    }
  }
  jsonSerializer.str("");
  jsonSerializer.clear();
  delay(5000);
}
