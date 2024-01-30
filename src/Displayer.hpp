/*
** EPITECH PROJECT, 2024
** CreditChecker
** File description:
** Displayer
*/

#ifndef DISPLAYER_HPP_
#define DISPLAYER_HPP_

#include "Roadblock.hpp"
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
            void displayCredits(sf::Vector2f pos);
            void displayRoadblock(sf::Vector2f pos, int block);
            void displayWarnings();

            int _width = 0;
            std::vector<Module *> _modules;
            Roadblock **_blocks = nullptr;
            float _size = 40.f;
            sf::RenderWindow _window;
            sf::VideoMode _videoMode;
            sf::Font _font;
            sf::Text _text;
            sf::RectangleShape _rect;
    };
}

#endif /* !DISPLAYER_HPP_ */
