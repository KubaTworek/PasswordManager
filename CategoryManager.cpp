//
// Created by Kuba on 15.06.2022.
//

#include <iostream>
#include <fstream>
#include "CategoryManager.h"
#include "Password.h"

CategoryManager::CategoryManager() {
    CategoryManager::categories = readCategories();
}

/**a
 * Adding a new category
 * @param vector vector of all categories added earlier to project
 */
void CategoryManager::addCategory(std::vector<std::string> &vector) {
    std::string category;
    std::cout << "Napisz nazwe kategorii, ktora chcesz dodac: " << std::endl;
    std::cin >> category;
    vector.push_back(category);
    saveCategories(vector);
    std::cout << "Dodales kategorie." << std::endl;
}

/**a
 * Deleting an existing category
 * @param pass vector of all passwords added earlier to project
 * @param categ vector of all categories added earlier to project
 */
void CategoryManager::deleteCategory(std::vector<Password> &pass, std::vector<std::string> &categ) {
    int chooseCategory;
    char confirm;
    std::cout << "Wybierz numer kategorii, ktora chcesz usunac: " << std::endl;
    std::cin >> chooseCategory;
    std::cout << "Wiaze sie to z usunieciem wszystkich hasel z tej kategorii. Na pewno chcesz to usunac? (y/n) "
              << std::endl;
    std::cin >> confirm;
    if (tolower(confirm) == 'y') {
        for (const Password &password: pass) {
            if (password.getCategory() == categ.at(chooseCategory - 1)) {
                pass.erase(pass.cbegin() + (chooseCategory - 1));
            }
        }
        categ.erase(categ.cbegin() + chooseCategory - 1);
        saveCategories(categ);
        std::cout << "Usunales kategorie i hasla" << std::endl;
    } else {
        std::cout << "Nie usunales kategorii" << std::endl;
    }
}

/**a
 * Write out every categories, which was added to project
 * @param vector vector of all categories added earlier to project
 */
void CategoryManager::writeOutCategories(std::vector<std::string> &vector) {
    int i = 1;
    for (const std::string &category: vector) {
        std::cout << i++ << ". " << category << std::endl;
    }
}

/**a
 * Reading categories from file
 * @return vector of every category in project
 */
std::vector<std::string> CategoryManager::readCategories() {
    std::vector<std::string> vector;
    std::ifstream Read;
    Read.open("../categories.txt");
    while (!Read.eof()) {
        std::string category;
        Read >> category;
        vector.push_back(category);
    }
    Read.close();
    return vector;
}

/**a
 * Saving categories to file
 * @param vector vector of all categories added earlier to project
 */
void CategoryManager::saveCategories(std::vector<std::string> &vector) {
    std::string str;
    std::ofstream save("../categories.txt");
    for (const std::string &category: vector) {
        str += "\n" + category;
    }
    save << str;
    save.close();
}

/**a
 * Getter for categories
 * @return vector of categories
 */
const std::vector<std::string> &CategoryManager::getCategories() const {
    return categories;
}

/**a
 * Setter for categories
 * @param categories vector of categories
 */
void CategoryManager::setCategories(const std::vector<std::string> &categories) {
    CategoryManager::categories = categories;
}
