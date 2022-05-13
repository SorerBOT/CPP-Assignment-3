//
// Created by sorer on 5/11/22.
//

#include "str.h"

Str::Str() { this->m_str = strdup("none"); }
Str::Str(const char *str) { delete this->m_str; this->m_str = strdup(str); }
Str::~Str() { delete this->m_str; }

bool Str::operator==(const Str &other) const { return strcmp(this->m_str, other.getStr()) == 0; }
bool Str::operator!=(const Str &other) const { return strcmp(this->m_str, other.getStr()) != 0; }
bool Str::operator>(const Str &other) const { return strcmp(this->m_str, other.getStr()) > 0; }
bool Str::operator<(const Str &other) const { return strcmp(this->m_str, other.getStr()) < 0; }

const Str& Str::operator=(const Str& other) { delete this->m_str; this->m_str = strdup(other.getStr()); return *this; }
const Str& Str::operator=(const char* str) { delete this->m_str; this->m_str = strdup(str); return *this; }

char& Str::operator[](int index) const { return const_cast<char &>(this->getStr()[index]); }

const Str& Str::operator++() {
    int iteration;
    for (iteration = 0; iteration < strlen(this->getStr()); iteration++) this->m_str[iteration]++;
    return *this;
}
Str Str::operator++(int) {
    Str& temp = *this;
    int iteration;
    for (iteration = 0; iteration < strlen(this->getStr()); iteration++) this->m_str[iteration]++;
    return temp;
}

Str::operator int() const { return strlen(this->m_str); }

int Str::operator()(char character) const {
    int index;
    for (index = 0; index < strlen(this->m_str); index++) if (this[index] == character) return index;
    return -1;
}

Str Str::operator+(const Str& other) const {
    int index, iteration;
    char* newString = new char[strlen(this->getStr()) + strlen(other.getStr()) + 1];
    for (index = 0; index < strlen(this->getStr()); index++) newString[index] = this[index];
    for (iteration = 0; iteration < strlen(other.getStr()); iteration++) newString[iteration + index] = other[iteration];
    newString[index + iteration] = '\0';
    return *new Str(newString);
}

Str operator+(const char* str, const Str& other) {
    int index, iteration;
    char* newString = new char[strlen(str) + strlen(other.getStr()) + 1];
    for (index = 0; index < strlen(str); index++) newString[index] = str[index];
    for (iteration = 0; iteration < strlen(other.getStr()); iteration++) newString[iteration + index] = other[iteration];
    newString[index + iteration] = '\0';
    return *new Str(newString);
}

Str operator*(int num, const Str& other) {
    int iteration, index;
    char* newString = new char[num * strlen(other.getStr()) + 1];
    for (iteration = 0; iteration < num; iteration++) {
        for (index = 0; index < strlen(other.getStr()); index++) {
            newString[iteration * strlen(other.getStr()) + index] = other.getStr()[index];
        }
    }
    newString[index + iteration] = '\0';
    return *new Str(newString);
}