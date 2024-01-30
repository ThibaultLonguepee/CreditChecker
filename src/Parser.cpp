/*
** EPITECH PROJECT, 2024
** CreditChecker
** File description:
** Parser
*/

#include "Parser.hpp"

static CredCheck::Project *parseProject(std::string line, CredCheck::Module *m)
{
    std::stringstream ss(line.substr(1));
    std::string name;
    float start, end;
    ss >> name >> start >> end;
    return new CredCheck::Project(name, m, start, end);
}

std::vector<CredCheck::Module *> CredCheck::Parser::parseModulesFromFile(std::string fileName)
{
    std::vector<Module *> modules;
    std::string line = "";
    std::ifstream fileStream(fileName);

    while (getline(fileStream, line)) {
        if (line == "" || !line.starts_with("#")) continue;
        std::stringstream ss(line.substr(1));
        std::string name;
        float c, r, g, b;
        ss >> name >> c >> r >> g >> b;
        Module *m = new Module(name, c, sf::Color(r, g, b));

        while (getline(fileStream, line)) {
            if (!line.starts_with("\t")) break;
            m->addProject(parseProject(line, m));
        }
        if (m->size() == 0)
            m->toggleSelect();

        modules.push_back(m);
    }

    fileStream.close();
    return modules;
}
