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

class OClock : public QWidget
{
    Q_OBJECT

    QTime time;
   // QPainter *paint;
    QTimer *updater;
    QPixmap *ring;
    QOpenGLPaintDevice* device;
    int angel;
    QPen pen;


public:
    explicit OClock(QWidget *parent = nullptr);

protected:

void paintEvent(QPaintEvent *e);

void drawHollowCircle(int n_points,int o_rx,int o_ry,int i_rx,int i_ry,QPainter *p,int p_t_s=-1);

void intializeHollowCircle(int n_points,int o_rx,int o_ry,int i_rx,int i_ry);

signals:

protected slots:

    void update();

};

#endif // OCLOCK_H
