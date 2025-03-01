#pragma once

//===================================================================//
//	appResourcesLoadContainer
//
//
//===================================================================//

#include "../../../../Common/CervidaeLib/Utility/UtilityRenderObject.h"

/**
 *  基本このクラスを使用する
 */
/**
 *	@class リソースファイル管理用基本クラス
 */
namespace DxLib
{
    /**
	 * 
	 */
	struct ResourcesLoadContainer
	{
	
		AppLib::Resources::ProcessStatus::ENUM_RESOURCES_VRAM_TYPE		m_vLoadVramType;		// テクスチャファイルをアップするVRAMタイプ
		std::string														m_vLoadTextureName;		// テクスチャファイル登録名
		AppLib::Resources::Archive::ENUM_ARCHIVE_FILETYPE_LIST			m_vFileArchIndex;		// テクスチャファイルのアーカイブインデックス
		int																m_vFileIndex;			// テクスチャファイルの登録インデックス
		AppLib::Resources::Attribute::ENUM_RESFILE_ATTRIBUTE_TYPE_LIST	m_vFileAttribute;		// テクスチャファイルの設定属性
		AppLib::Resources::Parameter::ENUM_GRAPHIC_FILE_ENTRY_TYPE		m_vFileEntryUseType;	// テクスチャファイルの
		int																m_vLoadFileHandle;		// テクスチャファイルのロードハンドル
		int																m_vFileStatus;			// テクスチャファイルの処理状況
		
		Utility::ObjectSize												m_vTextureObj;			// テクスチャファイルサイズ

		// 読み込みが成功した時のコールバック
		typedef int	(*resultCallBack) ( void *, int );
		
	};
}


/* End appResourcesLoadContainer.h */


