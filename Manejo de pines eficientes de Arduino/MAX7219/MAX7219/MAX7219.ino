
#include <MD_MAX72xx.h>
//construccion de cara, luego se puede convertir a hexa decimal par que no ocupe espacio, no deja de ser un numero
const byte smile[] = {B00011000,
                      B01100110,
                      B01000010,
                      B10100101, 
                      B10000001,
                      B01011010,
                      B00100100,
                      B00011000};

//constructor
MD_MAX72XX mx = MD_MAX72XX(MD_MAX72XX::DR0CR0RR1_HW, 13, 11, 12, 1);

void setup()
{
  //*******************************************
  //configuracion
  mx.begin();
  mx.control(MD_MAX72XX::INTENSITY, 15);
  mx.control(MD_MAX72XX::UPDATE, 1);
  //*******************************************
  //demostracion de funciones
  //-------------------------------------------------------
  //muestra obucacion del punto
  mx.setPoint(3, 3, true);//fila, columna
  delay(1000);
  mx.clear();
  //-------------------------------------------------------
  //un movimiento lineal para ver como se recorre
  for (int aux = 0; aux < 8; aux++) {
    mx.setPoint(aux, 7 - aux, true);
    mx.setPoint(7 - aux, 7 - aux, true);
    delay(400);
  }
  mx.clear();
  //-------------------------------------------------------
  //como se ve el orden de los byte en la matriz
  mx.setColumn(1, B00011111);//orden de esta funcion
  mx.setRow(2, B00011111);
  delay(1000);
  mx.clear();//siempre poner clear luego de un delay
  //-------------------------------------------------------
  //Letras
  for (int aux = 65; aux < 91; aux++) {//letras mayusculas
    int ancho = mx.setChar(7, char(aux));
    delay(500);
  }
  for (int aux = 97; aux < 123; aux++) {//letras minusculas
    int ancho = mx.setChar(7, char(aux));
    delay(500);
  }
  mx.clear();
  //-------------------------------------------------------
  //se supone que debe ser una cara pero no soy dibujante
  drawRows(smile);//caracter (se genera con funcion aparte)
  //-------------------------------------------------------
  
  Serial.print("listo");//aviasamos que terminamos
}
void loop(){
}

void drawRows( const byte fig[] ){//funcion de dibujado
  for( int i = 0; i < 8; i++ ){
    mx.setRow(0, i, fig[i]);
  }
}
