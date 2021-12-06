#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>

#include "display.h"
#ifdef AF
#include "src/afdata.h"
#else
#include "src/rpdata.h"
#endif

class RenderArea : public QWidget {
	Q_OBJECT

  public:
	explicit RenderArea(QWidget *parent, Display &display);
	Display &display;

	QSize minimumSizeHint() const override;
	QSize sizeHint() const override;

  public slots:
	void setPage(Page p) {
		page = p;
		update();
	};

  protected:
	virtual void paintEvent(QPaintEvent *event) override;
	virtual void mousePressEvent(QMouseEvent *event) override;

  private:
	Page page;
	qreal scaleFactor;

  signals:
	void itemClicked(int);
};

#endif // RENDERAREA_H