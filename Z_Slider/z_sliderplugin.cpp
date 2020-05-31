#include "z_slider.h"
#include "z_sliderplugin.h"

#include <QtPlugin>

Z_SliderPlugin::Z_SliderPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void Z_SliderPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool Z_SliderPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *Z_SliderPlugin::createWidget(QWidget *parent)
{
    return new Z_Slider(parent);
}

QString Z_SliderPlugin::name() const
{
    return QLatin1String("Z_Slider");
}

QString Z_SliderPlugin::group() const
{
    return QLatin1String("");
}

QIcon Z_SliderPlugin::icon() const
{
    return QIcon();
}

QString Z_SliderPlugin::toolTip() const
{
    return QLatin1String("");
}

QString Z_SliderPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool Z_SliderPlugin::isContainer() const
{
    return false;
}

QString Z_SliderPlugin::domXml() const
{
    return QLatin1String("<widget class=\"Z_Slider\" name=\"z_Slider\">\n</widget>\n");
}

QString Z_SliderPlugin::includeFile() const
{
    return QLatin1String("z_slider.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(z_sliderplugin, Z_SliderPlugin)
#endif // QT_VERSION < 0x050000
