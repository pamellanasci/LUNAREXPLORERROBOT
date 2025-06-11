// Biblioteca para controlar a fita de LED NeoPixel
#include <Adafruit_NeoPixel.h>

// Define os pinos conectados ao driver L298N (controle de motor)
#define IN1 16  // Entrada 1 do motor A
#define IN2 17  // Entrada 2 do motor A
#define IN3 18  // Entrada 1 do motor B
#define IN4 19  // Entrada 2 do motor B

// Define o pino e a quantidade de LEDs da fita NeoPixel
#define LED_PIN 15     // Pino conectado à fita de LED
#define LED_COUNT 18   // Número de LEDs na fita

// Cria o objeto 'strip' para controlar a fita
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Define os pinos do motor como saída
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Inicializa a fita de LED
  strip.begin();
  strip.show(); // Limpa todos os LEDs (desliga inicialmente)

  // Define todos os LEDs com a cor magenta (vermelho + azul)
  for (int i = 0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 255));  // Magenta (R=255, G=0, B=255)
  }
  strip.show(); // Atualiza os LEDs com a cor definida

  // Move o robô para frente por 2 segundos
  frente();     // Liga os motores para frente
  delay(2000);  // Espera 2 segundos
  parar();      // Para os motores
}

void loop() {
  // Não faz nada continuamente
}

// Função para andar para frente
void frente() {
  digitalWrite(IN1, HIGH); // Motor A gira em uma direção
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); // Motor B gira na mesma direção
  digitalWrite(IN4, LOW);
}

// Função para parar os motores
void parar() {
  digitalWrite(IN1, LOW);  // Motor A parado
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  // Motor B parado
  digitalWrite(IN4, LOW);
}
