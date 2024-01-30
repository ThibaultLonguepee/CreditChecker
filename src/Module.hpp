/*
** EPITECH PROJECT, 2024
** CreditChecker
** File description:
** Module
*/

#ifndef MODULE_HPP_
#define MODULE_HPP_

#include <SFML/Graphics.hpp>
#include "Project.hpp"
#include <vector>

namespace CredCheck {
    class Module {
        public:
            Module(std::string name, float creds, sf::Color color = sf::Color(60, 99, 208)) :
                _name(name),
                _credits(creds),
                _color(color) {};
            ~Module() { for (auto p : _projects) delete p; }
            const std::string name() const { return _name; }
            float credits() const { return _credits; }
            sf::Color color() const { return _color; }
            unsigned int size() { return _projects.size(); }
            void toggleSelect() { _selected = !_selected; }
            bool isSelected() const { return _selected; }
            void addProject(Project *p) { _projects.push_back(p); }
            Project *operator[](unsigned int n ) const { return _projects.at(n); }
        protected:
        private:
            const std::string _name = "";
            const float _credits = 0;
            const sf::Color _color = sf::Color(60, 99, 208);
            std::vector<Project *> _projects = {};
            bool _selected = false;
    };
}

#endif /* !MODULE_HPP_ */
