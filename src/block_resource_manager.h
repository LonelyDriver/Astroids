#ifndef _BLOCK_RESOURCEMANAGER_H
#define _BLOCK_RESOURCEMANAGER_H
#include <unordered_map>
#include <memory>
#include <string>
#include "SDL2/SDL.h"
#include "block_exeption.h"
#include "block_texture_loader.h"

namespace block {


    template<typename resource, typename identifier = int>
    class ResourceManager {
    private:
        std::unordered_map<identifier, std::unique_ptr<resource>> _dict;

    public:
        ResourceManager(const ResourceManager&) = delete;
        ResourceManager& operator=(const ResourceManager&) = delete;
        ResourceManager() = default;

        template<typename ... Args>
        void Load(const identifier& id, Args&& ... args);

        resource& Get(const identifier& id) const;
    };
}
#include "block_resource_manager.tpl"

#endif // _BLOCK_RESOURCEMANAGER_H