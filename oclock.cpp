#include "oclock.h"

OClock::OClock(QWidget *parent) : QWidget(parent)
{

    //qDebug()<<this->width()<<" "<<this->height();
    arrow=new QPointF[3];

    arrow[0]=QPointF(0,-0.6);
    arrow[1]=QPointF(0.01,-0.1);
    arrow[2]=QPointF(-0.01,-0.1);

    sec=0;
    min=0;
    hour=0;
    offset=0;

    time=QTime::currentTime();

    pen.setWidth(0);

    pen.setColor(Qt::black);

    sec=time.second();
    min=time.minute();

    if(time.hour()>12)
    {
    hour=time.hour()-12;
    }

    hour=360*(hour/12.f);

    hour+=30*(min/59.f);

    updater=new QTimer(this);

    ring=new QPixmap(":/fancy-ring.png");

    //qDebug()<<ring->width()<<" "<<ring->height();

    circle1=new HollowCircle(60,0.75f,-0.75f,0.69f,-0.69f);
    circle2=new HollowCircle(60,0.72f,-0.72f,0.69f,-0.69f);

    QObject::connect(updater,SIGNAL(timeout()),this,SLOT(update()));

    updater->start(1000);

}

void OClock::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter paint(this);


    paint.setPen(pen);

    paint.setBrush(QBrush(qRgb(0, 57, 138)));

    paint.drawPixmap(QRect(0,0,this->width(),this->height()),*ring);

    paint.translate(this->width()/2,this->height()/2);


    paint.scale(this->width()/2,this->height()/2);

    circle1->drawHollowCircle(&paint,min);

    paint.setBrush(QBrush(qRgb(167,2,48)));

    circle2->drawHollowCircle(&paint,sec);

    paint.setBrush(QBrush(Qt::black));

    paint.drawEllipse(QPointF(0,0),0.1f,0.1f);

    paint.setBrush(QBrush(qRgb(167,2,48)));

    paint.rotate(hour);

    paint.drawPolygon(arrow,3);



}


void OClock::update()
{
   // qDebug()<<offset;

    time=QTime::currentTime();

    time=time.addSecs(offset);

    sec=time.second();
    min=time.minute();

    hour=time.hour();
    if(hour>12)
    {
    hour-=12;
    }

    hour=360*(hour/12.f);

    hour+=30*(min/59.f);

    this->repaint();


}


