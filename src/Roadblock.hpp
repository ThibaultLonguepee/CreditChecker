/*
** EPITECH PROJECT, 2024
** CreditChecker
** File description:
** Roadblock
*/

#ifndef ROADBLOCK_HPP_
#define ROADBLOCK_HPP_

#include "Module.hpp"

namespace CredCheck {
    class Roadblock {
        public:
            Roadblock(std::string name, sf::Color color, int creds, int req);
            ~Roadblock() = default;
            static Roadblock **feedRoadBlocks(std::vector<Module *> modules);
            static void feedRoadBlocks(std::vector<Module *> modules, Roadblock **blocks);
            std::string getName() const;
            sf::Color getColor() const;
            int getCredits() const;
            int getRequired() const;
            bool valid() const;
            void operator+=(int creds);
        protected:
        private:
            std::string _name = "";
            sf::Color _color = sf::Color::Black;
            int _credits = 0;
            int _required = 0;
    };
}

#endif /* !ROADBLOCK_HPP_ */
