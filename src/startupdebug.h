#ifndef STARTUPDEBUG_H
#define STARTUPDEBUG_H

#include <QWidget>
#include <QDateTime>
#include <QFileInfo>
#include <QList>
#include <QFileInfoList>
#include <QDir>
#include <memory>
#include <tuple>

#include "crashwindow.h"
#include "logger.h"

namespace StartupDebug {

class StartupDebug {
public:
    StartupDebug(std::shared_ptr<Logger::Logger> ptr);
    int Run();
    bool CheckForCrashes();
    //returns null if no file is found
    QFileInfo GetOldestLogFile(QFileInfoList list);
    //returns null if no file is found
    QFileInfo GetLastLogFile(QFileInfoList list);
private:
    void Crash();
    void CleanLogFiles();
    QDateTime ParseLogName(QString name);

    QFileInfo m_lastlogfile;
    QDir m_AppPath;
    QDir m_LogDir;
    std::shared_ptr<Logger::Logger> m_logger_ptr;

};
}
#endif // STARTUPDEBUG_H
