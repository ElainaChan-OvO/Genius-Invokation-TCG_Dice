#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QMainWindow {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow() override;

private slots:
    void on_player1_begin_clicked();
    void on_player2_begin_clicked();
    void on_clearButton_clicked();
    void on_useButton1_clicked();
    void on_useButton2_clicked();
    void on_RebootButton1_clicked();
    void on_RebootButton2_clicked();
    void on_p1bplus_clicked();
    void on_p2bplus_clicked();
    void on_p1bminus_clicked();
    void on_p2bminus_clicked();
    void on_resetButton_clicked();
    void ResetUI();
    void Updateplayer1UI();
    void Updateplayer2UI();

private:
    Ui::mainwindow *ui;
};


#endif //MAINWINDOW_H
