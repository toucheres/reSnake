#include "main.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	system("chcp 65001");

	reSnake w;
	w.show();
	return a.exec();
}

// void loadmusic()//��������
//{
//	QSoundEffect music;
//	music.setSource(QUrl::fromLocalFile("qtres/bgmusic.mp3"));
//	music.setLoopCount(QSoundEffect::Infinite);
//	music.play();
// }

// QMediaPlayer ��һ����ǿ����֧࣬�ָ������Ƶ��ʽ
//  ������ .mp3)
// qrc��ַ��ʽ����ǰ���qrc:��"qrc:/qtres/bgmusic.mp3"
//!!!!!!ͼƬ����qrc,mp3�ļ���qrc


// QSoundEffect ��Ҫ���ڲ��Ŷ���Ч��ͨ��ֻ֧��.wav ��ʽ��
// void loadmusic2() // ��������
//{
//	QSoundEffect music;
//	music.setSource(QUrl::fromLocalFile("qtres/bgmusic.mp3"));
//	music.setLoopCount(QSoundEffect::Infinite);
//	music.play();
//	qDebug() << "Music is playing";
// }
