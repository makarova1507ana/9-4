#pragma once
#include <iostream>
#include <vector>
#include <ctime>


// fsdssdfs
void processTask() {
    for (int i = 0; i < 10000; ++i) {
        std::vector<int> vec;
        for (int j = 0; j < 100; ++j) {
            vec.push_back(j);
        }
    }
}

int main() {
    clock_t start = clock();
    processTask();
    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time taken by program is : " << time_taken << std::endl;
    return 0;
}



//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//// Функция для нахождения суммы элементов вектора
//int sumVector(const std::vector<int>& vec) {
//    int sum = 0;
//    for (int num : vec) {
//        sum += num;
//    }
//    return sum;
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//    // Создаем вектор из 1 миллиона целых чисел
//    std::vector<int> numbers(1000000);
//    std::fill(numbers.begin(), numbers.end(), 1);
//
//    // Вызываем функцию для нахождения суммы элементов вектора
//    int result = sumVector(numbers);
//
//    // Выводим результат на экран
//    std::cout << "Сумма элементов вектора: " << result << std::endl;
//
//    return 0;
//}
//
//
////// 9-4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//////
////
////#include <iostream>
////#include "Header1.h"
////int main() {
////    try {
////        std::string input1 = "Hello World";
////        std::string input2 = "The quick brown fox jumps over 2 lazy dogs.";
////
////        // Вычисляем среднюю длину слова для двух строк
////        double averageLength1 = calculateAverageWordLength(input1);
////        double averageLength2 = calculateAverageWordLength(input2);
////
////        // Выводим результаты
////        std::cout << "Average word length in \"" << input1 << "\": " << averageLength1 << std::endl;
////        std::cout << "Average word length in \"" << input2 << "\": " << averageLength2 << std::endl;
////    }
////    catch (const std::exception& e) {
////        // В случае ошибки выводим сообщение об ошибке
////        std::cerr << "Error: " << e.what() << std::endl;
////    }
////
////    return 0;
////}
////
////
////// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
////// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
////
////// Советы по началу работы 
//////   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//////   2. В окне Team Explorer можно подключиться к системе управления версиями.
//////   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//////   4. В окне "Список ошибок" можно просматривать ошибки.
//////   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//////   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
