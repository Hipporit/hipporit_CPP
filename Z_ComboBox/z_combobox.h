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

private:                            //Style

    QString m_stylesheet;

    QColor box_font_color;
    QColor box_background_color;
    int box_border_radius;
    QColor item_selection_color;
    QColor item_selection_backround_color;


protected:
    virtual void resizeEvent(QResizeEvent *e) override;
};

#endif // Z_COMBOBOX_H
