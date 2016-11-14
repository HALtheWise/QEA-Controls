float PID(float Kp, float Ki, float Vset){
  static float integralE;
  static long lastRead = millis();

  const int analogInPin = A0;
  const int analogOutPin = 5;

  float R =50;
  // read the analog in value:
  int inValue = analogRead(analogInPin);            
  
  float Vin = (float)inValue/1024.0*5.0;
  float err = (Vset-Vin);
  integralE = integralE +err*(millis() - lastRead)/1000.0;

  lastRead = millis(); 
  
  float P = Kp*err + Ki*integralE;
  if (P<0) P=0;
    
  float Vout = sqrt(P*R);
  if (Vout>5) Vout =5;
  if (Vout<0) Vout = 0;
  
  analogWrite(analogOutPin, (Vout/5.0)*255);

  return Vout;
}
