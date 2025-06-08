# 其他语言  Other languages
- [中文 Chinese](README.zh-CN.md)
- [英文 English](README.md)

我的英语不算太好，所以我使用了AI帮助我编写英文版本的README文件

# 第三方库
本项目使用了Qt库
- 协议：[LGPL-v3](https://www.gnu.org/licenses/lgpl-3.0.html)
- 授权说明：[Qt官方授权说明](https://www.qt.io/licensing)
# 介绍
这个项目是帮助你们游玩“七圣召唤”实体桌游的一个工具；哦，我制作这个项目背后的故事是这样的
## 背景
我的朋友搞来了一套“七圣召唤”的实体桌游；你知道，“七圣召唤”是《原神》中的一个附加游戏，它是在电脑中运行的，实际上，miHoYo官方并没有推出过“七圣召唤”的实体桌游

安装七圣召唤的规则，如果你想要正常地游玩这个桌游，那么你至少需要**16**个**8**面的骰子，这太不方便了；于是我的朋友就让我制作一个小程序，用于模拟“七圣召唤”的骰子

当然，记录角色的血量也不是简单事，或许可以在纸上记录一下，但是还是太麻烦了，所以就顺手把血量记录也给做了
## 功能
### 🎲 骰子相关
- 投骰子：首先，我利用了C++的`random`库来做随机数，用数组来记录结果
- 自动排序骰子：使用了`sort`来排序，让同元素的骰子排在一起
- 使用骰子：将指定编号的骰子使用掉（即设为空值），可以按回车使用，也可以点击使用按钮，使用后会重新排序
- 重投骰子：对指定编号的骰子重投，并重新排序
- 检查编号：有一定的检查编号是否合规的功能
- 开始下一回合：清空所以骰子
### ❤️ 血量记录
- 扣除/恢复血量：输入编号和血量来扣除或恢复血量
- 对于血量扣完的操作：无法恢复血量，且保持血量显示为0而非负数
- 重置血量：将所有血量恢复会10
## 技术实现
利用随机投掷骰子的核心算法：
```cpp
QString str[9] = {"冰", "水", "火", "雷", "岩", "草", "风", "万能", ""};    //空值用于表示没有骰子
for (int i = 0; i <= 7; i++) {
    int randomNum = dis(gen);
    player1[i] = randomNum;    //player1是玩家一的记录，是一个有8个值的int数组
}
std::sort(std::begin(player1), std::end(player1));
ui->player1_1->setText("1: " + str[player1[0]]);
//下面是其他标签的刷新代码
```
使用骰子（设置空值）的核心算法：
```cpp
QString Text = ui->use1->text();
QString str[9] = {"冰", "水", "火", "雷", "岩", "草", "风", "万能", ""};
if (!(Text.toInt() <= 8 && Text.toInt() >= 1)) {    //判断编号是否合法
    ui->Warning1->setText("请输入正确的编号！");
    return;
}
ui->Warning1->setText("");
player1[Text.toInt() - 1] = 8;
std::sort(std::begin(player1), std::end(player1));
ui->use1->setText("");
ui->player1_1->setText("1: " + str[player1[0]]);
//下面是其他标签的刷新代码
```
重投骰子（给数组重新赋值）的核心算法：
```cpp
QString Text = ui->use1->text();
QString str[9] = {"冰", "水", "火", "雷", "岩", "草", "风", "万能", ""};
if (!(Text.toInt() <= 8 && Text.toInt() >= 1)) {
    ui->Warning1->setText("请输入正确的编号！");
    return;
}
ui->Warning1->setText("");
if (player1[Text.toInt() - 1] != 9) {
    int randomNum = dis(gen);
    player1[Text.toInt() - 1] = randomNum;
    std::sort(std::begin(player1), std::end(player1));
    ui->use1->setText("");
} else {
    player1[Text.toInt() - 1] = 9;
}
ui->player1_1->setText("1: " + str[player1[0]]);
//下面是其他标签的刷新代码
```
扣除血量的核心算法：
```cpp
if (ui->cnEdit1->text() == "1") {
    if (ui->p1c1b->text() == "0") {    //保持值为0
        ui->p1c1b->setText("0");
    } else {
    ui->p1c1b->setText(QString::number((ui->p1c1b->text().toInt()) - (ui->bEdit1->text().toInt())));
    if (ui->p1c1b->text().toInt() <= 0) {    //使值非负数
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
恢复血量的核心算法：
```cpp
if (ui->cnEdit1->text() == "1") {
    if (!((ui->p1c1b->text()).toInt() <= 0)) {    //保证已死亡的角色不会被恢复血量
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
# 运行
项目使用`CLion`编写，可以使用CLion打开项目，当然，用`CMake`编译运行更加直接

你需要：
- 确保已安装**Qt5**，并安装了`MinGW`组件
- 确保系统`PATH`包含MinGW的**bin**目录
- 修改`CMakeLists`，将**CMAKE_PREFIX_PATH**的路径指定到你的Qt目录下的`cmake`目录
# 关于我
我来自中国，只是一个还在学习C++的学生，我也在学习其他语言，C++只是我的一个入口；我偶尔做一些小项目练练手

我非常喜欢**miHoYo**（一家位于上海的中国游戏公司）的精神和游戏（虽然我现在没有多少时间玩miHoYo的游戏，但是我依然非常喜欢miHoYo，或者说是喜欢miHoYo这个公司本身吧）；我希望能够成为miHoYo的一员

我的GitHub用户名——没错，这来自日本的动漫《魔女の旅々》（《魔女之旅》）中的角色イレイナ（伊蕾娜，Elaina）——作为一个二次元，我很喜欢她

## 联系我
### 邮箱
- liuyingjiang_QwQ@outlook.com
- ElainaOvO@outlook.com
### 社交平台
- [GitHub](https://github.com/ElainaChan-OvO)
- [bilibili](https://space.bilibili.com/3546591566760474)
