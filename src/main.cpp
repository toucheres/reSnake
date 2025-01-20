#include "main.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	system("chcp 65001");
	loadmusic(); // 确保在 QApplication 初始化后调用
	reSnake w;
	w.show();
	return a.exec();
}
// void loadmusic()//载入音乐
//{
//	QSoundEffect music;
//	music.setSource(QUrl::fromLocalFile("qtres/bgmusic.mp3"));
//	music.setLoopCount(QSoundEffect::Infinite);
//	music.play();
// }

// QMediaPlayer 是一个更强大的类，支持更多的音频格式
//  （包括 .mp3)
// qrc地址格式：（前面加qrc:）"qrc:/qtres/bgmusic.mp3"
//!!!!!!图片不加qrc,mp3文件加qrc
void loadmusic() // 载入音乐
{
	QMediaPlayer *player = new QMediaPlayer;
	QAudioOutput *audioOutput = new QAudioOutput;
	player->setAudioOutput(audioOutput);
	player->setSource(QUrl("qrc:/qtres/bgmusic.mp3"));
	audioOutput->setVolume(50);				  // 设置音量
	player->setLoops(QMediaPlayer::Infinite); // 设置循环播放
	player->play();
	qDebug() << "Music is playing";
	qDebug() << QString("测试"); // 先将常量字符串转换为 QString，再调用 toUtf8
}

// QSoundEffect 主要用于播放短音效，通常只支持.wav 格式。
// void loadmusic2() // 载入音乐
//{
//	QSoundEffect music;
//	music.setSource(QUrl::fromLocalFile("qtres/bgmusic.mp3"));
//	music.setLoopCount(QSoundEffect::Infinite);
//	music.play();
//	qDebug() << "Music is playing";
// }
