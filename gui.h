#ifndef PROIECTINFO_GUI_H
#define PROIECTINFO_GUI_H

#include <QPushButton>
#include <QVBoxLayout>

class gui {
private:
    QWidget &w;
    QVBoxLayout &layout;
    QPushButton &list_button;
    QPushButton &add_button;
    QPushButton &remove_button;
    QPushButton &info_button;
    QPushButton &exit_button;
public:
    explicit gui(QWidget *parent);

    void exec();
};

#endif //PROIECTINFO_GUI_H