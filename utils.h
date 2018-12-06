#ifndef UTILS_H
#define UTILS_H

#include <QImage>
#include <QColor>
#include <iostream>
#include "codelib/image/rgb.image.h"
#include "codelib/image/gray.image.h"
#include "codelib/image/binary.image.h"

namespace Utils {

    codelib::rgb_image QImage2RGBImage(const QImage &from) {

        codelib::rgb_image to(from.width(), from.height());

        for (unsigned i = 0; i < to.get_width(); ++i) {
            for (unsigned j = 0; j < to.get_height(); ++j) {
                QColor color(from.pixel(i, j));
                to(i,j).set_red(color.red());
                to(i,j).set_green(color.green());
                to(i,j).set_blue(color.blue());
            }
        }

        return to;
    }

    QImage RGBImage2QImage(const codelib::rgb_image &from) {
        QImage to(from.get_width(), from.get_height(), QImage::Format_RGB16);

        for (unsigned i = 0; i < from.get_width(); ++i) {
            for (unsigned j = 0; j < from.get_height(); ++j) {
                to.setPixel(i, j, QColor(
                    from(i,j).get_red(),
                    from(i,j).get_green(),
                    from(i,j).get_blue()
                ).rgb());
            }
        }

        return to;
    }

    QImage GrayImage2QImage(const codelib::gray_image &from) {
        QImage to(from.get_width(), from.get_height(), QImage::Format_RGB16);

        for (unsigned i = 0; i < from.get_width(); ++i) {
            for (unsigned j = 0; j < from.get_height(); ++j) {
                to.setPixel(i, j, QColor(from(i,j), from(i,j), from(i,j)).rgb());
            }
        }

        return to;
    }

    QImage BinaryImage2QImage(const codelib::binary_image &from) {
        QImage to(from.get_width(), from.get_height(), QImage::Format_RGB16);

        for (unsigned i = 0; i < from.get_width(); ++i) {
            for (unsigned j = 0; j < from.get_height(); ++j) {
                unsigned t = (from(i,j) == 0) ? 0 : 255;

                to.setPixel(i, j, QColor(t, t, t).rgb());
            }
        }

        return to;
    }

}

#endif // UTILS_H
