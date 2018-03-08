#ifndef FINDSTRING_H
#define FIND_STRING

#include <QWidget>

namespace Ui {
class FindString;
}

class FindString : public QWidget
{
    Q_OBJECT

public:
    explicit FindString(QWidget *parent = 0);
    ~FindString();

private slots:
    void on_btnGo_clicked();

private:
    Ui::FindString *ui;
    void getTextFile();
};

#endif // FINDSTRING_H
