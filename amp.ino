float getAnalogAmp()
{
  //Measuring Current Using ACS712

  int   sampling = 250;

  double mVperAmp = 66; // use 185 for 5A Module, 100 for 20A Module, and 66 for 30A Module
  float ACSoffset = 2470.345;

  double RawValue = 0;
  double V = 0;
  double Amps = 0;

  for(int i=0; i<sampling; i++)
    {
    RawValue += analogRead(23);  //pin 
    delay(1);
    }
  
  RawValue /= sampling;
   
  V = (RawValue / 4096.0) * 3300; // Gets you mV
  Amps = ((V - ACSoffset) / mVperAmp);

  Serial.print( "Amps:");
  Serial.println( Amps );
  return Amps;

}