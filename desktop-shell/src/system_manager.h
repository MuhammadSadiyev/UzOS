#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <QProcess>

class SystemManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int ramUsedMb READ ramUsedMb NOTIFY systemStatsChanged)
    Q_PROPERTY(int ramTotalMb READ ramTotalMb NOTIFY systemStatsChanged)
    Q_PROPERTY(bool zramActive READ zramActive NOTIFY systemStatsChanged)
    Q_PROPERTY(QString currentTime READ currentTime NOTIFY timeChanged)
    Q_PROPERTY(bool telemetryBlocked READ telemetryBlocked CONSTANT)

public:
    explicit SystemManager(QObject *parent = nullptr);

    int ramUsedMb() const { return m_ramUsedMb; }
    int ramTotalMb() const { return m_ramTotalMb; }
    bool zramActive() const { return m_zramActive; }
    QString currentTime() const { return m_currentTime; }
    bool telemetryBlocked() const { return true; }

    Q_INVOKABLE void launchApp(const QString &command);
    Q_INVOKABLE void openTerminal();
    Q_INVOKABLE void openFileManager();
    Q_INVOKABLE void openSettings();
    Q_INVOKABLE void powerOff();
    Q_INVOKABLE void reboot();
    Q_INVOKABLE void triggerNotification(const QString &sender, const QString &message);

signals:
    void systemStatsChanged();
    void timeChanged();
    void notificationReceived(const QString &sender, const QString &message, const QString &timestamp);

private slots:
    void updateStats();
    void updateClock();

private:
    int m_ramUsedMb = 380;
    int m_ramTotalMb = 8192;
    bool m_zramActive = true;
    QString m_currentTime;
    QTimer *m_statsTimer;
    QTimer *m_clockTimer;
};

#endif // SYSTEM_MANAGER_H
