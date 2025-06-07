#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0, 7);
int player1[8];
int player2[8];

mainwindow::mainwindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);
    ui->player1_1->setText("");
    ui->player1_2->setText("");
    ui->player1_3->setText("");
    ui->player1_4->setText("");
    ui->player1_5->setText("");
    ui->player1_6->setText("");
    ui->player1_7->setText("");
    ui->player1_8->setText("");
    ui->player2_1->setText("");
    ui->player2_2->setText("");
    ui->player2_3->setText("");
    ui->player2_4->setText("");
    ui->player2_5->setText("");
    ui->player2_6->setText("");
    ui->player2_7->setText("");
    ui->player2_8->setText("");
    ui->Warning1->setText("");
    ui->Warning2->setText("");
    ui->p1c1b->setText("10");
    ui->p1c2b->setText("10");
    ui->p1c3b->setText("10");
    ui->p2c1b->setText("10");
    ui->p2c2b->setText("10");
    ui->p2c3b->setText("10");
    connect(ui->use1,SIGNAL(returnPressed()), this,SLOT(on_useButton1_clicked()));
    connect(ui->use2,SIGNAL(returnPressed()), this,SLOT(on_useButton2_clicked()));
}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::on_player1_begin_clicked() {
    QString str[9] = {"冰", "水", "火", "雷", "岩", "草", "风", "万能", ""};
    for (int i = 0; i <= 7; i++) {
        int randomNum = dis(gen);
        player1[i] = randomNum;
    }
    std::sort(std::begin(player1), std::end(player1));
    ui->player1_1->setText("1: " + str[player1[0]]);
    ui->player1_2->setText("2: " + str[player1[1]]);
    ui->player1_3->setText("3: " + str[player1[2]]);
    ui->player1_4->setText("4: " + str[player1[3]]);
    ui->player1_5->setText("5: " + str[player1[4]]);
    ui->player1_6->setText("6: " + str[player1[5]]);
    ui->player1_7->setText("7: " + str[player1[6]]);
    ui->player1_8->setText("8: " + str[player1[7]]);
}

void mainwindow::on_player2_begin_clicked() {
    QString str[9] = {"冰", "水", "火", "雷", "岩", "草", "风", "万能", ""};
    for (int i = 0; i <= 7; i++) {
        int randomNum = dis(gen);
        player2[i] = randomNum;
    }
    std::sort(std::begin(player2), std::end(player2));
    ui->player2_1->setText("1: " + str[player2[0]]);
    ui->player2_2->setText("2: " + str[player2[1]]);
    ui->player2_3->setText("3: " + str[player2[2]]);
    ui->player2_4->setText("4: " + str[player2[3]]);
    ui->player2_5->setText("5: " + str[player2[4]]);
    ui->player2_6->setText("6: " + str[player2[5]]);
    ui->player2_7->setText("7: " + str[player2[6]]);
    ui->player2_8->setText("8: " + str[player2[7]]);
}

void mainwindow::on_clearButton_clicked() {
    ui->player1_1->setText("");
    ui->player1_2->setText("");
    ui->player1_3->setText("");
    ui->player1_4->setText("");
    ui->player1_5->setText("");
    ui->player1_6->setText("");
    ui->player1_7->setText("");
    ui->player1_8->setText("");
    ui->player2_1->setText("");
    ui->player2_2->setText("");
    ui->player2_3->setText("");
    ui->player2_4->setText("");
    ui->player2_5->setText("");
    ui->player2_6->setText("");
    ui->player2_7->setText("");
    ui->player2_8->setText("");
}

void mainwindow::on_useButton1_clicked() {
    QString Text = ui->use1->text();
    QString str[9] = {"冰", "水", "火", "雷", "岩", "草", "风", "万能", ""};
    if (!(Text.toInt() <= 8 && Text.toInt() >= 1)) {
        ui->Warning1->setText("请输入正确的编号！");
        return;
    }
    ui->Warning1->setText("");
    player1[Text.toInt() - 1] = 8;
    std::sort(std::begin(player1), std::end(player1));
    ui->use1->setText("");
    ui->player1_1->setText("1: " + str[player1[0]]);
    ui->player1_2->setText("2: " + str[player1[1]]);
    ui->player1_3->setText("3: " + str[player1[2]]);
    ui->player1_4->setText("4: " + str[player1[3]]);
    ui->player1_5->setText("5: " + str[player1[4]]);
    ui->player1_6->setText("6: " + str[player1[5]]);
    ui->player1_7->setText("7: " + str[player1[6]]);
    ui->player1_8->setText("8: " + str[player1[7]]);
}

void mainwindow::on_useButton2_clicked() {
    QString Text = ui->use2->text();
    QString str[9] = {"冰", "水", "火", "雷", "岩", "草", "风", "万能", ""};
    if (!(Text.toInt() <= 8 && Text.toInt() >= 1)) {
        ui->Warning2->setText("请输入正确的编号！");
        return;
    }
    ui->Warning2->setText("");
    player2[Text.toInt() - 1] = 8;
    std::sort(std::begin(player2), std::end(player2));
    ui->use2->setText("");
    ui->player2_1->setText("1: " + str[player2[0]]);
    ui->player2_2->setText("2: " + str[player2[1]]);
    ui->player2_3->setText("3: " + str[player2[2]]);
    ui->player2_4->setText("4: " + str[player2[3]]);
    ui->player2_5->setText("5: " + str[player2[4]]);
    ui->player2_6->setText("6: " + str[player2[5]]);
    ui->player2_7->setText("7: " + str[player2[6]]);
    ui->player2_8->setText("8: " + str[player2[7]]);
}

