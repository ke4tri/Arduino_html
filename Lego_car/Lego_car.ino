

//Put all the pins in an array to make them easy to work with
int pins[] {
    8,  //IN1 on the ULN2003 Board, BLUE end of the Blue/Yellow motor coil
    9,  //IN2 on the ULN2003 Board, PINK end of the Pink/Orange motor coil
    10,  //IN3 on the ULN2003 Board, YELLOW end of the Blue/Yellow motor coil
    11,   //IN4 on the ULN2003 Board, ORANGE end of the Pink/Orange motor coil
};

//Define the wave drive sequence.  
//With the pin (coil) states as an array of arrays
int waveStepCount = 4;
int waveSteps[][4] = {
    {HIGH,LOW,LOW,LOW},
    {LOW,HIGH,LOW,LOW},
    {LOW,LOW,HIGH,LOW},
    {LOW,LOW,LOW,HIGH}
  };

//Keeps track of the current step.
//We'll use a zero based index. 
int currentStep = 0;

//Keeps track of the current direction
//Relative to the face of the motor. 
//Clockwise (true) or Counterclockwise(false)
//We'll default to clockwise
bool clockwise = true;

// How many steps to go before reversing, set to zero to not bounce.
//int targetSteps = 0;  //targetSteps 0 means the motor will just run in a single direction.
int targetSteps = 2048;  //2049 steps per rotation when wave or full stepping
//int targetSteps = 4096;  //4096 steps per rotation when half stepping

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
  
  for(int pin = 0; pin < 4; pin++) {
    pinMode(pins[pin], OUTPUT);
    digitalWrite(pins[pin], LOW);
  }
}

void step(int steps[][4], int stepCount) {
  //Then we can figure out what our current step within the sequence from the overall current step
  //and the number of steps in the sequence
  int currentStepInSequence = currentStep % stepCount;
  
  //Figure out which step to use. If clock wise, it is the same is the current step
  //if not clockwise, we fire them in the reverse order...
  int directionStep = clockwise ? currentStepInSequence : (stepCount-1) - currentStepInSequence;  

  //Set the four pins to their proper state for the current step in the sequence, 
  //and for the current direction
  for(int pin=0; pin < 4; pin++){
    digitalWrite(pins[pin],steps[directionStep][pin]);
  }  
}

void loop() {
 
  //Comment out the Serial prints to speed things up
  //Serial.print("Step: ");
  //Serial.println(currentStep);
  
  //Get a local reference to the number of steps in the sequence
  //And call the step method to advance the motor in the proper direction
  int stepCount = waveStepCount;
  step(waveSteps,waveStepCount);
    
  // Increment the program field tracking the current step we are on
  ++currentStep;
  
  // If targetSteps has been specified, and we have reached
  // that number of steps, reset the currentStep, and reverse directions
  if(targetSteps != 0 && currentStep == targetSteps){
    currentStep = 0;
    clockwise = !clockwise;
  } else if(targetSteps == 0 && currentStep == stepCount) {
    // don't reverse direction, just reset the currentStep to 0
    // resetting this will prevent currentStep from 
    // eventually overflowing the int variable it is stored in.
    currentStep = 0;
  }
  
  //2000 microseconds, or 2 milliseconds seems to be 
  //about the shortest delay that is usable.  Anything
  //lower and the motor starts to freeze. 
  //delayMicroseconds(2250);
  delay(2);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//int bluePin = 8;    //IN1 on the ULN2003 Board, BLUE end of the Blue/Yellow motor coil
//int pinkPin = 9;    //IN2 on the ULN2003 Board, PINK end of the Pink/Orange motor coil
//int yellowPin = 10;  //IN3 on the ULN2003 Board, YELLOW end of the Blue/Yellow motor coil
//int orangePin = 11;  //IN4 on the ULN2003 Board, ORANGE end of the Pink/Orange motor coil

//int bluePin2 = 7;
//int pinkPin2 = 6;
//int yellowPin2 = 5;
//int orangePin2 = 4;

                          // Well use the step count in the loop method to help with logic
//int waveStepCount = 4;

                          //Keeps track of the current step.
                          //We'll use a zero based index. 
//int currentStep = 0;

                          //Keeps track of the current direction
                          //Relative to the face of the motor. 
                          //Clockwise (true) or Counterclockwise(false)
                          //We'll default to clockwise
//bool clockwise = true;

                          // How many steps to go before reversing, set to zero to not bounce.
                          //int targetSteps = 0;  //targetSteps 0 means the motor will just run in a single direction.
//int targetSteps = 2048;  //2048 steps per rotation when wave or full stepping
                         //int targetSteps = 4096;  //4096 steps per rotation when half stepping

                        // TRY AND WRITE A FUNCTION THAT WILL BE CALLED AND RUN BOTH MOTORS
                        // AT THE SAMETIME


                        //for(int s=0; s<step_step_360; s++){
                        //    myStepper1.step(1);
                        //    myStepper2.step(1);
                        //  }



//void setup() {
//  // put your setup code here, to run once:
//  Serial.begin(9600);  
//
//    pinMode(bluePin, OUTPUT);
//    pinMode(pinkPin, OUTPUT);
//    pinMode(yellowPin, OUTPUT);
//    pinMode(orangePin,OUTPUT);

//    pinMode(bluePin2, OUTPUT); IF REUSING DON'T UNCOMMIENT THE PIN2'S
//    pinMode(pinkPin2, OUTPUT);
//    pinMode(yellowPin2, OUTPUT);
//    pinMode(orangePin2,OUTPUT);
    
//    digitalWrite(bluePin, LOW);
//    digitalWrite(pinkPin, LOW);
//    digitalWrite(yellowPin, LOW);
//    digitalWrite(orangePin, LOW);
  
//    digitalWrite(bluePin2, LOW);
//    digitalWrite(pinkPin2, LOW);
//    digitalWrite(yellowPin2, LOW);
//    digitalWrite(orangePin2, LOW);
//  
}

