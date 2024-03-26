# game
**Этот код представляет собой текстовую игру, в которой игрок сражается с врагом, выбирая различные действия, такие как атака или попытка убегания. Игра продолжается до тех пор, пока игрок или враг не потеряют всё здоровье**

**Полный код: [gamecol.cpp](https://github.com/Skipper1231/gamecol/blob/main/gamecol.cpp)**
## Класс персонажа
```
class Character {
protected:
    string name;
    int health;

public:
    Character(const string& name, int health) : name(name), health(health) {}

    // Проверка на живого персонажа
    bool isAlive() const {
        return health > 0;
    }

    // Получение урона
    void takeDamage(int damage) {
        health -= damage;
        if (health < 0)
            health = 0;
    }

    // Получение текущего здоровья
    int getHealth() const {
        return health;
    }

    // Получение имени персонажа
    const string& getName() const {
        return name;
    }
};
```

| Переменная\Функция | Тип данных | Описание |
|-------------|-------------|-------------|
| name   | string   |   переменная отвечает за имя персонажа   |
| health  | int |   переменная отвечает за здоровье персонажа   |
| isAlive()   | bool   |  функция проверяет состояние персонажа (жив/мертв)  |
| takeDamage()   | void   |  функция отвечает за получение урона  |
| damage   | int  |  переменная отвечает за урон  |


## Наследуемый класс игрока от Character
```
class Player : public Character {
public:
    Player(const string& name) : Character(name, 100) {}

    // Метод для атаки врага
    void attack(Character& enemy) {
        int damage = rand() % 21 + 10; // Рандомный урон от 10 до 30
        enemy.takeDamage(damage);
        cout << name << " атакует " << enemy.getName() << " и наносит " << damage << " урона!\n";
    }
};


```
## Класс врага, наследуется от класса Character
```
class Enemy : public Character {
public:
    Enemy() : Character("Враг", 100) {}

    // Метод для атаки игрока
    void attack(Character& player) {
        int damage = rand() % 16 + 5; // Рандомный урон от 5 до 20
        player.takeDamage(damage);
        cout << "Враг атакует " << player.getName() << " и наносит " << damage << " урона!\n";
    }
}
```
## Функция для очистки экрана
```
void clearScreen() {
    cout << string(100, '\n');
}
```
## Функция для вывода текущего здоровья игрока и врага
```
void printHealth(const Player& player, const Enemy& enemy) {
    cout << "Здоровье " << player.getName() << ": " << player.getHealth() << endl;
    cout << "Здоровье " << enemy.getName() << ": " << enemy.getHealth() << endl;
}
```
