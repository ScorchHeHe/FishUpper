#include "compass.h"
#include "ui_compass.h"
#include <QVector>
#include <QString>
#include <QImage>


Compass::Compass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Compass)
{
    m_course = 0;
    ui->setupUi(this);
}

Compass::~Compass()
{
    delete ui;
}

void Compass::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    this->initParas();
    painter.translate(circular);
    this->drawFrame(painter);
    this->drawScales(painter, m_course);
    this->drawIndicator(painter, m_course);
    this->drawIcon(painter);
}

void Compass::initParas()
{
    circular = QPoint(width() / 2,height() / 2 + 10);
}

void Compass::drawFrame(QPainter &painter)
{
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(30,30,30));
    painter.drawEllipse(QPoint(0,0),110,110);
    painter.restore();
}

void Compass::drawIndicator(QPainter &painter, float course)
{
    painter.save();
    painter.rotate(course);
    QVector<QString> indicator = {"N", "NE", "E", "SE", "S", "SW", "W","NW"};
    painter.setPen(Qt::white);
    for (int i = 0; i < 360; i += 15){
        if (i % 90 == 0){
            painter.drawText(QPoint(-5,-80), indicator[i / 45]);
        }
        else if (i % 45 == 0){
            painter.drawText(QPoint(-10,-80), indicator[i / 45]);
        }
        painter.rotate(15);
    }
    painter.restore();
}

void Compass::drawScales(QPainter &painter, float course)
{
    painter.save();
    painter.rotate(course);
    QPen pen(Qt::white);

    for (int i = 0; i <= 360; i += 15){
        if (i % 45 == 0){
            pen.setWidth(2);
            painter.setPen(pen);
            painter.drawLine(110,0,95,0);
        }
        else {
            pen.setWidth(1);
            painter.setPen(pen);
            painter.drawLine(110,0,95,0);
        }
        painter.rotate(15);
    }
    painter.restore();
}

void Compass::drawIcon(QPainter &painter)
{
    painter.save();
    QBrush brush(QColor(116,0,0));
    painter.setBrush(brush);
    static const QPointF points[3] = {
        QPointF(6, 0.0),
        QPointF(-6, 0.0),
        QPointF(0, -80.0),
    };
    painter.drawPolygon(points, 3);
    painter.restore();
}

void Compass::update_compass(float course)
{
    m_course = course + 180;
    this->update();
}
