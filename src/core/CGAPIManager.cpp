/*!
 * File CGAPIManager.cpp
 */

#include <core/CGAPIManager.h>

hpms::CGAPIManager& hpms::CGAPIManager::Instance()
{
    static CGAPIManager inst;
    return inst;
}
