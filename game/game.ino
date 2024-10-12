const int numLeds = 10;  
int ledPins[numLeds] = {PC1, PC2, PC3, PC4, PC5, PC6, PC7,PC0 , PD2, PD3}; 
const int buttonPin = PD4; 
const int buzzerPin = PD5;  
int targetLed;   
int randomseedinitializer = 9;         
int buttonState = LOW;     

int ledIndex = 0;         
int delayTime = 100;     


int randomTargetLed() {
  randomSeed(randomseedinitializer);
  
  randomseedinitializer--;
  if (randomseedinitializer == 0) {
      randomseedinitializer = numLeds-1; 
  }
  return random(0, numLeds-1);  
}


void displayTargetLed() {
  //First set all LEDs to LOW
  for (int i = 0; i < numLeds; i++) {
        digitalWrite(ledPins[i], LOW);
  }
  //Set the TargetLED alone high
  digitalWrite(ledPins[targetLed], HIGH); 
 }

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT); 
  pinMode(buzzerPin, OUTPUT); 

  
  targetLed = randomTargetLed(); 
  Serial.begin(9600);             

  displayTargetLed();  
}

void loop() {

  for (int i = 0; i < numLeds; i++) {
    if ( i != targetLed)
      digitalWrite(ledPins[i], LOW);
  }

  digitalWrite(ledPins[ledIndex], HIGH);

  buttonState = digitalRead(buttonPin);

  
  if (buttonState == HIGH) {
    
    if (ledIndex == targetLed) {
      
      for (int i = 0; i < numLeds; i++) {
          digitalWrite(ledPins[i], HIGH);
      }
      delay(1500);  
     
      targetLed = randomTargetLed(); 
      displayTargetLed();            
      buttonState == LOW;
    } else {
      delay(500);  
    }
  }

  ledIndex++;
  
  if (ledIndex >= numLeds) {
    ledIndex = 0; 
  }
 
  delay(delayTime); 
}
