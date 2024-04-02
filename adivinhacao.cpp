#include <iostream> //Incluir biblioteca Input Output Stream
#include <cstdlib>
#include <ctime>
using namespace std; //"Abreviar" a função padrão std::

//Função principal, onde o código será executado
int main () {
    cout << "***********************" << endl; //endl = endline
    cout << "* Jogo da Adivinhação *" << endl;
    cout << "***********************" << endl;
    //C + Output = cout (<<)
    //C + Input = cin (>>)

    cout << "Você gostaria de jogar em qual dificuldade?" << endl;
    cout << "---> (F)Fácil -- (M)Médio -- (D)Difícil <---" << endl;

    char dificuldade;
    cin >> dificuldade;
    //char é usada para guardar uma letra

    int numero_de_tentativas = 0;

    switch(dificuldade){
        case 'F':
            numero_de_tentativas = 15;
            break;
        case 'M':
            numero_de_tentativas = 10;
            break;
        case 'D':
            numero_de_tentativas = 5;
        default:
            cout << "Digite uma dificuldade válida" << endl;
    }

    srand(time(NULL));

    const int NUMERO_SECRETO = rand() % 100;
    
    bool nao_acertou = true;

    double pontos = 1000.0;

    int tentativas = 0;

    for (tentativas = 1;tentativas <= numero_de_tentativas;tentativas++){
        // O ++ refere-se a adicionar mais um ( + 1 ) a variavel

        cout << "Você está na tentativa " << tentativas << endl;

        int chute;

        cout << "Qual o seu chute? " << endl;

        cin >> chute;

        cout << "O seu chte foi: " << chute << endl;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;
    
        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
                                // abs --> abreviação para absolute, valor absoluto
        pontos = pontos - pontos_perdidos;

        if(acertou){
            cout << "Você acertou o número secreto!" << endl;
            nao_acertou = false;
            break;

        } else if(maior){
            cout << "O seu chute foi maior que o número secreto!" << endl;
        } else{
            cout << "O seu chute foi menor que o número secreto!" << endl;
        }
    }

    cout << "Fim de Jogo!" << endl;

    if(nao_acertou) {
        cout << "As suas tentativas acabaram e você perdeu!" << endl;
        cout << "Tente novamente!" << endl;
    } else {
        cout << "Você ganhou em " << tentativas << " tentativas!" << endl;
        cout.precision(2); // seta quantas casas decimais
        cout << fixed; // modificador fixed, para corrigir a notação científica
        cout << "Sua pontuação foi de " << pontos << endl;
    }
}
