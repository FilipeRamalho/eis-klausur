#ifndef KLAUSUR_IMAGELOADER_H
#define KLAUSUR_IMAGELOADER_H


#include <QImage>
#include <game/Object.h>

class ImageLoader {


	std::vector<QImage> images;
public:
	ImageLoader();
	QImage getImage(Object* obj);
	QImage getImage(int index);
};


#endif //KLAUSUR_IMAGELOADER_H
