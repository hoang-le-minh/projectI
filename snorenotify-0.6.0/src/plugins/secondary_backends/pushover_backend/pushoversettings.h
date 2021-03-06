/*
    SnoreNotify is a Notification Framework based on Qt
    Copyright (C) 2015  Hannah von Reth <vonreth@kde.org>

    SnoreNotify is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    SnoreNotify is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with SnoreNotify.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef PUSHOVERSETTINGS_H
#define PUSHOVERSETTINGS_H

#include "plugins/pluginsettingswidget.h"

class QLineEdit;

class PushoverSettings : public Snore::PluginSettingsWidget
{
    Q_OBJECT
public:
    explicit PushoverSettings(Snore::SnorePlugin *plugin, QWidget *parent = 0);
    ~PushoverSettings();

    void load() override;
    void save() override;

private:
    QLineEdit *m_keyLineEdit;
    QLineEdit *m_soundLineEdit;
    QLineEdit *m_deviceLineEdit;

};

#endif // PUSHOVERSETTINGS_H
