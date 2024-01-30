/*
** EPITECH PROJECT, 2024
** CreditChecker
** File description:
** Displayer
*/

#ifndef DISPLAYER_HPP_
#define DISPLAYER_HPP_

#include "Module.hpp"
#include <algorithm>

namespace CredCheck {
    class Displayer {
        public:
            Displayer(std::vector<Module *> modules);
            ~Displayer();
            bool setup();
            void run();
        protected:
        private:
            void pollEvents();
            void displayModule(Module *, sf::Vector2f pos);
            void displayProject(Project *, sf::Vector2f pos);

            std::vector<Module *> _modules;
            float _size = 40.f;
            sf::RenderWindow _window;
            sf::VideoMode _videoMode;
            sf::Font _font;
            sf::Text _text;
            sf::RectangleShape _rect;
    };
}

#endif /* !DISPLAYER_HPP_ */
