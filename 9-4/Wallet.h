#pragma once
#ifndef WALLET_H
#define WALLET_H

#include <iostream>
#include <stdexcept>

// ����� ��� ����������, ������� ����� ������� � ������ �������������� ���������� �������
class InsufficientAmount : public std::exception {
public:
    // ��������������� ������ what() ��� �������� ��������� �� ������
    const char* what() const noexcept override {
        return "������������ ������� �� �����.";
    }
};

// ����� ��� ��������
class Wallet {
private:
    int wallet_id; // ������������� ��������
    int balance; // ������ � ������

public:
    // �����������, ����������� ������������� � ��������� ������ (�� ��������� 0)
    Wallet(int id = 1, int balance = 0);

    // ����� ��� ��������� �������������� ��������
    int get_wallet_id() const;

    // ����� ��� ��������� �������� �������
    int get_balance() const;

    // ����� ��� ���������� ����� �� ����
    void add_cash(int amount);

    // ����� ��� ������������ �������
    void spend_cash(int spend_sum);
};
#include "wallet.h"

// �����������, ����������� ������������� � ��������� ������ (�� ��������� 0)
Wallet::Wallet(int id, int balance) : wallet_id(id), balance(balance) {}

// ����� ��� ��������� �������������� ��������
int Wallet::get_wallet_id() const {
    return wallet_id;
}

// ����� ��� ��������� �������� �������
int Wallet::get_balance() const {
    return balance;
}

// ����� ��� ���������� ����� �� ����
void Wallet::add_cash(int amount) {
    balance += amount;
    std::cout << "������ �������� " << wallet_id << ": " << balance << std::endl;
}

// ����� ��� ������������ �������
void Wallet::spend_cash(int spend_sum) {
    // ���������, ���� �� ����������� ���������� ������� �� �����
    if (spend_sum <= balance) {
        // ���� ����, ��������� ������ �� ����� �������
        balance -= spend_sum;
        std::cout << "������ �������� " << wallet_id << ": " << balance << std::endl;
    }
    else {
        // ���� ������������ �������, ������� ����������
        throw InsufficientAmount();
    }
}
#endif // WALLET_H

