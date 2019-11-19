#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
char * ssid = "VaaYS";
char * password = "CLBKhoaHocTre2019";
IPAddress ip(192, 168, 11, 4);
IPAddress gateway(192, 168, 11, 1);
IPAddress subnet(255, 255, 255, 0);
const char * host = "192.168.11.103";
WiFiServer server(80);
String data1, data2;
byte ctro1, ctro2;
void setup() {
  Serial.begin(115200);

  Serial.print("Conneting ");
  Serial.println(ssid);
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(ip, gateway, subnet);
  WiFi.softAP(ssid, password);
  Serial.println("WiFi connected");
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  server.begin();
  Serial.println("Server started");

}

void loop() {

  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  // Wait until the client sends some data
  while (!client.available()) {
    delay(1);
  }

  // Read the first line of the request -------------------------------------
  String data = client.readStringUntil('\r');
  if (Serial1.available()) {
    data = Serial1.readString(); //Serial đọc chuỗi
  }
  for (int i = 0; i < data.length(); i++) {
    if (data.charAt(i) == '=') {
      ctro1 = i; //Tìm vị trí của dấu "="
    }
  }
  data.remove(0, ctro1 + 1);
  
  for (int i = 0; i < data.length(); i++) {
    if (data.charAt(i) == ' ') {
      ctro2 = i; //Tìm vị trí của dấu " "
    }
  }
  data.remove(ctro2);
  if (data == "Up")
  {
    Serial.print("1");
  }
  else if (data == "Down")
  {
    Serial.print("2");
  }
  else if (data == "Left")
  {
    Serial.print("3");
  }
  else  if (data == "Right")
  {
    Serial.print("4");
  }

 // Serial.println(data);
  client.flush();
}
