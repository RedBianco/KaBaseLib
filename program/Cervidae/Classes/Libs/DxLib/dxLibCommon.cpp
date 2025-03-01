
#include "DxLib.h"
#include "dxLibDefine.h"
#include "../../Common/appCommonParam.h"
#include "../../Common/appErrorCode.h"
#include "../../Common/appProcessCode.h"

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * 
 */
void	dxCommon_DrawFramerate( const int renderRate )
{
	DxLib::SetDrawBlendMode( DX_BLENDMODE_ALPHA, 255 );

	// DrawFormatStringは呼び続けないと消える
	DxLib::DrawFormatString(	DxLibCommon::Parameter::DISPLAY_FLAMERATE_POS_X,
								DxLibCommon::Parameter::DISPLAY_FLAMERATE_POS_Y,
								GetColor( 255, 255, 255 ), "FPS : %d", renderRate );
}



