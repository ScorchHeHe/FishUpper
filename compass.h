#ifndef COMPASS_H
#define COMPASS_H

#include <QWidget>
#include <QPainter>
#include <QColor>
#include <QBrush>


namespace Ui {
class Compass;
}

class Compass : public QWidget
{
    Q_OBJECT

public:
    explicit Compass(QWidget *parent = nullptr);
    ~Compass();

    void  paintEvent(QPaintEvent *event);

    void initParas();

    void drawFrame(QPainter &painter);

    void drawIndicator(QPainter &painter, float course);

    void drawScales(QPainter &painter, float course);

    void drawIcon(QPainter &painter);

    void update_compass(float course);

private:
    Ui::Compass *ui;
    QColor frameColor;
    QColor backgroundColor;
    QColor scaleColor;
    QPoint circular;
    int radius;
    int marginSize;
    float m_course;

};

#endif // COMPASS_H
