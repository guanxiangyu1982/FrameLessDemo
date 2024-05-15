#pragma once

#include <QtWidgets/QWidget>
#include "ui_FrameLessDemo.h"

//namespace Ui {
//    class FrameLessDemo;
//}
class FrameLessDemo : public QWidget
{
    Q_OBJECT

public:
    explicit FrameLessDemo(QWidget *parent = nullptr);
    virtual ~FrameLessDemo();
    void setContent(QWidget* w);

private:
    bool leftBorderHit(const QPoint& pos);
    bool rightBorderHit(const QPoint& pos);
    bool topBorderHit(const QPoint& pos);
    bool bottomBorderHit(const QPoint& pos);
    void styleWindow(bool bActive, bool bNoState);

public slots:
    void setWindowTitle(const QString& text);
    void setWindowIcon(const QIcon& ico);

private slots:
    void on_applicationStateChanged(Qt::ApplicationState state);
    void on_minimizeButton_clicked();
    void on_restoreButton_clicked();
    void on_maximizeButton_clicked();
    void on_closeButton_clicked();
    void on_windowTitlebar_doubleClicked();

protected:
    virtual void changeEvent(QEvent* event);
    virtual void mouseDoubleClickEvent(QMouseEvent* event);
    virtual void checkBorderDragging(QMouseEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual bool eventFilter(QObject* obj, QEvent* event);
private:
    Ui::FrameLessDemoClass ui;

    QRect m_StartGeometry;
    const quint8 CONST_DRAG_BORDER_SIZE = 15;
    bool m_bMousePressed;
    bool m_bDragTop;
    bool m_bDragLeft;
    bool m_bDragRight;
    bool m_bDragBottom;
};
