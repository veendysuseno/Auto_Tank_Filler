// Auto_Tank_Filler
#define ECHOPIN 10                            
#define TRIGPIN 11  
#define pompa 12

int H2,HT,H1,SetPoint;
void setup(){
    
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(pompa, OUTPUT);
  delay(1000);
  HT=200;
  SetPoint=150;
}

void loop(){
  digitalWrite(TRIGPIN, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   
  int distance = pulseIn(ECHOPIN, HIGH);        
  distance= distance/58;                        
  H2=HT-distance;                    
  if(H2>SetPoint){
      digitalWrite(pompa,HIGH);
    }
  else{
      digitalWrite(pompa,LOW);
  }
  delay(1000);    
}

