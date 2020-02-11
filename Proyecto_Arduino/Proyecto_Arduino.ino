#include "game.h"
#include "car.h"
#include "obstacle_node.h"
#include "LedControl.h"
int opcion_actual = 0;
int oscilation_speed = 300;
int left = 22; //Pin para mover a la izquierda
int right = 23; //Pin para mover a la derecha
int direction_pin = 30; //pin para controlar la direccion del letrero
LedControl lc = LedControl(19, 21, 20, 1); //Objeto de libreria del modulo recibe (DIN, CLK, CS, NO. DISPOSITIVOS)
//Pines para la matriz que no tiene módulo, filas
int f0 = 16;
int f1 = 17;
int f2 = 2;
int f3 = 3;
int f4 = 4;
int f5 = 5;
int f6 = 6;
int f7 = 7;

//Pines para la matriz que no tienen módulo, columnas
int c0 = 8;
int c1 = 9;
int c2 = 10;
int c3 = 11;
int c4 = 12;
int c5 = 13;
int c6 = 14;
int c7 = 15;

//array de filas
int rows[] = { f0, f1, f2, f3, f4, f5, f6, f7 };

//array de columnas
int columns[] = { c0, c1, c2, c3, c4, c5, c6, c7 };
////////////////////////////////////////////LETRERO///////////////////////////////////
#define LARGO 197

int direccion = 0;
int index = 0;
int letrero[LARGO][8] = {
  {0,0,1,1,1,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,1,0,1,1,1,0},
  {0,0,1,0,0,0,1,0},
  {0,0,1,0,0,0,1,0},
  {0,0,1,1,1,0,1,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,1,1,1,1,0},
  {0,0,1,0,0,0,1,0},
  {0,0,1,0,0,0,1,0},
  {0,0,1,1,1,1,1,0},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,1,1,1,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,0,1,1,1,0,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,1,1,1,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,1,1,1,1,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,1,1,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,1,1,1,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,1,0,0,0,0,1,0},
  {0,1,0,0,0,0,1,0},
  {0,1,0,0,0,0,1,0},
  {0,1,0,0,0,0,1,0},
  {0,1,0,0,0,0,1,0},
  {0,1,0,0,0,0,1,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,1,0},
  {0,1,0,0,0,0,1,0},
  {0,1,1,0,0,0,1,0},
  {0,1,0,1,0,0,1,0},
  {0,1,0,0,1,0,1,0},
  {0,1,0,0,0,1,1,0},
  {0,1,0,0,0,0,1,0},
  {0,1,0,0,0,0,1,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,1,1,0,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,1,1,1,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,1,1,0,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,1,1,1,1,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,1,1,0,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,1,1,1,1,0,0},
  {0,1,0,1,0,0,0,0},
  {0,1,0,0,1,0,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,0,1,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,1,1,0,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,1,1,1,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,1,1,0,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,1,1,1,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,1,1,0,0},
  {0,0,0,1,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,1,1,1,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};
int availableMemory() {
    int size = 2048; //Maximo de memoria teorico. Si devuelve 2048 significa que teoricamente tenemos toda la memoria disponible.
    byte *buf;
    while ((buf = (byte *) malloc(--size)) == NULL);
        free(buf);
    return size;
}
int** get_part() {
  if(index + 16 >= LARGO) index = 0;
  if (index < 0) {
    index = LARGO - 16 - 1;
  }
  int **res = new int*[16];
  int k = 0;
  for (short i = index; i < index + 16; i++)
  {
    res[k] = new int[8];
    for (short j = 0; j < 8; j++)
    {
      res[k][j] = letrero[i][j];
    }
    k++;
  }
  return res;
}

void clean_matrix_graph(){
  for(short i=0; i<8; i++){
    digitalWrite(rows[i],HIGH);
    digitalWrite(columns[i],LOW);
  }
}
void graph_row(int* row){
  for(short i = 0; i<8; i++){
    if(row[i]!=0)digitalWrite(columns[i],HIGH);
  }
}
void graph(int** matrix) {
  for(short i = 0; i<8; i++){
    byte binary = 0;
    for(short j=0; j<8; j++){
      binary += (matrix[i+8][7-j] * pow_int(2, j)); 
    }
    lc.setRow(0, i, byte(binary));
  }
  for(int r = 0; r<oscilation_speed; r++){
    for(short i=0; i<8; i++){
      clean_matrix_graph();
      digitalWrite(rows[i],LOW);
      graph_row(matrix[i]);
    } 
  }
}

void read_oscilation_speed(){
  oscilation_speed = analogRead(A2);      
  oscilation_speed = oscilation_speed*10/12 + 20;      
}
void change_direction(){
  direccion = digitalRead(direction_pin);
}
////////////////////////////////////////////END LETRERO////////////////////////////////////////////////////////////////////

