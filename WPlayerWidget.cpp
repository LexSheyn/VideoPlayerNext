#include "WPlayerWidget.h"

#include "WCameraTab.h"
#include "WSettingTab.h"
#include "WDiagnosticTab.h"

#include <QMediaPlayer>
#include <QVideoWidget>
#include <QtWidgets>

WPlayerWidget::WPlayerWidget(QWidget *parent)
    : QWidget          (parent)
    , m_videoWidget    (nullptr)
    , m_mediaPlayer    (nullptr)
    , m_openFileButton (nullptr)
    , m_playButton     (nullptr)
    , m_pauseButton    (nullptr)
    , m_stopButton     (nullptr)
{
    m_videoWidget = new QVideoWidget();
    m_videoWidget->setMinimumSize(320, 180);
    m_videoWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    m_mediaPlayer = new QMediaPlayer();
    m_mediaPlayer->setVideoOutput(m_videoWidget);

    m_tabWidget = new QTabWidget();
    m_tabWidget->setMinimumSize(64, 180);
    m_tabWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    m_tabWidget->addTab(new WCameraTab(), "Camera");
    m_tabWidget->addTab(new WSettingTab(), "Settings");
    m_tabWidget->addTab(new WDiagnosticTab(), "Diagnostics");

    m_openFileButton = new QPushButton(tr("Open File"));
    m_openFileButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    connect(m_openFileButton, &QAbstractButton::clicked, this, &WPlayerWidget::openFile);

    m_playButton = new QPushButton(tr("Play"));
    m_playButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    connect(m_playButton, &QAbstractButton::clicked, m_mediaPlayer, &QMediaPlayer::play);

    m_pauseButton = new QPushButton(tr("Pause"));
    m_pauseButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    connect(m_pauseButton, &QAbstractButton::clicked, m_mediaPlayer, &QMediaPlayer::pause);

    m_stopButton = new QPushButton(tr("Stop"));
    m_stopButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    connect(m_stopButton, &QAbstractButton::clicked, m_mediaPlayer, &QMediaPlayer::stop);

    QGridLayout* layout = new QGridLayout();

    layout->addWidget(m_videoWidget,    0, 0, 4, 5);
    layout->addWidget(m_openFileButton, 5, 0, 1, 1);
    layout->addWidget(m_playButton,     5, 1, 1, 1);
    layout->addWidget(m_pauseButton,    5, 2, 1, 1);
    layout->addWidget(m_stopButton,     5, 3, 1, 1);
    layout->addWidget(m_tabWidget,      0, 15, 1, 1);

    this->setMinimumSize(698, 360);
    this->setLayout(layout);
}

WPlayerWidget::~WPlayerWidget()
{

}

void WPlayerWidget::openFile()
{
    const QString videoPath = QStandardPaths::standardLocations(QStandardPaths::MoviesLocation).value(0, QDir::homePath());

    QFileDialog fileDialog(this);

    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Files"));
    fileDialog.setDirectory(videoPath);

    if (fileDialog.exec() == QDialog::Accepted)
    {
        m_mediaPlayer->setMedia(fileDialog.selectedUrls()[0]);
    }
}
