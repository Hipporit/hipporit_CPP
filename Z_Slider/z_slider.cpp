#include "z_slider.h"
#include "ui_z_slider.h"

Z_Slider::Z_Slider(QWidget *parent) :
    QSlider(parent),
    ui(new Ui::Z_Slider)
{
    ui->setupUi(this);
    this->setWindowOpacity(0);

    _Init_Data();
    _Refresh();
    connect(ui->m_slider, SIGNAL(valueChanged(int)), this, SLOT(by_value_Changed(int)));
    connect(ui->m_slider, SIGNAL(sliderPressed()), this, SLOT(by_slider_Pressed()));
    connect(ui->m_slider, SIGNAL(sliderMoved(int)), this, SLOT(by_slider_Moved(int)));
    connect(ui->m_slider, SIGNAL(sliderReleased()), this, SLOT(by_slider_Released()));
    connect(ui->m_slider, SIGNAL(rangeChanged(int,int)), this, SLOT(by_range_Changed(int,int)));
}

Z_Slider::~Z_Slider()
{
    delete ui;
}

void Z_Slider::by_value_Changed(int value)
{
    emit valueChanged(value);
}

void Z_Slider::by_slider_Pressed()
{
    emit sliderPressed();
}

void Z_Slider::by_slider_Moved(int value)
{
    emit sliderMoved(value);
}

void Z_Slider::by_slider_Released()
{
    emit sliderReleased();
}

void Z_Slider::by_range_Changed(int min,int max)
{
    emit rangeChanged(min, max);
}

QString Z_Slider::QColor_To_QString(QString name,QColor color)
{
    return QString(name+":rgb(%1,%2,%3);").arg(color.red()).arg(color.green()).arg(color.blue());
}

QString Z_Slider::Pixel_To_QString(QString name, int size)
{
    return QString(name+":%1px;").arg(size);
}

void Z_Slider::_SetOrientation(Z_Slider::SLIDER_DIRECTION direction)
{
    this->direction = direction;
    if(this->direction == Z_Slider::SLIDER_DIRECTION_HORIZONTAL)
    {
        ui->m_slider->setOrientation(Qt::Horizontal);
    }
    else
    {
        ui->m_slider->setOrientation(Qt::Vertical);
    }
}

Z_Slider::SLIDER_DIRECTION Z_Slider::_GetOrientation()
{
    return  (Z_Slider::SLIDER_DIRECTION)(int)ui->m_slider->orientation();
}

void Z_Slider::_SetRange(int min,int max)
{
    ui->m_slider->setRange(min, max);
}

void Z_Slider::_SetMinimum(int min)
{
    ui->m_slider->setMinimum(min);
}

int Z_Slider::_GetMinimum()
{
    return ui->m_slider->minimum();
}

void Z_Slider::_SetMaximum(int maximum)
{
    ui->m_slider->setMaximum(maximum);
}

int Z_Slider::_GetMaximum()
{
    return ui->m_slider->maximum();
}

void Z_Slider::_SetSliderPosition(int position)
{
    ui->m_slider->setSliderPosition(position);
}

int Z_Slider::_GetSliderPosition()
{
    return ui->m_slider->sliderPosition();
}

void Z_Slider::_SetSingleStep(int step)
{
    ui->m_slider->setSingleStep(step);
}

int Z_Slider::_GetSingleStep()
{
    return ui->m_slider->singleStep();
}

void Z_Slider::_Init_Data()
{
    direction = SLIDER_DIRECTION_HORIZONTAL;
    slider_backround = QColor(255,255,255);

    groove_background = QColor(255,255,255);
    groove_height = 10;
    groove_border_radius = 4;
    groove_background_diabled = QColor(176,176,176);

    subpage_background = QColor(96,96,224);
    subpage_height = 10;
    subpage_border_radius = 4;
    subpage_background_disabled = QColor(144,144,144);

    addpage_background = QColor(255,255,255);
    addpage_height = 10;
    addpage_border_radius = 4;
    addpage_background_disabled = QColor(144,144,144);

    handle_background = QColor(208,208,208);
    handle_height = 15;
    handle_width = 15;
    handle_border_radius = 3;
    handle_backround_disabled = QColor(224,224,244);
}

