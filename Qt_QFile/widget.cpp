#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QPushButton>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->fileButton, &QPushButton::clicked, [=](){
       QString fullPath = QFileDialog::getOpenFileName(this, QStringLiteral("选择文件"), "C://");
       ui->lineEdit->setText(fullPath);

//       //编码格式类
//       QTextCodec *codec = QTextCodec::codecForName("utf-8");

//       //读取文件内容
//       //QFile默认支持的格式是utf-8
//       QFile file(fullPath);//参数是将要读取的全路径

//       //设置打开方式
//       file.open(QIODevice::ReadOnly);

//       QByteArray array;
//       //array = file.readAll();
//       while(file.atEnd() == false){
//           array += file.readLine();
//       }

//       //将ansi编码的字符串转成Unicode
//       ui->textEdit->setText(codec->toUnicode(array));

//       file.close();

//       file.open(QIODevice::Append);
//       file.write(QStringLiteral("好好好").toUtf8());

//       file.close();

       QFileInfo info(fullPath);
       qDebug() << "size: " << info.size() << "suffix: " << info.suffix() << "fileName: " << info.fileName();
       qDebug() << "create time: " << info.created().toString("yyyy/MM/dd hh:mm:ss");
    });
}

Widget::~Widget()
{
    delete ui;
}
