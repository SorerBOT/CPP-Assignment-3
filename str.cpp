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
