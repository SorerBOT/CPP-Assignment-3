//
// Created by sorer on 5/11/22.
//

#include "str.h"

Str::Str() { this->m_str = strdup("none"); }
Str::Str(const char *str) { this->m_str = strdup(str); }
Str::Str( const Str& other ) { this->m_str = strdup(other.getStr()); }
Str::~Str() { delete this->m_str; }
bool Str::operator==(const Str &other) const { return strcmp(this->m_str, other.getStr()) == 0; }
bool Str::operator!=(const Str &other) const { return strcmp(this->m_str, other.getStr()) != 0; }
bool Str::operator>(const Str &other) const { return strcmp(this->m_str, other.getStr()) > 0; }
bool Str::operator<(const Str &other) const { return strcmp(this->m_str, other.getStr()) < 0; }

const Str& Str::operator=(const Str& other) { delete this->m_str; this->m_str = strdup(other.getStr()); return *this; }
const Str& Str::operator=(const char* str) { delete this->m_str; this->m_str = strdup(str); return *this; }

char& Str::operator[](int index) const { return this->m_str[index]; }

const Str& Str::operator++() {
    int iteration;
    for (iteration = 0; iteration < strlen(this->getStr()); iteration++) this->m_str[iteration]++;
    return *this;
}

Str Str::operator++(int) {
    Str temp = *this;
    int iteration;
    for (iteration = 0; iteration < strlen(this->getStr()); iteration++) this->m_str[iteration]++;
    return temp;
}

Str::operator int() const { return strlen(this->m_str); }

int Str::operator()(char character) const {
    int index;
    for (index = 0; index < strlen(this->m_str); index++) {
        if (this->m_str[index] == character) return index;
    }
    return -1;
}

Str Str::operator+(const Str& other) const {
    int index, iteration;
    char* newString = new char[strlen(this->getStr()) + strlen(other.getStr()) + 1];
    for (index = 0; index < strlen(this->getStr()); index++) newString[index] = this->m_str[index];
    for (iteration = 0; iteration < strlen(other.getStr()); iteration++) newString[iteration + index] = other.m_str[iteration];
    newString[index + iteration] = '\0';
    return *new Str(newString);
}

Str operator+(const char* str, const Str& other) {
    char* newString = new char[strlen(str) + strlen(other.getStr()) + 1];
    int index, iteration;
    for (index = 0; index < strlen(str); index++) newString[index] = str[index];
    for (iteration = 0; iteration < strlen(other.getStr()); iteration++) newString[iteration + index] = other.getStr()[iteration];
    newString[index + iteration] = '\0';
    return *new Str(newString);
}

Str operator*(int num, const Str& other) {
    int index;
    char* newString = new char[num * strlen(other.getStr()) + 1];
    for (index = 0; index < num * strlen(other.getStr()); index++) { newString[index] = other.m_str[index % strlen(other.getStr())]; }
    newString[index] = '\0';
    return *new Str(newString);
}

const Str& Str::operator+=(const Str& other) {
    int iteration, index;
    char* newString = new char[strlen(this->getStr()) + strlen(other.getStr()) + 1];
    for (index = 0; index < strlen(this->getStr()); index++) newString[index] = this->m_str[index];
    for (iteration = 0; iteration < strlen(other.getStr()); iteration++) newString[iteration + index] = other.m_str[iteration];
    newString[index + iteration] = '\0';
    delete this->m_str;
    this->m_str = newString;
}