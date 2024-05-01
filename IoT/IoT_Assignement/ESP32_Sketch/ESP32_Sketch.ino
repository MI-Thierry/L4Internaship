// Socket client

#include <DHT.h>
#include <WiFi.h>
#include <sstream>

// Declaration part
int DHTDataPin = 5;

// TCP port and IP address server is running on.
int port = 8080;
const char* ipAddress = "192.168.198.35";

// SSID and password of Wi-Fi network you're using.
const char* ssid = "Wi-Fi";
const char* password = "ThierryTeach";

// Declaration of objects that are going to be used in this project
WiFiClient server;
DHT dht(DHTDataPin, DHT11);
std::ostringstream jsonSerializer;

void setup() {
  // Initialization and allocation of resource we need.
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);

  // Connecting to the Wi-Fi network.
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
  // Reading temperature and humidity from DHT11 sensor we have
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  const char* land_plot = "KN87 St7 Kigali";

  // Serializing data into json format
  jsonSerializer << "{ \"land_plot\":\"" << land_plot
                 << "\", \"temperature\": " << temp
                 << ", \"humidity\": " << hum << "}\n";

  // Sending serialized data to the server
  if (server.connect(ipAddress, port)) {
    if (server.connected()) {
      server.write(jsonSerializer.str().c_str());
      //Serial.println(jsonSerializer.str().c_str());
    }
  }

  // Clearing the stringstream we're using in serialization.
  jsonSerializer.str("");
  jsonSerializer.clear();
  delay(5000);
}
