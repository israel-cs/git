#include<iostream>
#include<stdlib.h>
#include<locale.h>
#include<string>
#include<fstream>
using namespace std;

class cadastro {
    public: 
        string a, b, s;
    
        void limpa(){
          system("cls");  
        }
        void dados(){
            cout << "=====CADASTRAR DADOS=====" << "\n";
            getline(cin,s); //Para que não pule direto pro endereço
            cout << "Digite um nome: ";
            getline(cin,a);
            cout << "Digite um endereço: ";
            getline(cin,b);
        }          
        void imprima() {
            cout << "=====DADOS CADASTRADOS=====" << "\n";
            cout << "Nome: " << a << '\n' << "Endereço: " << b << "\n";
            cout << " " << '\n';
            system("Pause");
        }
        void grava(){
            ofstream arquivo{"banco.txt", ios::app};
                if (!arquivo){
                    cerr << "Arquivo não foi encontrado para gravar. " << "\n";
                    system("Pause");
                }
                arquivo << "Nome: " << a << "\n" << "Endereço: " << b << "\n" << "======================" << "\n";
                cout << "Arquivo gravado com êxito!" << "\n";
                arquivo.close();
                system("Pause");
        }
        void leia(){
            ifstream ler{"banco.txt"};
                if(!ler){
                    cerr << "Arquivo não foi encontrado para ler. " << "\n";
                    system("Pause");
                }
                while (ler){
                    string entrada;
                    getline(ler, entrada);
                    cout << entrada << "\n";
                }
                system("pause");
        }
};
int main() {
    setlocale(LC_ALL, "pt_BR"); //para exibir acentuações
    int x;
    cadastro cad;
    do
    {
        cad.limpa();
        cout << "Sistema de cadastros" << "\n";
        cout << "=====SELECIONE OPÇÕES=====" << "\n";
        cout << "1 - Cadastrar" << '\n' << "2 - Imprimir" << "\n" << "3 - Gravar" << "\n" 
             << "4 - Ler arquivo" << "\n" << "5 - Sair" << "\n";
        cout << "Qual opção? ";
        cin >> x;

            if (x == 1) {    
                cad.limpa();                           
                cad.dados();              
            }
            else if (x == 2) { 
                cad.limpa();              
                cad.imprima(); 
            }
            else if (x == 3) {
                cad.limpa();
                cad.grava();   
            }
            else if (x == 4){
                cad.limpa();
                cad.leia();
            }
            else if (x == 5){
                cad.limpa();
                cout << "Obrigado pelo uso! Fim do programa! " << "\n"; 
            }
            else if (x<1 || x>5) {
                cout << "Favor digitar as opções de 1 a 3" << "\n";
                system("Pause");
            }        
    } while (x!=5);   
    return 0;
}