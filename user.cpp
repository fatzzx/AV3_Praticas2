#include "user.hpp"


std::string User::get_age() {
    return m_age;
}

std::string User::get_name() {
    return m_name;
}

std::string User::get_gender() {
    return m_gender;
}

void User::set_age(int age) {
    m_age = age;
}

void User::set_name(std::string name) {
    m_name = name;
}

void User::set_gender(char gender) {
    m_gender = gender;
}

void User::ask_age() {
    std::string age;
    std::cout << "Qual a sua idade?" << std::endl;
    std::cin >> age;
    m_age = age;
}

void User::ask_name() {
    std::string name;
    std::cout << "Qual o seu nome?" << std::endl;
    std::cin >> name;
    m_name = name;
}

void User::ask_gender() {
    std::string gender;
    std::cout << "Qual o seu gênero? Digite 'masculino', 'feminino' ou 'outro'" << std::endl;

    while(1) {
        std::cin >> gender;
        if(gender == "masculino" || gender == "feminino" || gender == "outro") break;
        else std::cout << "Opção inválida! Por favor, digite 'masculino', 'feminino' ou 'outro'" << std::endl;
    }
    m_gender = gender;
}


void User::ask_q1() {
    std::string q1_answer;
    std::cout << "Você já sofreu alguma violação ao seu Direito à vida?" << std::endl;
    std::cout << "Digite 'sim' ou 'nao': ";

    while (1) {
        std::cin >> q1_answer;
        if (q1_answer == "sim" || q1_answer == "nao") {
            break;
        } else {
            std::cout << "Resposta inválida. Digite 'sim' ou 'nao': ";
        }
    }

    m_q1 = q1_answer;
}

void User::ask_q2() {
    std::string q2_answer;
    std::cout << "Você já sofreu algum ato de violência na vida?" << std::endl;
    std::cout << "Digite 'sim' ou 'nao': ";

    while (1) {
        std::cin >> q2_answer;
        if (q2_answer == "sim" || q2_answer == "nao") {
            break;
        } else {
            std::cout << "Resposta inválida. Digite 'sim' ou 'nao': ";
        }
    }

    m_q2 = q2_answer;
}

void User::ask_q3() {
    std::string q3_answer;
    std::cout << "Você já passou por alguma situação de escravidão?" << std::endl;
    std::cout << "Digite 'sim' ou 'nao': ";

    while (1) {
        std::cin >> q3_answer;
        if (q3_answer == "sim" || q3_answer == "nao") {
            break;
        } else {
            std::cout << "Resposta inválida. Digite 'sim' ou 'nao': ";
        }
    }

    m_q3 = q3_answer;
}

void User::ask_q4() {
    std::string q4_answer;
    std::cout << "Você já sofreu algum ato de torturas e maus tratos na vida?" << std::endl;
    std::cout << "Digite 'sim' ou 'nao': ";

    while (1) {
        std::cin >> q4_answer;
        if (q4_answer == "sim" || q4_answer == "nao") {
            break;
        } else {
            std::cout << "Resposta inválida. Digite 'sim' ou 'nao': ";
        }
    }

    m_q4 = q4_answer;
}

void User::ask_q5() {
    std::string q5_answer;
    std::cout << "Você já passou por julgamentos injustos e privação de liberdade arbitrária?" << std::endl;
    std::cout << "Digite 'sim' ou 'nao': ";

    while (1) {
        std::cin >> q5_answer;
        if (q5_answer == "sim" || q5_answer == "nao") {
            break;
        } else {
            std::cout << "Resposta inválida. Digite 'sim' ou 'nao': ";
        }
    }

    m_q5 = q5_answer;
}

void User::ask_q6() {
    std::string q6_answer;
    std::cout << "Você já passou por alguma situação de repressão?" << std::endl;
    std::cout << "Digite 'sim' ou 'nao': ";

    while (1) {
        std::cin >> q6_answer;
        if (q6_answer == "sim" || q6_answer == "nao") {
            break;
        } else {
            std::cout << "Resposta inválida. Digite 'sim' ou 'nao': ";
        }
    }

    m_q6 = q6_answer;
}


std::string User::get_q1(){
    return m_q1;
}

std::string User::get_q2(){
    return m_q2;
}

std::string User::get_q3(){
    return m_q3;
}

std::string User::get_q4(){
    return m_q4;
}

std::string User::get_q5(){
    return m_q5;
}

std::string User::get_q6(){
    return m_q6;
}

void User::ask_questions() {
    ask_name();
    ask_age();
    ask_gender();
    ask_q1();
    ask_q2();
    ask_q3();
    ask_q4();
    ask_q5();
    ask_q6();
}


void User::save_to_file(const std::string& filename) {
    
    std::ofstream file(filename, std::ios::app);
    
    if (file.is_open()) {
        file << "Nome: " << m_name << std::endl;
        file << "Idade: " << m_age << std::endl;
        file << "Gênero: " << m_gender << std::endl;
        file << "Respostas:" << std::endl;
        file << "Q1: " << m_q1 << std::endl;
        file << "Q2: " << m_q2 << std::endl;
        file << "Q3: " << m_q3 << std::endl;
        file << "Q4: " << m_q4 << std::endl;
        file << "Q5: " << m_q5 << std::endl;
        file << "Q6: " << m_q6 << std::endl;
        file << "=================================" << std::endl;
        
        file.close();
        std::cout << "Informações salvas com sucesso no arquivo: " << filename << std::endl;
    } else {
        std::cout << "Não foi possível abrir o arquivo: " << filename << std::endl;
    }

}





