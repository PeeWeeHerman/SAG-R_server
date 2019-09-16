#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial BT(10,11);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth
int led = 13;
char b = 0;

void setup()
{
  BT.begin(9600);       // Inicializamos el puerto serie BT (Para Modo AT 2)
  Serial.begin(9600);   // Inicializamos  el puerto serie  
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
}
 
void loop()
{
  if(BT.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    b = BT.read();
    Serial.write(b);
    if(b == 'hola'){
      Serial.print("entra");
      digitalWrite(led,HIGH);
      }
    if(b == '2'){
      Serial.print("chau");
      digitalWrite(led,LOW);
      BT.write("PUTAZO");
      }
        
  }
 
  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  {
     BT.write(Serial.read());
  }
}
