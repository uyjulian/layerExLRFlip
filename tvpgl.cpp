// Copied tvpgl functions, because we can't rely on the core to have them.

#include "tvpgl.h"

TVP_GL_FUNC_DECL(void, TVPReverse32_c, (tjs_uint32 *pixels, tjs_int len))
{
	tjs_uint32 *pixels2 = pixels + len -1u;
	len/=2u;
	for(int lu_n = 0; lu_n < len; lu_n++)
	{
		{
			tjs_uint32 tmp = *pixels;
			*pixels = *pixels2;
			*pixels2 = tmp;
			pixels2 --;
			pixels++;
		}
	}
}

TVP_GL_FUNC_DECL(void, TVPReverse8_c, (tjs_uint8 *pixels, tjs_int len))
{
	tjs_uint8 *pixels2 = pixels + len -1u;
	len/=2u;
	for(int lu_n = 0; lu_n < len; lu_n++)
	{
		{
			tjs_uint8 tmp = *pixels;
			*pixels = *pixels2;
			*pixels2 = tmp;
			pixels2 --;
			pixels++;
		}
	}
}
