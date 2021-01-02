#ifndef OCLOCK_H
#define OCLOCK_H

#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QTime>
#include <QImage>
#include <QPainter>
#include <QTimer>
#include <QOpenGLPaintDevice>
#include <cmath>
#include <hollowcircle.h>
#include <QKeyEvent>

class OClock : public QWidget
{
    Q_OBJECT

    QTime time;
   // QPainter *paint;
    QTimer *updater;
    QPixmap *ring;
    QOpenGLPaintDevice* device;
    int sec;
    int min;
    int hour;
    QPen pen;
    HollowCircle *circle1;
    HollowCircle *circle2;
    QPointF *arrow;
    int offset;


public:
    explicit OClock(QWidget *parent = nullptr);

    void move_up()
    {
        qDebug()<<sec<<" "<<min<<" "<<" "<<hour;
    offset+=60;
    }

    void move_down()
    {
        qDebug()<<sec<<" "<<min<<" "<<" "<<hour;
    offset-=60;
    }


protected:

void paintEvent(QPaintEvent *e);


signals:

protected slots:

    void update();

};

#endif // OCLOCK_H
