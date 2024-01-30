/*
** EPITECH PROJECT, 2024
** CreditChecker
** File description:
** Roadblock
*/

#include "Roadblock.hpp"

CredCheck::Roadblock::Roadblock(std::string name, sf::Color color, int creds, int req) :
    _name(name), _color(color), _credits(creds), _required(req)
{
}

CredCheck::Roadblock **CredCheck::Roadblock::feedRoadBlocks(std::vector<Module *> modules)
{
    Roadblock **blocks = new Roadblock*[6] {
        new Roadblock("Inno & Pro", sf::Color(96, 230, 143), 0, 4),
        new Roadblock("Soft Skills", sf::Color(97, 132, 230), 0, 3),
        new Roadblock("Tech Found", sf::Color(230, 167, 96), 0, 13),
        new Roadblock("Tech Supp", sf::Color(230, 96, 96), 0, 6),
        new Roadblock("Others", sf::Color(151, 142, 160), 0, 0),
        nullptr
    };
    feedRoadBlocks(modules, blocks);
    return blocks;
}

void CredCheck::Roadblock::feedRoadBlocks(std::vector<Module *> modules, CredCheck::Roadblock **blocks)
{
    for (int i = 0; blocks[i]; i++)
        blocks[i]->_credits = 0;
    for (auto m : modules)
        *blocks[m->roadblock()] += (m->credits() * m->isSelected());
}

std::string CredCheck::Roadblock::getName() const
{
    return _name;
}

sf::Color CredCheck::Roadblock::getColor() const
{
    return _color;
}

int CredCheck::Roadblock::getCredits() const
{
    return _credits;
}

int CredCheck::Roadblock::getRequired() const
{
    return _required;
}

bool CredCheck::Roadblock::valid() const
{
    return _credits >= _required;
}

void CredCheck::Roadblock::operator+=(int creds)
{
    _credits += creds;
}