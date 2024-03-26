#include "pch.h"
#include <tuple>
#include <string.h>
#include <cctype>
using namespace std;
#include <iostream>
#include <stdexcept>
#include "../../9-4/9-4/Wallet.h"
#include "../../9-4/9-4/User.h"

//tuple<входные значения, ождиаемое значение>
// фикстура - управление тестовыми значениями или состояниями    для каждого теста 
class WalletTest : public ::testing::TestWithParam<tuple<int, int, int>> {
protected:
    //перед запуском теста, будем создавать кошелек
    void SetUp() override {
        tie(wallet_id, initial_balance, expected) = GetParam(); //распаковка кортежа
        wallet = new Wallet(wallet_id, initial_balance);
    }

    // после завершения теста, удалять 
    void  TearDown() override {
        delete wallet;
    }
    int initial_balance;
    int wallet_id;
    int expected;
    Wallet* wallet;
};
INSTANTIATE_TEST_CASE_P(InitialeBalances, WalletTest,
    ::testing::Values(
        make_tuple(1, 100, 100), make_tuple(2, 0, 0), make_tuple(3, 1, 1), make_tuple(4, -100, -100)));
TEST_P(WalletTest, emptyWallet) {
    tie(wallet_id, initial_balance, expected) = GetParam(); //распаковка кортежа
    EXPECT_EQ(wallet->get_balance(), expected);
    EXPECT_EQ(wallet->get_wallet_id(), wallet_id);
}





#include <tuple>
// фикстура - управление тестовыми значениями или состояниями    для каждого теста 
class WalletAddParametrizedTest : public ::testing::TestWithParam<tuple<int, int, int>> {
protected:
    //перед запуском теста, будем создавать кошелек
    void SetUp() override {
        tie(initial_balance, cash, expected) = GetParam(); //распаковка кортежа
        wallet = new Wallet(1, initial_balance);
    }

    // после завершения теста, удалять 
    void  TearDown() override {
        delete wallet;
    }
    int initial_balance;
    int cash;
    int expected;
    Wallet* wallet;
};
INSTANTIATE_TEST_CASE_P(AddCashBalances, WalletAddParametrizedTest,
    ::testing::Values(
        make_tuple(100, 100, 100 + 100), make_tuple(1, 0, 1), make_tuple(-100, 100, 0)));

TEST_P(WalletAddParametrizedTest, add_balance) {
    tie(initial_balance, cash, expected) = GetParam(); //распаковка кортежа
    wallet->add_cash(cash);// добавлили кэш
    EXPECT_EQ(wallet->get_balance(), expected);
}



/*-------------------------тесты с исключениями---------------------------------*/

// фикстура - управление тестовыми значениями или состояниями    для каждого теста 
class Wallet_EXEPTIONS_Test : public ::testing::TestWithParam<pair<int, int>> {
protected:
    //перед запуском теста, будем создавать кошелек
    void SetUp() override {
        initial_balance = GetParam().first;
        wallet = new Wallet(1, initial_balance);
    }

    // после завершения теста, удалять 
    void  TearDown() override {
        delete wallet;
    }
    int initial_balance;
    Wallet* wallet;
};
INSTANTIATE_TEST_CASE_P(SpendCashBalances, Wallet_EXEPTIONS_Test,
    ::testing::Values(
        make_pair(0, 100), make_pair(1, 100), make_pair(-100, 100), make_pair(-100, -100)));
TEST_P(Wallet_EXEPTIONS_Test, spend_cash) {
    int cash = GetParam().second;//распаковка кортежа
    EXPECT_THROW(wallet->spend_cash(cash), InsufficientAmount); // тратим кэш
}

/*-----------------USers tests-----------------*/
class UsersTestInitial : public ::testing::TestWithParam<tuple<string, int, int>> {
protected:
    //перед запуском теста, будем создавать кошелек
    void SetUp() override {
        tie(name, wallet_id, initial_balance) = GetParam(); //распаковка кортежа
        user = new User(name, wallet_id, initial_balance);
    }

    // после завершения теста, удалять 
    void  TearDown() override {
        delete user;
    }
    int initial_balance;
    int wallet_id;
    string name;
    User* user;
};
INSTANTIATE_TEST_CASE_P(User_initialTest, UsersTestInitial,
    ::testing::Values(
        make_tuple("Ivan", 1, 100),
        make_tuple("Ivan312", 0, 0),
        make_tuple("Ivan Ivanov", 3, 1), 
        make_tuple(" ", -100, -100)));


TEST_P(UsersTestInitial, initialTestName) {
    tie(name, wallet_id, initial_balance) = GetParam(); //распаковка кортежа
    EXPECT_EQ(user->get_name(), name);
}

TEST_P(UsersTestInitial, initialTestID) {
    tie(name, wallet_id, initial_balance) = GetParam(); //распаковка кортежа
    EXPECT_EQ(user->get_wallet_id(), wallet_id);
}

TEST_P(UsersTestInitial, initialTestBalance) {
    tie(name, wallet_id, initial_balance) = GetParam(); //распаковка кортежа
    EXPECT_EQ(user->get_wallet_balance(), initial_balance);
 
}