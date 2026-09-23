#pragma once

#include <QtGui/QColor>
#include <QtGui/QPixmap>
#include <QtGui/QImage>
#include <QtGui/QPainter>
#include <QtGui/QPainterPath>
#include <QtGui/QLinearGradient>
#include <QtGui/QFont>

namespace UzTheme {

// Exact official Telegram Desktop palette tokens
inline const QColor kBgDark{ 0x0e, 0x16, 0x21 };        // #0e1621 (Chat / wallpaper background)
inline const QColor kSidebarBg{ 0x17, 0x21, 0x2b };     // #17212b (Dialogs list / drawer background)
inline const QColor kSearchBg{ 0x24, 0x2f, 0x3d };      // #242f3d (Input / search field background)
inline const QColor kHoverBg{ 0x20, 0x2b, 0x36 };       // #202b36 (Menu row hover background)
inline const QColor kActiveBg{ 0x2b, 0x52, 0x78 };      // #2b5278 (Selection / ripple)
inline const QColor kTelegramBlue{ 0x52, 0x88, 0xc1 };  // #5288c1 (Accent blue)
inline const QColor kTextFg{ 0xff, 0xff, 0xff };        // #ffffff (Primary text)
inline const QColor kSubTextFg{ 0x7f, 0x91, 0xa4 };     // #7f91a4 (Muted labels)
inline const QColor kIconFg{ 0x82, 0x93, 0xa6 };        // #8293a6 (Menu & tray icons)
inline const QColor kIconHoverFg{ 0xff, 0xff, 0xff };   // #ffffff (Hovered icon)
inline const QColor kBorderColor{ 0x10, 0x19, 0x21 };   // #101921 (Separators)

// Load official Telegram icon mask, apply grayscale-to-alpha conversion, and tint to exact color
inline QPixmap TintIcon(const QString &resourcePath, const QColor &color, int targetSize = 20) {
    QImage img(resourcePath);
    if (img.isNull()) {
        img.load(resourcePath.startsWith(":/") ? ("resources/" + resourcePath.mid(2)) : resourcePath);
    }
    if (img.isNull()) {
        return QPixmap();
    }

    int px = targetSize * 2; // High-DPI 2x buffer
    QImage scaled = img.scaled(px, px, Qt::KeepAspectRatio, Qt::SmoothTransformation).convertToFormat(QImage::Format_ARGB32);

    QImage tinted(scaled.size(), QImage::Format_ARGB32_Premultiplied);
    tinted.fill(Qt::transparent);

    const int r = color.red();
    const int g = color.green();
    const int b = color.blue();
    const int baseAlpha = color.alpha();

    // In Telegram Desktop, monochrome icon PNGs are grayscale masks where red/luminance defines the opacity
    for (int y = 0; y < scaled.height(); ++y) {
        const QRgb *srcRow = reinterpret_cast<const QRgb*>(scaled.constScanLine(y));
        QRgb *dstRow = reinterpret_cast<QRgb*>(tinted.scanLine(y));
        for (int x = 0; x < scaled.width(); ++x) {
            QRgb srcPixel = srcRow[x];
            // Use maximum channel value as mask opacity
            int lum = qMax(qRed(srcPixel), qMax(qGreen(srcPixel), qBlue(srcPixel)));
            if (lum > 0) {
                int finalAlpha = (lum * baseAlpha) / 255;
                dstRow[x] = qRgba(r, g, b, finalAlpha);
            } else {
                dstRow[x] = 0; // completely transparent
            }
        }
    }

    tinted.setDevicePixelRatio(2.0);
    return QPixmap::fromImage(tinted);
}

// Generate authentic Telegram blue circular gradient userpic avatar
inline QPixmap CreateTelegramAvatar(int size, const QString &initials = "UZ") {
    int px = size * 2;
    QImage img(px, px, QImage::Format_ARGB32_Premultiplied);
    img.fill(Qt::transparent);

    QPainter p(&img);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setRenderHint(QPainter::TextAntialiasing, true);

    QLinearGradient grad(0, 0, px, px);
    grad.setColorAt(0.0, QColor(0x5c, 0xa7, 0xf4));
    grad.setColorAt(1.0, QColor(0x40, 0x88, 0xd8));

    p.setPen(Qt::NoPen);
    p.setBrush(grad);
    p.drawEllipse(0, 0, px, px);

    p.setPen(Qt::white);
    QFont font("Segoe UI", size * 0.42, QFont::Bold);
    p.setFont(font);
    p.drawText(QRect(0, 0, px, px), Qt::AlignCenter, initials);
    p.end();

    img.setDevicePixelRatio(2.0);
    return QPixmap::fromImage(img);
}

} // namespace UzTheme
