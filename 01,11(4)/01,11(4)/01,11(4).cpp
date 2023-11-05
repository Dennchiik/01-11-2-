#include <iostream>
#include <string>

const int MAX_ENTRIES = 100;

struct PhoneEntry {
    std::string name;
    std::string phoneNumber;
};

void searchByName(const PhoneEntry* entries, int numEntries, const std::string& name) {
    for (int i = 0; i < numEntries; i++) {
        if (entries[i].name == name) {
            std::cout << "Найдено: " << entries[i].name << " - " << entries[i].phoneNumber << std::endl;
            return;
        }
    }
    std::cout << "Имя не найдено" << std::endl;
}

void searchByPhoneNumber(const PhoneEntry* entries, int numEntries, const std::string& phoneNumber) {
    for (int i = 0; i < numEntries; i++) {
        if (entries[i].phoneNumber == phoneNumber) {
            std::cout << "Найдено: " << entries[i].name << " - " << entries[i].phoneNumber << std::endl;
            return;
        }
    }
    std::cout << "Номер телефона не найден" << std::endl;
}

int main() {
    PhoneEntry entries[MAX_ENTRIES];
    int numEntries = 0;

    while (true) {
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Добавить запись" << std::endl;
        std::cout << "2. Поиск по имени" << std::endl;
        std::cout << "3. Поиск по номеру телефона" << std::endl;
        std::cout << "4. Выход" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            if (numEntries < MAX_ENTRIES) {
                std::string name, phoneNumber;
                std::cout << "Введите имя: ";
                std::cin >> name;
                std::cout << "Введите номер телефона: ";
                std::cin >> phoneNumber;
                entries[numEntries].name = name;
                entries[numEntries].phoneNumber = phoneNumber;
                numEntries++;
                std::cout << "Запись добавлена." << std::endl;
            }
            else {
                std::cout << "Достигнут максимальный лимит записей." << std::endl;
            }
        }
        else if (choice == 2) {
            std::string name;
            std::cout << "Введите имя для поиска: ";
            std::cin >> name;
            searchByName(entries, numEntries, name);
        }
        else if (choice == 3) {
            std::string phoneNumber;
            std::cout << "Введите номер телефона для поиска: ";
            std::cin >> phoneNumber;
            searchByPhoneNumber(entries, numEntries, phoneNumber);
        }
        else if (choice == 4) {
            break;
        }
        else {
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    }

    return 0;
}
