#ifndef IMAGECROPPERWRAPPER_H
#define IMAGECROPPERWRAPPER_H

#include <QWidget>
#include "imagecropper.h"
namespace Ui {
class ImageCropperContainer;
}

class ImageCropperContainer : public QWidget
{
    Q_OBJECT

public:
    explicit ImageCropperContainer(QWidget *parent = nullptr);
    ~ImageCropperContainer();
public slots:
    void setImage(const QPixmap& _image);
    void setBackgroundColor(const QColor& _backgroundColor);
    void setCroppingRectBorderColor(const QColor& _borderColor);
    void setProportion(const QSizeF& _proportion);
    void setProportionFixed(const bool _isFixed);

public:
    const QPixmap cropImage();

private slots:
    void on_zoomSlider_valueChanged(int value);

private:
    Ui::ImageCropperContainer *ui;
    QPixmap pixmap;
    void zoomCropper(int value);
};

#endif // IMAGECROPPERWRAPPER_H
