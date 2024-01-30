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
            Module(std::string name, float creds, int roadblock) :
                _name(name),
                _credits(creds),
                _roadblock(roadblock) {};
            ~Module() { for (auto p : _projects) delete p; }
            const std::string name() const { return _name; }
            float credits() const { return _credits; }
            int roadblock() const { return _roadblock; }
            unsigned int size() { return _projects.size(); }
            void toggleSelect() { _selected = !_selected; }
            bool isSelected() const { return _selected; }
            void addProject(Project *p) { _projects.push_back(p); }
            Project *operator[](unsigned int n ) const { return _projects.at(n); }
        protected:
        private:
            const std::string _name = "";
            const float _credits = 0;
            const int _roadblock = 0;
            std::vector<Project *> _projects = {};
            bool _selected = false;
    };
}

#endif /* !MODULE_HPP_ */