Game g; //Objeto de game
Car car; //Carrito


int led[16][8] = {0};
int count = 0;
unsigned long matrix2Time;
unsigned long baseTime = 5020;
unsigned long timeNow = 0;

unsigned long miliseconds = 0;
const long intervalo = 1000;

volatile unsigned long velocity = 1500;
int period = 20000;

byte number0[8] = {   //Numero 0
  B00000000,
  B00111100,
  B01100110,
  B01101110,
  B01110110,
  B01100110,
  B01100110,
  B00111100  
}

byte number1[8] = {             //Numero 1
  B00000000,
  B00011000,
  B00011000,
  B00111000,
  B00011000,
  B00011000,
  B00011000,
  B01111110
};
 
byte number2[8] = {     //Numero 2
  B00000000,
  B00111100,
  B01100110,
  B00000110,
  B00001100,
  B00110000,
  B01100000,
  B01111110
};

byte number3[8] = {    //Numero 3
  B00000000,
  B00111100,
  B01100110,
  B00000110,
  B00011100,
  B00000110,
  B01100110,
  B00111100
};
unsigned long tiempoS(){
  unsigned long segActual = millis();
  unsigned long segundos = (segActual - miliseconds)/1000;
  return segundos;
}


void probar(){
  for(int i=0; i<8; i++){
    digitalWrite(rows[i], LOW);
    for(int y=0; y<8; y++){
      digitalWrite(columns[y], HIGH);
      delay(250);
      digitalWrite(columns[y], LOW);
    }
    digitalWrite(rows[i],HIGH);
  }
}

void printLed(){
    for(int x=0; x<16; x++){
        Serial.println("---------------------------------------------------------------------------------------------------------------------------------");
        for(int y=0; y<8; y++){
            Serial.print("|\t" + String((led[x][y] != 0) ? "1" : " ") + "\t");
        }
        Serial.println("|");
        if(x == 15){
            Serial.println("---------------------------------------------------------------------------------------------------------------------------------");
        }
    }
}

void downwardMovement(){
  if((millis() - timeNow) > velocity){
    if(!g.obstacleList.isEmpty()){
      Obstacle_node *tmp = g.obstacleList.first;
      while(tmp != nullptr){
        tmp->a[0].y++;
        tmp = tmp->next;
      }
    }
    timeNow = millis();
  }
}

void showObstacles(){
  for(int x=0; x<16; x++){
    byte binary = 0;
    for(int y=7; y>=0; y--){
      binary += (led[x][y] * pow_int(2, abs(y-7)));
    }
    if(x<8){
      Serial.println("Printear en fila: " + String(x) + " con bite: " + String(binary));
      printOnMatrix(x, byte(binary));
    }
  }
}

void cleanMatrix(){
  for(int x=0; x<16; x++){
    for(int y=0; y<8; y++){
      led[x][y] = 0;
    }
  }
}

//Inicializar la matriz y los pines del arduino como salidas
void initializeMatrix(){
  for(int i=0; i<8; i++){
    pinMode(rows[i], OUTPUT);
    pinMode(columns[i], OUTPUT);
  }
  for(int i=0; i<8; i++){
    digitalWrite(rows[i], HIGH);
    digitalWrite(columns[i], LOW); 
  }
}

void saveMatrix(){
  if(!g.obstacleList.isEmpty()){
    Obstacle_node *tmp = g.obstacleList.first;
    while(tmp != nullptr){
      led[tmp->a[0].y][tmp->a[0].x] = 1;
      tmp = tmp->next;
    }
  }
  led[car.p1.x][car.p1.y] = 1;
  led[car.p2.x][car.p2.y] = 1;
  led[car.p3.x][car.p3.y] = 1;
  led[car.p4.x][car.p4.y] = 1;
  led[car.p5.x][car.p5.y] = 1;
}

void printOnMatrix(int row, byte value){
  Serial.println("row: " + String(row));
  matrix2Time = micros();
  while((micros() - matrix2Time) < baseTime){
    digitalWrite(rows[row], HIGH);
  }
  for(int i=0; i<8; i++){
    if(bitRead(value, i)){
      matrix2Time = micros();
      while((micros() - matrix2Time) < baseTime){
        digitalWrite(columns[7-i], LOW);
      }
    }
  }
  for(int i=0; i<8; i++){
    if(bitRead(value, i)){
      matrix2Time = micros();
      while((micros() - matrix2Time) < baseTime){
        digitalWrite(columns[7-i], HIGH);
      }
    }
  }
  matrix2Time = micros();
  while((micros() - matrix2Time) < baseTime){
    digitalWrite(row, LOW);
  }
}

