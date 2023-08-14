#ifndef WCAMERATAB_H
#define WCAMERATAB_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QPushButton;
QT_END_NAMESPACE

class WCameraTab : public QWidget
{
    Q_OBJECT;

public:

    explicit WCameraTab(QWidget* parent = nullptr);
    virtual ~WCameraTab() override;

//public: signals:

    // TO DO

private:

    QPushButton* m_button0;
    QPushButton* m_button1;
    QPushButton* m_button2;
};

#endif // WCAMERATAB_H
