#include "z_combobox.h"
#include "ui_z_combobox.h"
#include <QtUiPlugin/QDesignerCustomWidgetInterface>


Z_ComboBox::Z_ComboBox(QWidget *parent) :
    QComboBox(parent),
    ui(new Ui::Z_ComboBox)
{
    ui->setupUi(this);

    _Init_Data();
    _Refresh();

    connect(ui->m_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(by_currentIndexChanged(int)));
    connect(ui->m_comboBox, SIGNAL(activated(int)), this, SLOT(by_actived(int)));
}

Z_ComboBox::~Z_ComboBox()
{
    delete ui;
}

void Z_ComboBox::by_actived(int index)
{
    emit activated(index);
}

void Z_ComboBox::by_currentIndexChanged(int index)
{
    emit currentIndexChanged(index);
}

void Z_ComboBox::_SetGeomotry(QRect rect)
{
    this->setGeometry(rect);
}

void Z_ComboBox::_Clear()
{
    disconnect(ui->m_comboBox, SIGNAL(currentIndexChanged()), this, SLOT(by_currentIndexChanged()));
    ui->m_comboBox->clear();
    connect(ui->m_comboBox, SIGNAL(currentIndexChanged()), this, SLOT(by_currentIndexChanged()));
}

void Z_ComboBox::_AddItem(const QString &text)
{
    disconnect(ui->m_comboBox, SIGNAL(currentIndexChanged()), this, SLOT(by_currentIndexChanged()));
    ui->m_comboBox->addItem(text);
    connect(ui->m_comboBox, SIGNAL(currentIndexChanged()), this, SLOT(by_currentIndexChanged()));
}

int Z_ComboBox::_CurrentIndex()
{
    return ui->m_comboBox->currentIndex();
}

void Z_ComboBox::_SetCurrentIndex(int index)
{
    ui->m_comboBox->setCurrentIndex(index);
}

QString Z_ComboBox::_CurrentText()
{
    return ui->m_comboBox->currentText();
}

void Z_ComboBox::_SetEnabled(bool parameter)
{
    ui->m_comboBox->setEnabled(parameter);
}

void Z_ComboBox::_InsertItem(int index, const QString &text)
{
    if(index < 0 || index >= ui->m_comboBox->count())
    {
        return;
    }
    connect(ui->m_comboBox, SIGNAL(currentIndexChanged()), this, SLOT(by_currentIndexChanged()));
    ui->m_comboBox->insertItem(index, text);
    connect(ui->m_comboBox, SIGNAL(currentIndexChanged()), this, SLOT(by_currentIndexChanged()));
}

void Z_ComboBox::_RemoveItem(int index)
{
    if(index < 0 || index >= ui->m_comboBox->count())
    {
        return;
    }
    disconnect(ui->m_comboBox, SIGNAL(currentIndexChanged()), this, SLOT(by_currentIndexChanged()));
    ui->m_comboBox->removeItem(index);
    connect(ui->m_comboBox, SIGNAL(currentIndexChanged()), this, SLOT(by_currentIndexChanged()));
}

void Z_ComboBox::_SetFocus()
{
    ui->m_comboBox->setFocus();
}

bool Z_ComboBox::_HasFocus()
{
    return ui->m_comboBox->hasFocus();
}

QVector<QString> Z_ComboBox::_GetItemTexts()
{
    QVector<QString> result;
    for (int i = 0; i < ui->m_comboBox->count(); i++)
    {
        result.push_back(ui->m_comboBox->itemText(i));
    }
    return result;
}

QString Z_ComboBox::QColor_To_QString(QString name,QColor color)
{
    return QString(name+":rgb(%1,%2,%3);").arg(color.red()).arg(color.green()).arg(color.blue());
}

QString Z_ComboBox::Pixel_To_QString(QString name, int size)
{
    return QString(name+":%1px;").arg(size);
}

void Z_ComboBox::_Init_Data()
{
    box_font_color = QColor(255,255,0);
    box_background_color = QColor(0,255,255);
    box_border_radius = 1;
    item_selection_color = QColor(255,0,0);
    item_selection_backround_color = QColor(0,0,0);
}

void Z_ComboBox::_Refresh()
{
    QString str_box_font_color = QColor_To_QString(QString("color"), box_font_color);
    QString str_box_background_color = QColor_To_QString(QString("background-color"), box_background_color);
    QString str_box_border_radius = Pixel_To_QString(QString("border-radius"), box_border_radius);
    QString str_item_selection_color = QColor_To_QString(QString("selection-color"), item_selection_color);
    QString str_item_background_color = QColor_To_QString(QString("selection-background-color"), item_selection_backround_color);


    m_stylesheet = str_box_font_color + str_box_background_color + str_box_border_radius+
            str_item_selection_color + str_item_background_color;

    ui->m_comboBox->setStyleSheet(m_stylesheet);
}

void Z_ComboBox::resizeEvent(QResizeEvent *e)
{
    QRect rect = this->geometry();
    ui->m_comboBox->setGeometry(0,0,rect.width(),rect.height());
}


























