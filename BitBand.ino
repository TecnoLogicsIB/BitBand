// componentes utilitzats:
const int SensorDo = 5;
const int SensorRe = 6;
const int SensorMi = 7;
const int SensorFa = 8;
const int SensorSol = 9;
const int SensorLa = 10;
const int SensorSi = 11;
const int altaveu = 13;
const int Joystick_X = A0;
const int Joystick_Y = A1;

// freqüències notes (tons):
float DO = 261.63;
float RE = 293.66;
float MI = 329.63;
float FA = 349.23;
float SOL = 392.00;
float LA = 440.00;
float SI = 493.88;

// freqüències semitons:
float DOs = 277.18;
float REs = 311.13;
float FAs = 369.99;
float SOLs = 415.30;
float LAs = 466.16;

float octava = 0;  // multiplicador de la freqüència

// ....................

// configuració dels pins digitals:
void setup()
{
  pinMode(SensorDo, INPUT);
  pinMode(SensorRe, INPUT);
  pinMode(SensorMi, INPUT);
  pinMode(SensorFa, INPUT);
  pinMode(SensorSol, INPUT);
  pinMode(SensorLa, INPUT);
  pinMode(SensorSi, INPUT);
  pinMode(altaveu, OUTPUT);
}

// definició de l'execució:
void loop()
{
  assigna_octava();
  if (analogRead(Joystick_X) < 1000)
  { assigna_nota(); }
  else
  { assigna_semito(); }
  delay(10);
}

// ....................

void assigna_octava() 
// valor de la variable octava segons posició del joystick:
{
  if (analogRead(Joystick_Y) > 600) 
  { octava = 2; }
  else if (analogRead(Joystick_Y) < 400) 
  { octava = 0.5; }
  else 
  { octava = 1; }
}

void assigna_nota()  
// freqüència segons el sensor activat: 
{
  if (digitalRead(SensorDo) == 1) 
  { tone(altaveu, DO * octava); }
  else if (digitalRead(SensorRe) == 1) 
  { tone(altaveu, RE * octava); }
  else if (digitalRead(SensorMi) == 1) 
  { tone(altaveu, MI * octava); }
  else if (digitalRead(SensorFa) == 1) 
  { tone(altaveu, FA * octava); }
  else if (digitalRead(SensorSol) == 1) 
  { tone(altaveu, SOL * octava); }
  else if (digitalRead(SensorLa) == 1) 
  { tone(altaveu, LA * octava); }
  else if (digitalRead(SensorSi) == 1) 
  { tone(altaveu, SI * octava); }
  else  
  { noTone(altaveu); }
}

void assigna_semito() 
// freqüència segons el sensor activat:
{
  if (digitalRead(SensorDo) == 1) 
  { tone(altaveu, DOs * octava); }
  else if (digitalRead(SensorRe) == 1) 
  { tone(altaveu, REs * octava); }
  else if (digitalRead(SensorMi) == 1) 
  { tone(altaveu, MI * octava); }
  else if (digitalRead(SensorFa) == 1) 
  { tone(altaveu, FAs * octava); }
  else if (digitalRead(SensorSol) == 1) 
  { tone(altaveu, SOLs * octava); }
  else if (digitalRead(SensorLa) == 1) 
  { tone(altaveu, LAs * octava); }
  else if (digitalRead(SensorSi) == 1) 
  { tone(altaveu, SI * octava); }
  else  
  { noTone(altaveu); }
}

