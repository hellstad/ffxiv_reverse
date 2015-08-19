#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
//#include <exception>

#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/format.hpp>

#include <zlib.h>

#include <xiv/utils/crc32.h>

#include <xiv/dat/Cat.h>
#include <xiv/dat/Dat.h>
#include <xiv/dat/File.h>
#include <xiv/dat/GameData.h>
#include <xiv/dat/Index.h>
#include <xiv/dat/SqPack.h>

#include <xiv/exd/Cat.h>
#include <xiv/exd/Exd.h>
#include <xiv/exd/ExdData.h>
#include <xiv/exd/Exh.h>
#include <xiv/exd/logger.h>

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	boost::log::add_file_log("extractor.log");

	boost::log::core::get()->set_filter(xiv::utils::log::severity_level >= xiv::utils::log::Severity::trace);

//		auto game_data = xiv::dat::GameData("D:\\ffxiv-fuckit");
//		auto game_data = xiv::dat::GameData("D:\\ffxiv-testbed");
	auto game_data = xiv::dat::GameData("D:\\ffxiv-copy\\game\\sqpack\\ffxiv");
	xiv::exd::ExdData exddata(game_data);
	exddata.export_as_csvs("D:\\ffxiv-dump\\");

//	auto& icon_cat = game_data.get_category("ui");
//	auto cat_hash_table = icon_cat.get_index().get_hash_table();
	return 0;
}