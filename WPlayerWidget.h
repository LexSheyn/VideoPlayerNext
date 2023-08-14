#ifndef WPLAYERWIDGET_H
#define WPLAYERWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QMediaPlayer;
class QVideoWidget;
class QTabWidget;
class QPushButton;
QT_END_NAMESPACE

class WPlayerWidget : public QWidget
{
    Q_OBJECT;

public:

    explicit WPlayerWidget(QWidget *parent = nullptr);
    virtual ~WPlayerWidget() override;

private slots:

    void openFile();

private:

    QVideoWidget* m_videoWidget;
    QMediaPlayer* m_mediaPlayer;
    QTabWidget*   m_tabWidget;

    QPushButton*  m_openFileButton;
    QPushButton*  m_playButton;
    QPushButton*  m_pauseButton;
    QPushButton*  m_stopButton;
};

#endif // WPLAYERWIDGET_H
