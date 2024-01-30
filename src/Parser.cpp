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
        float c = 0.f;
        int r = 0;
        ss >> name >> c >> r;
        Module *m = new Module(name, c, r);

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
