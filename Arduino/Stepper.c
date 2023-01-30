//To use it, change the file format to .ino instead of C/C++!
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
unsigned long previousMillis = 0;
long interval;

int Step = 0;
int tryb;
long szybkosc;
int kierunek;
int liczbaKrokow;
int wykonaneKroki = 0;
float liczbaObrotow;
float wykonaneObroty = 0;

const int lengthSeq = 8;
int stepsMatrix[lengthSeq][4] = {
  {0, 0, 0, 1},  // 0
  {0, 0, 1, 1},  // 1
  {0, 0, 1, 0},  // 2
  {0, 1, 1, 0},  // 3
  {0, 1, 0, 0},  // 4
  {1, 1, 0, 0},  // 5
  {1, 0, 0, 0},  // 6
  {1, 0, 0, 1},  // 7
};

void zadanie(int tryb, long szybkosc, int kierunek, int liczbaKrokow, float liczbaObrotow) {
    liczbaKrokow = liczbaObrotow*liczbaKrokow;
    long a = 64 * szybkosc; // ilość ząbków razy szybkosc na minutę - kroki na minutę
    long b = a / 60; // ilosc kroków na sekundę
    interval = 1000 / b;  // odstęp pomiędzy krokami w sekundzie

    if (wykonaneKroki >= liczbaKrokow) {
      return;
    }
    if (wykonaneObroty >= liczbaObrotow) {
      return;
    }
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        int index;
        if (tryb == 0) {
            index = Step % 4 * 2;
        } else if (tryb == 1) {
            index = (Step % 4) * 2 + 1;
        } else {
            index = Step % 8;
        }
        if(kierunek == -1) {
            index = (index + lengthSeq - 1) % lengthSeq;
        }
        digitalWrite(IN1, stepsMatrix[index][0]);
        digitalWrite(IN2, stepsMatrix[index][1]);
        digitalWrite(IN3, stepsMatrix[index][2]);
        digitalWrite(IN4, stepsMatrix[index][3]);
        Step += kierunek;
        
        if (tryb == 0){
          wykonaneKroki+=2;
        }
        else if (tryb == 1){
          wykonaneKroki+=2;
        }
        else{
          wykonaneKroki++;
        }
        if (wykonaneKroki == 4096){
          wykonaneObroty == 1;
        }
    }
}

void setup() {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void loop() {
   //tryb: 0 - falowy, 1 - pełnokrokowy, 2 - półkrokowy
   //szybkosc: dowolna wartosc wedle uznania uzytkownika
   //kierunek: 1 = zgodnie z ruchem wskazowek zegara -1 = przeciwnie do ruchu wskazowek zegara
   //liczbaKrokow: dowolna wartosc wedle uznania uzytkownika !!!Pelny obrot to 4096 krokow!!!
   //liczbaObrotow: dowolna wartosc wedle uznania uzytkownika
    zadanie(2, 300, -1, 4096, 2.5);
}
