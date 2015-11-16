#include <QWidget>
#include "mainwindow.h"


mainwindow::mainwindow(QWidget *parent) : QWidget(parent)
{
    my_pong = new pongview(this);
    my_ball = new ball(this);
    timer = new QTimer(this);
    g_engine = new game_engine(this);
    g_engine->get_object(my_ball, my_pong);

    QHBoxLayout *layoutH = new QHBoxLayout;
    my_pong->setFocus();

//  timer->start(100);
    connect(timer, SIGNAL(timeout()), g_engine , SLOT(update_me()));
    timer->start(100);

    layoutH->addWidget(my_pong);
    layoutH->setAlignment(Qt::AlignHCenter);
    setLayout(layoutH);
}

void mainwindow::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    my_pong->paint_me(painter);
    my_ball->draw_me(painter);

    update();
}


