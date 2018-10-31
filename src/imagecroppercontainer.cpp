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
    ui->imageCropper->setImage(_image);
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
