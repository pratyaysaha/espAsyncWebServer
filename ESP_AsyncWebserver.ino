#include<Arduino.h>
#include<ESP8266WiFi.h>
#include<ESPAsyncWebServer.h>
#include<ESPAsyncTCP.h>
#include<FS.h>


const char* ssid = "NodeMCU";
const char* pass = "project21";

const int led =16;
String ledstate;

AsyncWebServer server(80);
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

String procesor(const String& var)
{
    Serial.println(var);
    if(var=="STATE")
    {
        if(digitalRead(led))
            ledstate="ON";
        else
            ledstate="OFF";
    }
    Serial.println(ledstate);
    return ledstate;
}

void setup()
{
    Serial.begin(9600);
    pinMode(led,OUTPUT);
    
    if(SPIFFS.begin())
    {
        Serial.println("No mounting!!");
    }


    WiFi.softAP(ssid,pass);
    WiFi.softAPConfig(local_ip,gateway,subnet);
    Serial.println(WiFi.softAPIP());

    server.on("/",HTTP_GET,[](AsyncWebServerRequest *request)
    {
        request->send(SPIFFS,"/index.html",String(),false,procesor);
    });
    server.on("/index.css",HTTP_GET,[](AsyncWebServerRequest *request)
    {
        request->send(SPIFFS,"/index.css","text/css");
    });
    server.on("/on",HTTP_GET,[](AsyncWebServerRequest *request)
    {
        digitalWrite(led,HIGH);
        request->send(SPIFFS,"/index.html",String(),false,procesor);
    });
    server.on("/off",HTTP_GET,[](AsyncWebServerRequest *request)
    {
        digitalWrite(led,LOW);
        request->send(SPIFFS,"/index.html",String(),false,procesor);
    });
    server.begin();
}
void loop()
{
    
}

