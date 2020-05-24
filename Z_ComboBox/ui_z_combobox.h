/********************************************************************************
** Form generated from reading UI file 'z_combobox.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_Z_COMBOBOX_H
#define UI_Z_COMBOBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Z_ComboBox
{
public:
    QComboBox *m_comboBox;

    void setupUi(QWidget *Z_ComboBox)
    {
        if (Z_ComboBox->objectName().isEmpty())
            Z_ComboBox->setObjectName(QString::fromUtf8("Z_ComboBox"));
        Z_ComboBox->resize(100, 30);
        Z_ComboBox->setStyleSheet(QString::fromUtf8(""));
        m_comboBox = new QComboBox(Z_ComboBox);
        m_comboBox->setObjectName(QString::fromUtf8("m_comboBox"));
        m_comboBox->setGeometry(QRect(0, 0, 100, 30));
        m_comboBox->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(Z_ComboBox);

        QMetaObject::connectSlotsByName(Z_ComboBox);
    } // setupUi

    void retranslateUi(QWidget *Z_ComboBox)
    {
        Z_ComboBox->setWindowTitle(QCoreApplication::translate("Z_ComboBox", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Z_ComboBox: public Ui_Z_ComboBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_Z_COMBOBOX_H