void barrido(){ //Mostrar en matriz de leds de pines 
  int tmpMatrix[8][8] = {0}; /* Mete a una matriz 8x8  los 1 de la matrzi 16*8 */
  for(int x=0; x<8; x++){
    for(int y=0; y<8; y++){
      if(led[x][y]){
        tmpMatrix[x][y] = 1;
      }
    }
  }
    for(int de=0; de<=50; de++){ //Barrido para mostrar la matriz
      for(int x=0; x<8; x++){
        byte binary = 0;
        for(int y=0; y<8; y++){
          if(tmpMatrix[y][x]){
            digitalWrite(columns[x], HIGH);
            digitalWrite(rows[y], LOW);
            delay(1);
            digitalWrite(columns[x], LOW);
            digitalWrite(rows[y], HIGH);
          }
          binary += (led[x+8][7-y] * pow_int(2, y)); //Obtiene el numero decimal equivalente a un binario para encender un fila de leds en la matriz con modulo   ej: 1 = 00000001
        }
        lc.setRow(0, x, byte(binary));
      }
     }
}

//Funcion que ejecuta la operacion b^e
int pow_int(int b,int e){
  if(e==0)return 1;
  int r=b;  
  for(int i=0;i<e-1;i++){   
    r=r*b;
  }
  return r;    
}

void countdown(){
  showNumber3();
  delay(1000);
  showNumber2();
  delay(1000);
  showNumber1();
  delay(1000);
}

void showNumber1(){
  for(int i=0; i<8; i++){
    lc.setRow(0, i, number1[i]);
  }
}

void showNumber2(){
  for(int i=0; i<8; i++){
    lc.setRow(0, i, number2[i]);
  }
}

void showNumber3(){
  for(int i=0; i<8; i++){
    lc.setRow(0, i, number3[i]);
  }
}

void setup() {
  
  initializeMatrix(); //Inicializa la matriz de leds
  lc.shutdown(0, false); //Inicializados la matrix con max
  lc.setIntensity(0, 5); //Intensidad de los led con el max
  lc.clearDisplay(0); //Apagar los leds
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  pinMode(30, INPUT);  
  Serial.begin(9600); //Inicializa el puerto del serial para los print
  randomSeed(analogRead(A0)); //Semilla para generar numeros random, como se le pasa un pin que tiene solo ruido genera un random puro
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(opcion_actual){
      case 0:{
          int **part;
          part = get_part();
          if (direccion == 0)index++;
          else index--;
          graph(part);
          for (int i = 0; i < 16; ++i)
            delete [] part[i];
          delete [] part;
          read_oscilation_speed();
          change_direction();
        }break;
      case 1:{
        countdown();
        opcion_actual = 2;
        miliseconds = millis();
      }break;
      case 2:{
        if(digitalRead(left)){
          car.p1.y--;
          car.p2.y--;
          car.p3.y--;
          car.p4.y--;
          car.p5.y--;
        }else if(digitalRead(right)){
          car.p1.y++;
          car.p2.y++;
          car.p3.y++;
          car.p4.y++;
          car.p5.y++;
        }
        checkOut();
        //CHEQUEO DE COLISION
        if(g.obstacleList.checkCollision(car)){
          //SE ACABO EL JUEGO
          //MOSTRAR TIEMPO
        }
        downwardMovement();
        if(g.obstacleList.checkCollision(car)){
          //SE ACABO EL JUEGO
          //MOSTRAR TIEMPO
        }
        g.obstacleList.checkObstacles();
        unsigned long timeObs = millis();
        if(millis() < timeObs + period && count % 3 == 0){
          int generate = random(0, 11);
          if(generate > 10){
            generate = 10;
          }
          if(generate == 2 || generate == 5){
            g.generateObstacle();
            Serial.println("nUMERO DE OBSTACULOS: " + String(g.obstacleList.totalObstacles()));
          } 
        }
        saveMatrix();
        barrido();
        cleanMatrix();
        count++;
    }break;  
  }
}

//Comprueba si el carro salio de la matriz en izquierda o derecha
void checkOut(){ 
  if(car.p1.y < 0 || car.p2.y < 0 || car.p3.y < 0 || car.p4.y < 0 || car.p5.y < 0){
    car.p1.y = 0;
    car.p2.y = 2;
    car.p3.y = 1;
    car.p4.y = 0;
    car.p5.y = 2;
  }else if(car.p1.y > 7 || car.p2.y > 7 || car.p3.y > 7 || car.p4.y > 7 || car.p5.y > 7){
    car.p1.y = 5;
    car.p2.y = 7;
    car.p3.y = 6;
    car.p4.y = 5;
    car.p5.y = 7;
  }
}
