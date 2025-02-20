#include "game.h"
#include "QPushbutton"
#include<QPainter>
#include<QPaintEvent>
#include<QTimer>
#include<iostream>
#include<list>
#include "snakeEnum.h"
#include "select.h"

game::game(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->initpixmap();
	//ui.btn3->setAutoDefault(false);
	//ui.btn3->setDefault(false);
	//ui.btn3->setShortcutAutoRepeat(false);
	
	//setWindowFlags(Qt::WindowStaysOnTopHint | Qt::MaximizeUsingFullscreenGeometryHint);
	//this->setFixedSize(700, 1198);
	this->snake = new snakeClass;
	this->snakemap = new snakemapClass(snake);
	this->food = new foodClass(snake);
	//this->init();
	//setWindowFlags(Qt::WindowStaysOnTopHint);
	this->resize(600, 1027);
	this->move(900, 0);
	// buttons
	// connect(ui.btn3, &QPushButton::clicked, this, [=]() {
	//	emit this->backtopage2();
	//	});
	connect(this->snake, &snakeClass::stateChange, this, [=]()
			{ 
				// this->repaint();//崩溃
			});

	logic();
}

void game::paintEvent(QPaintEvent* e)
{
    snake->checkState();
	std::unique_ptr<QPainter> painter = std::make_unique<QPainter>(this);
	painter->drawPixmap(0, 0, *pixmaps[14]);
	for (std::deque<snakeNodeClass>::iterator it = this->snake->body.begin(); it != this->snake->body.end(); it++) {
        int px = snakemap->getpx(it->x);
        int py = snakemap->getpy(it->y);
        switch (it->type) {
        case shetou:
            switch (it->direction) {
            case left:
                painter->drawPixmap(px, py, *pixmaps[pixmapIndex::shetouleft_pixmap]);
                break;
            case right:
                painter->drawPixmap(px, py, *pixmaps[pixmapIndex::shetouright_pixmap]);
                break;
            case up:
				painter->drawPixmap(px, py, *pixmaps [pixmapIndex::shetouup_pixmap]);
				break;
            case down:
                painter->drawPixmap(px, py, *pixmaps[pixmapIndex::shetoudown_pixmap]);
                break;
            }
            break;
        case shesheng:
			painter->drawPixmap(px, py, *pixmaps [pixmapIndex::shesheng_pixmap]);
			break;
        case shewei:
            switch (it->direction) {
            case left:
				painter->drawPixmap(px, py, *pixmaps [pixmapIndex::sheweileft_pixmap]);
				break;
            case right:
				painter->drawPixmap(px, py, *pixmaps[pixmapIndex::sheweiright_pixmap]);
				break;
            case up:
				painter->drawPixmap(px, py, *pixmaps [pixmapIndex::sheweiup_pixmap]);
				break;
            case down:
				painter->drawPixmap(px, py, *pixmaps[pixmapIndex::sheweidown_pixmap]);
				break;
            }
            break;
        case shewan:
            switch (it->shewanDirection) {
            case leftup:
				painter->drawPixmap(px, py, *pixmaps [pixmapIndex::shewanleftup_pixmap]);
				break;
            case rightdown:
				painter->drawPixmap(px, py, *pixmaps[pixmapIndex::shewanrightdown_pixmap]);
				break;
            case leftdown:
				painter->drawPixmap(px, py, *pixmaps [pixmapIndex::shewanleftdown_pixmap]);
				break;
            case rightup:
				painter->drawPixmap(px, py, *pixmaps [pixmapIndex::shewanrightup_pixmap]);
				break;
            }
            break;
        }
    }

    for (std::vector<int>::iterator it = this->food->foodLocation.begin(); it != this->food->foodLocation.end(); it++) {
        int x = *it % (int)(this->snakemap->xlengthnum);
        int y = 1 + *it / (int)(this->snakemap->xlengthnum);
        int px = snakemap->getpx(x - 0.3);
        int py = snakemap->getpx(y - 0.8);
        painter->drawPixmap(px, py, *pixmaps[13]);
    }

    snake->checkState();
    painter->end();
}

