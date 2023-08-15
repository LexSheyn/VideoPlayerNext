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

    m_mediaPlayer = new QMediaPlayer();
    m_mediaPlayer->setVideoOutput(m_videoWidget);

    m_tabWidget = new QTabWidget();
    m_tabWidget->setMinimumSize(64, 180);
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

    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* videoLayout = new QHBoxLayout();
    QHBoxLayout* buttonLayout = new QHBoxLayout();

    mainLayout->addLayout(videoLayout);
    mainLayout->addLayout(buttonLayout);

    videoLayout->addWidget(m_videoWidget);
    videoLayout->addWidget(m_tabWidget);
    videoLayout->setStretch(0, 5);
    videoLayout->setStretch(1, 1);

    buttonLayout->addWidget(m_openFileButton);
    buttonLayout->addWidget(m_playButton);
    buttonLayout->addWidget(m_pauseButton);
    buttonLayout->addWidget(m_stopButton);
    buttonLayout->addWidget(new QWidget());
    buttonLayout->setStretch(0, 1);
    buttonLayout->setStretch(1, 1);
    buttonLayout->setStretch(2, 1);
    buttonLayout->setStretch(3, 1);
    buttonLayout->setStretch(4, 2);

    this->setMinimumSize(698, 360);
    this->setLayout(mainLayout);
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
