
#include <iostream>
using namespace std;

struct Aluno {
    string nome;
    int idade;
    float nota;
};

int main() {
    Aluno aluno1;
    aluno1.nome = "João";
    aluno1.idade = 20;
    aluno1.nota = 7.5;

    cout << "Nome: " << aluno1.nome << endl;
    cout << "Idade: " << aluno1.idade << endl;
    cout << "Nota: " << aluno1.nota << endl;

    return 0;
     

struct Led {
    string cor;
    int intensidade;
    bool ligado;
};

int main() {    
    Led led1;

    led1.cor = "verde";
    led1.intensidade = 50;
    led1.ligado = true;
  
    cout << "Cor do LED: " << led1.cor << endl;
    cout << "Intensidade do LED: " << led1.intensidade << "%" << endl;
    cout << "O LED está ligado? " << (led1.ligado ? "Sim" : "Não") << endl;

    return 0;
}
