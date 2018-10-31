#include "imagecroppercontainer.h"
#include "ui_imagecroppercontainer.h"

ImageCropperContainer::ImageCropperContainer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageCropperContainer)
{
    ui->setupUi(this);
}

ImageCropperContainer::~ImageCropperContainer()
{
    delete ui;
}

void ImageCropperContainer::setImage(const QPixmap &_image)
{
    pixmap = _image;
    ui->imageCropper->setImage(_image);
    ui->imageCropper->setProportion(QSizeF(1,1));
    ui->imageCropper->setProportionFixed(true);
    zoomCropper(100);
}

void ImageCropperContainer::setBackgroundColor(const QColor &_backgroundColor)
{
    ui->imageCropper->setBackgroundColor(_backgroundColor);
}

void ImageCropperContainer::setCroppingRectBorderColor(const QColor &_borderColor)
{
    ui->imageCropper->setCroppingRectBorderColor(_borderColor);
}

void ImageCropperContainer::setProportion(const QSizeF &_proportion)
{
    ui->imageCropper->setProportion(_proportion);
}

void ImageCropperContainer::setProportionFixed(const bool _isFixed)
{
    ui->imageCropper->setProportionFixed(_isFixed);
}

const QPixmap ImageCropperContainer::cropImage()
{
    return ui->imageCropper->cropImage();
}

void ImageCropperContainer::zoomCropper(int value)
{
    auto size = pixmap.size();
    double newHeight = size.width() * (value / 100.0);
    double newWidth = size.width() * (value / 100.0);
    ui->imageCropper->setFixedSize(size.scaled(static_cast<int>(newHeight),static_cast<int>(newWidth),Qt::AspectRatioMode::KeepAspectRatio));
    ui->imageCropper->onZoom();
}

void ImageCropperContainer::on_zoomSlider_valueChanged(int value)
{
    zoomCropper(value);
}
