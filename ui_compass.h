/********************************************************************************
** Form generated from reading UI file 'compass.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPASS_H
#define UI_COMPASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Compass
{
public:

    void setupUi(QWidget *Compass)
    {
        if (Compass->objectName().isEmpty())
            Compass->setObjectName(QString::fromUtf8("Compass"));
        Compass->resize(200, 220);

        retranslateUi(Compass);

        QMetaObject::connectSlotsByName(Compass);
    } // setupUi

    void retranslateUi(QWidget *Compass)
    {
        Compass->setWindowTitle(QApplication::translate("Compass", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Compass: public Ui_Compass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPASS_H
