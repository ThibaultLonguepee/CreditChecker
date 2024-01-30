/*
** EPITECH PROJECT, 2024
** CreditChecker
** File description:
** Main
*/

#include "Saver.hpp"
#include "Displayer.hpp"
#include "Parser.hpp"

int main(void)
{
    std::vector<CredCheck::Module *> modules = CredCheck::Parser::parseModulesFromFile("assets/modules");
    if (!CredCheck::Saver::loadFromFile("save.data", modules))
        return 84;
    CredCheck::Displayer displayer(modules);

    if (!displayer.setup())
        return 84;
    displayer.run();
    if (CredCheck::Saver::saveToFile("save.data", modules))
        return 84;
    return 0;
}
