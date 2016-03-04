#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QPointF>
#include <QTimer>
#include "header.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    virtual void mousePressEvent(QMouseEvent *event);
    void prepare_fields();
    void add_plant();

private slots:
    void on_menu_quit_triggered();
    void on_menu_New_Game_triggered();
    void on_menu_Random_triggered();
    void on_menu_Clear_Map_triggered();
    void on_start_button_toggled(bool checked);
    void on_stop_button_clicked();
    void play_game();

private:
    void display();
    int creat_number(int x, int y);
    QTimer *timer;
    field_value creat_type();
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
