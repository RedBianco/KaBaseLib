#pragma once

// STLのmin、max対策用マクロ
// C++標準ライブラリ側のmin、maxを無効化する
#define NOMINMAX
#include <Windows.h>
#include <time.h>	
#include <math.h>	
#include <stdio.h>	
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <utility>
#include <direct.h>				// ファイル操作
#include <complex.h>			// 複素数計算を行うための関数
#include <iosfwd>
#include <conio.h>
#include <memory>				/** スマートポインタ */
#include <array>				// since C++11
#include <atomic>				// since C++11
#include <cfenv>				// since C++11
#include <chrono>				// since C++11
#include <cinttypes>			// since C++11
#include <condition_variable>	// since C++11
#include <cstdint>				// since C++11
#include <cuchar>				// since C++11
#include <forward_list>			// since C++11
#include <future>				// since C++11
#include <initializer_list>		// since C++11
#include <random>				// since C++11
#include <ratio>				// since C++11
#include <regex>				// since C++11
#include <scoped_allocator>		// since C++11
#include <mutex>				// since C++11
#include <system_error>			// since C++11
#include <thread>				// since C++11
#include <tuple>				// since C++11
#include <type_traits>			// since C++11
#include <typeindex>			// since C++11
#include <unordered_map>		// since C++11
#include <unordered_set>		// since C++11
/*
#include <execution>			// since C++17
#include <filesystem>			// since C++17
#include <memory_resource>		// since C++17
#include <optional>				// since C++17
#include <string_view>			// since C++17
#include <variant>				// since C++17
*/

#include "CervidaeLib/CLAssert.h"

//=================================================================================//
//  appCommonParam.h
//  Cervidae
//
//  Created by kashima akihiro on 2018/11/07.
//=================================================================================//

// ファイル読み込み系
#define  FILE_OPEN( t, fname )			fopen_s( t, fname, "r" )		// テキストファイル等読み込み
#define  FILE_OPEN_BIN( t, fname )		fopen_s( t, fname, "rb" )		// バイナリファイル読み込み
#define  FILE_WRITE( t, fname )			fopen_s( t, fname, "w" )		// テキストファイル等書き込み
#define  FILE_WRITE_BIN( t, fname )		fopen_s( t, fname, "wb" )		// バイナリファイル書き込み

//	汎用ループ計算
#define  VALUE_LOOP( value, max )							((value + max) % (max))
//	三項演算子：定数Ａが１ならtrueを違うならfalseを返す
#define  VALUE_PRM_CHECK( _arg1 )							( _arg1 == 1 )? true : false
//	三項演算子：ビット演算VER
#define  VALUE_PRM_BIT( _arg1, _arg2, _Ret1, _Ret2 )		( _arg1 & _arg2 )? _Ret1 : _Ret2
#define  VALUE_PRM_BIT_CHECK( _arg1, _arg2 )				( _arg1 |= _arg2 )
//	三項演算子：numがsumより小さいならAnsAを、大きいならAnsBを返す
#define  VALUE_PRM_NUM_MIN( _num, _sum, _AnsA, _AnsB )		( _num < _sum )? _AnsA : _AnsB
//	三項演算子：numがsumより大きいならAnsAを、小さいならAnsBを返す
#define  VALUE_PRM_NUM_MAX( _num, _sum, _AnsA, _AnsB )		( _num > _sum )? _AnsA : _AnsB

#define  McsValueLimit( value, limit, adj )					(( (value + limit - adj) % limit) + adj )

// 数学計算系
#define  MAX( x, max )								( (x) > (max) ? (x) : (max) )
#define  MIN( x, min )								( (x) < (min) ? (x) : (min) )
#define  CLAMP( x, min, max )						( (x) < (min) ? (min) : ( (x) > (max) ? (max) : (x) ) )
#define  ABS( x )									abs( x )
#define  ATAN2( y, x )								atan2( y, x )
#define  SIGN( x )									( x == 0 ? (x) = 0 : (x) / ABS(x) )
#define  DEG2RAD( x )								( (x) / 180.0f * PAI )
#define  RAD2DEG( x )								( (x) / PAI * 180.0f )

#define  DegToRad( Red )							(((Red) * PAI) / 180.0f)		// 度→ラジアン
#define  RadToDeg( Red )							(((Red) * 180.0f) / PAI)		// ラジアン→度	
#define  COMPUTE_CIRCLE( r )						(r * r * 3.14)					// 円の面積を計算。r = 半径

//	ミリ秒変換
#define  TICK_TIME_MSEC						( 1000000L )
//	時間変換
#define  CALC_TIME_HOUR( time )				(( time) / 3600)
#define  CALC_TIME_MINUTE( time )			(( time) % 3600 / 60)
#define  CALC_TIME_SECOND( time )			(( time) % 60)

#define  PARAM_BIT_SET( obj, val )			((obj) |= (val))				// ビット値の設定
#define  PARAM_BIT_CLR( obj, val )			((obj) &= ~(val))				// ビット値のクリア
#define  PARAM_BIT_CHK( obj, val )			((obj) & (val))					// ビット値の判定
#define  PARAM_BIT_CMP( obj, val )			(((obj) & (val)) == val )		// ビット値の判定(一致するか)

