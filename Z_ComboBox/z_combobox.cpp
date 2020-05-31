#include "z_combobox.h"
#include "ui_z_combobox.h"
#include <QtUiPlugin/QDesignerCustomWidgetInterface>
#include <QListView>
#include <QStandardItemModel>

Z_ComboBox::Z_ComboBox(QWidget *parent) :
    QComboBox(parent),
    ui(new Ui::Z_ComboBox)
{
    ui->setupUi(this);

    model = qobject_cast<QStandardItemModel*>(ui->m_comboBox->model());

    ui->m_comboBox->setView(new QListView());
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

void Z_ComboBox::_SetItemEnabled(int index, bool parameter)
{
    if(index < 0 || index >= ui->m_comboBox->count())
    {
        return;
    }
    if(parameter)
    {
        ui->m_comboBox->setItemData(index, -1,Qt::UserRole - 1);
    }
    else
    {
        ui->m_comboBox->setItemData(index, 0,Qt::UserRole - 1);
    }
}

void Z_ComboBox::_SetBoxBorderRadius(int size)
{
    box_border_radius = size;
    _Refresh();
}

int Z_ComboBox::_GetBoxBorderRadius()
{
    return box_border_radius;
}

void Z_ComboBox::_SetBoxFontColor(QColor color)
{
    box_font_color = color;
    _Refresh();
}

QColor Z_ComboBox::_GetBoxFontColor()
{
    return box_font_color;
}

void Z_ComboBox::_SetBoxBackgroundColor(QColor color)
{
    box_background_color = color;
    _Refresh();
}

QColor Z_ComboBox::_GetBoxBackgroundColor()
{
    return box_background_color;
}

void Z_ComboBox::_SetItemViewFontColor(QColor color)
{
    itemview_font_color = color;
    _Refresh();
}

void Z_ComboBox::_SetBoxFontSize(int size)
{
     box_font_size = size;
     _Refresh();
}

int Z_ComboBox::_GetBoxFontSize()
{
    return box_font_size;
}

QColor Z_ComboBox::_GetItemViewFontColor()
{
    return itemview_font_color;
}

void Z_ComboBox::_SetItemViewBackgroundColor(QColor color)
{
    itemview_background_color = color;
    _Refresh();
}

QColor Z_ComboBox::_GetItemViewBackgroundColor()
{
    return itemview_background_color;
}

void Z_ComboBox::_SetItemViewFontSize(int size)
{
    itemview_font_size = size;
    _Refresh();
}

int Z_ComboBox::_GetItemViewFontSize()
{
    return itemview_font_size;
}

void Z_ComboBox::_SetDropDownWidth(int width)
{
    dropdown_width = width;
    _Refresh();
}
int Z_ComboBox::_GetDropDownWidth()
{
    return dropdown_width;
}

void Z_ComboBox::_SetDownArrowImage(QString image)
{
    downarrow_image = image;
    _Refresh();
}

void Z_ComboBox::_SetItemFontColor(QColor color)
{
    item_font_color = color;
    _Refresh();
}

QColor Z_ComboBox::_GetItemFontColor()
{
    return item_font_color;
}

void Z_ComboBox::_SetItemBackgroundColor(QColor color)
{
    item_background_color = color;
    _Refresh();
}

QColor Z_ComboBox::_GetItemBackgroundColor()
{
    return item_background_color;
}

void Z_ComboBox::_SetItemSelectionColor(QColor color)
{
    item_selection_font_color = color;
    _Refresh();
}

QColor Z_ComboBox::_GetItemSelectionColor()
{
    return item_selection_font_color;
}

void Z_ComboBox::_SetItemHeight(int size)
{
    item_height = size;
    _Refresh();
}

int Z_ComboBox::_GetItemHeight()
{
    return item_height;
}

void Z_ComboBox::_SetItemSelectionBackgroundColor(QColor color)
{
    item_selection_background_color = color;
    _Refresh();
}

QColor Z_ComboBox::_GetItemSelectionBackgroundColor()
{
    return item_selection_background_color;
}

void Z_ComboBox::_SetItemHoverFontColor(QColor color)
{
    item_hover_font_color = color;
    _Refresh();
}

QColor Z_ComboBox::_GetItemHoverFontColor()
{
    return item_hover_font_color;
}

void Z_ComboBox::_SetItemHoverBackgroundColor(QColor color)
{
    item_hover_background_color = color;
    _Refresh();
}

QColor Z_ComboBox::_GetItemHoverBackgroundColor()
{
    return item_hover_background_color;
}

void Z_ComboBox::_SetItemDisabledFontColor(QColor color)
{
    item_disabled_font_color = color;
    _Refresh();
}

QColor Z_ComboBox::_GetItemDisabledFontColor()
{
    return item_disabled_font_color;
}

void Z_ComboBox::_SetItemDisabledBackgroundColor(QColor color)
{
    item_disabled_background_color = color;
    _Refresh();
}

QColor Z_ComboBox::_GetItemDisabledBackgroundColor()
{
    return item_disabled_background_color;
}

void Z_ComboBox::_Clear()
{
    disconnect(ui->m_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(by_currentIndexChanged(int)));
    ui->m_comboBox->clear();
    connect(ui->m_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(by_currentIndexChanged(int)));
}

void Z_ComboBox::_AddItem(const QString &text)
{
    disconnect(ui->m_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(by_currentIndexChanged(int)));
    ui->m_comboBox->addItem(text);
    connect(ui->m_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(by_currentIndexChanged(int)));
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
    connect(ui->m_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(by_currentIndexChanged(int)));
    ui->m_comboBox->insertItem(index, text);
    connect(ui->m_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(by_currentIndexChanged(int)));
}

void Z_ComboBox::_RemoveItem(int index)
{
    if(index < 0 || index >= ui->m_comboBox->count())
    {
        return;
    }
    disconnect(ui->m_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(by_currentIndexChanged(int)));
    ui->m_comboBox->removeItem(index);
    connect(ui->m_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(by_currentIndexChanged(int)));
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
    box_border_radius = 0;
    box_font_color = QColor(255,255,255);
    box_background_color = QColor(51,25,255);
    box_font_size = 25;
    itemview_font_color = QColor(255,255,255);
    itemview_background_color = QColor(51,25,255);
    itemview_font_size = 25;
    dropdown_width = 30;
    downarrow_image = QString("ui.png");
    item_font_color = QColor(255,255,255);
    item_background_color = QColor(82,85,219);
    item_height = 30;
    item_selection_font_color = QColor(255,92,56);
    item_selection_background_color = QColor(82,85,255);
    item_hover_font_color = QColor(255,92,56);
    item_hover_background_color = QColor(82,85,255);
    item_disabled_font_color = QColor(200,200,200);
    item_disabled_background_color = QColor(5,10,255);
}

void Z_ComboBox::_Refresh()
{
    QString str_box_border_radius = Pixel_To_QString(QString("border"), box_border_radius);
    QString str_box_font_color = QColor_To_QString(QString("color"), box_font_color);
    QString str_box_background_color = QColor_To_QString(QString("background"), box_background_color);
    QString str_box_font_size = Pixel_To_QString(QString("font-size"), box_font_size);

    QString str_itemview_font_color = QColor_To_QString(QString("color"), itemview_font_color);
    QString str_itemview_background_color = QColor_To_QString(QString("background"), itemview_background_color);
    QString str_itemview_font_size = Pixel_To_QString(QString("font-size"), itemview_font_size);

    QString str_dropdown_width = Pixel_To_QString(QString("width"), dropdown_width);

    QString str_downarrow_image = QString("image:url(:/%1)").arg(downarrow_image);

    QString str_item_font_color = QColor_To_QString(QString("color"), item_font_color);
    QString str_item_background_color = QColor_To_QString(QString("background"), item_background_color);
    QString str_item_height = Pixel_To_QString(QString("height"), item_height);

    QString str_item_selection_font_color = QColor_To_QString(QString("color"), item_selection_font_color);
    QString str_item_selection_background_color = QColor_To_QString(QString("background"), item_selection_background_color);

    QString str_item_hover_font_color = QColor_To_QString(QString("color"), item_hover_font_color);
    QString str_item_hover_background_color = QColor_To_QString(QString("background"), item_hover_background_color);

    QString str_item_disabled_font_color = QColor_To_QString(QString("color"), item_disabled_font_color);
    QString str_item_disabled_background_color = QColor_To_QString(QString("background"), item_disabled_background_color);

    QString m_stylesheet;
    m_stylesheet = QString("QComboBox{%1%2%3%4}").arg(str_box_border_radius).arg(str_box_font_color).arg(str_box_background_color).arg(str_box_font_size);
    m_stylesheet += QString("QComboBox QAbstractItemView{%1%2%3}").arg(str_itemview_font_color).arg(str_itemview_background_color).arg(str_itemview_font_size);
    m_stylesheet += QString("QComboBox::drop-down{%1}").arg(str_dropdown_width);
    m_stylesheet += QString("QComboBox::down-arrow{%1;}").arg(str_downarrow_image);
    m_stylesheet += QString("QListView::item{%1%2%3}").arg(str_item_font_color).arg(str_item_background_color).arg(str_item_height);
    m_stylesheet += QString("QListView::item:selected{%1%2}").arg(str_item_selection_font_color).arg(str_item_selection_background_color);
    m_stylesheet += QString("QListView::item:hover{%1%2}").arg(str_item_hover_font_color).arg(str_item_hover_background_color);
    m_stylesheet += QString("QComboBox QAbstractItemView::item::!enabled{%1%2}").arg(str_item_disabled_font_color).arg(str_item_disabled_background_color);
    ui->m_comboBox->setStyleSheet(m_stylesheet);
}

void Z_ComboBox::resizeEvent(QResizeEvent *e)
{
    QComboBox::resizeEvent(e);
    QRect rect = this->geometry();
    ui->m_comboBox->setGeometry(0,0,rect.width(),rect.height());
    box_font_size = rect.height()>5?rect.height()-5:5;
    item_height = rect.height();
    itemview_font_size = rect.height()>5?rect.height()-5:5;
    _Refresh();
}


















