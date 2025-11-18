#include "HeartSpeed.h"

HeartSpeed heartspeed(A1);                  ///<The serial port for at observe pulse.
//HeartSpeed heartspeed(A1,RAW_DATA);       ///<The serial port mapper, observation of ECG diagram.
const int NumReadings = 10;
int heartbeatreadings[NumReadings];
int readIndex = 0;
int total = 0;
int average = 0;
/* Print the position result */
void mycb(uint8_t rawData, int value)
{
  if(rawData){
    Serial.println(value);
  }else{
    total -= heartbeatreadings[readIndex]; //subtracts the oldest reading from the total 
    heartbeatreadings[readIndex] = value; // stores the new value in the array
    total += heartbeatreadings[readIndex]; // add the new value to the overall total 

    readIndex = (readIndex + 1) % NumReadings;
    average = total / NumReadings;
    Serial.print("HeartRate Value = "); Serial.println(average); // Outputs the average of current and last heart beat reading in order to minimize noise fluctuation
  }
}
void setup() {
  Serial.begin(115200);
  heartspeed.setCB(mycb);    ///Callback function.
  heartspeed.begin(); // start heartrate monitoring

  for (int i = 0; i <NumReadings; i++){
    heartbeatreadings[i] = 0;
  }
}

void loop() {

}