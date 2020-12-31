#include "oclock.h"

OClock::OClock(QWidget *parent) : QWidget(parent)
{

    device=new QOpenGLPaintDevice();


    //paint=new QPainter(this);

    angel=0;

    time=QTime::currentTime();

    pen.setWidth(0);

   pen.setColor(QColor(qRgb(0, 57, 138)));

    //pen.setStyle(Qt::NoPen);



    angel=-360*(time.second()/59.f);

    updater=new QTimer(this);

    ring=new QPixmap(":/fancy-ring.png");

    QObject::connect(updater,SIGNAL(timeout()),this,SLOT(update()));

    updater->start(1000);

}

void OClock::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    //angel=0;

    QPainter paint(this);




    paint.setPen(pen);

    paint.setBrush(QBrush(qRgb(0, 57, 138)));


    float rx=(this->width()/2)*0.78f;
    float ry=(this->height()/2)*0.78f;

    paint.drawPie((this->width()/2)-rx,(this->height()/2)-ry,2*rx,2*ry,90*16,angel*16);


    paint.drawPixmap(QRect(0,0,this->width(),this->height()),*ring);
}


void OClock::update()
{
    time=QTime::currentTime();

    angel=-360*(time.second()/59.f);

    /*if(angel<=-360)
    {
        angel=0;
    }*/

    this->repaint();


}
