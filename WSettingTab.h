#ifndef WSETTINGTAB_H
#define WSETTINGTAB_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QPushButton;
QT_END_NAMESPACE

class WSettingTab : public QWidget
{
    Q_OBJECT;

public:

    explicit WSettingTab(QWidget* parent = nullptr);
    virtual ~WSettingTab() override;

//public: signals:

    // TO DO

private:

    QPushButton* m_button0;
    QPushButton* m_button1;
    QPushButton* m_button2;
};

#endif // WSETTINGTAB_H
