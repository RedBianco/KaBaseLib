#pragma once


//===================================================================//
//
//
//  Created by kashima akihiro on 2019/03/09.
//===================================================================//

// namespace内定義に同じnamespace使用定義は使えない

namespace DxLibSound
{
	namespace BaseInfo
	{
		const static char * SE_PLAY_RESULT_OK	= "SE_Answer.mp3";
		const static char * SE_PLAY_SELECT		= "SE_Select.mp3";
		const static char * SE_PLAY_CANCEL		= "SE_Cancel.mp3";

		const static int			SOUND_STREAM_NORMALPLAY	= DX_PLAYTYPE_NORMAL;	// @param ノーマル再生
		const static int			SOUND_STREAM_BACKGRPLAY	= DX_PLAYTYPE_BACK;		// @param バックグラウンド再生
		const static int			SOUND_STREAM_BACKGRLOOP	= DX_PLAYTYPE_LOOP;		// @param バックグラウンド＋ループ再生

		const static int			SOUND_FILE_MEMORY_ENTRY_MAX = ( 8 );			// @param メモリ登録ＳＥファイル最大数

		const static int			SETTING_STREAM_SYNCHRO_PLAY_MAX	= ( 4 );		// @param ストリーム同時再生最大数
		const static int			SETTING_FILE_MEMORY_ENTRY_MAX	= ( 8 );		// @param メモリ登録ＳＥファイル最大数
		const static int			SETTING_BGM_SYNCHRO_PLAY_MAX	= ( 2 );		// @param BGMの同時最大保持数(再生数)

		const static unsigned int	SOUND_SAMPLE_FREQUENCY = 44100;					// @param サンプル周波数
	}
	namespace Command
	{
		typedef enum// @enum 
		{
			eSYSTEM_SE_SELECT		= 0,	// 選択
			eSYSTEM_SE_OK			= 1,	// 決定
			eSYSTEM_SE_CANCEL		= 2,	// キャンセル
			eSYSTEM_SE_PAUSE		= 3,	// ポーズ

			eSYSTEM_SE_COMMAND_MAX
		} ENUM_SYSTEM_SE_COMMAND;
        
		typedef enum// @enum 
		{
			eSOUND_PLAY_STREAM		= 0,	// ストリーム再生
			eSOUND_PLAY_MEMORY		= 1,	// メモリロード再生

			eSOUND_PLAY_MODE_MAX
		} ENUM_SOUND_PLAY_MODE;

		typedef enum// @enum 
		{
			eSOUND_PROCESS_STOP		= 0,	// 再生停止命令
			eSOUND_PROCESS_PLAY,			// 再生開始命令
			eSOUND_PROCESS_CHECK,			// 再生状況チェック命令

			eSOUND_PROCESS_MAX
		} ENUM_SOUND_PROCESS_LIST;

		typedef enum// @enum 
		{
			eSOUND_ORDER_STOP		= 0,	// 再生停止
			eSOUND_ORDER_PLAY,				// 再生中
			eSOUND_ORDER_PAUSE,				// 再生一時停止

			eSOUND_ORDER_MAX
		} ENUM_SOUND_ORDER_LIST;

		typedef enum// @enum 
		{
			eSEDATA_ENTRY_NON		= -1,	// 未登録
			eSEDATA_ENTRY_SET, 

			eSEDATA_ENTRY_MAX
		} ENUM_SOUND_SEDATA_ENTRY;

		typedef enum// @enum 
		{
			eSEHANDLE_NOTLOAD = -1,
			eSEHANDLE_LOADCLEAR,
		} ENUM_SOUND_SEHANDLE_STATE;
	}
	namespace Movie
	{
		const static int	SOFDEC_PLAYING_KEYLOCK = DX_MOVIEPLAYTYPE_NORMAL;		// 再生ボタンキャンセルなし (1 << 0)
		const static int	SOFDEC_PLAYING_KEYCANCEL = DX_MOVIEPLAYTYPE_BCANCEL;	// 再生ボタンキャンセルあり (1 << 1)
		const static int	SOFDEC_PLAYING_SKIPKEY = KEY_INPUT_RETURN;				// ムービー再生スキップキー
		const static int	SOFDEC_FILE_FORMAT_LEN = ( 4 );
		const static int	SOFDEC_PLAY_NOUSE = ( -1);

		enum	DXENUM_SOFDEC_PLAY
		{
			eSOFDEC_PLAYTOPAUSE = 0,			// ムービーグラフィックの動画再生を一時停止する
			eSOFDEC_PLAYTOSEEK,					// ムービーグラフィックの動画の再生位置を変更する
			eSOFDEC_PLAYTOTIMECOUNT,			// ムービーグラフィックの動画の再生位置を得る
			eSOFDEC_PLAYTOSTATE,				// ムービーグラフィックの動画の再生状態を得る
		};

		enum	DXENUM_SOFDEC_PROCSTATE
		{
			eSOFDEC_STATE_PLAYERROR = -1,		// ムービー再生エラー
			eSOFDEC_STATE_PLAYSTOP = 0,			// ムービー停止中
			eSOFDEC_STATE_PLAYING = 1,			// ムービー再生中
			eSOFDEC_STATE_PLAYPAUSE,			// ムービー一時停止中
			eSOFDEC_STATE_PLAYSKIPSTOP,
		};

		enum	DXENUM_SOFDEC_PLAYRESULT
		{
			eSOFDEC_PLAYRESULT_NONE = -1,
			eSOFDEC_PLAYRESULT_PLAYING = 1,		// ムービー再生中
			eSOFDEC_PLAYRESULT_PLAYEND = 2,		// ムービー自動再生終了
			eSOFDEC_PLAYRESULT_SKIPSTOP = 3,	// ムービーキー押しスキップ終了
		};
	}
}/* namespace DxLibSound */



/* End dxLibSoundManageConfig.h */
