/*
    SnoreNotify is a Notification Framework based on Qt
    Copyright (C) 2014-2015  Hannah von Reth <vonreth@kde.org>

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

#ifndef SNORELOG_H
#define SNORELOG_H

#include <QDebug>
#include "snore_exports.h"

/**
 * @file
 */

/**
 * SnoreDebugLevels enumerates all possible debugg levels.
 */
enum SnoreDebugLevels {
    /**
     * The most important messages, will be diplayed if the debug level >= 1
     */
    SNORE_WARNING = 0,

    /**
     * Information messages, will be diplayed if the debug level >= 2
     */
    SNORE_INFO = 1,

    /**
     * Debug messages will be diplayed if the debug level >= 3
     */
    SNORE_DEBUG = 2

};

/**
 * Logg macro use to logg messages.
 * snoreDebug( SNORE_DEBUG ) << "Message" << notification;
 */

#if !defined(QT_NO_DEBUG_OUTPUT)
#define snoreDebug(X) Snore::SnoreLog( X ) << #X << Q_FUNC_INFO
#else
#define snoreDebug(X) QNoDebug()
#endif

namespace Snore
{

/**
 * SnoreLog is a helper class to provide a logging system to Snore.
 * @author Hannah von Reth \<vonreth at kde.org\>
 */
class SNORE_EXPORT SnoreLog : public QDebug
{

public:
    /**
     * Creates a debugg message whith a priority lvl.
     * Use the snoreDebug(lvl) macro for logging.<br>
     * snoreDebug( SNORE_DEBUG ) << "Message" << notification;
     * @param lvl
     */
    SnoreLog(SnoreDebugLevels lvl);
    ~SnoreLog();

    /**
     * Sets the debug threshold
     * @param lvl the debug level
     */
    static void setDebugLvl(int lvl);

private:
    SnoreDebugLevels m_lvl;
    QString m_msg;
};

}

#endif // SNORELOG_H
