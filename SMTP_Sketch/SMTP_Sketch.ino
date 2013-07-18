// SMTP Email Sender using Arduino
// github.com/haoji/SMTP_Email_Sender_Arduino

#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xAF, 0xCE, 0xDD }; // Ethernet Shield MAC Address
byte ip[] = { 192, 168, 1, 3 }; // Ethernet Shield IP Address
byte server[] = { 98, 136, 86, 109 }; // SMTP Server IP Address

Client client(server, 587);  // SMTP Server Address and Port

void setup()
{
 Ethernet.begin(mac, ip);
 Serial.begin(9600);
 
 delay(1000);
 
 Serial.println("connecting...");
 
 if (client.connect()) {
   Serial.println("connected");
   client.println("EHLO MYSERVER");
   client.println("AUTH PLAIN ************************************");  // Replace the "*" with your auth info, see README
   client.println("MAIL FROM:<email@email.email>");
   client.println("RCPT TO:<email@email.email>");
   client.println("DATA");
   client.println("From: <email@email.email>");
   client.println("TO: <email@email.email>");
   client.println("SUBJECT: This is the subject");
   client.println();
   client.println("This is the body.");
   client.println("This is another line of the body.");
   client.println(".");
   client.println(".");
 } else {
   Serial.println("connection failed");
 }
}

void loop()
{
 if (client.available()) {
   char c = client.read();
   Serial.print(c);
 }
 
 if (!client.connected()) {
   Serial.println();
   Serial.println("disconnecting.");
   client.stop();
   for(;;)
     ;
 }
}
