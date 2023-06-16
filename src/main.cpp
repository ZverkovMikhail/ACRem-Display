#include <Arduino.h>
#include <Display/Display.h>


int temp = 19;
ACStatus statusGenerate(int temp, Power p, Mode m, Fan f, Swing_v s){
 ACStatus stat;
 stat.power = p;
    stat.mode = m;
    stat.temp = temp;
    stat.fan = f;
    stat.swing_v = s;
    return stat;
}
void setup() {
  DisPlay.init();
}

void loop() {  
  DisPlay.output_status(statusGenerate(temp++, off, Auto, Quiet, Highest));
  delay(3000);
  DisPlay.output_status(statusGenerate(temp++, on, Auto, Quiet, Highest));
  delay(3000);
  DisPlay.output_status(statusGenerate(temp++, on, Fun, Medium, High));
  delay(3000);
  DisPlay.output_status(statusGenerate(temp++, on, Dry, Maximum, Middle));
  delay(3000);
  DisPlay.output_status(statusGenerate(temp++, on, Cool, Quiet, Low));
  delay(3000);
  DisPlay.output_status(statusGenerate(temp++, on, Heat, Medium, Auto_swing));
  delay(3000);
  DisPlay.output_status(statusGenerate(temp++, on, Auto, Maximum, Highest));
  if(temp > 30)
    temp = 19;
  delay(3000);
}