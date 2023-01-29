#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

unsigned long previousMillis = 0;
long interval;

int Step = 0;
int tryb = 0; //0 - falowy, 1 - pełnokrokowy, 2 - półkrokowy
int szybkosc = 10; //dowolna wartosc wedle uznania uzytkownika
int kierunek = 1; // 1 = zgodnie z ruchem wskazowek zegara -1 = przeciwnie do ruchu wskazowek zegara

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

void zadanie(long szybkosc, int direction) {
    long a = 64 * szybkosc; // ilość ząbków razy okrażenia na minutę - kroki na minutę
    long b = a / 60; // ilosc kroków na sekundę
    interval = 1000 / b;  // odstęp pomiędzy krokami w sekundzie

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
    }
}

void setup() {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void loop() {
    zadanie(szybkosc, kierunek);
}
