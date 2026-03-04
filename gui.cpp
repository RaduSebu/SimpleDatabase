#include "gui.h"
#include <QPushButton>
#include <QVBoxLayout>

gui::gui() {
    w = new QWidget();
}

void gui::exec() {
    w->setFixedSize(500,400);
    w->show();
}
