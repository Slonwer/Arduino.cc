#include <FastLED.h> // Inclui a biblioteca FastLED para controle de LEDs
#define NUM_LEDS 174 // Define o número total de LEDs conectados
#define DATA_PIN 5 // Define o pino de dados para a tira de LEDs

int redVal = 255; // Valor inicial da componente vermelha do LED
int greenVal = 255; // Valor inicial da componente verde do LED
int blueVal = 255; // Valor inicial da componente azul do LED
bool setColors = false; // Flag para indicar se novas cores estão sendo definidas
bool receiveNotes = false; // Flag para indicar se notas estão sendo recebidas
int colorSetCounter = 0; // Contador para controlar a definição das cores

CRGB leds[NUM_LEDS]; // Define um array de LEDs com o número especificado

void setup() 
{
    Serial.begin(9600); // Inicializa a comunicação serial com a taxa de 9600 bps
    Serial.setTimeout(10); // Define o tempo limite de espera para leitura serial
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); // Adiciona os LEDs ao controlador FastLED
}

void loop() 
{
    // Comunicação serial    
    while(Serial.available() > 0 )
    {
        int inByte = Serial.read(); // Lê o byte recebido pela porta serial       
        if (inByte > 0) 
        {
            // Se o byte for 255, os próximos 3 bytes serão os novos valores RGB
            if (inByte == 255) 
            {
                setColors = true;
                colorSetCounter = 0;
            } 
            else if (setColors) 
            {
                switch (colorSetCounter) 
                {
                    case 0:
                        redVal = inByte;
                        break;
                    case 1:
                        greenVal = inByte;
                        break;
                    case 2:
                        blueVal = inByte;
                        setColors = false;
                        receiveNotes = true;
                        // Define todas as LEDs como preto para limpar a exibição
                        fill_solid(leds, NUM_LEDS, CRGB::Black);
                        FastLED.show();
                        break;
                }
                colorSetCounter++;
            } 
            else if (receiveNotes) 
            {               
                controlLeds(inByte);
            }
        }
    }
}

// Função para controlar as LEDs com base na nota recebida
void controlLeds (int note) 
{
    note -= 1; // Ajusta a nota para começar em 0
    if (!leds[note]) 
    {
        // Se a LED estiver apagada, define uma cor aleatória para ela
        redVal = random(10,250);
        greenVal = random(10,250);
        blueVal = random(10,250);
        
        leds[note].red = redVal;
        leds[note].green = greenVal;
        leds[note].blue = blueVal;     
    } 
    else 
    {
        // Se a LED estiver acesa, apaga ela
        leds[note] = CRGB::Black;
    }
    FastLED.show(); // Atualiza a exibição dos LEDs
}
