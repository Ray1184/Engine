/*!
 * File CGAPIManager.cpp
 */

#include <core/CGAPIManager.h>

CGAPIManager& hpms::CGAPIManager::Instance()
{
    static CGAPIManager inst;
    return inst;
}
