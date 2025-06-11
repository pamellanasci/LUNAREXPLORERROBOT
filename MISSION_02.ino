#include <Adafruit_NeoPixel.h>

// Definição dos pinos da ponte H
#define IN1 16
#define IN2 17
#define IN3 18
#define IN4 19

// Fita de LED
#define LED_PIN 15
#define LED_COUNT 18
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Configura pinos dos motores como saída
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Inicializa a fita de LED
  strip.begin();
  strip.show();
  for (int i = 0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 255)); // Magenta
  }
  strip.show();

  // Movimento: anda 2 quadrados
  frente();
  delay(4000);  // Tempo para andar 2 quadrados
  parar();
  delay(1000);

  // Movimento: vira à esquerda
  esquerda();
  delay(1000);  // Tempo aproximado para giro de 90 graus
  parar();
  delay(500);

  // Movimento: anda mais 2 quadrados
  frente();
  delay(4000);
  parar();
}

void loop() {
  // Não faz nada
}

// Função: anda para frente
void frente() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Função: para os motores
void parar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Função: vira para a esquerda

