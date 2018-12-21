#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qstring.h"
#include <QKeyEvent>
#include <QMouseEvent>

#pragma execution_character_set("utf-8")

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString ip=ui->lineEdit->text();
    QString name=ui->lineEdit_2->text();
    QString udp = ui->lineEdit_3->text();
    QString use=ui->lineEdit_4->text();
    QString pass=ui->lineEdit_5->text();
    int tmp=udp.toInt();
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
    db=QSqlDatabase::addDatabase("QMYSQL");
    /*
     *      QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
    db=QSqlDatabase::addDatabase("QMYSQL");
    在新的qt版本中如果不是用使用上面的一段话会报错。
    另外需要在安装的时候在qt库中加入mysql驱动程序，可以依据自己的系统百度libqsqlmysql.os
*/
    db.setHostName(ip); //数据库服务器地址，我这里使用的是虚拟机建的数据库服务器，实际中可以使用本地数据库服务器地址
    db.setDatabaseName(name);//数据库名称，这里是你数据库服务器中的数据库，一定要自己建一个，别问我怎么知道的
    db.setPort(tmp);//数据库服务器的端口，一般不用写，如果你数据库是在另一个服务器上的话建议写上，因为你服务器端口开放哪个只有自己知道
    db.setUserName(use);//数据库用户名，在数据库中可以自己建一个用户，权限看自己怎么设定
    db.setPassword(pass);//数据库密码，没有密码的话""
    if(db.open())//打开数据库
        ui->statusBar->showMessage("数据库链接成功",3000);
    else
        ui->statusBar->showMessage("数据库链接失败",4000);
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    int x = ui->pushButton->x();
       int y = ui->pushButton->y();
       switch (e->key())
       {
       case Qt::Key_W : ui->pushButton->move(x, y-10); break;
       case Qt::Key_S : ui->pushButton->move(x, y+10); break;
       case Qt::Key_A : ui->pushButton->move(x-10, y); break;
       case Qt::Key_D : ui->pushButton->move(x+10, y); break;
       }
}

void MainWindow::mousePressEvent(QMouseEvent *)
{
    ui->statusBar->showMessage("鼠标动作");
}
