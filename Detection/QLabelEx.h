#pragma once
#include <QLabel>
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include <QApplication>
#include <QVector>

#include "JsonTool.h"

class QLabelEx : public QLabel
{
	Q_OBJECT
private:
	bool m_debug = true;

	bool m_press = false;
	
	int m_startX = 0;
	
	int m_startY = 0;
	
	int m_endX = 0;
	
	int m_endY = 0;
	
	QVector<QPoint> m_startCoord;
	
	QVector<QPoint> m_endCoord;
protected:
	void paintEvent(QPaintEvent* paintEvent);

	void mousePressEvent(QMouseEvent* event);
	
	void mouseReleaseEvent(QMouseEvent* event);
	
	void mouseMoveEvent(QMouseEvent* event);
public:
	QLabelEx(QWidget* parent = nullptr);
	
	~QLabelEx();
	
	void enableDebug(bool debug);

	void getCoordinate(QVector<QPoint>* start, QVector<QPoint>* end);

signals:
	void coordinateSignal(const QPoint& point);
};
