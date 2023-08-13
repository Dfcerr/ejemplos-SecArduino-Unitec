/*
este codigo lo que hace es enviar valores
seriales de un numero y convertirlos en valores paralelos para 
visualizarlos con los leds
*/
#define latchPin  4 // (STCP)
#define clockPin 6 //  (SHCP)
#define dataPin 5  //  (DS)
#define resetPin 3  //  (MR)

void setup() {
  pinMode(latchPin, OUTPUT); //le decimos latch dado que carga los datos
  pinMode(clockPin, OUTPUT); 
  pinMode(dataPin, OUTPUT);
  pinMode(resetPin, OUTPUT);
  digitalWrite(resetPin, HIGH);//siempre flaco hacendente para que funcione
}

void loop() {
  for (int aux = 244; aux < 1001; aux++) { //envia valores en numeros binarios hasta el 1000
    digitalWrite(latchPin, LOW);
    /*
    shiftOut(dataPin, clockPin, bitOrder, value)
    esta funcion lo que hace es enviar un valor serie que queramos en este caso aux
    bitOrder: Nos indica si queremos que los valores se envien de izquirda a derecha o alrevez, eso se indica con:
    MSBFIRST o LSBFIRST
    MS    LS
    10110111
    */
    shiftOut(dataPin, clockPin, MSBFIRST, (aux >> 8)); //con << podes desplazar los bits como queres; (0110 << 2) = 011000,
    // en este caso lo hago para tomar los ultimos valores ya que solo puedo enviar de byte en byte
    shiftOut(dataPin, clockPin, MSBFIRST, aux);
    digitalWrite(latchPin, HIGH);
    delay(10);
  }
  digitalWrite(resetPin, LOW);//resetea los valores
  delay(500);
  digitalWrite(resetPin, HIGH);
}