void Z_Slider::_Refresh()
{
    QString slider_direction = direction==SLIDER_DIRECTION_HORIZONTAL?"horizontal":"vertical";
    QString str_slider_background = QColor_To_QString(QString("background"), slider_backround);

    QString str_groove_background = QColor_To_QString(QString("background"), groove_background);
    QString str_groove_height = Pixel_To_QString(QString("height"), groove_height);
    QString str_groove_border_radius = Pixel_To_QString(QString("border-radius"), groove_border_radius);

    QString str_subpage_background = QColor_To_QString(QString("background"), subpage_background);
    QString str_subpage_height = Pixel_To_QString(QString("height"), subpage_height);
    QString str_subpage_border_radius = Pixel_To_QString(QString("border-radius"), subpage_border_radius);

    QString str_addpage_background = QColor_To_QString(QString("background"), addpage_background);
    QString str_addpage_height = Pixel_To_QString(QString("height"), addpage_height);
    QString str_addpage_border_radius = Pixel_To_QString(QString("border-radius"), addpage_border_radius);

    QString str_handle_background = QColor_To_QString(QString("background"), handle_background);
    QString str_handle_height = Pixel_To_QString(QString("height"), handle_height);
    QString str_handle_width = Pixel_To_QString(QString("height"), handle_width);
    QString str_handle_border_radius = Pixel_To_QString(QString("border-radius"), handle_border_radius);

    QString str_groove_disabled = QColor_To_QString(QString("background"), groove_background_diabled);
    QString str_subpage_disabled = QColor_To_QString(QString("background"), subpage_background_disabled);
    QString str_addpage_disabled = QColor_To_QString(QString("background"), addpage_background_disabled);
    QString str_handle_disabled = QColor_To_QString(QString("background"), handle_backround_disabled);

    QString m_stylesheet;
    m_stylesheet += QString("QSlider{%1}").arg(str_slider_background);
    m_stylesheet += QString("QSlider::groove:%1{%2%3%4}").arg(slider_direction).arg(str_groove_background).arg(str_groove_height).arg(str_groove_border_radius);
    m_stylesheet += QString("QSlider::sub-page:%1{%2%3%4}").arg(slider_direction).arg(str_subpage_background).arg(str_subpage_height).arg(str_subpage_border_radius);
    m_stylesheet += QString("QSlider::add-pgae:%1{%2%3%4}").arg(slider_direction).arg(str_addpage_background).arg(str_addpage_height).arg(str_addpage_border_radius);
    m_stylesheet += QString("QSlider::handle:%1{%2%3%4%5}").arg(slider_direction).arg(str_handle_background).arg(str_handle_height).arg(str_handle_width).arg(str_handle_border_radius);
    m_stylesheet += QString("QSlider::groove:%1:disabled{%2}").arg(slider_direction).arg(str_groove_disabled);
    m_stylesheet += QString("QSlider::sub-page:%1:disabled{%2}").arg(slider_direction).arg(str_subpage_disabled);
    m_stylesheet += QString("QSlider::add-page:%1:disabled{%2}").arg(slider_direction).arg(str_addpage_disabled);
    m_stylesheet += QString("QSlider::handle:%1:disabled{%2}").arg(slider_direction).arg(str_handle_disabled);

    ui->m_slider->setStyleSheet(m_stylesheet);
    ui->m_slider->setGeometry(0,0,this->geometry().width(),this->geometry().height());
}

void Z_Slider::_SetSliderBackground(QColor color)
{
    slider_backround = color;
    _Refresh();
}

QColor Z_Slider::_GetSliderBackground()
{
    return slider_backround;
}

void Z_Slider::_SetGrooveBackground(QColor color)
{
    groove_background = color;
    _Refresh();
}

QColor Z_Slider::_GetGrooveBackground()
{
    return groove_background;
}

void Z_Slider::_SetGrooveHeight(int height)
{
    groove_height = height;
    _Refresh();
}

int Z_Slider::_GetGrooveHeight()
{
    return groove_height;
}

void Z_Slider::_SetGrooveBorderRadius(int radius)
{
    groove_border_radius = radius;
    _Refresh();
}

int Z_Slider::_GetGrooveBorderRadius()
{
    return groove_border_radius;
}

void Z_Slider::_SetGrooveBackgroundDisabled(QColor color)
{
    groove_background_diabled = color;
    _Refresh();
}

QColor Z_Slider::_GetGrooveBackgroundDisabled()
{
    return groove_background_diabled;
}

void Z_Slider::_SetSubpageBackground(QColor color)
{
    subpage_background = color;
    _Refresh();
}

QColor Z_Slider::_GetSubpageBackground()
{
    return subpage_background;
}

void Z_Slider::_SetSubpageHeight(int height)
{
    subpage_height = height;
    _Refresh();
}

int Z_Slider::_GetSubpageHeight()
{
    return subpage_height;
}

void Z_Slider::_SetSubpageBorderRadius(int radius)
{
    subpage_border_radius = radius;
    _Refresh();
}

int Z_Slider::_GetSubpageBorderRadius()
{
    return  subpage_border_radius;
}

void Z_Slider::_SetSubpageBackgroundDisabled(QColor color)
{
    subpage_background_disabled = color;
    _Refresh();
}

QColor Z_Slider::_GetSubpageBackgroundDisabled()
{
    return subpage_background_disabled;
}

void Z_Slider::_SetAddpageBackground(QColor color)
{
    addpage_background = color;
    _Refresh();
}

QColor Z_Slider::_GetAddpageBackground()
{
    return addpage_background;
}

void Z_Slider::_SetAddpageHeight(int height)
{
    addpage_height = height;
    _Refresh();
}

int Z_Slider::_GetAddpageHeight()
{
    return addpage_height;
}

void Z_Slider::_SetAddpageBorderRadius(int radius)
{
    addpage_border_radius = radius;
    _Refresh();
}

int Z_Slider::_GetAddpageBorderRadius()
{
    return addpage_border_radius;
}

void Z_Slider::_SetAddpageBackgroundDisabled(QColor color)
{
    addpage_background_disabled = color;
    _Refresh();
}

QColor Z_Slider::_GetAddpageBackgroundDisabled()
{
    return addpage_background_disabled;
}

void Z_Slider::_SethandleBackground(QColor color)
{
    handle_background = color;
    _Refresh();
}

QColor Z_Slider::_GethandleBackground()
{
    return handle_background;
}

void Z_Slider::_SethandleHeight(int height)
{
    handle_height = height;
    _Refresh();
}

int Z_Slider::_GethandleHeight()
{
    return handle_height;
}

void Z_Slider::_SethandleBorderRadius(int radius)
{
    handle_border_radius = radius;
    _Refresh();
}

int Z_Slider::_GethandleBorderRadius()
{
    return handle_border_radius;
}

void Z_Slider::_SethandleBackgroundDisabled(QColor color)
{
    handle_backround_disabled = color;
    _Refresh();
}

QColor Z_Slider::_GethandleBackgroundDisabled()
{
    return handle_backround_disabled;
}

void Z_Slider::resizeEvent(QResizeEvent *e)
{
    QSlider::resizeEvent(e);
    _Refresh();
}
