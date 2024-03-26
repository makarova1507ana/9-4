#include <iostream>
#include <string>
#include <cctype>

// ������� ���������� ������� ����� ����� � ������
double calculateAverageWordLength(const std::string& input) {
    // �������� �� ������ ������
    if (input.empty()) {
        throw std::invalid_argument("Input string is empty");
    }

    size_t wordCount = 0;        // ���������� ���� � ������
    size_t totalWordLength = 0;  // ����� ����� ���� ���� � ������
    bool inWord = false;         // ����, �����������, ��������� �� �� ������ �����

    // ������ �� ������� ������� � ������
    for (char c : input) {
        // ��������, �������� �� ������ ������ ��� ������
        if (std::isalnum(c)) {
            // ���� �������� ����� �����
            if (!inWord) {
                inWord = true;  // ������������� ����, ��� �� ������ �����
                wordCount++;    // ����������� ������� ����
            }
            totalWordLength++;  // ����������� ����� ����� �����
        }
        else {
            inWord = false;  // ���� ������ �� �������� ������ ��� ������, �������, ��� ����� �����������
        }
    }

    // ���� � ������ �� ������� ����, ������� ����������
    if (wordCount == 0) {
        throw std::invalid_argument("No words found in the input string");
    }

    // ���������� ������� ����� �����
    return static_cast<double>(totalWordLength) / wordCount;
}
