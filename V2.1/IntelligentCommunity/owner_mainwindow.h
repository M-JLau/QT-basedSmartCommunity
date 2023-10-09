#ifndef OWNER_MAINWINDOW_H
#define OWNER_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class Owner_MainWindow;
}

class Owner_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Owner_MainWindow(QWidget *parent = 0);
    ~Owner_MainWindow();

private slots:
    void on_action_3_triggered();

    void on_action_2_triggered();

    void on_action_4_triggered();

    void on_action_triggered();

    void on_action_5_triggered();

private:
    Ui::Owner_MainWindow *ui;
};

#endif // OWNER_MAINWINDOW_H
