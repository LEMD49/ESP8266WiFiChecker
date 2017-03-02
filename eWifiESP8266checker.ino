/*
  From scratch, to test the quality of the Wifi
  by Etienne Maricq @LEMD49 maricq@ieee.org
  with Amica using NodeMCU 12E and Slab USB 2 UART 11
*/

#include <ESP8266WiFi.h>  //must have correct board else will not compile
#include <credentialsAdafruitIO.h>
byte mac[6];
int i = 0;

void setup() {
  Serial.begin(115200);
  int n = WiFi.scanNetworks(false, true);

  String ssid;
  uint8_t encryptionType;
  int32_t RSSI;
  uint8_t* BSSID;
  int32_t channel;
  bool isHidden;

  for (int i = 0; i < n; i++)
  {
    WiFi.getNetworkInfo(i, ssid, encryptionType, RSSI, BSSID, channel, isHidden);
    Serial.printf("%d: %s, Ch:%d (%ddBm) %s %s\n", i + 1, ssid.c_str(), channel, RSSI, encryptionType == ENC_TYPE_NONE ? "open" : "", isHidden ? "hidden" : "");
  }
}

void loop() {
  // put your main code here, to run repeatedly:


  //with first Wifi AP
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(5000);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: "); Serial.println(WiFi.localIP());

  long rssi = WiFi.RSSI();
  Serial.print("RSSI:");
  Serial.println(rssi);
  Serial.print("WiFi gateway IP: ");
  Serial.println(WiFi.gatewayIP());
  Serial.print("WiFi subnet mask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("WiFi DNS1: ");
  Serial.println(WiFi.dnsIP(0));
  Serial.print("WiFi DNS2: ");
  Serial.println(WiFi.dnsIP(1));
  Serial.print("WiFi SSID: ");
  Serial.println(WiFi.SSID());
  Serial.print("WiFi psk: ");
  Serial.println(WiFi.psk());
  Serial.print("WiFi BSSID: ");
  Serial.println(WiFi.BSSIDstr());

  WiFi.macAddress(mac);
  Serial.print("MAC: ");
  for (i = 5; i > 0; i--) {
    Serial.print(mac[i], HEX);
    Serial.print(":");
  }
  Serial.println(mac[0], HEX);




  delay(5000);
  WiFi.disconnect();
  Serial.println(">>>disconnecting<<<");
  Serial.println("vvvvvvvvvvvvvvvvvvv");



  //with third Wifi AP
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID3);
  WiFi.begin(WLAN_SSID3, WLAN_PASS3);
  while (WiFi.status() != WL_CONNECTED) {
    delay(5000);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());

  rssi = WiFi.RSSI();
  Serial.print("RSSI:");
  Serial.println(rssi);
  Serial.print("WiFi gateway IP: ");
  Serial.println(WiFi.gatewayIP());
  Serial.print("WiFi subnet mask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("WiFi DNS1: ");
  Serial.println(WiFi.dnsIP(0));
  Serial.print("WiFi DNS2: ");
  Serial.println(WiFi.dnsIP(1));
  Serial.print("WiFi SSID: ");
  Serial.println(WiFi.SSID());
  Serial.print("WiFi psk: ");
  Serial.println(WiFi.psk());
  Serial.print("WiFi BSSID: ");
  Serial.println(WiFi.BSSIDstr());

  WiFi.macAddress(mac);
  Serial.print("MAC: ");
  for (i = 5; i > 0; i--) {
    Serial.print(mac[i], HEX);
    Serial.print(":");
  }
  Serial.println(mac[0], HEX);


  delay(5000);
  WiFi.disconnect();
  Serial.println(">>>disconnecting<<<");
  Serial.println("vvvvvvvvvvvvvvvvvvv");


}
