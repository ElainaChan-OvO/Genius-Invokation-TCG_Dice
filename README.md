# Other languages  其他语言
- [Chinese 中文](README.zh-CN.md)
- [English 英文](README.md)

My English isn't particularly good, so I used AI to help me write this README in English.
# Third-Party Libraries
This project utilizes the Qt framework:
- **License**: [LGPL-v3](https://www.gnu.org/licenses/lgpl-3.0.html)
- **Official Licensing Info**: [Qt Licensing](https://www.qt.io/licensing)

# Project Overview
## Genius Invokation TCG Dice Simulator
**Background Story**:  
My friend acquired a physical version of "Genius Invokation TCG" - originally an in-game card game within *Genshin Impact* developed by miHoYo (a Shanghai-based game company). Note that miHoYo has never officially released a physical edition.

Per game rules, playing requires **sixteen 8-sided dice**, making gameplay cumbersome. This tool solves two core problems:
1. **Digital Dice Simulation**: Replaces physical dice requirements
2. **HP Tracking**: Automates character health management

## Key Features
### 🎲 Dice System
- **Dice Roll**: Generates random elements using C++ `<random>` library
- **Auto-Sorting**: Groups same-element dice via `std::sort`
- **Dice Consumption**: Marks selected dice as "empty" and re-sorts
- **Single Reroll**: Re-rolls specific dice while preserving others
- **Turn Reset**: Clears all dice for new rounds
- **Input Validation**: Checks dice index validity

### ❤️ HP Management
- **HP Adjustment**: Modify health via character ID + value input
- **Zero-Lock**: Prevents negative HP (minimum value = 0)
- **HP Reset**: Restores all characters to 10 HP
- **Death Prevention**: Blocks HP recovery for defeated characters

## Technical Implementation
### Core Algorithms
**Dice Initialization**:
```cpp
// Element mapping: Ice, Hydro, Pyro, Electro, Geo, Dendro, Anemo, Omni, Empty
QString elements[9] = {"Ice", "Hydro", "Pyro", "Electro", "Geo", "Dendro", "Anemo", "Omni", ""};  

for (int i = 0; i <= 7; i++) {
    int randomNum = dis(gen); // Random number generation
    player1[i] = randomNum;   // Stores to player1 array
}
std::sort(std::begin(player1), std::end(player1)); // Element grouping
ui->player1_1->setText("1: " + elements[player1[0]]);
// Additional UI update code follows...
```

**Deduct the amount of HP**:
```cpp
if (ui->cnEdit1->text() == "1") {
    if (ui->p1c1b->text() == "0") {    // The hold value is 0
        ui->p1c1b->setText("0");
    } else {
    ui->p1c1b->setText(QString::number((ui->p1c1b->text().toInt()) - (ui->bEdit1->text().toInt())));
    if (ui->p1c1b->text().toInt() <= 0) {    // Make the value non-negative
        ui->p1c1b->setText("0");
    }
}
} else if (ui->cnEdit1->text() == "2") {
    if (ui->p1c2b->text() == "0") {
        ui->p1c2b->setText("0");
    } else {
        ui->p1c2b->setText(QString::number((ui->p1c2b->text().toInt()) - (ui->bEdit1->text().toInt())));
        if (ui->p1c2b->text().toInt() <= 0) {
            ui->p1c2b->setText("0");
        }
    }
} else if (ui->cnEdit1->text() == "3") {
    if (ui->p1c3b->text() == "0") {
        ui->p1c3b->setText("0");
    } else {
        ui->p1c3b->setText(QString::number((ui->p1c3b->text().toInt()) - (ui->bEdit1->text().toInt())));
        if (ui->p1c3b->text().toInt() <= 0) {
            ui->p1c3b->setText("0");
        }
    }
}
ui->bEdit1->setText("");
```

**Restore HP**:
```cpp
if (ui->cnEdit1->text() == "1") {
    if (!((ui->p1c1b->text()).toInt() <= 0)) {    // Ensures that dead characters will not be restored
        ui->p1c1b->setText(QString::number((ui->p1c1b->text().toInt()) + (ui->bEdit1->text().toInt())));
    }
} else if (ui->cnEdit1->text() == "2") {
    if (!((ui->p1c2b->text()).toInt() <= 0)) {
        ui->p1c2b->setText(QString::number((ui->p1c2b->text().toInt()) + (ui->bEdit1->text().toInt())));
    }
} else if (ui->cnEdit1->text() == "3") {
    if (!((ui->p1c3b->text()).toInt() <= 0)) {
        ui->p1c3b->setText(QString::number((ui->p1c3b->text().toInt()) + (ui->bEdit1->text().toInt())));
    }
}
ui->bEdit1->setText("");
```

# Build & Run
**Prerequisites**:
- Qt5 with MinGW components
- MinGW bin directory in system PATH
- Change CMakeLists, Envoy CMAKE_PREFIX_PATH become "your_Qt_path\your_Qt_version\mingw81_64\lib\cmake"

> 💡 CLion users can directly import the project

# About Me
Computer science student from China exploring C++ and other languages. Passionate about miHoYo's game design philosophy and aspiring to join their development team.

**Fun Fact**: My GitHub handle references Elaina from *The Journey of Elaina* anime.

## Contact
- **Email**:
    - liuyingjiang_QwQ@outlook.com
    - ElainaOvO@outlook.com
- **GitHub**: [ElainaChan-OvO](https://github.com/ElainaChan-OvO)
- **Bilibili**: [Channel](https://space.bilibili.com/3546591566760474)
