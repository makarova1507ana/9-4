#pragma once
#ifndef WALLET_H
#define WALLET_H

#include <iostream>
#include <stdexcept>

// Класс для исключения, которое будет брошено в случае недостаточного количества средств
class InsufficientAmount : public std::exception {
public:
    // Переопределение метода what() для возврата сообщения об ошибке
    const char* what() const noexcept override {
        return "Недостаточно средств на счету.";
    }
};

// Класс для кошелька
class Wallet {
private:
    int wallet_id; // идентификатор кошелька
    int balance; // баланс в рублях

public:
    // Конструктор, принимающий идентификатор и начальный баланс (по умолчанию 0)
    Wallet(int id = 1, int balance = 0);

    // Метод для получения идентификатора кошелька
    int get_wallet_id() const;

    // Метод для получения текущего баланса
    int get_balance() const;

    // Метод для добавления денег на счет
    void add_cash(int amount);

    // Метод для расходования средств
    void spend_cash(int spend_sum);
};
#include "wallet.h"

// Конструктор, принимающий идентификатор и начальный баланс (по умолчанию 0)
Wallet::Wallet(int id, int balance) : wallet_id(id), balance(balance) {}

// Метод для получения идентификатора кошелька
int Wallet::get_wallet_id() const {
    return wallet_id;
}

// Метод для получения текущего баланса
int Wallet::get_balance() const {
    return balance;
}

// Метод для добавления денег на счет
void Wallet::add_cash(int amount) {
    balance += amount;
    std::cout << "Баланс кошелька " << wallet_id << ": " << balance << std::endl;
}

// Метод для расходования средств
void Wallet::spend_cash(int spend_sum) {
    // Проверяем, есть ли достаточное количество средств на счету
    if (spend_sum <= balance) {
        // Если есть, уменьшаем баланс на сумму расхода
        balance -= spend_sum;
        std::cout << "Баланс кошелька " << wallet_id << ": " << balance << std::endl;
    }
    else {
        // Если недостаточно средств, бросаем исключение
        throw InsufficientAmount();
    }
}
#endif // WALLET_H

