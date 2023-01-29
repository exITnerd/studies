//To use it, change the file format to .ino instead of C/C++!
//ZADANIE 1
/*
Napisz program, który pozwoli na mruganie diodami, które podłączone są do pinów 2, 3 
oraz 4. Mrugać ma cała kolumna diod, w kolejności 2->3->4. Każda kolumna świeci się przez 
1s, po czym gaśnie i zaczyna świecić się kolejna kolumna. Program ma działać cyklicznie. 
Zastosuj funkcję delay().
*/
void setup() {
	for (int i = 2; i < 14; i++)
	{
		pinMode(i, OUTPUT);
	}
}

void loop() {
	for (int j = 2; j < 5; j++)
	{
		digitalWrite(j, HIGH);
		delay(1000);
		digitalWrite(j, LOW);
	}
}

//ZADANIE 2
/*
Napisz program na wędrującą diodę. W pierwszym kroku świeci dioda na pierwszej 
warstwie, pierwszej kolumnie. Po 1s gaśnie, i świeci się dioda na pierwszej warstwie, 
drugiej kolumnie, itd., aż do końca pierwszej warstwy (dziewięć kolumn). Następnie przejdź 
przez wszystkie kolumny warstwy 2, i ostatecznie wszystkie kolumny warstwy 3. Zastosuj 
funkcję delay(). Program powinien działać cyklicznie.
*/
int led[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
int pin[] = {11, 12, 13};
int delayTime = 1000;

void setup() {
  for (int i = 0; i < 9; i++) {
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  for (int j = 0; j < 3; j++) {
	pinMode(pin[j], OUTPUT);
	for (int k = 0; k < 9; k++) {
     digitalWrite(led[k], HIGH);
     delay(delayTime);
     digitalWrite(led[k], LOW);
  	}
  pinMode(pin[j], INPUT);
  }
}

//ZADANIE 3
/*
Napisz program, który zaświeci wszystkie diody LED na pierwszej warstwie, a po sekundzie 
je zgasi. Następnie włączy i po sekundzie wyłączy wszystkie diody LED warstwy2, a później 
trzeciej. W programie zastosuj funkcję milis(). Program powinien działać cyklicznie.
Materiały pomocnicze: https://www.arduino.cc/en/Tutorial/BlinkWithoutDelay.
*/
unsigned long previousMilis;
unsigned long interval = 1000;

void setup(){
	for(int i = 2; i < 11; i++){
		pinMode(i, OUTPUT);
		digitalWrite(i, HIGH);
	}
	
		for(int i = 11; i < 14; i++){
		pinMode(i, OUTPUT);
		digitalWrite(i, HIGH);
	}
}

void loop(){
	for(int i = 11; i < 14; i++){
		previousMilis = millis(); //10000
		while(millis() - previousMilis <= interval) //10500 - 10000 < 1000
		{
			digitalWrite(i, LOW);
		}
		digitalWrite(i, HIGH);
	}
}

//ZADANIE 5
/*
Napisz program, który zaświeci diody LED według schematu: pierwsza dioda na pierwszej 
warstwie, dryga dioda na drugiej warstwie, trzecia dioda na trzeciej warstwie (rysunek 9).
Aby uzyskać oczekiwany efekt, należy wybierać diody bardzo szybko. Wykorzystaj funkcję
milis()
*/
int pin[] = {2, 6, 10};
int layer[] = {11, 12, 13};
unsigned long previousMilis;
unsigned long interval = 1000;

void setup() {
  for (int i = 2; i < 11; i++) {
     pinMode(i, OUTPUT);
  digitalWrite(i, LOW);
  }
  for (int i = 11; i < 14; i++) {
     pinMode(i, OUTPUT);
  digitalWrite(i, HIGH);
  }
}

void loop() {
  for(int i = 0; i < 3; i++){
  previousMilis = millis();
    while(millis() - previousMilis <= interval)
    {
      digitalWrite(pin[i], HIGH);
      digitalWrite(layer[i], LOW);  
      digitalWrite(pin[i], LOW);
      digitalWrite(layer[i], HIGH);
    }
  }
}
