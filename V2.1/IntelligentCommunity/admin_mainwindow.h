#ifndef ADMIN_MAINWINDOW_H
#define ADMIN_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class admin_MainWindow;
}

class admin_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin_MainWindow(QWidget *parent = 0);
    ~admin_MainWindow();

private slots:
    void on_action_triggered();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_actionAbout_us_triggered();

    void on_action_5_triggered();

    void on_action_6_triggered();

private:
    Ui::admin_MainWindow *ui;
};

#endif // ADMIN_MAINWINDOW_H
