#include <cstring>
#include "ldnmitm_config.hpp"
#include "debug.hpp"

namespace ams::mitm::ldn {
    std::atomic_bool LdnConfig::LdnEnabled = true;

    Result LdnConfig::GetVersion(sf::Out<LdnMitmVersion> version) {
        std::strcpy(version.GetPointer()->raw, GITDESCVER);
        
        R_SUCCEED();
    }
    Result LdnConfig::GetLogging(sf::Out<u32> enabled) {
        return ::GetLogging(enabled.GetPointer());
    }
    Result LdnConfig::SetLogging(u32 enabled) {
        return ::SetLogging(enabled);
    }
    Result LdnConfig::GetEnabled(sf::Out<u32> enabled) {
        enabled.SetValue(LdnEnabled);
        
        R_SUCCEED();
    }
    Result LdnConfig::SetEnabled(u32 enabled) {
        LdnEnabled = enabled;
        
        R_SUCCEED();
    }
}
