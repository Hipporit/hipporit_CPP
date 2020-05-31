#ifndef Z_SLIDER_H
#define Z_SLIDER_H

#include <QWidget>
#include <QtUiPlugin/QDesignerCustomWidgetInterface>
#include <QtUiPlugin/QDesignerExportWidget>
#include <QSlider>

namespace Ui {
class Z_Slider;
}

class QDESIGNER_WIDGET_EXPORT Z_Slider : public QSlider
{
    Q_OBJECT

public:
    explicit Z_Slider(QWidget *parent = nullptr);
    ~Z_Slider() override;

private:
    Ui::Z_Slider *ui;

public:
    enum SLIDER_DIRECTION{
        SLIDER_DIRECTION_HORIZONTAL = 0,
        SLIDER_DIRECTION_VERTICAL = 1,
    };

public slots:
    void by_value_Changed(int value);
    void by_slider_Pressed();
    void by_slider_Moved(int value);
    void by_slider_Released();
    void by_range_Changed(int min,int max);

signals:
    void valueChanged(int value);
    void sliderPressed();
    void sliderMoved(int value);
    void sliderReleased();
    void rangeChanged(int min,int max);


private:
    QString QColor_To_QString(QString name,QColor color);
    QString Pixel_To_QString(QString name, int size);
    void _Init_Data();
    void _Refresh();

public:

    void _SetRange(int min,int max);

    void _SetMinimum(int min);
    int _GetMinimum();

    void _SetMaximum(int maximum);
    int _GetMaximum();

    void _SetSliderPosition(int position);
    int _GetSliderPosition();

    void _SetSingleStep(int step);
    int _GetSingleStep();


public:         //style
    void _SetOrientation(SLIDER_DIRECTION direction);
    SLIDER_DIRECTION _GetOrientation();

    void _SetSliderBackground(QColor color);
    QColor _GetSliderBackground();

    void _SetGrooveBackground(QColor color);
    QColor _GetGrooveBackground();

    void _SetGrooveHeight(int height);
    int _GetGrooveHeight();

    void _SetGrooveBorderRadius(int radius);
    int _GetGrooveBorderRadius();

    void _SetGrooveBackgroundDisabled(QColor color);
    QColor _GetGrooveBackgroundDisabled();

    void _SetSubpageBackground(QColor color);
    QColor _GetSubpageBackground();

    void _SetSubpageHeight(int height);
    int _GetSubpageHeight();

    void _SetSubpageBorderRadius(int radius);
    int _GetSubpageBorderRadius();

    void _SetSubpageBackgroundDisabled(QColor color);
    QColor _GetSubpageBackgroundDisabled();

    void _SetAddpageBackground(QColor color);
    QColor _GetAddpageBackground();

    void _SetAddpageHeight(int height);
    int _GetAddpageHeight();

    void _SetAddpageBorderRadius(int radius);
    int _GetAddpageBorderRadius();

    void _SetAddpageBackgroundDisabled(QColor color);
    QColor _GetAddpageBackgroundDisabled();

    void _SethandleBackground(QColor color);
    QColor _GethandleBackground();

    void _SethandleHeight(int height);
    int _GethandleHeight();

    void _SethandleBorderRadius(int radius);
    int _GethandleBorderRadius();

    void _SethandleBackgroundDisabled(QColor color);
    QColor _GethandleBackgroundDisabled();

private:        //style
    SLIDER_DIRECTION direction;
    QColor slider_backround;

    QColor groove_background;
    int groove_height;
    int groove_border_radius;
    QColor groove_background_diabled;

    QColor subpage_background;
    int subpage_height;
    int subpage_border_radius;
    QColor subpage_background_disabled;

    QColor addpage_background;
    int addpage_height;
    int addpage_border_radius;
    QColor addpage_background_disabled;

    QColor handle_background;
    int handle_height;
    int handle_width;
    int handle_border_radius;
    QColor handle_backround_disabled;

protected:
    virtual void resizeEvent(QResizeEvent *e) override;
};

#endif // Z_SLIDER_H
























