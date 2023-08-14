#ifndef WDIAGNOSTICTAB_H
#define WDIAGNOSTICTAB_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QPushButton;
QT_END_NAMESPACE

class WDiagnosticTab : public QWidget
{
    Q_OBJECT;

public:

    explicit WDiagnosticTab(QWidget* parent = nullptr);
    virtual ~WDiagnosticTab() override;

//public: signals:

    // TO DO

private:

    QPushButton* m_button0;
    QPushButton* m_button1;
    QPushButton* m_button2;
};

#endif // WDIAGNOSTICTAB_H
