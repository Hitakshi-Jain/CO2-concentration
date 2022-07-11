#define anInput A0
#define digTrigger 2
#define co2Zero 55

void setup() {
  // put your setup code here, to run once:
  pinMode(anInput,INPUT);
  pinMode(digTrigger,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int co2now[10];
  int co2raw = 0;
  int co2comp = 0;
  int co2ppm = 0;
  int zzz = 0;
  int grafX = 0;

  for (int x=0; x<10; x++){
    co2now[x]=analogRead(A0);
    delay(200);
  }
  for (int x=0; x<10; x++){
    zzz = zzz + co2now[x];
  }
  co2raw = zzz/10;
  co2comp = co2raw - co2Zero;
  co2ppm = map (co2comp,0,1023,400,5000);

  Serial.println("CO2 level");
  Serial.print(co2ppm);
  Serial.println("PPM");
  grafX = map(co2ppm,0,1000,0,127);
  Serial.println(grafX);
}
