#ifndef Z_COMBOBOX_H
#define Z_COMBOBOX_H

#include <QtUiPlugin/QDesignerCustomWidgetInterface>
#include <QtUiPlugin/QDesignerExportWidget>
#include <QWidget>
#include <QComboBox>
#include <QString>


namespace Ui {
class Z_ComboBox;
}

class QDESIGNER_WIDGET_EXPORT Z_ComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit Z_ComboBox(QWidget *parent = nullptr);
    ~Z_ComboBox() override;

private:
    Ui::Z_ComboBox *ui;

public slots:
    void by_actived(int);
    void by_currentIndexChanged(int);

signals:
    void currentIndexChanged(int);
    void actived(int);

public:                             //Data
    void _Clear();
    void _AddItem(const QString &text);
    int _CurrentIndex();
    void _SetCurrentIndex(int index);
    QString _CurrentText();
    void _SetEnabled(bool parameter);
    void _InsertItem(int index, const QString &text);
    void _RemoveItem(int index);
    void _SetFocus();
    bool _HasFocus();
    QVector<QString> _GetItemTexts();

    private:
    QString QColor_To_QString(QString name,QColor color);
    QString Pixel_To_QString(QString name, int size);
    void _Init_Data();
    void _Refresh();

public:                             //Style
    void _SetGeomotry(QRect rect);

    void _SetItemEnabled(int index, bool parameter);

    void _SetBoxBorderRadius(int size);
    int _GetBoxBorderRadius();

    void _SetBoxFontColor(QColor color);
    QColor _GetBoxFontColor();

    void _SetBoxBackgroundColor(QColor color);
    QColor _GetBoxBackgroundColor();

    void _SetBoxFontSize(int size);
    int _GetBoxFontSIze();

    void _SetItemViewFontColor(QColor color);
    QColor _GetItemViewFontColor();

    void _SetItemViewBackgroundColor(QColor color);
    QColor _GetItemViewBackgroundColor();

    void _SetItemViewFontSize(int size);
    int _GetItemViewFontSize();

    void _SetDropDownWidth(int width);
    int _GetDropDownWidth();

    void _SetDownArrowImage(QString image);

    void _SetItemFontColor(QColor color);
    QColor _GetItemFontColor();

    void _SetItemBackgroundColor(QColor color);
    QColor _GetItemBackgroundColor();

    void _SetItemSelectionColor(QColor color);
    QColor _GetItemSelectionColor();

    void _SetItemHeight(int size);
    int _GetItemHeight();

    void _SetItemSelectionBackgroundColor(QColor color);
    QColor _GetItemSelectionBackgroundColor();

    void _SetItemHoverFontColor(QColor color);
    QColor _GetItemHoverFontColor();

    void _SetItemDisabledFontColor(QColor color);
    QColor _GetItemDisabledFontColor();

    void _SetItemDisabledBackgroundColor(QColor color);
    QColor _GetItemDisabledBackgroundColor();

private:                            //Style
    int box_border_radius;
    QColor box_font_color;
    QColor box_background_color;
    int box_font_size;

    QColor itemview_font_color;
    QColor itemview_background_color;
    int itemview_font_size;

    int dropdown_width;
    QString downarrow_image;

    QColor item_font_color;
    QColor item_background_color;
    int item_height;

    QColor item_selection_font_color;
    QColor item_selection_background_color;

    QColor item_hover_font_color;
    QColor item_hover_background_color;

    QColor item_disabled_font_color;
    QColor item_disabled_background_color;

protected:
    virtual void resizeEvent(QResizeEvent *e) override;
};

#endif // Z_COMBOBOX_H
