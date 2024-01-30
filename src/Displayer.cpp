/*
** EPITECH PROJECT, 2024
** CreditChecker
** File description:
** Displayer
*/

#include "Displayer.hpp"

CredCheck::Displayer::Displayer(std::vector<Module *> modules) : _modules(modules)
{
}

CredCheck::Displayer::~Displayer()
{
    for (auto m : _modules)
        delete m;
}

bool CredCheck::Displayer::setup()
{
    _window.close();

    for (auto m : _modules)
    {
        if (m->size() == 0) continue;
        for (unsigned int i = 0; i < m->size(); i++)
            if (_videoMode.width < ((*m)[i]->end() + 1) * _size * 1.5f)
                _videoMode.width = ((*m)[i]->end() + 1) * _size * 1.5f;
        _videoMode.height += _size + 2.f;
    }
    _videoMode.width += _size * 2.f;
    _videoMode.height += _size * 2.f;

    // Prepare the rectangle
    _rect.setOutlineColor(sf::Color(247, 249, 253));
    _rect.setOutlineThickness(2.f);

    // Prepare the font
    if (!_font.loadFromFile("assets/regular.ttf"))
        return false;

    // Prepare the text
    _text.setFont(_font);
    _text.setCharacterSize(_size * 0.4f);
    _text.setFillColor(sf::Color(7, 11, 21));
    _text.setPosition(sf::Vector2f(0.f, 0.f));
    return true;
}

void CredCheck::Displayer::run()
{
    _window.create(_videoMode, "CreditChecker Alpha 0.1.1");
    _window.setFramerateLimit(60);

    while (_window.isOpen())
    {
        sf::Vector2f pos(_size, _size);
        _window.clear(sf::Color(247, 249, 253));
        pollEvents();

        for (auto m : _modules)
        {
            if (m->size() == 0) continue;
            displayModule(m, pos);
            pos.y += _size + 2.f;
        }
        _window.display();
    }
}

void CredCheck::Displayer::pollEvents()
{
    sf::Event event;
    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _window.close();
        if (event.type == 10 && event.mouseButton.button == 0) {
            unsigned int i = event.mouseButton.y / (_size + 2.f) + 2;
            if (i >= _modules.size()) continue;
            _modules[i]->toggleSelect();
        }
    }
}

void CredCheck::Displayer::displayModule(Module *m, sf::Vector2f pos)
{
    for (unsigned int i = 0; i < m->size(); i++)
        displayProject((*m)[i], pos);
}

void CredCheck::Displayer::displayProject(Project *p, sf::Vector2f pos)
{
    sf::FloatRect bounds;
    float width = _size * 1.5f * (p->end() - p->start() + 1);
    float x = pos.x + (p->start() * _size * 1.5f);
    sf::Color c = p->module()->color();
    int a = p->module()->isSelected() ? 255 : 40;

    _rect.setSize(sf::Vector2f(width, _size));
    _rect.setPosition(sf::Vector2f(x, pos.y));
    _rect.setFillColor(sf::Color(c.r, c.g, c.b, a));
    _window.draw(_rect);

    _text.setFillColor(sf::Color(247, 249, 253));
    _text.setString(p->name());
    _text.setPosition(sf::Vector2f(x, pos.y));
    _window.draw(_text);
}
