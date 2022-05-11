//
// Created by sorer on 5/11/22.
//

#include "str.h"

Str::Str() { this->m_str = strdup("none"); }
Str::~Str() { delete this->m_str; }
