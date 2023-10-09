#ifndef WORKER_MAINWINDOW_H
#define WORKER_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class worker_MainWindow;
}

class worker_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit worker_MainWindow(QWidget *parent = 0);
    ~worker_MainWindow();

private slots:
    void on_action_triggered();

    void on_actionrenshi_triggered();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_action_6_triggered();

    void on_action_7_triggered();

    void on_action_8_triggered();

    void on_action_9_triggered();

    void on_action_10_triggered();

private:
    Ui::worker_MainWindow *ui;
};

#endif // WORKER_MAINWINDOW_H
