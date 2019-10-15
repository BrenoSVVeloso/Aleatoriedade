/*
 * Autor: Bruno Simoes - brunossfer@gmail.com
 * usando a plataforma carro 2 motores e base acrilica
 * link que mostra as ligações ---  https://www.tinkercad.com/things/7BfcupKZCOg 
*/

#include <HCSR04.h> // bib - listada no gerenciador como hcsr04 - martin sosic

int echo = 12;
int trig = 13;
 
//Definicoes pinos Arduino ligados a entrada da Ponte H
int velocidadeE = 2;
int velocidadeD = 3;
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

UltraSonicDistanceSensor medidor(trig,echo);
  
void setup(){
  //Define os pinos como saida
 pinMode(velocidadeE, OUTPUT);
 pinMode(velocidadeD, OUTPUT);
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 Serial.begin(9600);
}
  
void loop(){
int vel = 30;
double cm = medidor.measureDistanceCm();
Serial.print("Distancia: ");
Serial.println(cm);
if(cm > 15){
  frente(vel);
  parar();
  } 
else{
  esquerda(vel);
  parar();
  }
}

void esquerda(int vel){
  // velocidade
 digitalWrite(velocidadeE, vel);
 digitalWrite(velocidadeD, vel);
 //Gira o Motor A no sentido horario
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
 delay(15);
 //Para o motor A
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, HIGH);
 delay(5);
  }

void direita(int vel){
 // velocidade
 digitalWrite(velocidadeE, vel);
 digitalWrite(velocidadeD, vel);
 //Gira o Motor A no sentido horario
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
 delay(15);
 //Para o motor A
 digitalWrite(IN1, HIGH);
 digitalWrite(IN4, HIGH);
 delay(5);
  }
  
void parar(){
 digitalWrite(velocidadeE, 120);
 digitalWrite(velocidadeD, 120);
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, HIGH);
 
 delay(5);
}
  
void frente(int vel){
  // velocidade
 digitalWrite(velocidadeE, vel);
 digitalWrite(velocidadeD, vel);
 //Gira o Motor A no sentido horario
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 //Gira o Motor B no sentido horario
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
  delay(200);
 
 //Parar os motores
 digitalWrite(IN2, HIGH);
 digitalWrite(IN4, HIGH);
 delay(5);
  }