//void loop() {
  
  
                //Comment out the Serial prints to speed things up
                //Serial.print("Step: ");
                //Serial.println(currentStep);
                
                //Get a local reference to the number of steps in the sequence
 // int stepCount = waveStepCount;
  
                //Then we can figure out what our current step within the sequence from the overall current step
                //and the number of steps in the sequence
  //int currentStepInSequence = currentStep % stepCount;
  
                //Figure out which step to use. If clock wise, it is the same is the current step
                //if not clockwise, we fire them in the reverse order...
 // int directionStep = clockwise ? currentStepInSequence : (stepCount-1) - currentStepInSequence;  
  
 
  
//  switch(directionStep){
//    case 0:
//      digitalWrite(bluePin, HIGH);
//      digitalWrite(pinkPin, LOW);
//      digitalWrite(yellowPin, LOW);
//      digitalWrite(orangePin, LOW);
//      break;
//    case 1:
//      digitalWrite(bluePin, LOW);
//      digitalWrite(pinkPin, HIGH);
//      digitalWrite(yellowPin, LOW);
//      digitalWrite(orangePin, LOW);
//      break;
//    case 2:
//      digitalWrite(bluePin, LOW);
//      digitalWrite(pinkPin, LOW);
//      digitalWrite(yellowPin, HIGH);
//      digitalWrite(orangePin, LOW);
//      break;
//    case 3:
//      digitalWrite(bluePin, LOW);
//      digitalWrite(pinkPin, LOW);
//      digitalWrite(yellowPin, LOW);
//      digitalWrite(orangePin, HIGH);
//      break;
//  }


//    switch(directionStep){   DONT USE THIS BELOW IT IS REDUNDANT AND IS GOING TO BE USED FOR THE RUNNING 2 MOTORS AT ONCE
//    case 0:
//      digitalWrite(bluePin, HIGH);
//      digitalWrite(pinkPin, LOW);
//      digitalWrite(yellowPin, LOW);
//      digitalWrite(orangePin, LOW);
//      break;
//    case 1:
//      digitalWrite(bluePin, LOW);
//      digitalWrite(pinkPin, HIGH);
//      digitalWrite(yellowPin, LOW);
//      digitalWrite(orangePin, LOW);
//      break;
//    case 2:
//      digitalWrite(bluePin, LOW);
//      digitalWrite(pinkPin, LOW);
//      digitalWrite(yellowPin, HIGH);
//      digitalWrite(orangePin, LOW);
//      break;
//    case 3:
//      digitalWrite(bluePin, LOW);
//      digitalWrite(pinkPin, LOW);
//      digitalWrite(yellowPin, LOW);
//      digitalWrite(orangePin, HIGH);
//      break;
//  }
  
    // Increment the program field tracking the current step we are on
    
  //++currentStep;
  
  // If targetSteps has been specified, and we have reached
  // that number of steps, reset the currentStep, and reverse directions
  
//  if(targetSteps != 0 && currentStep == targetSteps){
//    currentStep = 0;
//    clockwise = !clockwise;
//  } else if(targetSteps == 0 && currentStep == stepCount) {
    
    // don't reverse direction, just reset the currentStep to 0
    // resetting this will prevent currentStep from 
    // eventually overflowing the int variable it is stored in.
    
//    currentStep = 0;
//  }
  
        //2000 microseconds, or 2 milliseconds seems to be 
        //about the shortest delay that is usable.  Anything
        //lower and the motor starts to freeze. 
        //delayMicroseconds(2250);
//  delay(2);
//}
