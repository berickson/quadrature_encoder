
long odometer = 0;

int pin_sensor_a = 22;
int pin_sensor_b = 7;


void count_interrupt_a() {
  if(digitalRead(pin_sensor_a)==digitalRead(pin_sensor_b)){
    --odometer;
  } else {
    ++odometer;
  }
}

void count_interrupt_b() {
  if(digitalRead(pin_sensor_a)==digitalRead(pin_sensor_b)){
    ++odometer;
  } else {
    --odometer;
  }
}

void setup() {                
  Serial.begin(9600);
  Serial.println("started optical_counter");
  pinMode(pin_sensor_a,INPUT);
  pinMode(pin_sensor_b,INPUT);
  
  attachInterrupt(pin_sensor_a,count_interrupt_a, CHANGE);
  attachInterrupt(pin_sensor_b,count_interrupt_b, CHANGE);
  
}


void loop() {
  Serial.println(odometer);
  delay(1000);
}
