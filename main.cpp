#include "user.hpp"
#include "menu.hpp"

static const std::string file_name = "info.txt";

int main(){
    User user;
    while(1){
        char option;
        display_menu();
        std::cout << "Escolha uma opcao" << std::endl;
        std::cin >> option;
        clear_screen();
        if(option == 'a'){
            user.ask_questions();
            user.save_to_file(file_name);
        } 
        else if(option == 'b') print_file(file_name);
        else if(option == 'c') search_user_by_name(searched_name(), file_name);
        else if(option == 'd') calculate_violation_totals(file_name);
        else if(option == 'e') break;
        else std::cout << "Opcao invalida" << std::endl;
    }
    return 0;
}
