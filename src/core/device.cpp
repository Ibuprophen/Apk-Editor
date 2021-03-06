#include "device.h"

QList<Device> Devices::devices;

// Devices

void Devices::init()
{
    const QIcon ANDROID(":/gfx/devices/android.png");
    const QIcon BLACKBERRY(":/gfx/devices/blackberry.png");
    const QIcon AMAZON(":/gfx/devices/amazon.png");

    const QSize TV(320, 180);

    Device android("Android Default", ANDROID, 36, 48, 72, 96, 144, 192, TV);
    Device bb_q10("BlackBerry Q10", BLACKBERRY, 90, 90, 90, 90, 90, 90, TV); // Q10, Q5, Q10
    Device bb_z10("BlackBerry Z10", BLACKBERRY, 110, 110, 110, 110, 110, 110, TV);
    Device bb_z30("BlackBerry Z30", BLACKBERRY, 96, 96, 96, 96, 96, 96, TV); // Z30, Z3, Z30
    Device bb_passport("BlackBerry Passport", BLACKBERRY, 144, 144, 144, 144, 144, 144, TV);
    Device kindle1("Kindle Fire (1st Gen)", AMAZON, 36, 322, 72, 96, 144, 192, TV);
    Device kindle2("Kindle Fire (2nd Gen)", AMAZON, 36, 365, 72, 96, 144, 192, TV);
    Device kindle3("Kindle Fire HD 7\" (2nd Gen)", AMAZON, 36, 48, 425, 96, 144, 192, TV);
    Device kindle4("Kindle Fire HD 8.9\" (2nd Gen)", AMAZON, 36, 48, 675, 96, 144, 192, TV);
    Device kindle5("Kindle Fire HD 7\" (3rd Gen)", AMAZON, 36, 48, 375, 96, 144, 192, TV);
    Device kindle6("Kindle Fire HDX 7\" (3rd Gen)", AMAZON, 36, 48, 72, 562, 144, 192, TV);
    Device kindle7("Kindle Fire HDX 8.9\" (3rd Gen)", AMAZON, 36, 48, 72, 624, 144, 192, TV);
    Device kindle8("Kindle Fire - All Models", AMAZON, 36, 365, 675, 624, 144, 192, TV);
    kindle1.setHintMdpi("Carousel");
    kindle2.setHintMdpi("Carousel");
    kindle3.setHintHdpi("Carousel");
    kindle4.setHintHdpi("Carousel");
    kindle5.setHintHdpi("Carousel");
    kindle6.setHintXhdpi("Carousel");
    kindle7.setHintXhdpi("Carousel");
    kindle8.setHintMdpi("Kindle Fire Carousel");
    kindle8.setHintHdpi("Kindle Fire HD Carousel");
    kindle8.setHintXhdpi("Kindle Fire HDX Carousel");

    devices.push_back(android);
    devices.push_back(bb_q10);
    devices.push_back(bb_z10);
    devices.push_back(bb_z30);
    devices.push_back(bb_passport);
    devices.push_back(kindle1);
    devices.push_back(kindle2);
    devices.push_back(kindle3);
    devices.push_back(kindle4);
    devices.push_back(kindle5);
    devices.push_back(kindle6);
    devices.push_back(kindle7);
    devices.push_back(kindle8);
}

// Device

Device::Device(QString title, QIcon thumb,
               short ldpi, short mdpi, short hdpi,
               short xhdpi, short xxhdpi, short xxxhdpi,
               QSize banner)
{
    this->title = title;
    this->thumb = thumb;
    sizes.push_back(Dpi("LDPI", QSize(ldpi, ldpi)));
    sizes.push_back(Dpi("MDPI", QSize(mdpi, mdpi)));
    sizes.push_back(Dpi("HDPI", QSize(hdpi, hdpi)));
    sizes.push_back(Dpi("XHDPI", QSize(xhdpi, xhdpi)));
    sizes.push_back(Dpi("XXHDPI", QSize(xxhdpi, xxhdpi)));
    sizes.push_back(Dpi("XXXHDPI", QSize(xxxhdpi, xxxhdpi)));
    sizes.push_back(Dpi("TV", banner));
}

QSize Device::getDpiSize(Dpi::Type dpi) const
{
    return sizes.at(dpi).size;
}

QString Device::getDpiTitle(Dpi::Type dpi) const
{
    const Dpi DPI = sizes.at(dpi);
    return DPI.info.isNull()
           ? QString("%1 (%2x%3)").arg(DPI.title).arg(DPI.size.width()).arg(DPI.size.height())
           : QString("%1 (%2x%3) - %4").arg(DPI.title).arg(DPI.size.width()).arg(DPI.size.height()).arg(DPI.info);
}
