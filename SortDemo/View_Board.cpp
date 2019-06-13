// ---------------------------------------------------------------------------

#pragma hdrstop

#include "View_Board.h"
#include "Model_Board.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

#include <Vcl.Graphics.hpp>

namespace ColorConverter {

	// ---------------------------------------------------------------------------
	static float HueToRGB(float v1, float v2, float vH) {
		if (vH < 0)
			vH += 1;
		if (vH > 1)
			vH -= 1;
		if ((6 * vH) < 1)
			return (v1 + (v2 - v1) * 6 * vH);
		if ((2 * vH) < 1)
			return v2;
		if ((3 * vH) < 2)
			return (v1 + (v2 - v1) * ((2.0f / 3) - vH) * 6);
		return v1;
	}

	static TColor HLSToTColor(float hue, float light, float sat) {
		float v2 = light * 2;
		float v1 = 2 * light - v2;
		unsigned char r =
			(unsigned char)(255 * HueToRGB(v1, v2, hue + (sat / 3)));
		unsigned char g = (unsigned char)(255 * HueToRGB(v1, v2, hue));
		unsigned char b =
			(unsigned char)(255 * HueToRGB(v1, v2, hue - (sat / 3)));
		return TColor(RGB(r, g, b));
	}
}

// ---------------------------------------------------------------------------
void TBoardView::DrawBoardItem(int index) {
	TCanvas* canvas = PaintBox1->Canvas;
	int boardHeight = PaintBox1->Height;
	int x = index * 3;
	int value = this->FBoardModel->data[index];
	int len = boardHeight * value / BoardModel->MAX_VALUE;
	canvas->Pen->Color = ColorConverter::HLSToTColor
		((float)value / BoardModel->MAX_VALUE, 0.35f, 1.0f);
	canvas->Rectangle(x, 0, x + 2, len);
	canvas->Pen->Color = clWhite;
	canvas->Rectangle(x, len, x + 2, boardHeight);
}
