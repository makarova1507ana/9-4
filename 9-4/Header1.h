#include <iostream>
#include <string>
#include <cctype>

// Функция вычисления средней длины слова в строке
double calculateAverageWordLength(const std::string& input) {
    // Проверка на пустую строку
    if (input.empty()) {
        throw std::invalid_argument("Input string is empty");
    }

    size_t wordCount = 0;        // Количество слов в строке
    size_t totalWordLength = 0;  // Общая длина всех слов в строке
    bool inWord = false;         // Флаг, указывающий, находимся ли мы внутри слова

    // Проход по каждому символу в строке
    for (char c : input) {
        // Проверка, является ли символ буквой или цифрой
        if (std::isalnum(c)) {
            // Если началось новое слово
            if (!inWord) {
                inWord = true;  // Устанавливаем флаг, что мы внутри слова
                wordCount++;    // Увеличиваем счетчик слов
            }
            totalWordLength++;  // Увеличиваем общую длину слова
        }
        else {
            inWord = false;  // Если символ не является буквой или цифрой, считаем, что слово закончилось
        }
    }

    // Если в строке не найдено слов, бросаем исключение
    if (wordCount == 0) {
        throw std::invalid_argument("No words found in the input string");
    }

    // Возвращаем среднюю длину слова
    return static_cast<double>(totalWordLength) / wordCount;
}
