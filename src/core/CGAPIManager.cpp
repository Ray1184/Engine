/*!
 * File CGAPIManager.cpp
 */

CGAPIManager& hpms::CGAPIManager::Instance()
{
    static CGAPIManager inst;
    return inst;
}
