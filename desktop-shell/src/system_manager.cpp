#include "system_manager.h"
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QDebug>

SystemManager::SystemManager(QObject *parent)
    : QObject(parent)
{
    m_clockTimer = new QTimer(this);
    connect(m_clockTimer, &QTimer::timeout, this, &SystemManager::updateClock);
    m_clockTimer->start(1000);
    updateClock();

    m_statsTimer = new QTimer(this);
    connect(m_statsTimer, &QTimer::timeout, this, &SystemManager::updateStats);
    m_statsTimer->start(3000);
    updateStats();
}

void SystemManager::updateClock()
{
    QString formatted = QDateTime::currentDateTime().toString("HH:mm");
    if (formatted != m_currentTime) {
        m_currentTime = formatted;
        emit timeChanged();
    }
}

void SystemManager::updateStats()
{
#if defined(Q_OS_LINUX)
    QFile file("/proc/meminfo");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        long memTotal = 0, memAvailable = 0;
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.startsWith("MemTotal:")) {
                memTotal = line.split(QRegularExpression("\\s+")).at(1).toLong();
            } else if (line.startsWith("MemAvailable:")) {
                memAvailable = line.split(QRegularExpression("\\s+")).at(1).toLong();
            }
        }
        if (memTotal > 0) {
            m_ramTotalMb = static_cast<int>(memTotal / 1024);
            m_ramUsedMb = static_cast<int>((memTotal - memAvailable) / 1024);
        }
    }
#else
    m_ramUsedMb = 380;
    m_ramTotalMb = 8192;
#endif
    m_zramActive = true;
    emit systemStatsChanged();
}

void SystemManager::launchApp(const QString &command)
{
    qDebug() << "[UzOS Shell] Ilova ishga tushirilmoqda:" << command;
    QProcess::startDetached(command, QStringList());
}

void SystemManager::openTerminal()
{
    launchApp("x-terminal-emulator");
}

void SystemManager::openFileManager()
{
    launchApp("xdg-open ~");
}

void SystemManager::openSettings()
{
    launchApp("uzos-settings");
}

void SystemManager::powerOff()
{
    launchApp("systemctl poweroff");
}

void SystemManager::reboot()
{
    launchApp("systemctl reboot");
}

void SystemManager::triggerNotification(const QString &sender, const QString &message)
{
    QString timeStr = QDateTime::currentDateTime().toString("HH:mm");
    emit notificationReceived(sender, message, timeStr);
}
