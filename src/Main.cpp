/*
** EPITECH PROJECT, 2024
** CreditChecker
** File description:
** Main
*/

#include "Displayer.hpp"
#include "Parser.hpp"

int main(void)
{
    std::vector<CredCheck::Module *> modules = CredCheck::Parser::parseModulesFromFile("assets/modules");
    CredCheck::Displayer displayer(modules);

    if (!displayer.setup())
        return 84;
    displayer.run();
    return 0;
}
