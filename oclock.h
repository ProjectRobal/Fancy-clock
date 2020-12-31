#ifndef OCLOCK_H
#define OCLOCK_H

#include <QWidget>
#include <QLabel>
#include <QTime>
#include <QImage>
#include <QPainter>
#include <QTimer>
#include <QOpenGLPaintDevice>

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

signals:

protected slots:

    void update();

};

#endif // OCLOCK_H
