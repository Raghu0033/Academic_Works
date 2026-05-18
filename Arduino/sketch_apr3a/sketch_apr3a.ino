#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "krishinova";      // Replace with your WiFi SSID
const char* password = "12345678";  // Replace with your WiFi password

ESP8266WebServer server(2221); // Web server on port 80

void handleRoot() {
    server.send(200, "text/html", "<h1>Hello, World! from ESP8266</h1>");
}

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }

    Serial.println("\nConnected to WiFi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP()); // Print ESP8266 IP address

    server.on("/", handleRoot); // Define the root URL response
    server.begin();
    Serial.println("HTTP server started");
}

void loop() {
    server.handleClient(); // Handle incoming client requests
}
