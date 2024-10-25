#include "game.h"
#include "QPushbutton"
#include<QPainter>
#include<QPaintEvent>
#include<QTimer>
#include<iostream>
#include<list>
#include "snakeEnum.h"
game::game(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//setWindowFlags(Qt::WindowStaysOnTopHint | Qt::MaximizeUsingFullscreenGeometryHint);
	//this->setFixedSize(700, 1198);
	this->snake = new snakeClass;
	this->snakemap = new snakemapClass;
	this->food = new foodClass;
	this->init();
	//setWindowFlags(Qt::WindowStaysOnTopHint);
	this->resize(600, 1027);
	this->move(900, 0);
	//buttons
	connect(ui.btn3, &QPushButton::clicked, this, [=]() {
		emit this->backtopage2();
		});


	//logic( snake);
}
void game::paintEvent(QPaintEvent* e)
{
	std::cout << snake->body.begin()->x << " " << snake->body.begin()->y << std::endl;
	QPainter* painter = new QPainter(this);
	//载入
	QPixmap* bkg_pixmap = new QPixmap(":/qtres/bg.png");
	

	QPixmap* shesheng_pixmap = new QPixmap(":/shesheng/qtres/shesheng/shesheng.png");

	QPixmap* shetouleft_pixmap = new QPixmap(":/shetou/qtres/shetou/shetouleft.png");
	QPixmap* shetouright_pixmap = new QPixmap(":/shetou/qtres/shetou/shetouright.png");
	QPixmap* shetouup_pixmap = new QPixmap(":/shetou/qtres/shetou/shetouup.png");
	QPixmap* shetoudown_pixmap = new QPixmap(":/shetou/qtres/shetou/shetoudown.png");

	QPixmap* sheweileft_pixmap = new QPixmap(":/shewei/qtres/shewei/sheweileft.png");
	QPixmap* sheweiright_pixmap = new QPixmap(":/shewei/qtres/shewei/sheweiright.png");
	QPixmap* sheweidown_pixmap = new QPixmap(":/shewei/qtres/shewei/sheweidown.png");
	QPixmap* sheweiup_pixmap = new QPixmap(":/shewei/qtres/shewei/sheweiup.png");

	QPixmap* shewanleftdown_pixmap = new QPixmap(":/shewan/qtres/shewan/shewanleftdown.png");
	QPixmap* shewanrightup_pixmap = new QPixmap(":/shewan/qtres/shewan/shewanrightup.png");
	QPixmap* shewanleftup_pixmap = new QPixmap(":/shewan/qtres/shewan/shewanleftup.png");
	QPixmap* shewanrightdown_pixmap = new QPixmap(":/shewan/qtres/shewan/shewanrightdown.png");

	std::vector<QPixmap*> pixmaps = {shesheng_pixmap,shetouleft_pixmap,shetouright_pixmap,shetouup_pixmap,shetoudown_pixmap,sheweileft_pixmap,sheweiright_pixmap,sheweidown_pixmap,sheweiup_pixmap,shewanleftdown_pixmap,shewanrightup_pixmap,shewanleftup_pixmap,shewanrightdown_pixmap };
	int tpi = 0;
	for (std::vector<QPixmap*>::iterator it = pixmaps.begin(); it != pixmaps.end(); it++)
	{
		tpi++;
		if (*it != nullptr && !(*it)->isNull()) 
		{
			//**it = (*it)->scaled(100, 100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		}
		else 
		{
			std::cout<< "无效的QPixmap 指针,或图像为空"<< tpi <<std::endl;
		}
	}

	//调整图片大小跟随窗口
	*bkg_pixmap = bkg_pixmap->scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	for (std::vector<QPixmap*>::iterator it = pixmaps.begin(); it != pixmaps.end(); it++)
	{
		**it = (*it)->scaled((57.0/700)*snakemap->xlengthp, (57.0 / 700) * snakemap->xlengthp, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		
	}
	//背景
	painter->drawPixmap(0, 0, *bkg_pixmap);
	//snake
	for (std::list<snakeNodeClass>::iterator it = this->snake->body.begin(); it != this->snake->body.end(); it++)
	{
		int px = snakemap->getpx(it->x);
		int py = snakemap->getpy(it->y);
		switch (it->type)
		{
		case shetou:
		{
			switch (it->direction)
			{
			case left:
				painter->drawPixmap(px, py, *shetouleft_pixmap);
				break;
			case right:
				painter->drawPixmap(px, py, *shetouright_pixmap);
				break;
			case up:
				painter->drawPixmap(px, py, *shetouup_pixmap);
				break;
			case down:
				painter->drawPixmap(px, py, *shetoudown_pixmap);
				break;
			}
			break;
		}
		case shesheng:
		{
			painter->drawPixmap(px, py, *shesheng_pixmap);
			break;
		}
		case shewei:
		{
			switch (it->direction)
			{
			case left:
				painter->drawPixmap(px, py, *sheweileft_pixmap);
				break;
			case right:
				painter->drawPixmap(px, py, *sheweiright_pixmap);
				break;
			case up:
				painter->drawPixmap(px, py, *sheweiup_pixmap);
				break;
			case down:
				painter->drawPixmap(px, py, *sheweidown_pixmap);
				break;
			}
			break;
		}
		}

	}
	painter->end();
	

}

void game::resizeEvent(QResizeEvent*)
{
	std::cout << "resize" << std::endl;
	snakemap->xlengthp = this->width();
	snakemap->ylengthp = this->height();
}

game::~game()
{
	delete snake;

}

void game::init()
{
	std::cout<<"init"<<std::endl;
	//snakeNodeClass newNode(snakemap->getpx((snakemap->xlengthnum / 2) + 1),
	//	snakemap->getpy((snakemap->ylengthnum / 2) + 1),
	//	up,
	//	shetou);
	//this->snake->body.push_back(newNode);

	this->snake->body.push_back(*new snakeNodeClass((snakemap->xlengthnum / 2)+1,(snakemap->ylengthnum / 2) + 1, up, shetou));
	this->snake->body.push_back(*new snakeNodeClass((snakemap->xlengthnum / 2)+1,(snakemap->ylengthnum / 2) + 2, up, shesheng));
	this->snake->body.push_back(*new snakeNodeClass((snakemap->xlengthnum / 2)+1,(snakemap->ylengthnum / 2) + 3, up, shewei));


}

void game::logic()
{

	QTimer* timer = new QTimer(this);
	timer->start(1000);
	connect(timer, &QTimer::timeout, this, [=]() {
		//
		});

}


