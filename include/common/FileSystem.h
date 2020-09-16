/*!
 * File FileSystem.h
 */

#pragma once

#include <string>
#include <physfs.h>
#include <pods/pods.h>
#include <pods/binary.h>
#include <pods/buffers.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <common/Utils.h>

namespace hpms
{
    class FileSystem
    {
    public:

        static int MountFS(const std::string& pak);

        inline static void* LoadRawResource(const std::string& path, size_t* size);

        inline static void DeleteRawResource(void* ptr)
        {
            hpms::SafeDeleteArray(ptr);
        }

        template<typename T>
        inline static T* LoadBinResource(const std::string& path, size_t* size);

        template<typename T>
        inline static void DeleteBinResource(T* ptr)
        {
            hpms::SafeDelete(ptr);
        }

    private:
        static bool init;
        static std::vector<std::string> mountedPaths;
    };



}


