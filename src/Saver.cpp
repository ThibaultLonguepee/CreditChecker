/*
** EPITECH PROJECT, 2024
** CreditChecker
** File description:
** Saver
*/

#include "Saver.hpp"

bool CredCheck::Saver::loadFromFile(std::string filename, std::vector<CredCheck::Module *> modules)
{
    std::ifstream fileStream(filename);
    if (!fileStream.is_open()) return false;

    std::string line;
    std::vector<std::string> lines;
    while (getline(fileStream, line))
        lines.push_back(line);
    for (auto m : modules) {
        if (m->isSelected()) continue;
        for (auto l : lines)
            if (l == m->name())
                m->toggleSelect();
    }
    return true;
}

bool CredCheck::Saver::saveToFile(std::string filename, std::vector<CredCheck::Module *> modules)
{
    std::ofstream ofs(filename, std::ofstream::trunc);
    if (!ofs.is_open()) return false;
    for (auto m : modules) {
        if (!m->isSelected()) continue;
        ofs << m->name() << std::endl;
    }
    ofs.close();
    return true;
}
