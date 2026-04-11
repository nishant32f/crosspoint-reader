#include "BootActivity.h"

#include <GfxRenderer.h>
#include <I18n.h>

#include "fontIds.h"
#include "images/Logo120.h"

namespace {
constexpr const char* kBootMotto = "Sic Parvis Magna";
constexpr const char* kBootStatus = "WARPING...";
constexpr const char* kBootSignature = "Nishant Khurana";
}

void BootActivity::onEnter() {
  Activity::onEnter();

  const auto pageWidth = renderer.getScreenWidth();
  const auto pageHeight = renderer.getScreenHeight();
  const int logoY = pageHeight / 2 - 100;
  const int signatureRightMargin = 24;

  renderer.clearScreen();
  renderer.drawImage(Logo120, (pageWidth - 120) / 2, logoY, 120, 120);
  renderer.drawCenteredText(UI_10_FONT_ID, pageHeight / 2 + 50, kBootMotto, true, EpdFontFamily::BOLD);
  renderer.drawCenteredText(SMALL_FONT_ID, pageHeight / 2 + 88, kBootStatus);

  const int signatureWidth = renderer.getTextWidth(UI_10_FONT_ID, kBootSignature, EpdFontFamily::BOLD);
  renderer.drawText(UI_10_FONT_ID, pageWidth - signatureRightMargin - signatureWidth, pageHeight - 36, kBootSignature,
                    true, EpdFontFamily::BOLD);
  renderer.displayBuffer();
}
