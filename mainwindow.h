#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void keyPressEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
