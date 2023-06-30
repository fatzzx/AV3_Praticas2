#include "user.hpp"
#include "menu.hpp"

//Variavel global estatica que representa o nome do arquivo
static const std::string file_name = "info.txt";

int main(){
  User user;
  //Loop principal do programa
    while(1){
      //Variavel utulizada para executar as funcionalidades do programa 
        char option;
        //Funcao para printar o menu
        display_menu();
        std::cout << "Escolha uma   opcao" << std::endl;
        std::cin >> option;
      //Limpa a tela
        clear_screen();
        if(option == 'a'){
          //Metodo utilizado para setar os atributos do objeto user
            user.ask_questions();
          //Metodo que armazena os dados do usuario no arquivo
            user.save_to_file(file_name);
        } 
          //Funcao que simplismente printa todo conteudo do arquivo
        else if(option == 'b') print_file(file_name);
          //Funcao que printa apenas as informacoes do usuario procurado
        else if(option == 'c') search_user_by_name(searched_name(), file_name);
          //Funcao que calcula e printa as estatiticas
        else if(option == 'd') calculate_violation_totals(file_name);
          //Sai do loop
        else if(option == 'e') break;
        else std::cout << "Opcao invalida" << std::endl;
    }

    return 0;
}
