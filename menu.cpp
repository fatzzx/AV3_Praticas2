#include "menu.hpp"

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

std::string searched_name(){
    std::string name;
    std::cout << "Qual o nome da pessoa que deseja buscar ?" << std::endl;
    std::cin >> name;
    return name;
}

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
    int totalGenderM = 0;
    int totalGenderF = 0;
    int totalGenderO = 0; 
    int totalAgeUnder18 = 0;
    int totalAgeAbove18 = 0;

    while (std::getline(file, line)) {
        if (line.find("Q1: sim") != std::string::npos) {
            totalViolations++;
            totalQ1++;
        }
        if (line.find("Q2: sim") != std::string::npos) {
            totalViolations++;
            totalQ2++;
        }
        if (line.find("Q3: sim") != std::string::npos) {
            totalViolations++;
            totalQ3++;
        }
        if (line.find("Q4: sim") != std::string::npos) {
            totalViolations++;
            totalQ4++;
        }
        if (line.find("Q5: sim") != std::string::npos) {
            totalViolations++;
            totalQ5++;
        }
        if (line.find("Q6: sim") != std::string::npos) {
            totalViolations++;
            totalQ6++;
        }

        if (line.find("Gênero: masculino") != std::string::npos) {
            totalGenderM++;
        }
        if (line.find("Gênero: feminino") != std::string::npos) {
            totalGenderF++;
        }
        if (line.find("Gênero: outro") != std::string::npos) { // Verifica se o gênero é "outro"
            totalGenderO++;
        }

        if (line.find("Idade: ") != std::string::npos) {
            int age = std::stoi(line.substr(line.find("Idade: ") + 7));
            if (age < 18) {
                totalAgeUnder18++;
            } else {
                totalAgeAbove18++;
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
    std::cout << "Total de violações por gênero - Masculino: " << totalGenderM << std::endl;
    std::cout << "Total de violações por gênero - Feminino: " << totalGenderF << std::endl;
    std::cout << "Total de violações por gênero - Outro: " << totalGenderO << std::endl;
    std::cout << "Total de violações para menores de 18 anos: " << totalAgeUnder18 << std::endl;
    std::cout << "Total de violações para maiores ou iguais a 18 anos: " << totalAgeAbove18 << std::endl;
}

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

void clear_screen(){
    #ifdef _WIN32 
        system("cls");
    #else
        system("clear");
    #endif
}
