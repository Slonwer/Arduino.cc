 ////////////////////////////////////////////////////////////////////////////////
//    Fun??o para ler as informa??es de temperatura e umidade no sensor DHT11   //
 ////////////////////////////////////////////////////////////////////////////////

#define dht11_dir trisB.f1             //bit de configura��o da dire��o I/O da porta de comunica��o com o sensor DHT11
#define dht11dado portB.f1             //porta de comunica��o com o sensor DHT11

//vari�veis usadas na leitura do sensor de umidade e temperatura DHT11
unsigned short int temperatura1;
unsigned short int temperatura2;
unsigned short int umidade1;
unsigned short int umidade2;
unsigned short int checksum;

void Inicia_ambiente(){
	ANSELB.f1 = 0;                      //configura o pino de comunica��o com o m�dulo DHT11 como digital
	dht11_dir = 0;                      //define porta como sa�da
	dht11dado = 1;                      //envia 1 na porta de sa�da
}

void dht11_read(){
   int count;
   INTCON.GIE = 0;                     //desliga chave geral das interrup��es
   temperatura1=0;                     //zera vari�veis antes da comunica��o
   temperatura2=0;                     //zera vari�veis antes da comunica��o
   umidade1=0;                         //zera vari�veis antes da comunica��o
   umidade2=0;                         //zera vari�veis antes da comunica��o
   checksum=0;                         //zera vari�veis antes da comunica��o
//inicia comunica��o requisitando o envio dos dados
   dht11_dir = 0;                      //define como sa�da
   dht11dado = 0;                      //envia 0
   delay_ms(20);                       //por 20 milisegundos
   dht11dado = 1;                      //envia 1
   delay_us(42);                       //por 42 microsegundos
   dht11_dir = 1;                      //define como entrada
   while(dht11dado);                   //aguarda inicio do recebimento dos dados
//recebe resposta
   while(!dht11dado);                  //recebe 0 (zero)
   while(dht11dado);                   //recebe 1 (um)
//inicia recep��o dos dados
   while(!dht11dado);                  //recebe 0 (zero)
   for(count=1; count<=8; count++){    //recebe a 1� parte do valor da umidade
      delay_us(40);
	  if(dht11dado){umidade1++ ; while(dht11dado);}
	  umidade1<<=1;
	  while(!dht11dado);
   }
   for(count=1; count<=8; count++){    //recebe a 2� parte do valor da umidade
      delay_us(40);
	  if(dht11dado){umidade2++ ; while(dht11dado);}
	  umidade2<<=1;
	  while(!dht11dado);
   }
   for(count=1; count<=8; count++){    //recebe a 1� parte do valor da temperatura
      delay_us(40);
	  if(dht11dado){temperatura1++ ; while(dht11dado);}
	  temperatura1<<=1;
	  while(!dht11dado);
   }
   for(count=1; count<=8; count++){    //recebe a 2� parte do valor da temperatura
      delay_us(40);
	  if(dht11dado){temperatura2++ ; while(dht11dado);}
	  temperatura2<<=1;
	  while(!dht11dado);
   }
   for(count=1; count<=8; count++){    //recebe o checksum para confirmar se a mensagens foi recebida corretamente
      delay_us(40);
	  if(dht11dado){checksum++ ; while(dht11dado);}
	  checksum<<=1;
	  while(!dht11dado);
   }
   umidade1>>=1;
   temperatura1>>=1;
   checksum>>=1;
   if(checksum==temperatura1+temperatura2+umidade1+umidade2){ //se o checksum estiver correto

   }
   INTCON.GIE = 1;                     //religa chave geral das interrup��es
}
 ////////////////////////////////////////////////////////////////////////////////
//    Fun??o para ler as informa??es de temperatura e umidade no sensor DHT11   //
 ////////////////////////////////////////////////////////////////////////////////

#define dht11_dir trisB.f1             //bit de configura��o da dire��o I/O da porta de comunica��o com o sensor DHT11
#define dht11dado portB.f1             //porta de comunica��o com o sensor DHT11

//vari�veis usadas na leitura do sensor de umidade e temperatura DHT11
unsigned short int temperatura1;
unsigned short int temperatura2;
unsigned short int umidade1;
unsigned short int umidade2;
unsigned short int checksum;

void Inicia_ambiente(){
	ANSELB.f1 = 0;                      //configura o pino de comunica��o com o m�dulo DHT11 como digital
	dht11_dir = 0;                      //define porta como sa�da
	dht11dado = 1;                      //envia 1 na porta de sa�da
}

void dht11_read(){
   int count;
   INTCON.GIE = 0;                     //desliga chave geral das interrup��es
   temperatura1=0;                     //zera vari�veis antes da comunica��o
   temperatura2=0;                     //zera vari�veis antes da comunica��o
   umidade1=0;                         //zera vari�veis antes da comunica��o
   umidade2=0;                         //zera vari�veis antes da comunica��o
   checksum=0;                         //zera vari�veis antes da comunica��o
//inicia comunica��o requisitando o envio dos dados
   dht11_dir = 0;                      //define como sa�da
   dht11dado = 0;                      //envia 0
   delay_ms(20);                       //por 20 milisegundos
   dht11dado = 1;                      //envia 1
   delay_us(42);                       //por 42 microsegundos
   dht11_dir = 1;                      //define como entrada
   while(dht11dado);                   //aguarda inicio do recebimento dos dados
//recebe resposta
   while(!dht11dado);                  //recebe 0 (zero)
   while(dht11dado);                   //recebe 1 (um)
//inicia recep��o dos dados
   while(!dht11dado);                  //recebe 0 (zero)
   for(count=1; count<=8; count++){    //recebe a 1� parte do valor da umidade
      delay_us(40);
	  if(dht11dado){umidade1++ ; while(dht11dado);}
	  umidade1<<=1;
	  while(!dht11dado);
   }
   for(count=1; count<=8; count++){    //recebe a 2� parte do valor da umidade
      delay_us(40);
	  if(dht11dado){umidade2++ ; while(dht11dado);}
	  umidade2<<=1;
	  while(!dht11dado);
   }
   for(count=1; count<=8; count++){    //recebe a 1� parte do valor da temperatura
      delay_us(40);
	  if(dht11dado){temperatura1++ ; while(dht11dado);}
	  temperatura1<<=1;
	  while(!dht11dado);
   }
   for(count=1; count<=8; count++){    //recebe a 2� parte do valor da temperatura
      delay_us(40);
	  if(dht11dado){temperatura2++ ; while(dht11dado);}
	  temperatura2<<=1;
	  while(!dht11dado);
   }
   for(count=1; count<=8; count++){    //recebe o checksum para confirmar se a mensagens foi recebida corretamente
      delay_us(40);
	  if(dht11dado){checksum++ ; while(dht11dado);}
	  checksum<<=1;
	  while(!dht11dado);
   }
   umidade1>>=1;
   temperatura1>>=1;
   checksum>>=1;
   if(checksum==temperatura1+temperatura2+umidade1+umidade2){ //se o checksum estiver correto

   }
   INTCON.GIE = 1;                     //religa chave geral das interrup��es
}
