/*
** EPITECH PROJECT, 2024
** CreditChecker
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include "Module.hpp"
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

namespace CredCheck {
    class Parser {
        public:
            static std::vector<CredCheck::Module *> parseModulesFromFile(std::string fileName);
        protected:
        private:
    };
}

#endif /* !PARSER_HPP_ */
