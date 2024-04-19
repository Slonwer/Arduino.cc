# Linguagem de Programação Arduino

A linguagem de programação Arduino é uma variante da linguagem C/C++, especialmente projetada para a plataforma de prototipagem de dispositivos eletrônicos Arduino. Sua simplicidade e eficácia a tornam uma ferramenta ideal para controlar microcontroladores e interagir com o mundo físico.

## Variáveis no Arduino

Existem diferentes tipos de variáveis suportadas pelo Arduino, incluindo:

- `int` (inteiro): armazena números inteiros entre -32.768 e 32.767.
- `unsigned int` (inteiro sem sinal): armazena números inteiros entre 0 e 65.535.
- `long` (longo): armazena números inteiros entre -2.147.483.648 e 2.147.483.647.
- `unsigned long` (longo sem sinal): armazena números inteiros entre 0 e 4.294.967.295.
- `float` (flutuante): armazena números de ponto flutuante com precisão de 6 a 7 dígitos.
- `double` (duplo): armazena números de ponto flutuante com precisão de 15 dígitos.
- `char` (caractere): armazena um único caractere.
- `boolean` (booleano): armazena valores verdadeiros ou falsos.

Para declarar variáveis e atribuir valores a elas, utilize o seguinte formato:

```c
tipo_variavel nome_variavel = valor_inicial;
## Variáveis no Arduino

Existem diferentes tipos de variáveis suportadas pelo Arduino, incluindo:

- `int` (inteiro): armazena números inteiros entre -32.768 e 32.767.
- `unsigned int` (inteiro sem sinal): armazena números inteiros entre 0 e 65.535.
- `long` (longo): armazena números inteiros entre -2.147.483.648 e 2.147.483.647.
- `unsigned long` (longo sem sinal): armazena números inteiros entre 0 e 4.294.967.295.
- `float` (flutuante): armazena números de ponto flutuante com precisão de 6 a 7 dígitos.
- `double` (duplo): armazena números de ponto flutuante com precisão de 15 dígitos.
- `char` (caractere): armazena um único caractere.
- `boolean` (booleano): armazena valores verdadeiros ou falsos.

Para declarar variáveis e atribuir valores a elas, utilize o seguinte formato:

```c
int ledPin = 13;
float temperatura = 25.3;
char letra = 'A';
boolean ligado = false;
