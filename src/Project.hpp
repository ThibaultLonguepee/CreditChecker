/*
** EPITECH PROJECT, 2024
** CreditChecker
** File description:
** Project
*/

#ifndef PROJECT_HPP_
#define PROJECT_HPP_

#include "Module.hpp"
#include <iostream>

namespace CredCheck {
    class Module;

    class Project {
        public:
            Project(std::string name, Module *module, float start, float end) :
                _name(name),
                _module(module),
                _start(start),
                _end(end) {};
            // Yeah this is definetly not coding style ...
            ~Project() = default;
            std::string name() const { return _name; }
            const Module *module() const { return _module; }
            float start() const { return _start; }
            float end() const { return _end; }
        protected:
        private:
            const std::string _name = "";
            // Gamble on the circular import lol
            const Module *_module = nullptr;
            const float _start = 0;
            const float _end = 1;
    };
}

#endif /* !PROJECT_HPP_ */
