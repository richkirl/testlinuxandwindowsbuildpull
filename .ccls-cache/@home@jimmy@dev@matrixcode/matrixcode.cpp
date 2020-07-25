#include "matrixcode.hpp"
// #include <QResizeEvent>
#include <GL/gl.h>
#include <QDebug>
#include <QFont>
#include <QString>
#include <QTimer>
#include <QTimerEvent>
#include <iostream>
#include <list>
#include <map>
#include <random>
#include <sstream>
#include <vector>
matrixcode::matrixcode() { matrixcode::inithisprogram();}
matrixcode::~matrixcode() {}
void matrixcode::initializeGL() {
  glViewport(0, 0, 800, 600);
  glLoadIdentity();
  glOrtho(0, 800, 0, 600, 0, 1);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glDisable(GL_DEPTH);
  glEnable(GL_MULTISAMPLE);
  glEnable(GL_BLEND);
  glEnable(GL_LINE_SMOOTH);
  glEnable(GL_POINT_SMOOTH);
  glEnable(GL_SMOOTH);
}
void matrixcode::resizeGL(int aw, int ah) {
  glViewport(0, 0, (GLint)aw, (GLint)ah);
  glLoadIdentity();
  glOrtho(0, aw, ah, 0, 0, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}
void matrixcode::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  qglClearColor(Qt::black);
  _processing();
  _draw();
}
void matrixcode::resizeEvent(QResizeEvent *e) {

    if(e->Resize) {
        auto aw = this->width();
        auto ah = this->height();
        matrixcode::resizeGL(aw,ah);
    }
}
void matrixcode::_processing() {}
void matrixcode::_draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  static auto font = QFont("Terminus", 18);
  font.setStyleName("Terminus");
  renderText(this->x1, this->y1, (QString)stringelement=rand()%25+97, font);
}
void matrixcode::keyReleaseEvent(QKeyEvent *e) {
    if(e->key()==Qt::Key_Escape) close();
}
void matrixcode::inithisprogram() {
    this->x1=20;
    this->y1=20;
    this->a.setHMS(0,0,0);
    QTimer *tmr = new QTimer;
    connect(tmr,SIGNAL(timeout()),this,SLOT(updateGL()));
    tmr->start(32);
    this->timerID=startTimer(32);
}
void matrixcode::updatetime() {
    this->a=this->a.addSecs(1);
}
void matrixcode::timerEvent(QTimerEvent *e){

}
