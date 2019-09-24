#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionnew, &QAction::triggered, [=](){
        //模式对话框
//        QDialog dialog(this);
//        dialog.resize(300, 150);
//        dialog.exec();//代码在此阻塞，进入消息处理循环

        //非模态对话框
//        QDialog *dialog = new QDialog(this);
//        dialog->resize(300, 150);
//        dialog->setAttribute(Qt::WA_DeleteOnClose);
//        dialog->show();

        //消息对话框
//        QMessageBox::StandardButton btn = QMessageBox::information(this,"title","text",(QMessageBox::Yes|QMessageBox::Abort|QMessageBox::Save),QMessageBox::Abort);
//        if(btn == QMessageBox::Abort){
//            qDebug() << "Abort";
//        }


        //颜色对话框
        //QColorDialog::getColor(Qt::white, this, "title");
//        QColorDialog *colorDlg = new QColorDialog(QColor(), this);
//        colorDlg->setAttribute(Qt::WA_DeleteOnClose);
//        colorDlg->setWindowTitle(QStringLiteral("标题"));
//        colorDlg->setWindowIcon(QIcon("images/adlist_icon_mycenter_sed2x.png"));

//        connect(colorDlg, &QColorDialog::colorSelected, [=](const QColor &color)
//        {
//            qDebug() << color.red() << "  " << color.green() << "  " << color.blue();
//        });
//        colorDlg->exec();

//        //文件对话框
//        QString filepath = QFileDialog::getOpenFileName(this, "caption", "c:\\");
//        qDebug() << filepath ;

        //字体对话框
        bool ok;
        QFontDialog::getFont(&ok, QFont("宋体", 24), this, "title");
        qDebug() << ok ;

    });


}

MainWindow::~MainWindow()
{
    delete ui;
}
