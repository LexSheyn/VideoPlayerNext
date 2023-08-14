#include "WCameraTab.h"

#include <QtWidgets>

WCameraTab::WCameraTab(QWidget *parent)
    : QWidget (parent)
{
    m_button0 = new QPushButton(tr("Button 0"));
    m_button0->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_button1 = new QPushButton(tr("Button 1"));
    m_button1->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_button2 = new QPushButton(tr("Button 2"));
    m_button2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QHBoxLayout* layout = new QHBoxLayout();

    layout->addWidget(m_button0);
    layout->addWidget(m_button1);
    layout->addWidget(m_button2);

    this->setMinimumSize(64, 180);
    this->setLayout(layout);
}

WCameraTab::~WCameraTab()
{
}