void game::resizeEvent(QResizeEvent*)
{
	std::cout << "resize" << std::endl;
	snakemap->xlengthp = this->width();
	snakemap->ylengthp = this->height();
	for (int i = 0; i < 14; i++)
	{

		*pixmaps[i] = pixmaps[i]->scaled(((PX_OF_LATTICE + 1) / PX_OF_WIDTH_OF_MAP) * snakemap->xlengthp,
										 ((PX_OF_LATTICE + 1) / PX_OF_LENGTH_OF_MAP) * snakemap->ylengthp,
										 Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	}
	*pixmaps[14] = pixmaps[14]->scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}

void game::keyPressEvent(QKeyEvent* event)
{
	// 普通键
	switch (event->key())
	{
		// ESC键
	case Qt::Key_Escape:
		//返回page2
		emit this->backtopage2();
		break;
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
	case Qt::Key_B:
			qDebug() << "B";
			this->snake->getLonger();
		break;
	case Qt::Key_N:
		qDebug() << "N";
		this->snake->getShorter();
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

void game::isover()
{
	int limitx = 0;
	int limity = 0;
	if (this->snakewidth == 1 || this->snakewidth == 2 || this->snakewidth == 0.5)
	{
		limitx = snakemap->xlengthnum;
		limity = snakemap->ylengthnum;
	}
	else
	{
		limitx = snakemap->xlengthnum + 1;
		limity = snakemap->ylengthnum + 1;
	}
	if (this->snake->body.front().x <= 0 || this->snake->body.front().x > limitx || this->snake->body.front().y <= 0 || this->snake->body.front().y > limity)
	{
		this->snake->live = dead;
		std::cout << "game over" << std::endl;
		this->backtopage2();
	}
	
	
}

void game::closeEvent(QCloseEvent* event)
{
	this->backtopage2();
}

game::~game()
{
	delete snake;
	delete food;
	delete snakemap;

}

void game::init(int tspeed,int tlength,double twight)
{
	std::cout<<"init"<<std::endl;
	//snakeNodeClass newNode(snakemap->getpx((snakemap->xlengthnum / 2) + 1),
	//	snakemap->getpy((snakemap->ylengthnum / 2) + 1),
	//	up,
	//	shetou);
	//this->snake->body.push_back(newNode);
	this->snakewidth=twight;
	this->snakemap->snakewidth=twight;


	this->snake->speed = tspeed;
	this->snake->body.emplace_back((snakemap->xlengthnum / 2)+1,(snakemap->ylengthnum / 2) + 1, up, shetou);
	int i = 0;
	for (i = 0; i < tlength - 2; i++)
	{
		this->snake->body.emplace_back((snakemap->xlengthnum / 2) + 1, (snakemap->ylengthnum / 2) + i +2, up, shesheng);
	}
	this->snake->body.emplace_back((snakemap->xlengthnum / 2)+1,(snakemap->ylengthnum / 2) + i + 2, up, shewei);
	this->snake->lenght= tlength;
}

void game::initpixmap()
{
	std::unique_ptr<QPixmap> bkg_pixmap = std::make_unique<QPixmap>(":/qtres/bg.png");
	std::unique_ptr<QPixmap> food_pixmap = std::make_unique<QPixmap>(":/food/qtres/food/food.png");
	std::unique_ptr<QPixmap> shesheng_pixmap = std::make_unique<QPixmap>(":/shesheng/qtres/shesheng/shesheng.png");
	std::unique_ptr<QPixmap> shetouleft_pixmap = std::make_unique<QPixmap>(":/shetou/qtres/shetou/shetouleft.png");
	std::unique_ptr<QPixmap> shetouright_pixmap = std::make_unique<QPixmap>(":/shetou/qtres/shetou/shetouright.png");
	std::unique_ptr<QPixmap> shetouup_pixmap = std::make_unique<QPixmap>(":/shetou/qtres/shetou/shetouup.png");
	std::unique_ptr<QPixmap> shetoudown_pixmap = std::make_unique<QPixmap>(":/shetou/qtres/shetou/shetoudown.png");
	std::unique_ptr<QPixmap> sheweiright_pixmap = std::make_unique<QPixmap>(":/shewei/qtres/shewei/sheweileft.png");
	std::unique_ptr<QPixmap> sheweileft_pixmap = std::make_unique<QPixmap>(":/shewei/qtres/shewei/sheweiright.png");
	std::unique_ptr<QPixmap> sheweiup_pixmap = std::make_unique<QPixmap>(":/shewei/qtres/shewei/sheweidown.png");
	std::unique_ptr<QPixmap> sheweidown_pixmap = std::make_unique<QPixmap>(":/shewei/qtres/shewei/sheweiup.png");
	std::unique_ptr<QPixmap> shewanleftdown_pixmap = std::make_unique<QPixmap>(":/shewan/qtres/shewan/shewanleftdown.png");
	std::unique_ptr<QPixmap> shewanrightup_pixmap = std::make_unique<QPixmap>(":/shewan/qtres/shewan/shewanrightup.png");
	std::unique_ptr<QPixmap> shewanleftup_pixmap = std::make_unique<QPixmap>(":/shewan/qtres/shewan/shewanleftup.png");
	std::unique_ptr<QPixmap> shewanrightdown_pixmap = std::make_unique<QPixmap>(":/shewan/qtres/shewan/shewanrightdown.png");

	pixmaps.push_back(std::move(shesheng_pixmap));		  // 0
	pixmaps.push_back(std::move(shetouleft_pixmap));	  // 1
	pixmaps.push_back(std::move(shetouright_pixmap));	  // 2
	pixmaps.push_back(std::move(shetouup_pixmap));		  // 3
	pixmaps.push_back(std::move(shetoudown_pixmap));	  // 4
	pixmaps.push_back(std::move(sheweileft_pixmap));	  // 5
	pixmaps.push_back(std::move(sheweiright_pixmap));	  // 6
	pixmaps.push_back(std::move(sheweidown_pixmap));	  // 7
	pixmaps.push_back(std::move(sheweiup_pixmap));		  // 8
	pixmaps.push_back(std::move(shewanleftdown_pixmap));  // 9
	pixmaps.push_back(std::move(shewanrightup_pixmap));	  // 10
	pixmaps.push_back(std::move(shewanleftup_pixmap));	  // 11
	pixmaps.push_back(std::move(shewanrightdown_pixmap)); // 12
	pixmaps.push_back(std::move(food_pixmap));			  // 13
	pixmaps.push_back(std::move(bkg_pixmap));			  // 14
	int tpi = 0;
	for (auto &pixmap : pixmaps)
	{
		tpi++;
		if (pixmap && !pixmap->isNull())
		{
			// pixmap = pixmap->scaled(100, 100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		}
		else
		{
			std::cout << "无效的QPixmap 指针,或图像为空" << tpi << std::endl;
		}
	}
}

void game::logic()
{
	QTimer* timer = new QTimer(this);
	timer->start(1000);
	QTimer* timer1 = new QTimer(this);
	timer1->start(100);
	QTimer* timer2 = new QTimer(this);
	timer2->start(3000);

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
		snake->checkState();
		this->food->setFood();
		if (this->snake->flag_direction_changed == true)
		{
			timer->start(this->snake->speed/2);//转向后500ms才开始移动
			snake->move();
			//std::cout << "changedmove" << std::endl;
			this->snake->flag_direction_changed = false;
			update();
		}
		this->isover();


		
	//for (auto it = this->snake->body.begin(); it != this->snake->body.end(); ++it)
	//	{
	//		snakeNodeClass& node = *it;
	//		this->food->isFoodEaten(node.x, node.y);
	//	}
        std::cout << "";
		//---------------------------------------------
		// if (!this) {
		// 	// 处理蛇身为空的情况
		// 	return;
		// }
		if (!this->snake) {
			// 处理蛇身为空的情况
			return;
		}

		if (this->snake == (snakeClass*)0xdddddddddddddddd) {
			// 处理蛇身为空的情况
			return;
		}

		if (this->snake->body.empty()) {
			// 处理蛇身为空的情况
			return;
		}
		

		int flag = 0;
		for (auto it = this->snake->body.begin(); it != this->snake->body.end(); ++it) {
			snakeNodeClass& node = *it;
			if (snake->live==alive)
			{ // 根据实际情况定义有效性检查
				if (this->food->isFoodEaten(node.x, node.y))
				{
					flag = 1;
				}
			}
			update();
		}
		if (flag == 1)
		{
			this->snake->getLonger();
			flag = 0;
		}

		//----------------------------

			
		
		//this->snake->checkState();
		});
	connect(timer2, &QTimer::timeout, this, [=]() {
		//this->snake->checkState();
		//this->food->deleteFood();
		});
}


