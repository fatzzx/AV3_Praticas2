#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class User {
private:
    std::string m_age;
    std::string m_name;
    std::string m_gender;
    std::string m_q1;
    std::string m_q2;
    std::string m_q3;
    std::string m_q4;
    std::string m_q5;
    std::string m_q6;
public:
    std::string get_age();
    std::string get_name();
    std::string get_gender();
    void set_age(int age);
    void set_name(std::string name);
    void set_gender(char gender);
    void ask_age();
    void ask_name();
    void ask_gender();
    void ask_q1();
    void ask_q2();
    void ask_q3();
    void ask_q4();
    void ask_q5();
    void ask_q6();
    void ask_questions();
    std::string get_q1();
    std::string get_q2();
    std::string get_q3();
    std::string get_q4();
    std::string get_q5();
    std::string get_q6();
    void save_to_file(const std::string& filename);
};
