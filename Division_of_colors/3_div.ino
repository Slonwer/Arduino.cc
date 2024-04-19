#include <FastLED.h> // Inclui a biblioteca FastLED para controle de LEDs
#define NUM_LEDS 174 // Define o número total de LEDs
#define DATA_PIN 5 // Define o pino de dados para a tira de LEDs

int redVal = 255; // Valor inicial para a componente vermelha do LED
int greenVal = 255; // Valor inicial para a componente verde do LED
int blueVal = 255; // Valor inicial para a componente azul do LED
bool setColors = false; // Flag para indicar se novas cores estão sendo definidas
bool receiveNotes = false; // Flag para indicar se notas estão sendo recebidas
int colorSetCounter = 0; // Contador para controlar a definição das cores

CRGB leds[NUM_LEDS]; // Array de LEDs

void setup() {
    Serial.begin(9600); // Inicia a comunicação serial
    Serial.setTimeout(10); // Define o tempo limite de espera para leitura serial
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); // Adiciona os LEDs ao controlador FastLED
}

void loop() {
    while(Serial.available() > 0) { // Loop enquanto houver dados disponíveis na porta serial
        int inByte = Serial.read(); // Lê o byte recebido
        if (inByte > 0) { // Verifica se o byte é válido
            if (inByte == 255) { // Se o byte for 255, os próximos 3 bytes serão novas cores RGB
                setColors = true; // Ativa a flag para definir novas cores
                colorSetCounter = 0; // Reseta o contador de definição de cores
            } else if (setColors) { // Se as cores estão sendo definidas
                switch (colorSetCounter) { // Verifica o contador de definição de cores
                    case 0:
                        redVal = inByte; // Define o valor vermelho
                        break;
                    case 1:
                        greenVal = inByte; // Define o valor verde
                        break;
                    case 2:
                        blueVal = inByte; // Define o valor azul
                        setColors = false; // Desativa a flag de definição de cores
                        receiveNotes = true; // Ativa a flag para receber notas
                        fill_solid(leds, NUM_LEDS, CRGB::Black); // Limpa todas as LEDs
                        FastLED.show(); // Mostra as LEDs
                        break;
                }
                colorSetCounter++; // Incrementa o contador de definição de cores
            } else if (receiveNotes) { // Se as notas estão sendo recebidas
                controlLeds(inByte); // Chama a função para controlar as LEDs com base na nota recebida
            }
        }
    }
}

void controlLeds (int note) {
    note -= 1; // Ajusta a nota para começar de 0
    if (!leds[note]) { // Se a LED estiver apagada
        // Define as cores das LEDs com base na nota recebida
        leds[note].red = redVal;
        leds[note].green = greenVal;
        leds[note].blue = blueVal;
        // Define cores específicas para diferentes intervalos de notas
        if (note >= 0 && note < 72) {
            leds[note].red = 250;
            leds[note].green = 20;
            leds[note].blue = 20;
        } else if (note > 71 && note < 116) {
            leds[note].red = 255;
            leds[note].green = 255;
            leds[note].blue = 20;
        } else if (note > 115 && note < 174) {
            leds[note].red = 0;
            leds[note].green = 215;
            leds[note].blue = 20;
        }
    } else { // Se a LED estiver acesa
        leds[note] = CRGB::Black; // Apaga a LED
    }
    FastLED.show(); // Mostra as alterações nas LEDs
}
