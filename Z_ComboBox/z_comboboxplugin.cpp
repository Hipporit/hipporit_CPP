#include "z_combobox.h"
#include "z_comboboxplugin.h"

#include <QtPlugin>

Z_ComboBoxPlugin::Z_ComboBoxPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void Z_ComboBoxPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool Z_ComboBoxPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *Z_ComboBoxPlugin::createWidget(QWidget *parent)
{
    return new Z_ComboBox(parent);
}

QString Z_ComboBoxPlugin::name() const
{
    return QLatin1String("Z_ComboBox");
}

QString Z_ComboBoxPlugin::group() const
{
    return QLatin1String("");
}

QIcon Z_ComboBoxPlugin::icon() const
{
    return QIcon();
}

QString Z_ComboBoxPlugin::toolTip() const
{
    return QLatin1String("");
}

QString Z_ComboBoxPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool Z_ComboBoxPlugin::isContainer() const
{
    return false;
}

QString Z_ComboBoxPlugin::domXml() const
{
    return QLatin1String("<widget class=\"Z_ComboBox\" name=\"z_ComboBox\">\n</widget>\n");
}

QString Z_ComboBoxPlugin::includeFile() const
{
    return QLatin1String("z_combobox.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(z_comboboxplugin, Z_ComboBoxPlugin)
#endif // QT_VERSION < 0x050000
