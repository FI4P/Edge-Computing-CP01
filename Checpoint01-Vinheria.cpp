// C++ code

//Declarando as variaveis
int greenLed , yellowLed , redLed, ldr , ldrValue , intensidadeLuz , buzzer; // Declara os leds presentes em nosso sistema


void setup() {
   
    // Atribui os valores para as variaveis declaradas

   	greenLed = 4; // Recebe o pino digital 4
 	yellowLed = 3; //Recebe o pino digital 3
 	redLed = 2;// Recebe o pino digital 2
    ldrValue = 0; //Valor captado pelo ldr inicialmente em 0
    ldr = A0; //Recebe a Porta analógica A0
    buzzer = 5; //Recebe o pino digital 5

    //Atribui o modo do Pino para cada pino.
    pinMode(A0, INPUT);
    pinMode(greenLed , OUTPUT);
    pinMode(yellowLed , OUTPUT);
    pinMode(redLed , OUTPUT);
    pinMode(buzzer , OUTPUT);

    //Inicialização da comunicação serial, com taxa de transferência em bits por segundo de 9600
    Serial.begin(9600);

}

void loop() {

    //Atribui o valor captado pelo ldr para a variavel ldrValue
    ldrValue = analogRead(ldr);
  	int luz = map(ldrValue, 6, 676, 0 , 100);
  	Serial.println(luz);
  
  digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, LOW);
  
  //Condição 
  if(luz <=70){
   digitalWrite(greenLed, HIGH); // Acende o led verde

   
   
  } else if (luz <= 90){
  	digitalWrite(yellowLed, HIGH); // Acende o led amarelo
     tone(buzzer, 1500,3000); // Liga o buzzer na frequencia 1500hz	
  		delay(3000);
    noTone(buzzer); //Desliga o buzzer
    delay(1000);
  }else{
  
    digitalWrite(redLed, HIGH);
    tone(buzzer, 1500, 3000); // Liga o buzzer na frequencia 1500hz
    delay(1000);
    digitalWrite(redLed, LOW);// Desliga 
    noTone(buzzer); //Desliga o buzzer

   
  }

}
