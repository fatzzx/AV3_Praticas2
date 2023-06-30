#include "menu.hpp"

//Funcao tem um loop principalr que vai percorrendo e printando cada linha do arquivo
void print_file(const std::string& filename){
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;

        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }

        file.close();
    } else {
        std::cout << "Não foi possível abrir o arquivo: " << filename << std::endl;
    }
}

//Funcao recebe um string e retorna ela
std::string searched_name() {
    std::string name;
    std::cout << "Qual o nome da pessoa que deseja buscar?" << std::endl;
    std::getline(std::cin >> std::ws, name);
    return name;
}


//Funcao percorre todo o arquivo ate achar a linha onde consta o nome do participante buscado, apos achar a linha ela printa as proximas 8 linhas que constam todas as outras informacoes
void search_user_by_name(const std::string& name, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    bool found = false;

    while (std::getline(file, line)) {
        if (line.find("Nome: " + name) != std::string::npos) {
            found = true;
            std::cout << "Dados do usuário encontrado:" << std::endl;
            std::cout << line << std::endl; 
            for (int i = 0; i <= 8; ++i) {
                std::getline(file, line);
                std::cout << line << std::endl;
            }
            std::cout << "=================================" << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "Usuário não encontrado." << std::endl;
    }

    file.close();
}

//Funcao que inicializa varias variaveis e percorre todo o arquivo incrementando o valor delas com base na aparição das respostas
void calculate_violation_totals(const std::string& filename){
    std::ifstream file(filename);
    std::string line;
    int totalViolations = 0;
    int totalQ1 = 0;
    int totalQ2 = 0;
    int totalQ3 = 0;
    int totalQ4 = 0;
    int totalQ5 = 0;
    int totalQ6 = 0;
    int totalViolationsInGenderM = 0;
    int totalViolationsInGenderF = 0;
    int totalViolationsInGenderO = 0;
    int totalAgeUnder18 = 0;
    int totalAgeAbove18 = 0;
    bool male = false;
    bool female = false;
    bool other = false;
    bool under18 = false;
    bool above18 = false;

    while (std::getline(file, line)) {

        if (line.find("Gênero: masculino") != std::string::npos) {
            male = true;
            female = false;
            other = false; 
        }

        if (line.find("Gênero: feminino") != std::string::npos) {
            male = false;
            female = true;
            other = false; 
        }

        if (line.find("Gênero: outro") != std::string::npos) {
            male = false;
            female = false;
            other = true;  
        }


        if (line.find("Q1: sim") != std::string::npos) {
            totalViolations++;
            totalQ1++;
            if(male == true) totalViolationsInGenderM++;
            else if(female == true) totalViolationsInGenderF++;
            else if(other == true) totalViolationsInGenderO++;
            if(under18 == true) totalAgeUnder18++;
            else if(above18 == true) totalAgeAbove18++;
        }

        if (line.find("Q2: sim") != std::string::npos) {
            totalViolations++;
            totalQ2++;
            if(male == true) totalViolationsInGenderM++;
            else if(female == true) totalViolationsInGenderF++;
            else if(other == true) totalViolationsInGenderO++;
            if(under18 == true) totalAgeUnder18++;
            else if(above18 == true) totalAgeAbove18++;
        }

        if (line.find("Q3: sim") != std::string::npos) {
            totalViolations++;
            totalQ3++;
            if(male == true) totalViolationsInGenderM++;
            else if(female == true) totalViolationsInGenderF++;
            else if(other == true) totalViolationsInGenderO++;
            if(under18 == true) totalAgeUnder18++;
            else if(above18 == true) totalAgeAbove18++;
        }

        if (line.find("Q4: sim") != std::string::npos) {
            totalViolations++;
            totalQ4++;
            if(male == true) totalViolationsInGenderM++;
            else if(female == true) totalViolationsInGenderF++;
            else if(other == true) totalViolationsInGenderO++;
            if(under18 == true) totalAgeUnder18++;
            else if(above18 == true) totalAgeAbove18++;
        }

        if (line.find("Q5: sim") != std::string::npos) {
            totalViolations++;
            totalQ5++;
            if(male == true) totalViolationsInGenderM++;
            else if(female == true) totalViolationsInGenderF++;
            else if(other == true) totalViolationsInGenderO++;
            if(under18 == true) totalAgeUnder18++;
            else if(above18 == true) totalAgeAbove18++;
        }

        if (line.find("Q6: sim") != std::string::npos) {
            totalViolations++;
            totalQ6++;
            if(male == true) totalViolationsInGenderM++;
            else if(female == true) totalViolationsInGenderF++;
            else if(other == true) totalViolationsInGenderO++;
            if(under18 == true) totalAgeUnder18++;
            else if(above18 == true) totalAgeAbove18++;
        }

        if (line.find("Idade: ") != std::string::npos) {
            int age = std::stoi(line.substr(line.find("Idade: ") + 7));
            if (age < 18) {
                under18 = true;
                above18 = false;
            } else {
                under18 = false;
                above18 = true;
            }
        }
    }

    file.close();

    std::cout << "Total de violações dos direitos humanos: " << totalViolations << std::endl;
    std::cout << "Total de violações da Q1: " << totalQ1 << std::endl;
    std::cout << "Total de violações da Q2: " << totalQ2 << std::endl;
    std::cout << "Total de violações da Q3: " << totalQ3 << std::endl;
    std::cout << "Total de violações da Q4: " << totalQ4 << std::endl;
    std::cout << "Total de violações da Q5: " << totalQ5 << std::endl;
    std::cout << "Total de violações da Q6: " << totalQ6 << std::endl;
    std::cout << "Total de violações por gênero - Masculino: " << totalViolationsInGenderM << std::endl;
    std::cout << "Total de violações por gênero - Feminino: " << totalViolationsInGenderF << std::endl;
    std::cout << "Total de violações por gênero - Outro: " << totalViolationsInGenderO << std::endl;
    std::cout << "Total de violações para menores de 18 anos: " << totalAgeUnder18 << std::endl;
    std::cout << "Total de violações para maiores ou iguais a 18 anos: " << totalAgeAbove18 << std::endl;
}

//Printa o menu
void display_menu(){
    #ifdef _WIN32
        std::cout << "MENU PRINCIPAL" << std::endl;
        std::cout << "a. Responder a pesquisa" << std::endl;
        std::cout << "b. Listar dados dos respondentes" << std::endl;
        std::cout << "c. Listar dados individuais" << std::endl;
        std::cout << "d. Listar estatísticas" << std::endl;
        std::cout << "e. Fim" << std::endl;
    #else
        std::cout << "╔═══════════════════════════════════╗" << std::endl;
        std::cout << "║          MENU PRINCIPAL           ║" << std::endl;
        std::cout << "╠═══════════════════════════════════╣" << std::endl;
        std::cout << "║ a. Responder a pesquisa           ║" << std::endl;
        std::cout << "║ b. Listar dados dos respondentes  ║" << std::endl;
        std::cout << "║ c. Listar dados individuais       ║" << std::endl;
        std::cout << "║ d. Listar estatísticas            ║" << std::endl;
        std::cout << "║ e. Fim                            ║" << std::endl;
        std::cout << "╚═══════════════════════════════════╝" << std::endl;
    #endif
}

//Limpa a tela do terminal em todos OS
void clear_screen(){
    #ifdef _WIN32 
        system("cls");
    #else
        system("clear");
    #endif
}
