
#include "tjsCommHead.h"
#include "LayerBitmapIntf.h"
#include "LayerBitmapLRFlip.h"

void LRFlip(tTVPBaseBitmap *destbmp, const tTVPRect &rect)
{
	// left-right flip
	if(rect.left < 0 || rect.top < 0 || rect.right > (tjs_int)destbmp->GetWidth() ||
		rect.bottom > (tjs_int)destbmp->GetHeight())
				TVPThrowExceptionMessage(TJS_W("Source rectangle out of bitmap"));

	tjs_int h = rect.bottom - rect.top;
	tjs_int w = rect.right - rect.left;

	tjs_int pitch = destbmp->GetPitchBytes();
	tjs_uint8 * line = (tjs_uint8*)destbmp->GetScanLineForWrite(rect.top);

	if(destbmp->Is32BPP())
	{
		// 32bpp
		line += rect.left * sizeof(tjs_uint32);
		while(h--)
		{
			TVPReverse32((tjs_uint32*)line, w);
			line += pitch;
		}
	}
	else
	{
		// 8bpp
		line += rect.left;
		while(h--)
		{
			TVPReverse8(line, w);
			line += pitch;
		}
	}
}
