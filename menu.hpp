#pragma once 
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

//Declaracoes das funcoes usadas 
void print_file(const std::string& filename);
std::string searched_name();
void search_user_by_name(const std::string& name, const std::string& filename);
void calculate_violation_totals(const std::string& filename);
void display_menu();
void clear_screen();
