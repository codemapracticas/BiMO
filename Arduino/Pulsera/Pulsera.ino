float temp;         // temperatura

int vibrador = 0;   // estado del vibrador


void manageChar(char c){
    //if the char equals 1
    if(c='1')
    {
        digitalWrite(9, HIGH);  
        digitalWrite(8, HIGH);   
        digitalWrite(7, HIGH);    
        digitalWrite(6, HIGH);   
        digitalWrite(5, HIGH);   
        digitalWrite(4, HIGH);    
        digitalWrite(3, HIGH);   
        digitalWrite(2, HIGH);
    }

    //if the char equals 0
    if(c='0')
    {
        digitalWrite(9, LOW);  
        digitalWrite(8, LOW);   
        digitalWrite(7, LOW);    
        digitalWrite(6, LOW);   
        digitalWrite(5, LOW);   
        digitalWrite(4, LOW);    
        digitalWrite(3, LOW);   
        digitalWrite(2, LOW);
    }
    if(c='V' && vibrador == 0)
    {
        vibrador = 1;
    }
    if(c='V' && vibrador == 1)
    {
        vibrador = 0;
    }

}


void setup() {
  Serial.begin(19200);

  pinMode(8, OUTPUT);
  
}

void loop() {
  if (vibrador == 1) 
    analogWrite(8, 128);
  else
    analogWrite(8, 0);
    
  temp = analogRead(0)*5/1024.0;
  temp = temp - 0.5;
  temp = temp / 0.01;
  Serial.print("T, ");
  Serial.println(temp);
  delay(500);
  
//  Serial.print("H, ");
//  Serial.println(h);

  while(Serial.available()>0){
    char incomingChar = Serial.read();
    manageChar(incomingChar);
  }     
}
