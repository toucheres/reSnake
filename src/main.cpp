#include "main.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	system("chcp 65001");

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


// QSoundEffect 主要用于播放短音效，通常只支持.wav 格式。
// void loadmusic2() // 载入音乐
//{
//	QSoundEffect music;
//	music.setSource(QUrl::fromLocalFile("qtres/bgmusic.mp3"));
//	music.setLoopCount(QSoundEffect::Infinite);
//	music.play();
//	qDebug() << "Music is playing";
// }