void mainwindow::on_RebootButton1_clicked() {
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
    ui->player1_2->setText("2: " + str[player1[1]]);
    ui->player1_3->setText("3: " + str[player1[2]]);
    ui->player1_4->setText("4: " + str[player1[3]]);
    ui->player1_5->setText("5: " + str[player1[4]]);
    ui->player1_6->setText("6: " + str[player1[5]]);
    ui->player1_7->setText("7: " + str[player1[6]]);
    ui->player1_8->setText("8: " + str[player1[7]]);
}

void mainwindow::on_RebootButton2_clicked() {
    QString Text = ui->use2->text();
    QString str[9] = {"冰", "水", "火", "雷", "岩", "草", "风", "万能", ""};
    if (!(Text.toInt() <= 8 && Text.toInt() >= 1)) {
        ui->Warning2->setText("请输入正确的编号！");
        return;
    }
    ui->Warning2->setText("");
    if (player2[Text.toInt() - 1] != 9) {
        int randomNum = dis(gen);
        player2[Text.toInt() - 1] = randomNum;
        std::sort(std::begin(player2), std::end(player2));
        ui->use2->setText("");
    } else {
        player2[Text.toInt() - 1] = 9;
    }
    ui->player2_1->setText("1: " + str[player2[0]]);
    ui->player2_2->setText("2: " + str[player2[1]]);
    ui->player2_3->setText("3: " + str[player2[2]]);
    ui->player2_4->setText("4: " + str[player2[3]]);
    ui->player2_5->setText("5: " + str[player2[4]]);
    ui->player2_6->setText("6: " + str[player2[5]]);
    ui->player2_7->setText("7: " + str[player2[6]]);
    ui->player2_8->setText("8: " + str[player2[7]]);
}

void mainwindow::on_p1bminus_clicked() {
    if (ui->cnEdit1->text() == "1") {
        if (ui->p1c1b->text() == "0") {
            ui->p1c1b->setText("0");
        } else {
            ui->p1c1b->setText(QString::number((ui->p1c1b->text().toInt()) - (ui->bEdit1->text().toInt())));
            if (ui->p1c1b->text().toInt() <= 0) {
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
}

void mainwindow::on_p2bminus_clicked() {
    if (ui->cnEdit2->text() == "1") {
        if (ui->p2c1b->text() == "0") {
            ui->p2c1b->setText("0");
        } else {
            ui->p2c1b->setText(QString::number((ui->p2c1b->text().toInt()) - (ui->bEdit2->text().toInt())));
            if (ui->p2c1b->text().toInt() <= 0) {
                ui->p2c1b->setText("0");
            }
        }
    } else if (ui->cnEdit2->text() == "2") {
        if (ui->p2c2b->text() == "0") {
            ui->p2c2b->setText("0");
        } else {
            ui->p2c2b->setText(QString::number((ui->p2c2b->text().toInt()) - (ui->bEdit2->text().toInt())));
            if (ui->p2c2b->text().toInt() <= 0) {
                ui->p2c2b->setText("0");
            }
        }
    } else if (ui->cnEdit2->text() == "3") {
        if (ui->p2c3b->text() == "0") {
            ui->p2c3b->setText("0");
        } else {
            ui->p2c3b->setText(QString::number((ui->p2c3b->text().toInt()) - (ui->bEdit2->text().toInt())));
            if (ui->p2c3b->text().toInt() <= 0) {
                ui->p2c3b->setText("0");
            }
        }
    }
    ui->bEdit2->setText("");
}

void mainwindow::on_p1bplus_clicked() {
    if (ui->cnEdit1->text() == "1") {
        if (!((ui->p1c1b->text()).toInt() <= 0)) {
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
}

void mainwindow::on_p2bplus_clicked() {
    if (ui->cnEdit2->text() == "1") {
        if (!((ui->p2c1b->text()).toInt() <= 0)) {
            ui->p2c1b->setText(QString::number((ui->p2c1b->text().toInt()) + (ui->bEdit2->text().toInt())));
        }
    } else if (ui->cnEdit2->text() == "2") {
        if (!((ui->p2c2b->text()).toInt() <= 0)) {
            ui->p2c2b->setText(QString::number((ui->p2c2b->text().toInt()) + (ui->bEdit2->text().toInt())));
        }
    } else if (ui->cnEdit2->text() == "3") {
        if (!((ui->p2c3b->text()).toInt() <= 0)) {
            ui->p2c3b->setText(QString::number((ui->p2c3b->text().toInt()) + (ui->bEdit2->text().toInt())));
        }
    }
    ui->bEdit2->setText("");
}

void mainwindow::on_resetButton_clicked() {
    ui->p1c1b->setText("10");
    ui->p1c2b->setText("10");
    ui->p1c3b->setText("10");
    ui->p2c1b->setText("10");
    ui->p2c2b->setText("10");
    ui->p2c3b->setText("10");
    ui->cnEdit1->setText("");
    ui->cnEdit2->setText("");
    ui->bEdit1->setText("");
    ui->bEdit2->setText("");
}
