/*
** EPITECH PROJECT, 2024
** CreditChecker
** File description:
** Saver
*/

#ifndef SAVER_HPP_
#define SAVER_HPP_

#include <fstream>
#include <sstream>
#include "Module.hpp"

namespace CredCheck {
    class Saver {
        public:
            static bool loadFromFile(std::string filename, std::vector<Module *> modules);
            static bool saveToFile(std::string filename, std::vector<Module *> modules);
        protected:
        private:
    };
}

#endif /* !SAVER_HPP_ */
