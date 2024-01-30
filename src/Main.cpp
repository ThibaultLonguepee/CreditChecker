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
    std::vector<CredCheck::Module *> modules = CredCheck::Parser::parseModulesFromFile("assets/modules.data");
    if (!CredCheck::Saver::loadFromFile("save.data", modules))
        std::cout << "No valid save data file found." << std::endl;
    CredCheck::Displayer displayer(modules);

    if (!displayer.setup())
        return 84;
    displayer.run();
    if (!CredCheck::Saver::saveToFile("save.data", modules))
        std::cout << "Could not create save data file." << std::endl;
    return 0;
}
