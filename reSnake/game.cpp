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
	ui.btn3->setAutoDefault(false);
	ui.btn3->setDefault(false);
	ui.btn3->setShortcutAutoRepeat(false);
	
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


	logic();
}
void game::paintEvent(QPaintEvent* e)
{
	snake->printSnake();
	snake->checkState();
	//std::cout << snake->body.begin()->x << " " << snake->body.begin()->y << std::endl;
	QPainter* painter = new QPainter(this);
	//载入
	QPixmap* bkg_pixmap = new QPixmap(":/qtres/bg.png");
	

	QPixmap* shesheng_pixmap = new QPixmap(":/shesheng/qtres/shesheng/shesheng.png");

	QPixmap* shetouleft_pixmap = new QPixmap(":/shetou/qtres/shetou/shetouleft.png");
	QPixmap* shetouright_pixmap = new QPixmap(":/shetou/qtres/shetou/shetouright.png");
	QPixmap* shetouup_pixmap = new QPixmap(":/shetou/qtres/shetou/shetouup.png");
	QPixmap* shetoudown_pixmap = new QPixmap(":/shetou/qtres/shetou/shetoudown.png");

	QPixmap* sheweiright_pixmap = new QPixmap(":/shewei/qtres/shewei/sheweileft.png");
	QPixmap* sheweileft_pixmap = new QPixmap(":/shewei/qtres/shewei/sheweiright.png");
	QPixmap* sheweiup_pixmap = new QPixmap(":/shewei/qtres/shewei/sheweidown.png");
	QPixmap* sheweidown_pixmap = new QPixmap(":/shewei/qtres/shewei/sheweiup.png");

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
		**it = (*it)->scaled((58.0/700)*snakemap->xlengthp, (58.0 / 1198) * snakemap->ylengthp, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		
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
		case shewan:
		{
			switch (it->shewanDirection)
			{
				case leftup:
					painter->drawPixmap(px, py, *shewanleftup_pixmap);
					break;
				case rightdown:
					painter->drawPixmap(px, py, *shewanrightdown_pixmap);
					break;
				case leftdown:
					painter->drawPixmap(px, py, *shewanleftdown_pixmap);
					break;
				case rightup:
					painter->drawPixmap(px, py, *shewanrightup_pixmap);
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

void game::keyPressEvent(QKeyEvent* event)
{
	// 普通键
	switch (event->key())
	{
		// ESC键
	case Qt::Key_Escape:
		qDebug() << "ESC";
		break;
	case Qt::Key_Space:
		qDebug() << "Space";
		break;
		// 回车键
	case Qt::Key_Return:
		qDebug() << "Enter";
		break;
		// F1键
	case Qt::Key_F1:
		qDebug() << "F1";
		break;
	case Qt::Key_E:
		qDebug() << "E";
		break;
	case Qt::Key_W:
		if(this->snake->flag_direction_changed==false)
			this->snake->changeDirection(up);
		break;
	case Qt::Key_S:
		if (this->snake->flag_direction_changed == false)
			this->snake->changeDirection(down);
		break;
	case Qt::Key_A:
		if (this->snake->flag_direction_changed == false)
			this->snake->changeDirection(left);
		break;
	case Qt::Key_D:
		if (this->snake->flag_direction_changed == false)
			this->snake->changeDirection(right);
		break;

	}

	// 两键组合
	if (event->modifiers() == Qt::ControlModifier) { // 如果按下了CTRL键
		if (event->key() == Qt::Key_M) {
			qDebug() << "CTRL + M";
		}
	}

	if (event->modifiers() == Qt::AltModifier) { // 如果按下了ALT键
		if (event->key() == Qt::Key_M)
			qDebug() << "ALT + M";
	}

	if (event->modifiers() == Qt::ShiftModifier) { // 如果按下了Shift键
		if (event->key() == Qt::Key_M)
			qDebug() << "Shift + M";
	}

	// 三键组合Shift + Ctrl + A的实现
	if (event->modifiers() == (Qt::ShiftModifier | Qt::ControlModifier) && event->key() == Qt::Key_A) {
		qDebug() << "CTRL + Shift + A";
	}
}

void game::keyReleaseEvent(QKeyEvent* e)
{
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
	this->snake->body.push_back(*new snakeNodeClass((snakemap->xlengthnum / 2)+1,(snakemap->ylengthnum / 2) + 3, up, shesheng));
	this->snake->body.push_back(*new snakeNodeClass((snakemap->xlengthnum / 2)+1,(snakemap->ylengthnum / 2) + 4, up, shesheng));
	this->snake->body.push_back(*new snakeNodeClass((snakemap->xlengthnum / 2)+1,(snakemap->ylengthnum / 2) + 5, up, shewei));
}

void game::logic()
{
	QTimer* timer = new QTimer(this);
	timer->start(1000);
	QTimer* timer1 = new QTimer(this);
	timer1->start(100);
	QTimer* timer2 = new QTimer(this);
	timer2->start(1000);
	//if (this->snake->flag_direction_changed == true)
	//{
	//	snake->move();
	//	std::cout << "changedmove" << std::endl;
	//	this->snake->flag_direction_changed = false;
	//	update();
	//}
	connect(timer, &QTimer::timeout, this, [=]() {
		snake->move();
		update();
		timer->start(this->snake->speed);//转向后500ms移动后设置为正常速度
		});
	connect(timer1, &QTimer::timeout, this, [=]() {
		if (this->snake->flag_direction_changed == true)
		{
			timer->start(this->snake->speed/2);//转向后500ms才开始移动
			snake->move();
			//std::cout << "changedmove" << std::endl;
			this->snake->flag_direction_changed = false;
			update();
		}
		//this->snake->checkState();
		});
	connect(timer2, &QTimer::timeout, this, [=]() {
		//this->snake->checkState();
		});
}


