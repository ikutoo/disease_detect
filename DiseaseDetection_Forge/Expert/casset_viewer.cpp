#include "casset_viewer.h"
#include <QLabel>
#include <QPixmap>
///////////////////////////////////////////////////////////////////
//all public functions are here
///////////////////////////////////////////////////////////////////
CAssetViewer::CAssetViewer() {

}

CAssetViewer::~CAssetViewer() {

}
void CAssetViewer::sPreViewFile(const QString &path, const QString &type, const QPointF &point) {
	if (type == "picture")
		mPreViewPicture(path, type, point);
	if (type == "audio")
		mPreViewAudio(path, type, point);
	if (type == "text")
		mPreViewText(path, type, point);
}
///////////////////////////////////////////////////////////////////
//all private functions are here
///////////////////////////////////////////////////////////////////
void CAssetViewer::run() {

}
void CAssetViewer::mPreViewPicture(const QString &path, const QString &type, const QPointF &point) {
	QLabel *label = new QLabel();
	QPixmap pix(path);
	pix = pix.scaled(200, 200, Qt::KeepAspectRatio);
	label->setPixmap(pix);
	label->move(point.x(), point.y());
	label->show();
}

void CAssetViewer::mPreViewAudio(const QString &path, const QString &type, const QPointF &point) {
}

void CAssetViewer::mPreViewText(const QString &path, const QString &type, const QPointF &point) {
}



