#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

std::vector<std::string> canonNames = {
    "gardenGnostic", "gutsyGumshoe", "carcinoGeneticist", "arachnidsGrip",
    "turntechGodhead", "tipsyGnostalgic", "gallowsCalibrator", "cuttlefishCuller",
    "arsenicCatnip", "terminallyCapricious", "grimAuxiliatrix", "caligulasAquarium",
    "apocalypseArisen", "twinArmageddons", "ghostyTrickster", "golgothasTerror",
    "centaursTesticle", "adiosToreador", "tentacleTherapist", "timaeusTestified"
};

std::vector<std::string> validInitials = { "A", "C", "G", "T" };

std::string random_line(const std::string& v_file) {
    std::ifstream file(v_file);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    int randomIndex = std::rand() % lines.size();
    return lines[randomIndex];
}

std::string getFirstPartOfHandle(const std::string& initial, const std::string& a, const std::string& c, const std::string& g, const std::string& t) {
    if (initial == "A") {
        return random_line(a);
    }
    else if (initial == "C") {
        return random_line(c);
    }
    else if (initial == "G") {
        return random_line(g);
    }
    else if (initial == "T") {
        return random_line(t);
    }
    return "";
}

std::string getSecondPartOfHandle(const std::string& initial, const std::string& a, const std::string& c, const std::string& g, const std::string& t) {
    std::string line = getFirstPartOfHandle(initial, a, c, g, t);
    if (!line.empty()) {
        line[0] = std::toupper(line[0]);
    }
    return line;
}

std::string returnChumHandle(const std::string& initialA, const std::string& initialB, const std::string& a, const std::string& c, const std::string& g, const std::string& t) {
    std::string firstPart = getFirstPartOfHandle(initialA, a, c, g, t);
    std::string secondPart = getSecondPartOfHandle(initialB, a, c, g, t);
    return firstPart + secondPart;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::string a = "files/A.txt";
    std::string c = "files/C.txt";
    std::string g = "files/G.txt";
    std::string t = "files/T.txt";

    while (true) {
        std::string handle;
        std::cout << "Input the initials for your handle >> ";
        std::cin >> handle;

        if (handle.size() == 2) {
            std::string firstInitial = std::string(1, std::toupper(handle[0]));
            std::string secondInitial = std::string(1, std::toupper(handle[1]));

            std::string chumHandle = returnChumHandle(firstInitial, secondInitial, a, c, g, t);

            if (std::find(canonNames.begin(), canonNames.end(), chumHandle) != canonNames.end()) {
                std::cout << "CANON NAME FOUND" << std::endl;
            }
            std::cout << chumHandle << '\n';
            std::cout << "" << std::endl;
        }
        else {
            std::cout << "2 INITIALS NECESSARY" << std::endl;
        }
    }

    return 0;
}