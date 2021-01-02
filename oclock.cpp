#include "oclock.h"

OClock::OClock(QWidget *parent) : QWidget(parent)
{

   // device=new QOpenGLPaintDevice();


    //paint=new QPainter(this);

    qDebug()<<this->width()<<" "<<this->height();

  //  points=new QPointF[40];




   //points[61]=QPointF(this->width()/2,this->height()/2);

    //points[0]=QPointF(this->width()/2,this->height());
    //points[1]=QPointF(this->width(),this->height()/2);
    //points[2]=QPointF(this->width()/2,0);
    //points[3]=QPointF(0,0);

    angel=0;

    time=QTime::currentTime();

    pen.setWidth(0);

   pen.setColor(QColor(qRgb(0, 57, 138)));

    //pen.setStyle(Qt::NoPen);



    angel=-360*(time.second()/59.f);

    updater=new QTimer(this);

    ring=new QPixmap(":/fancy-ring.png");

    qDebug()<<ring->width()<<" "<<ring->height();

  /*  for(short i=0;i<61;i++)
    {
    points[i]=QPointF((sin(i*a)*r),(cos(i*a)*r));

    qDebug()<<i*a;
    }

    for(short i=61;i<122;i++)
    {
    points[i]=QPointF((sin((i-61)*a)*5),(cos((i-61)*a)*5));

    qDebug()<<(i-61)*a;
    }*/




    QObject::connect(updater,SIGNAL(timeout()),this,SLOT(update()));

    updater->start(1000);

}

void OClock::intializeHollowCircle(int n_points,int o_rx,int o_ry,int i_rx,int i_ry)
{
    QPointF* o_points;

    o_points=new QPointF[n_points+1];

    //float r=100;

   float a=(2*M_PI)/n_points;

   //qDebug()<<a;



    for(short i=0;i<n_points+1;i++)
    {
        o_points[i]=QPointF((sin(i*a)*o_rx),(cos(i*a)*o_ry));
    }

    QPointF* i_points;

    i_points=new QPointF[n_points+1];

    for(short i=0;i<n_points+1;i++)
    {
        i_points[i]=QPointF((sin(i*(-a))*i_rx),(cos(i*(-a))*i_ry));
    }
}


void OClock::drawHollowCircle(int n_points,int o_rx,int o_ry,int i_rx,int i_ry,QPainter *p,int p_t_s)
{

    if(!p_t_s)
    {
        return;
    }

    if(p_t_s<0)
    {
    p_t_s=n_points;
    }

    if(p_t_s>n_points)
    {
    p_t_s=n_points;
    }

    /*QPointF* points;

    points=new QPointF[(n_points+1)*2];

    //float r=100;

   float a=(2*M_PI)/n_points;

   //qDebug()<<a;



    for(short i=0;i<n_points+1;i++)
    {
        points[i]=QPointF((sin(i*a)*o_r),(cos(i*a)*o_r));
    }

    int u=n_points+1;

   for(short i=n_points;i>=0;i--)
    {
        points[u]=QPointF((sin(i*a)*i_r),(cos(i*a)*i_r));

        u++;
    }

   p->drawPolygon(points,(n_points+1)*2);*/





        QPointF* o_points;

        o_points=new QPointF[n_points+1];

        //float r=100;

       float a=(2*M_PI)/n_points;

       //qDebug()<<a;



        for(short i=0;i<n_points+1;i++)
        {
            o_points[i]=QPointF((sin(i*a)*o_rx),(cos(i*a)*o_ry));
        }

        QPointF* i_points;

        i_points=new QPointF[n_points+1];

        for(short i=0;i<n_points+1;i++)
        {
            i_points[i]=QPointF((sin(i*(-a))*i_rx),(cos(i*(-a))*i_ry));
        }

      //  p->drawPolygon(o_points,n_points);

       // p->setBrush(QBrush(qRgb(255,0,0)));

       // p->drawPolygon(i_points,n_points);





        QPointF* points=new QPointF[(n_points+1)*2];

        memmove(points,o_points,(p_t_s+1)*sizeof(QPointF));

        memmove(points+p_t_s+1,i_points+(n_points-p_t_s),(p_t_s+1)*sizeof(QPointF));

       /* for(int i=0;i<(n_points+1)*2;i++)
        {
            qDebug()<<points[i];
        }*/

         p->drawPolygon(points,(p_t_s+1)*2);
}

void OClock::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    //angel=0;

    QPainter paint(this);


    paint.setPen(pen);

    paint.setBrush(QBrush(qRgb(0, 57, 138)));

   // qDebug()<<ring->width()<<" "<<ring->height();

    paint.drawPixmap(QRect(0,0,this->width(),this->height()),*ring);

    paint.translate(this->width()/2,this->height()/2);

    int rx=this->width()/2;
    int ry=this->height()/2;

   // paint.drawPolygon(points,40);

    this->drawHollowCircle(60,rx*0.75f,ry*0.75f,rx*0.5f,ry*0.5f,&paint,angel+1);

   // paint.setBrush(QBrush(qRgb(0, 255, 0)));

    //this->drawHollowCircle(60,rx*0.75f,ry*0.75f,rx*0.5f,ry*0.5f,&paint);

}


void OClock::update()
{
    time=QTime::currentTime();

    angel=time.second();

    /*if(angel<=-360)
    {
        angel=0;
    }*/

    this->repaint();


}
