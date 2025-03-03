#include "reSnake.h"
#include "game.h"
//#include<QPushbutton>
#include"select.h"
#include"mypushbutton.h"
#include<iostream>
#include<QTimer>
#include<QTime>
#include<QPainter>
#include<QPaintEvent>
#include<QApplication>
//#include<QtGUI>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <qsoundeffect.h>
reSnake::reSnake(QWidget *parent)
    : QMainWindow (parent)
{
    ui.setupUi(this);
    loadmusic();
    //setWindowFlags(Qt::WindowStaysOnTopHint|Qt::MaximizeUsingFullscreenGeometryHint);
    //setWindowFlags(Qt::WindowStaysOnTopHint);
    this->resize(600, 1027);
    this->move(900,0);
    this->ppage2 = new selectpage(this);
    //按钮
    //std::cout<< "anxia";
    mypushbutton* text = new mypushbutton(QString(":/setting/qtres/setting/pause.png"),this);
    text->setParent(this);
    text->move((this->width()-text->width())/2,this->height()/2);
    connect(text, &mypushbutton::released, this, [=]() 
        {
        connect(tptime, &QTimer::timeout, this, &reSnake::gotopage2);
        connect(tptime, &QTimer::timeout, tptime ,&QTimer::stop);//点击后暂停
        tptime->start(200);
        });

    //接受page2的gotopage1信号
    connect(this->ppage2, &selectpage::backtopage1, this, &reSnake::gotopage1);

}

reSnake::~reSnake()
{
    delete ppage2;
}

void reSnake::paintEvent(QPaintEvent* e)
{
    QPainter* painter = new QPainter(this);
    QPixmap* bkg_pixmap = new QPixmap(":/qtres/bg.png");
    *bkg_pixmap = bkg_pixmap->scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter->drawPixmap(0, 0, *bkg_pixmap);
    painter->end();
    delete painter;
    delete bkg_pixmap;
}

void reSnake::resizeEvent(QResizeEvent*)
{
    std::cout << "resize" << std::endl;
    QList<mypushbutton*>mypushbuttons = this->findChildren<mypushbutton*>();
    for (mypushbutton* button : mypushbuttons)
    {
        button->move((this->width()-button->width())/2,this->height()/2);
    }

}

void reSnake::gotopage2()
{
    this->ppage2->show();//子界面出现
    QTime dieTime = QTime::currentTime().addMSecs(200);//5为延迟时间，可更改
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->hide();//主界面关闭
}
void reSnake::gotopage1()
{
    this->show();
    QTime dieTime = QTime::currentTime().addMSecs(5);//5为延迟时间，可更改
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->ppage2->hide();
}

void reSnake::loadmusic() // 载入音乐
{
    // WARNING!!!
    // wsl2下没有声卡，暂不支持于原生wsl2中的音频输出，可以通过PulseAudio解决
    // 参见https://blog.sandtears.com/2020/02/27/wsl-gui-audio-support.html#%E9%9F%B3%E9%A2%91%E6%94%AF%E6%8C%81
    QMediaPlayer *player = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);
    qDebug() << player->isAvailable();
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/qtres/bgmusic.mp3"));
    audioOutput->setVolume(50);               // 设置音量
    player->setLoops(QMediaPlayer::Infinite); // 设置循环播放
    player->play();
    qDebug() << QString("test"); // 先将常量字符串转换为 QString，再调用 toUtf8
}

// void reSnake::loadmusic() // 载入音乐
// {
//     // 尝试使用QMediaPlayer (首选方法)
//     QMediaPlayer *player = new QMediaPlayer(this);
//     QAudioOutput *audioOutput = new QAudioOutput(this);

//     bool playerAvailable = player->isAvailable();
//     qDebug() << "QMediaPlayer available:" << playerAvailable;

//     if (playerAvailable)
//     {
//         player->setAudioOutput(audioOutput);
//         player->setSource(QUrl("qrc:/qtres/bgmusic.mp3"));
//         audioOutput->setVolume(50);               // 设置音量
//         player->setLoops(QMediaPlayer::Infinite); // 设置循环播放

//         // 监听错误
//         connect(player, &QMediaPlayer::errorOccurred,
//                 [=](QMediaPlayer::Error error, const QString &errorString)
//                 {
//                     qDebug() << "Media player error:" << error << errorString;
//                     // 出错时可以尝试备用方案
//                 });

//         player->play();
//         qDebug() << "Music is playing with QMediaPlayer";
//     }
//     else
//     {
//         // 备用方案：使用QSoundEffect (仅支持WAV格式)
//         qDebug() << "Falling back to QSoundEffect";

//         // 注意：QSoundEffect只支持WAV格式
//         // 如果需要播放MP3，需要将资源转换为WAV格式
//         QSoundEffect *effect = new QSoundEffect(this);
//         // 假设您也有WAV格式的音乐
//         effect->setSource(QUrl("qrc:/qtres/bgmusic.wav"));
//         effect->setLoopCount(QSoundEffect::Infinite);
//         effect->setVolume(0.5);
//         effect->play();
//     }
// }