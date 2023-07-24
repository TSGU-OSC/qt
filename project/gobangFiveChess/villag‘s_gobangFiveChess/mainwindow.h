#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"gamemodel.h"


QT_BEGIN_NAMESPACE
namespace ui{class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



protected:
    void paintEvent(QPaintEvent *event);


    void mouseMoveEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);



private:
    gamemodel *game;
    GameType game_type;
    int clickPosRow,clickPosCol;
    void initGame();
    void checkGame(int y,int x);



private slots:
    void chessOneByPerson();
    void chessOneByAi();
    void initPVPGame();
    void initPVCGame();
};

#endif // MAINWINDOW_H
