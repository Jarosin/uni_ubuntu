//
// Created by jarozin on 25.04.22.
//
#include "canvas.h"

void Canvas::rotate() {

}

void Canvas::move() {

}

void Canvas::scale() {

}

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    int err = NONE;
    this->filename = SRC_FILE;
    err = this->setup_cube();
}

Canvas::~Canvas() {

}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setPen(Qt::black);
    draw_cube(this->my_cube, painter);
   // painter.setFont(QFont("Arial", 30));
    //painter.drawText(rect(), Qt::AlignCenter, "Qt");
}

int Canvas::setup_cube() {
    int err = NONE;
    FILE *in = fopen(this->filename.c_str(), "r");
    cube *new_cube = nullptr;
    new_cube = alloc_cube();
    if (new_cube != nullptr)
    {
        this->my_cube = *new_cube;
        err = read_cube(this->my_cube, in);
    }
    else
    {
        err = EMPTY_PTR_ERR;
    }
    error_handling(static_cast<errors>(err));
    fclose(in);
    return err;
}