//	アライメント
#define  VALUE_ALIGN( d, align_size )		d __attribute__(( aligned( align_size ) ))

//	汎用ループ計算
#define  VALUE_LOOP( value, max )			((value + max) % (max))

//	引数無効用
#define  UNUSED_VARIABLE( x )				(void)(x)



namespace CommonList
{
	namespace Resources
	{
		enum ENUM_UI_FILE_TYPE
		{
			eUI_FILE_TYPE_SYSTEM		= 0,
			eUI_FILE_TYPE_ETC,
		};
		enum ENUM_EFFECT_FILE_TYPE
		{
			eEFFECT_FILE_TYPE_2D		= 0,
			eEFFECT_FILE_TYPE_3D
		};
	}
	const std::string   RESOURCES_LOAD_PATH_LUA		= "..\\..\\resources\\script\\lua\\";
	const std::string   RESOURCES_LOAD_PATH_ADX2	= "..\\..\\resources\\script\\sound\\";
	const std::string   RESOURCES_LOAD_PATH_2D		= "..\\..\\resources\\asset\\";
	const std::string   RESOURCES_LOAD_PATH_3D		= "..\\..\\resources\\model\\";
	const std::string   RESOURCES_LOAD_PATH_EFFECT	= "..\\..\\resources\\asset\\effect\\";

	namespace GameSystem
	{
		static const unsigned int			APP_FLAGDATA_ENTRY_MAX = (100);
		static const unsigned int			SYSTEM_FLAGDATA_ENTRY_MAX = (30);
		static const unsigned int			FLAGDATA_USE_MAX = (APP_FLAGDATA_ENTRY_MAX + SYSTEM_FLAGDATA_ENTRY_MAX);
	}

	namespace TaskEvent
	{
		static const unsigned int			EVT_CREATE		= 0;		// タスクが作成された瞬間
		static const unsigned int			EVT_DESTROY		= 1;		// タスクが破棄された瞬間
		static const unsigned int			EVT_RUN			= 2;		// 実行中
		static const unsigned int			EVT_USER		= 3;		// ユーザ任意
		static const unsigned int			EVT_SUSPENSION	= 4;		// 一時中断

		static const signed int				PRIORITY_HIGHEST			= 0x7FFFFFFF;		// プライオリティ：最高
		static const signed int				PRIORITY_ABOVE_NORMAL		= 0x3FFFFFFF;		// プライオリティ：高い
		static const signed int				PRIORITY_NORMAL				= 0x00000000;		// プライオリティ：標準
		static const signed int				PRIORITY_BELOW_NORMAL		= 0xC0000000;		// プライオリティ：低い
		static const signed int				PRIORITY_LOWEST				= 0x80000000;		// プライオリティ：最低

		static const unsigned int			STATE_CODE_ERROR			= 0;			// エラー
		static const unsigned int			STATE_CODE_FREE				= 1;			// 未使用
		static const unsigned int			STATE_CODE_SUSPENDED		= 2;			// 停止中
		static const unsigned int			STATE_CODE_RESERVE			= 3;			// 予約中
		static const unsigned int			STATE_CODE_RUN				= 4;			// 実行中

		static const unsigned int			EVT_TASK_SINGLE				= 0;			// 
		static const unsigned int			EVT_TASK_DOUBLE				= 1;			// 
		static const unsigned int			EVT_TASK_MULTI				= 2;			// 
		static const unsigned int			EVT_TASK_SUSPEND			= 3;			// 
		static const unsigned int			EVT_TASK_CLEAR				= 4;			// 
		static const unsigned int			EVT_TASK_DELETE				= 5;			// 

		enum TASK_PRIORITY_LIST
		{
			eTASK_PRIORITY_MAIN = 0,

			TASK_PRIORITY_LIST_MAX = 16,
		};
	}

	/*! １秒(s)=1,000ミリ秒(ms)=1,000,000マイクロ秒(us)=1,000,000,000ナノ秒(ns)
	*/
	/*! @var static const uint64_t g_unUsecPerFrame
	*/
	static const unsigned __int64		g_unUsecPerFrameCount = static_cast<unsigned __int64>(g_unUsecPerFrameCount);
	/*! @var static const uint64_t g_unUsecPerFrame
	*/
	static const unsigned __int64		g_unUsecPerCountLimit = 99999999;
	/*! @var static const uint64_t g_unUsecPerFrame
	*/
	static const unsigned long long		g_unUsecPerFrame = 16666;
	/*! @var static const float g_fUsecPerFrame
	*/
	static const float		g_fUsecPerFrame = 16666.6f;
	/*! @var static const float g_fInvUsecPerFrame
	*/
	static const float		g_fInvUsecPerFrame = (1.f / g_fUsecPerFrame);
	/*! @var static const float g_fUsecPerCountFrame
	*/
	static const float		g_fUsecPerCountFrame = (1.f / 60.f) * 1000.f * 1000.f;
}




/* End appCommonParam.h */