#include "widget.h"
#include "ui_widget.h"

#include <QLabel>
#include <QPixmap>
#include <QProgressBar>
#include <QPushButton>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    createListWidgetItem("123.jpg");
    createListWidgetItem("456.jpg");
    createListWidgetItem("123.jpg");
    createListWidgetItem("456.jpg");
    createListWidgetItem("123.jpg");
    createListWidgetItem("456.jpg");
}

Widget::~Widget()
{
    delete ui;
}

//创建自定义的item
void Widget::createListWidgetItem(QString filename)
{
    QWidget *itemWidget = new QWidget(ui->listWidget);
    itemWidget->setStyleSheet("background:transparent;");

    //创建自定义的item
    QLabel *fileTypeLabel = new QLabel(itemWidget);//下载文件类型标签
    QPixmap myPix(":/img/chooseCoin.png");
    fileTypeLabel->setFixedSize(62, 32);
    fileTypeLabel->setPixmap(myPix);
    fileTypeLabel->setScaledContents(true);
    fileTypeLabel->setStyleSheet("QLabel{padding-left:15px;padding-right:15px;}");

    QWidget *widgetOfFileNameLabelAndFileSizePercentLabel = new QWidget(itemWidget);//下载文件名标签和文件下载占比标签的父窗口
    widgetOfFileNameLabelAndFileSizePercentLabel->setFixedHeight(32);

    QLabel *fileNameLabel = new QLabel(widgetOfFileNameLabelAndFileSizePercentLabel);//下载文件名标签
    fileNameLabel->setText(filename);

    QLabel *fileSizePercentLabel = new QLabel(widgetOfFileNameLabelAndFileSizePercentLabel);//文件下载占比标签
    fileSizePercentLabel->setText("0 KB/0 KB");

    QWidget *widgetOfProgressBarAndSpeedLabel = new QWidget(itemWidget);//进度条和网速标签的父窗口
    widgetOfProgressBarAndSpeedLabel->setFixedSize(158, 32);

    QProgressBar *progressBar = new QProgressBar(widgetOfProgressBarAndSpeedLabel);//下载进度条
    progressBar->setTextVisible(true);
    progressBar->setMinimum(0);
    progressBar->setMaximum(100);
    progressBar->setValue(60);
    progressBar->setFixedHeight(12);
    progressBar->setStyleSheet("QProgressBar{ border:none; background:rgb(230, 230, 230); border-radius:0px; text-align:center; color:gray }\
                            QProgressBar::chunk{ background:rgb(71, 137, 250); border-radius:0px; }");

    QLabel *speedLabel = new QLabel(widgetOfProgressBarAndSpeedLabel);//网速标签
    speedLabel->setText("0 B/s");

    QPushButton *openFolderButton = new QPushButton(itemWidget);//打开文件夹按钮
    openFolderButton->setToolTip(QStringLiteral("打开文件夹"));
    openFolderButton->setFixedSize(82, 32);
    QIcon icon3(":/img/default_head.png");
    openFolderButton->setIcon(icon3);
    openFolderButton->setIconSize(QSize(24, 24));
    openFolderButton->setProperty("index", QString::number(99));
    openFolderButton->setStyleSheet("QPushButton{ margin-left:25px;margin-right:25px;border:none; color:white; background:none; }QPushButton:hover{color:#FFFFFF; background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 0% ), stop:1 rgba(200, 200, 200, 60% )); }\
                                                                QPushButton:pressed{ color:white; background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 0% ), stop:1 rgba(200, 200, 200, 80% )); }");
    connect(openFolderButton, SIGNAL(clicked()), this, SLOT(OpenFolder()));

    QLabel *tipIconLabel = new QLabel(itemWidget);
    QPixmap myPix2(":/img/start.png");
    tipIconLabel->setFixedSize(25, 20);
    tipIconLabel->setPixmap(myPix2);
    tipIconLabel->setScaledContents(true);
    tipIconLabel->setStyleSheet("QLabel{padding-left:0px;padding-right:5px;}");

    QLabel *tipTextLabel = new QLabel(itemWidget);
    tipTextLabel->setText(QStringLiteral("等待中"));
    tipTextLabel->setStyleSheet("QLabel{padding-left:0px;padding-right:0px;}");
    tipTextLabel->setFixedWidth(55);

    QPushButton *closeButton = new QPushButton(itemWidget);
    closeButton->setToolTip(QStringLiteral("取消下载"));
    closeButton->setFixedSize(34, 24);
    QIcon icon4(":/img/shanchu@3x.png");
    closeButton->setIcon(icon4);
    closeButton->setIconSize(QSize(12, 12));
    closeButton->setProperty("index", QString::number(99));
    closeButton->setStyleSheet("QPushButton{ margin-left:0px;margin-right:10px;border:none; color:white; background:none; }QPushButton:hover{color:#FFFFFF; background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 0% ), stop:1 rgba(200, 200, 200, 60% )); }\
                            QPushButton:pressed{ color:white; background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 0% ), stop:1 rgba(200, 200, 200, 80% )); }");
    connect(closeButton, SIGNAL(clicked()), this, SLOT(HideItem()));

    QVBoxLayout *verLayout = new QVBoxLayout;
    verLayout->setContentsMargins(0, 0, 0, 0);
    verLayout->setMargin(0);
    verLayout->setSpacing(0);
    verLayout->addWidget(fileNameLabel);
    verLayout->addWidget(fileSizePercentLabel);
    widgetOfFileNameLabelAndFileSizePercentLabel->setLayout(verLayout);

    QVBoxLayout *verLayout2 = new QVBoxLayout;
    verLayout2->setContentsMargins(0, 0, 0, 0);
    verLayout2->setMargin(0);
    verLayout2->setSpacing(0);
    verLayout2->addWidget(progressBar);
    verLayout2->addWidget(speedLabel);
    widgetOfProgressBarAndSpeedLabel->setLayout(verLayout2);

    QHBoxLayout *horLayout = new QHBoxLayout;
    horLayout->setContentsMargins(0, 0, 0, 0);
    horLayout->setMargin(0);
    horLayout->setSpacing(0);
    horLayout->addWidget(fileTypeLabel);
    horLayout->addWidget(widgetOfFileNameLabelAndFileSizePercentLabel);
    horLayout->addWidget(widgetOfProgressBarAndSpeedLabel);
    horLayout->addWidget(openFolderButton);
    horLayout->addWidget(tipIconLabel);
    horLayout->addWidget(tipTextLabel);
    horLayout->addWidget(closeButton);
    itemWidget->setLayout(horLayout);

    //将widget作为列表的item
    QListWidgetItem *ITEM = new QListWidgetItem();
    QSize size = ITEM->sizeHint();
    ITEM->setSizeHint(QSize(size.width(), 56));
    ui->listWidget->addItem(ITEM);
    itemWidget->setSizeIncrement(size.width(), 56);
    ui->listWidget->setItemWidget(ITEM, itemWidget);

}
