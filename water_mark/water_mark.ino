int pin = 2; 
volatile unsigned int pulse; 
float volume = 0; 
float flow_rate =0; 
const int pulses_per_litre = 450; 
void setup() 
{ 
Serial.begin(9600); 
pinMode(pin, INPUT); 
attachInterrupt(0, count_pulse, RISING); 
} 
void loop() 
{ 
pulse=0; 
interrupts(); 
delay(1000); 
noInterrupts(); 

Serial.print("Pulses per second: "); 
Serial.println(pulse); 
 
flow_rate = pulse * 1000/pulses_per_litre; 
Serial.print("Water flow rate: "); 
Serial.print(flow_rate); 
Serial.println(" milliliters per second"); 
 
volume = volume + flow_rate; 
Serial.print("Volume: "); 
Serial.print(volume); 
Serial.println(" milliliters"); 
} 
void count_pulse() 
{ 
  pulse++; 
} 
