#include <objects/Wall.h>
#include <objects/SmartGhost.h>
#include <objects/PacDot.h>
#include <objects/Player.h>
#include <objects/PacPill.h>
#include <QPixmap>
#include <QBitmap>
#include "ImageLoader.h"

QImage ImageLoader::getImage(Object *obj) {
	if(dynamic_cast<Wall*>(obj)){
		auto* wall = dynamic_cast<Wall*>(obj);
		switch (wall->type) {
			case BRICK:	return images[0];
			case HOR: return images[4];
			case VERT: return images[5];
			case LL: return images[6];
			case LU: return images[7];
			case RL: return images[9];
			case RU: return images[8];
		}
	}
	if(dynamic_cast<SmartGhost*>(obj)){
		return images[10];
	}
	if(dynamic_cast<Ghost*>(obj)){
		return images[1];
	}
	if(dynamic_cast<PacPill*>(obj)){
		// Quelle [6]
		QImage image = images[2];

		for(int y = 0; y < image.height(); y++)
			for(int x= 0; x < image.width(); x++)
				if(image.pixelColor(x,y) == Qt::white)
					image.setPixelColor(x,y,Qt::red);

		return image;
	}
	if(dynamic_cast<PacDot*>(obj)){
		return images[2];
	}
	if(dynamic_cast<Player*>(obj)){
		// Quelle [6]
		auto* player = dynamic_cast<Player*>(obj);
		if(player->pill_ticks > 0){
			QImage image = images[3];

			for(int y = 0; y < image.height(); y++)
				for(int x= 0; x < image.width(); x++)
					if(image.pixelColor(x,y) == Qt::yellow)
						image.setPixelColor(x,y,Qt::green);

			return image;
		}
		return images[3];
	}
	return images[0];
}

QImage ImageLoader::getImage(int index) {
	return images[index];
}

ImageLoader::ImageLoader() {
	images = {
			QImage("brick.png").scaled(20,20), //images[0]
			QImage("stupid_ghost.png").scaled(20,20), //images[1]
			QImage("dot.png").scaled(20,20), //images[2]
			QImage("pacman.png").scaled(20,20), //images[3]
			QImage("h-wall.png").scaled(20,20), //images[4]
			QImage("v-wall.png").scaled(20,20), //images[5]
			QImage("left-lower-corner.png").scaled(20,20), //images[6]
			QImage("left-upper-corner.png").scaled(20,20), //images[7]
			QImage("right-upper-corner.png").scaled(20,20), //images[8]
			QImage("right-lower-corner.png").scaled(20,20), //images[9]
			QImage("smart_ghost.png").scaled(20,20), //images[10]
	};
}
