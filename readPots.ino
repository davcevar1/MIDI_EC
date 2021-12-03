void readPots(){
  int diff = 4; // difference among ponten..

  // read potenciometers //

   int potVal = analogRead(pot); 
 int potVal1 = analogRead(pot1);
 int potVal2 = analogRead(pot2);
 int potVal3 = analogRead(pot3);
 int potVal4 = analogRead(pot4); 
 int potVal5 = analogRead(pot5);

 //Calculate diferences between new value and last recorded value//

 int potValdif = potVal - lastPotVal; 
 int potVal1dif = potVal1 - lastPotVal1;
 int potVal2dif = potVal2 - lastPotVal2;
 int potVal3dif = potVal3 - lastPotVal3;
 int potVal4dif = potVal4 - lastPotVal4;
 int potVal5dif = potVal5 - lastPotVal5;
  
  

 // now we will send a MIDImessage//

  if (abs(potValdif) > diff)
    {
    MIDImessage(177, 0, map(potVal, 0, 1023 , 0, 127));//thats the way that we will map the sensor range to midi range
    lastPotVal =  potVal;// will read the old value as a new reading
    }
  
  if (abs(potVal1dif) > diff)
    {
    MIDImessage(177, 1, map(potVal1, 0, 1023 , 0, 127));//thats the way that we will map the sensor range to midi range
    lastPotVal1 =  potVal1;// will read the old value as a new reading
    }

  
  if (abs(potVal2dif) > diff)
    {
    MIDImessage(177, 2, map(potVal2, 0, 1023 , 0, 127));//thats the way that we will map the sensor range to midi range
    lastPotVal2 =  potVal2;// will read the old value as a new reading
    }

    
  if (abs(potVal3dif) > diff)
    {
    MIDImessage(177, 3, map(potVal3, 0, 1023 , 0, 127));//thats the way that we will map the sensor range to midi range
    lastPotVal3 =  potVal3;// will read the old value as a new reading
    }

 
  if (abs(potVal4dif) > diff)
    {
    MIDImessage(177, 4, map(potVal4, 0, 1023 , 0, 127));//thats the way that we will map the sensor range to midi range
    lastPotVal4 =  potVal4;// will read the old value as a new reading
    }
    
  if (abs(potVal5dif) > diff)
    {
    MIDImessage(177, 5, map(potVal5, 0, 1023 , 0, 127));//thats the way that we will map the sensor range to midi range
    lastPotVal5 =  potVal5;// will read the old value as a new reading
    }
    delay(2);//  delay will stabilizes readings while mapping

}
